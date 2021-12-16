
void tetrisWordPrint(void);//단순한 TETRIS 글자 출력  
void clickMenu(int point);// 게임 매뉴화면 출력  
void printManual(void);//게임 설명 출력  
void mapFrame(int best,int score,int level,int line);//게임맵 틀 출력  
void setGameMap(int shape);//현재 진행중인 게임맵 출력  
void nextOrHoldBlockPrint(int next,int log[],int num,int hOn);//다음블록 또는 홀드 블록 출력  
void printGameOver(int best,int score);//게임오버 화면 출력  

void gotoxy(int x,int y); // 커서의 위치를 화면의 [x][y]로 이동시킨다. 
void cursorView(void); // 커서 숨기기  


void tetrisWordPrint(void){
	printf("\n\n          ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
	printf("■■■■■  ");//t1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑 
	printf("■■■■■  ");//e1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록 
	printf("■■■■■   ");//t1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑 
	printf("■■■     ");//r1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//옥색 
	printf("  ■■■     ");//i1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//자주 
	printf("  ■■■   \n");//s1
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
	printf("    ■      ");//t2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑 
	printf("■          ");//e2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록 
	printf("    ■       ");//t2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑 
	printf("■    ■   ");//r2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//옥색 
	printf("    ■       ");//i2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//자주 
	printf("■      ■ \n");//s2
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
	printf("    ■      ");//t3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑 
	printf("■          ");//e3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록 
	printf("    ■       ");//t3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑 
	printf("■    ■   ");//r3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//옥색 
	printf("    ■       ");//i3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//자주 
	printf("  ■       \n");//s3
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
	printf("    ■      ");//t4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑 
	printf("■■■■■  ");//e4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록 
	printf("    ■       ");//t4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑 
	printf("■■■     ");//r4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//옥색 
	printf("    ■       ");//i4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//자주 
	printf("    ■     \n");//s4
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
	printf("    ■      ");//t5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑 
	printf("■          ");//e5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록 
	printf("    ■       ");//t5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑 
	printf("■ ■      ");//r5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//옥색 
	printf("    ■       ");//i5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//자주 
	printf("      ■   \n");//s5
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
	printf("    ■      ");//t6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑 
	printf("■          ");//e6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록 
	printf("    ■       ");//t6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑 
	printf("■   ■    ");//r6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//옥색 
	printf("    ■       ");//i6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//자주 
	printf("■      ■ \n");//s6
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
	printf("    ■      ");//t7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑 
	printf("■■■■■  ");//e7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록 
	printf("    ■       ");//t7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑 
	printf("■    ■   ");//r7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//옥색 
	printf("  ■■■     ");//i7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//자주 
	printf("  ■■■   \n");//s7
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
}

void clickMenu(int point){
		int x=39,y=14; 
		
		gotoxy(x,y);
		printf("게임 시작  ");
    	gotoxy(x,y+3);
    	printf("게임 설명  ");
    	gotoxy(x,y+6);
    	printf("게임 종료  ");
   	    gotoxy(x-12,y+10);
        printf("(방향키로 이동 [space]를 눌러 선택)");
        
        gotoxy(x-5,y);
        printf("   ");
        gotoxy(x-5,y+3);
        printf("   ");
        gotoxy(x-5,y+6);
        printf("   ");
        
   	  	switch(point){//매개 변수 point의 숫자 확인후 사용자가 가리키고 있는 곳을 알수있게 해준다. 
            case 0://0은 게임 시작  
                gotoxy(x-5,y);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록
                printf("☞    ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//파랑
				printf("게임 시작");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색  
                break;
            case 1://1은 게임 설명  
                gotoxy(x-5,y+3);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록
                printf("☞    ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//노랑
    			printf("게임 설명");
    			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
                break;
            case 2://2는 게임종료  
                gotoxy(x-5,y+6);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//초록
                printf("☞    ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강
    			printf("게임 종료");
    			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
                break;
		}
        
        gotoxy(0,0);
}

void printManual(void){
	int touch=-1;//입력받은 버튼을 저장하는 변수  
	system("cls");
	printf("\n\n\n   조작키\n");
	    printf("                          \n");
		printf("                          \n");
		printf("      이동:  <- , ->      \n");
		printf("                          \n");
		printf("                          \n");
		printf("      회전:  Z  ,  X      \n");
		printf("                          \n");
		printf("                          \n");
		printf("      홀드:     C         \n");
		printf("                          \n");
		printf("                          \n");
		printf("   \n");
		
	while(1){
		touch=getch();
		if(touch!=-1){ //touch가 초기화한 -1이 아닐경우 즉 아무런 버튼이 눌러 졌을때  
			system("cls"); //화면을 지운다. 
			return ;   // 메인 화면으로 돌아간다.  
		}
	}
	
}

void mapFrame(int best,int score,int level,int line){
	gotoxy(0,0);
	printf("□□□□□□□□□■■■■■■■■■■■■□□□□□□□□□\n");
	printf("□              □■                    ■□              □\n");
	printf("□              □■                    ■□              □\n");
	printf("□              □■                    ■□              □\n");
	printf("□              □■                    ■□              □\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);//빨강
	printf("■■■■■■■■■▶                    ◀■■■■■■■■■\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
    printf("□     ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//누런색
	printf("HOLD");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
	printf("     □■                    ■□     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//누런색
	printf("NEXT");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
	printf("     □\n");
    printf("□□□□□□□□□■                    ■□□□□□□□□□\n");
    printf("□              □■                    ■□              □\n");
    printf("□              □■                    ■□              □\n");
    printf("□              □■                    ■□              □\n");
    printf("□              □■                    ■□              □\n");
    printf("□              □■                    ■□              □\n");
    printf("□              □■                    ■□              □\n");
    printf("□              □■                    ■□              □\n");
    printf("□□□□□□□□□■                    ■□□□□□□□□□\n");
    printf("□              □■                    ■□              □\n");
    printf("□     SCORE    □■                    ■□     LEVEL    □\n");
    printf("□              □■                    ■□              □\n");
    printf("□     %05d    □■                    ■□      %2d      □\n",score,level);
    printf("□              □■                    ■□              □\n");
    printf("□     BEST     □■                    ■□     LINES    □\n");
    printf("□              □■                    ■□              □\n");
    printf("□     %05d    □■                    ■□      %2d      □\n",best,line);
    printf("□              □■                    ■□              □\n");
    printf("□              □■                    ■□              □\n");
    printf("□□□□□□□□□■■■■■■■■■■■■□□□□□□□□□\n");
}

void setGameMap(int shape){
	register int i,j;
	int color;
	switch(shape){
		case 0: // O블록  
			color=14;
			break;
		case 1: // I블록  
			color=3;
			break;
		case 2: // S블록  
			color=10;
			break;
		case 3: // Z블록  
			color=4;
			break;
		case 4: // L블록  
			color=1;
			break;
		case 5: // J블록  
			color=6;
			break;
		case 6: // T블록  
			color=5;
			break;
		
	}
	for(i=0;i<MAP_X;i++){
		gotoxy(20,i+1);
		for(j=0;j<MAP_Y;j++){
			if(map[i][j]==0){//빈 공간  
				printf("  ");
			}else if(map[i][j]==1){//현재 컨트롤중인 블록 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);//블록색   
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);//흰색  
			}else if(map[i][j]==2){//쌓인 블록  
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);//회색  
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색  
			}
		}
	}
}

void nextOrHoldBlockPrint(int next,int log[],int num,int hOn){
	char *str;
	
	if(hOn==1) {//다음블록 출력인지 홀드블록인지 구분한다.  
		hOn=42;
	}
	
	if(num==1)str="■";
	else str="  ";
	
	switch(log[next]){
		case 0://O
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			gotoxy(48-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(48-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			break;
		case 1://I
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//흰색 
			gotoxy(50-hOn,9);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,12);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
			break;
		case 2://S
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//흰색 
			gotoxy(48-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(48-hOn,11);
			printf("%s",str);
			gotoxy(46-hOn,11);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
			break;
		case 3://Z
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//흰색 
			gotoxy(48-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(52-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
			break;
		case 4://L
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//흰색 
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,12);
			printf("%s",str);
			gotoxy(52-hOn,12);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
			break;
		case 5://J
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//흰색 
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,12);
			printf("%s",str);
			gotoxy(48-hOn,12);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
			break;
		case 6://T
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//흰색 
			gotoxy(48-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(52-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//흰색 
			break;	
	}
}

void printGameOver(int best,int score){
	int key,i,j; 
	
	if(best<score){
		best=score;
		FILE *fp=fopen("best_score.txt","wt");
		fprintf(fp,"%d",best);
		fclose(fp);
	}
	
	system("cls");
	system("mode con cols=100 lines=30");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//빨강색  
    
    printf("\n\n\n\n\n      ■■■      ■      ■      ■  ■■■■      ■■    ■      ■  ■■■■  ■■■  \n");
    printf("    ■          ■  ■    ■■  ■■  ■          ■    ■  ■      ■  ■        ■    ■\n");
    printf("    ■  ■■    ■  ■    ■  ■  ■  ■■■■    ■    ■    ■  ■    ■■■■  ■■■  \n");
    printf("    ■    ■  ■■■■■  ■      ■  ■          ■    ■    ■  ■    ■        ■    ■\n");
    printf("      ■■■  ■      ■  ■      ■  ■■■■      ■■        ■      ■■■■  ■    ■\n");

    printf("\n\n                                  당신의 점수는 %d점 입니다.",score);
    printf("\n\n                                  최고 점수는 %d 점 입니다.",best);
    
    printf("\n\n\n\n\n                          [space]를 누르면 메인화면으로 돌아갑니다.");
    
    for(i=0;i<MAP_X;i++){
    	for(j=0;j<MAP_Y;j++){
    		map[i][j]=0;
		}
	}
    
    while(1){
    	key=getch();
    	if(key==32) return ;
	}
}

void gotoxy(int x,int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(consoleHandle,pos);
}

void cursorView(void){
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    
    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}
