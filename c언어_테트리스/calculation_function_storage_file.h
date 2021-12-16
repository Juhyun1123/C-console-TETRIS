
int mainMenu(void);// ���۸޴�
void randBlock(int log[],int point);// ���� ����� �������� ����
void setControlBlock(int block,int th,int x_pos,int y_pos,int in);//������ġ ��� ����  
int blockBreak(void);//��� �ı�
int cheackProhibitedArea(TetrisBlock *T,int *th,int shape);//���� ����� ���豸���� �ִ����� üũ 
void controlBlockTurnMove(TetrisBlock *T,int *th,int shape,int *ss);//����� ��Ʈ���Ѵ�. 
int blockStop(TetrisBlock *T,int *th,int shape);//����� �Ʒ��� �����̸�, �����ϼ� ������ ����� �����.
int cheackGameOver(void);//���ӿ��� Ȯ��  
 
int mainMenu(void){
	int key,point=0; //�Է¹��� ��ư�� �����ϴ� ����, ���簡��Ű�� ���� ���� ����(0~2) 
	system("mode con cols=93 lines=30");//ȭ�� ������ 30�� 93���� ����  
	
	while(1){
		tetrisWordPrint(); //��Ʈ���� ���� ���  
		clickMenu(point); // ���� ����â ���  
		key=getch();  //��ư �Է�  
		
        if(key==32){ //�����̽��ٸ� ������ ���  
            if(point==0)return 1; //point�� 0�ϰ�� 1����(���� ����) 
            else if(point==1)printManual();// point�� 1�ϰ�� ���Ӽ��� ��� 
            else if(point==2)return 0; //point�� 2�ϰ�� 0���� (���� ����)
        }
        if(key==224)key=getch();  
        if(key==UP)point--;  //�� ����Ű�� �������� point--  
        else if(key==DOWN)point++; // �Ʒ� ����Ű�� �������� point++ 
        if(point<0)point=2; //point�� ����(0~2) ���� �۾����� 2�� �ִ´�. 
        if(point>2)point=0; //point�� ����(0~2) ���� ũ�� 0�� �ִ´�.  
	}
}

void randBlock(int log[],int point){
	srand(time(NULL));
	register int i;
	
	if(point==12){ //�ٴ����� �����α׷� �Ѿ��  
			for(i=0;i<40;i++){
				int a=rand()%7;
				int b=rand()%7;
				int temp=log[a];
				log[a]=log[b];
				log[b]=temp;
			}
		}else if(point==5){ //�ٴ����� �����α׷� �Ѿ��  
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
		for(j=0;j<MAP_Y;j++) if(map[i][j]!=2) break; //������ �� ��ä�� ���� break  
		
		if(j>=MAP_Y) { //���� ������ �� ä������ ���  
			combo++; //�޺��� 1���  
			for(k=i;k>4;k--) for(j=0;j<MAP_Y;j++) map[k][j]=map[k-1][j];// �� ä����ĭ�� �������� ��ĭ�� ����� ������. 
			i++; 
		}
	}
	
	return combo; //�޺��� ����  
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
    	case 'z': //z,Z�� ������ �� ����� �������� ������. 
    	case 'Z':
    		*th=(*th+1)%4;
			if(cheackProhibitedArea(T,th,shape)) *th=(*th+3)%4;
			break;
			
    	case 'x': //x,X�� ������ �� ����� ���������� ������.  
    	case 'X':
    		*th=(*th+3)%4;
			if(cheackProhibitedArea(T,th,shape)) *th=(*th+1)%4;
			break;
			
    	case 'c': //c,C�� ������ �� ���� ����� Ȧ���Ѵ�.  
    	case 'C':
    		if(*ss==0) *ss=1;
    		break;
    	
    	case 's'://s.S�� ������ �� �Ͻ������Ѵ�. 
    	case 'S':
    		while(!kbhit());
    		break;
    		
    	case RIGHT: //������ ����Ű�� ������ �� ����� ���������� ��ĭ �ű��.  
    		T->yposS++;
    		if(cheackProhibitedArea(T,th,shape)) T->yposS--;
    		break;
    		
    	case LEFT: //���� ����Ű�� ������ �� ����� �������� ��ĭ �ű��.  
    		T->yposS--;
    		if(cheackProhibitedArea(T,th,shape)) T->yposS++;
    		break;
    		
    	case DOWN: //�Ʒ�����Ű�� ������ �� ����� ��ĭ ������.  
    		T->xposS++;
			if(cheackProhibitedArea(T,th,shape)) T->xposS--;
			break;
	}
} 

int blockStop(TetrisBlock *T,int *th,int shape){
	T->xposS++; //����� ��ĭ ������.  
	if(cheackProhibitedArea(T,th,shape)){//���� ����� ���豸���� ������  
		T->xposS--; //����� �ٽ� ��ĭ �ø���.  
		register int count=0; 
		
		while(1){
			Sleep(10);
			if(kbhit()){ //��ư�� �������� �����Ǿ��� �� return   
				
				return 0;
			}
			count+=10;  
			if(count>=150){
				setControlBlock(shape,*th,T->xposS,T->yposS,2); //���� ����� ���������� ���� 
				T->xposS=2; //��Ʈ���� ����� ������ ��ġ�� �̵�   
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
	for(i=0;i<10;i++){ //���� �������� ��� �������϶� ����  
		if(map[4][i]==2){
			return 1;
		}
	}
	return 0;
} 

