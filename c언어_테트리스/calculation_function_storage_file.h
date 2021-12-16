
int mainMenu(void);// 시작메뉴
void randBlock(int log[],int point);// 다음 블록을 랜덤으로 세팅
void setControlBlock(int block,int th,int x_pos,int y_pos,int in);//현재위치 블록 설정  
int blockBreak(void);//블록 파괴
int cheackProhibitedArea(TetrisBlock *T,int *th,int shape);//현재 블록이 위험구역에 있는지를 체크 
void controlBlockTurnMove(TetrisBlock *T,int *th,int shape,int *ss);//블록을 컨트롤한다. 
int blockStop(TetrisBlock *T,int *th,int shape);//블록을 아래로 움직이며, 움직일수 없으면 블록을 멈춘다.
int cheackGameOver(void);//게임오버 확인  
 
int mainMenu(void){
	int key,point=0; //입력받은 버튼을 저장하는 변수, 현재가리키는 선택 저장 변수(0~2) 
	system("mode con cols=93 lines=30");//화면 사이즈 30행 93열로 조정  
	
	while(1){
		tetrisWordPrint(); //테트리스 글자 출력  
		clickMenu(point); // 게임 선택창 출력  
		key=getch();  //버튼 입력  
		
        if(key==32){ //스페이스바를 눌렀을 경우  
            if(point==0)return 1; //point가 0일경우 1리턴(게임 시작) 
            else if(point==1)printManual();// point가 1일경우 게임설명 출력 
            else if(point==2)return 0; //point가 2일경우 0리턴 (게임 종료)
        }
        if(key==224)key=getch();  
        if(key==UP)point--;  //윗 방향키를 눌렀을때 point--  
        else if(key==DOWN)point++; // 아래 방향키를 눌렀을때 point++ 
        if(point<0)point=2; //point가 범위(0~2) 보다 작아지면 2를 넣는다. 
        if(point>2)point=0; //point가 범위(0~2) 보다 크면 0을 넣는다.  
	}
}

void randBlock(int log[],int point){
	srand(time(NULL));
	register int i;
	
	if(point==12){ //다다음에 다음로그로 넘어갈때  
			for(i=0;i<40;i++){
				int a=rand()%7;
				int b=rand()%7;
				int temp=log[a];
				log[a]=log[b];
				log[b]=temp;
			}
		}else if(point==5){ //다다음에 다음로그로 넘어갈때  
			for(i=0;i<40;i++){
				int a=rand()%7+7;
				int b=rand()%7+7;
				int temp=log[a];
				log[a]=log[b];
				log[b]=temp;
			}
	}
}

void setControlBlock(int block,int th,int x_pos,int y_pos,int in){
	register int i,j;
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(tatris[block][th][i][j]==1){
				map[x_pos-(i-1)][y_pos-(j-2)]=in;
			}
		}
	}
}

int blockBreak(void){
	int combo=0;
	register int i,j,k;
	
	for(i=MAP_X-1;i>4;i--){
		for(j=0;j<MAP_Y;j++) if(map[i][j]!=2) break; //한줄이 다 안채워 지면 break  
		
		if(j>=MAP_Y) { //만약 한줄이 다 채워졌을 경우  
			combo++; //콤보수 1상승  
			for(k=i;k>4;k--) for(j=0;j<MAP_Y;j++) map[k][j]=map[k-1][j];// 다 채워진칸을 기준으로 한칸씩 블록을 내린다. 
			i++; 
		}
	}
	
	return combo; //콤보수 리턴  
}

int cheackProhibitedArea(TetrisBlock *T,int *th,int shape){
	register int i,j;
	for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(tatris[shape][*th][i][j]==1){
					int a=T->xposS-(i-1);
					int b=T->yposS-(j-2);
					if((map[a][b]==2)||(a<0)||!(a<MAP_X)||(b<0)||!(b<MAP_Y)){
						return 1;
					}
			}
		}
	}
	return 0;
}

void controlBlockTurnMove(TetrisBlock *T,int *th,int shape,int *ss){
	
	int key=getch();  
    if(key==224)key=getch(); 

    switch(key){
    	case 'z': //z,Z를 눌렀을 때 블록을 왼쪽으로 돌린다. 
    	case 'Z':
    		*th=(*th+1)%4;
			if(cheackProhibitedArea(T,th,shape)) *th=(*th+3)%4;
			break;
			
    	case 'x': //x,X를 눌렀을 때 블록을 오른쪽으로 돌린다.  
    	case 'X':
    		*th=(*th+3)%4;
			if(cheackProhibitedArea(T,th,shape)) *th=(*th+1)%4;
			break;
			
    	case 'c': //c,C를 눌렀을 때 현재 블록을 홀드한다.  
    	case 'C':
    		if(*ss==0) *ss=1;
    		break;
    	
    	case 's'://s.S를 눌렀을 때 일시정지한다. 
    	case 'S':
    		while(!kbhit());
    		break;
    		
    	case RIGHT: //오른쪽 방향키를 눌렀을 때 블록을 오른쪽으로 한칸 옮긴다.  
    		T->yposS++;
    		if(cheackProhibitedArea(T,th,shape)) T->yposS--;
    		break;
    		
    	case LEFT: //왼쪽 방향키를 눌렀을 때 블록을 왼쪽으로 한칸 옮긴다.  
    		T->yposS--;
    		if(cheackProhibitedArea(T,th,shape)) T->yposS++;
    		break;
    		
    	case DOWN: //아래방향키를 눌렀을 때 블록을 한칸 내린다.  
    		T->xposS++;
			if(cheackProhibitedArea(T,th,shape)) T->xposS--;
			break;
	}
} 

int blockStop(TetrisBlock *T,int *th,int shape){
	T->xposS++; //블록을 한칸 내린다.  
	if(cheackProhibitedArea(T,th,shape)){//만약 블록이 위험구역에 있을때  
		T->xposS--; //블록을 다시 한칸 올린다.  
		register int count=0; 
		
		while(1){
			Sleep(10);
			if(kbhit()){ //버튼을 누른것이 감지되었을 때 return   
				
				return 0;
			}
			count+=10;  
			if(count>=150){
				setControlBlock(shape,*th,T->xposS,T->yposS,2); //현재 블록을 멈춘블록으로 설정 
				T->xposS=2; //컨트롤은 블록이 나오는 위치로 이동   
				T->yposS=4;
				return 1; 
			}
		}
		
	} else{
		return 0;
	}
}

int cheackGameOver(void){
	register int i;
	for(i=0;i<10;i++){ //가장 위라인이 모두 멈춘블록일때 종료  
		if(map[4][i]==2){
			return 1;
		}
	}
	return 0;
} 

