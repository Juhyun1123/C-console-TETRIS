
void tetrisWordPrint(void);//�ܼ��� TETRIS ���� ���  
void clickMenu(int point);// ���� �Ŵ�ȭ�� ���  
void printManual(void);//���� ���� ���  
void mapFrame(int best,int score,int level,int line);//���Ӹ� Ʋ ���  
void setGameMap(int shape);//���� �������� ���Ӹ� ���  
void nextOrHoldBlockPrint(int next,int log[],int num,int hOn);//������� �Ǵ� Ȧ�� ��� ���  
void printGameOver(int best,int score);//���ӿ��� ȭ�� ���  

void gotoxy(int x,int y); // Ŀ���� ��ġ�� ȭ���� [x][y]�� �̵���Ų��. 
void cursorView(void); // Ŀ�� �����  


void tetrisWordPrint(void){
	printf("\n\n          ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
	printf("������  ");//t1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
	printf("������  ");//e1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ� 
	printf("������   ");//t1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ� 
	printf("����     ");//r1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//���� 
	printf("  ����     ");//i1
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//���� 
	printf("  ����   \n");//s1
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
	printf("    ��      ");//t2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
	printf("��          ");//e2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ� 
	printf("    ��       ");//t2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ� 
	printf("��    ��   ");//r2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//���� 
	printf("    ��       ");//i2
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//���� 
	printf("��      �� \n");//s2
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
	printf("    ��      ");//t3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
	printf("��          ");//e3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ� 
	printf("    ��       ");//t3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ� 
	printf("��    ��   ");//r3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//���� 
	printf("    ��       ");//i3
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//���� 
	printf("  ��       \n");//s3
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
	printf("    ��      ");//t4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
	printf("������  ");//e4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ� 
	printf("    ��       ");//t4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ� 
	printf("����     ");//r4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//���� 
	printf("    ��       ");//i4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//���� 
	printf("    ��     \n");//s4
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
	printf("    ��      ");//t5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
	printf("��          ");//e5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ� 
	printf("    ��       ");//t5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ� 
	printf("�� ��      ");//r5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//���� 
	printf("    ��       ");//i5
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//���� 
	printf("      ��   \n");//s5
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
	printf("    ��      ");//t6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
	printf("��          ");//e6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ� 
	printf("    ��       ");//t6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ� 
	printf("��   ��    ");//r6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//���� 
	printf("    ��       ");//i6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//���� 
	printf("��      �� \n");//s6
	printf("          ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
	printf("    ��      ");//t7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
	printf("������  ");//e7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ� 
	printf("    ��       ");//t7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ� 
	printf("��    ��   ");//r7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//���� 
	printf("  ����     ");//i7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//���� 
	printf("  ����   \n");//s7
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
}

void clickMenu(int point){
		int x=39,y=14; 
		
		gotoxy(x,y);
		printf("���� ����  ");
    	gotoxy(x,y+3);
    	printf("���� ����  ");
    	gotoxy(x,y+6);
    	printf("���� ����  ");
   	    gotoxy(x-12,y+10);
        printf("(����Ű�� �̵� [space]�� ���� ����)");
        
        gotoxy(x-5,y);
        printf("   ");
        gotoxy(x-5,y+3);
        printf("   ");
        gotoxy(x-5,y+6);
        printf("   ");
        
   	  	switch(point){//�Ű� ���� point�� ���� Ȯ���� ����ڰ� ����Ű�� �ִ� ���� �˼��ְ� ���ش�. 
            case 0://0�� ���� ����  
                gotoxy(x-5,y);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ�
                printf("��    ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//�Ķ�
				printf("���� ����");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//���  
                break;
            case 1://1�� ���� ����  
                gotoxy(x-5,y+3);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ�
                printf("��    ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//���
    			printf("���� ����");
    			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
                break;
            case 2://2�� ��������  
                gotoxy(x-5,y+6);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//�ʷ�
                printf("��    ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//����
    			printf("���� ����");
    			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
                break;
		}
        
        gotoxy(0,0);
}

void printManual(void){
	int touch=-1;//�Է¹��� ��ư�� �����ϴ� ����  
	system("cls");
	printf("\n\n\n   ����Ű\n");
	    printf("                          \n");
		printf("                          \n");
		printf("      �̵�:  <- , ->      \n");
		printf("                          \n");
		printf("                          \n");
		printf("      ȸ��:  Z  ,  X      \n");
		printf("                          \n");
		printf("                          \n");
		printf("      Ȧ��:     C         \n");
		printf("                          \n");
		printf("                          \n");
		printf("   \n");
		
	while(1){
		touch=getch();
		if(touch!=-1){ //touch�� �ʱ�ȭ�� -1�� �ƴҰ�� �� �ƹ��� ��ư�� ���� ������  
			system("cls"); //ȭ���� �����. 
			return ;   // ���� ȭ������ ���ư���.  
		}
	}
	
}

void mapFrame(int best,int score,int level,int line){
	gotoxy(0,0);
	printf("�������������������������������\n");
	printf("��              ���                    ���              ��\n");
	printf("��              ���                    ���              ��\n");
	printf("��              ���                    ���              ��\n");
	printf("��              ���                    ���              ��\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);//����
	printf("���������ᢺ                    ������������\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
    printf("��     ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//������
	printf("HOLD");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
	printf("     ���                    ���     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//������
	printf("NEXT");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
	printf("     ��\n");
    printf("�����������                    �����������\n");
    printf("��              ���                    ���              ��\n");
    printf("��              ���                    ���              ��\n");
    printf("��              ���                    ���              ��\n");
    printf("��              ���                    ���              ��\n");
    printf("��              ���                    ���              ��\n");
    printf("��              ���                    ���              ��\n");
    printf("��              ���                    ���              ��\n");
    printf("�����������                    �����������\n");
    printf("��              ���                    ���              ��\n");
    printf("��     SCORE    ���                    ���     LEVEL    ��\n");
    printf("��              ���                    ���              ��\n");
    printf("��     %05d    ���                    ���      %2d      ��\n",score,level);
    printf("��              ���                    ���              ��\n");
    printf("��     BEST     ���                    ���     LINES    ��\n");
    printf("��              ���                    ���              ��\n");
    printf("��     %05d    ���                    ���      %2d      ��\n",best,line);
    printf("��              ���                    ���              ��\n");
    printf("��              ���                    ���              ��\n");
    printf("�������������������������������\n");
}

void setGameMap(int shape){
	register int i,j;
	int color;
	switch(shape){
		case 0: // O���  
			color=14;
			break;
		case 1: // I���  
			color=3;
			break;
		case 2: // S���  
			color=10;
			break;
		case 3: // Z���  
			color=4;
			break;
		case 4: // L���  
			color=1;
			break;
		case 5: // J���  
			color=6;
			break;
		case 6: // T���  
			color=5;
			break;
		
	}
	for(i=0;i<MAP_X;i++){
		gotoxy(20,i+1);
		for(j=0;j<MAP_Y;j++){
			if(map[i][j]==0){//�� ����  
				printf("  ");
			}else if(map[i][j]==1){//���� ��Ʈ������ ��� 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);//��ϻ�   
				printf("��");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);//���  
			}else if(map[i][j]==2){//���� ���  
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);//ȸ��  
				printf("��");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//���  
			}
		}
	}
}

void nextOrHoldBlockPrint(int next,int log[],int num,int hOn){
	char *str;
	
	if(hOn==1) {//������� ������� Ȧ�������� �����Ѵ�.  
		hOn=42;
	}
	
	if(num==1)str="��";
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//��� 
			gotoxy(50-hOn,9);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,12);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
			break;
		case 2://S
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//��� 
			gotoxy(48-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(48-hOn,11);
			printf("%s",str);
			gotoxy(46-hOn,11);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
			break;
		case 3://Z
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//��� 
			gotoxy(48-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(52-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
			break;
		case 4://L
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);//��� 
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,12);
			printf("%s",str);
			gotoxy(52-hOn,12);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
			break;
		case 5://J
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);//��� 
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			gotoxy(50-hOn,12);
			printf("%s",str);
			gotoxy(48-hOn,12);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
			break;
		case 6://T
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//��� 
			gotoxy(48-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,10);
			printf("%s",str);
			gotoxy(52-hOn,10);
			printf("%s",str);
			gotoxy(50-hOn,11);
			printf("%s",str);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//��� 
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//������  
    
    printf("\n\n\n\n\n      ����      ��      ��      ��  �����      ���    ��      ��  �����  ����  \n");
    printf("    ��          ��  ��    ���  ���  ��          ��    ��  ��      ��  ��        ��    ��\n");
    printf("    ��  ���    ��  ��    ��  ��  ��  �����    ��    ��    ��  ��    �����  ����  \n");
    printf("    ��    ��  ������  ��      ��  ��          ��    ��    ��  ��    ��        ��    ��\n");
    printf("      ����  ��      ��  ��      ��  �����      ���        ��      �����  ��    ��\n");

    printf("\n\n                                  ����� ������ %d�� �Դϴ�.",score);
    printf("\n\n                                  �ְ� ������ %d �� �Դϴ�.",best);
    
    printf("\n\n\n\n\n                          [space]�� ������ ����ȭ������ ���ư��ϴ�.");
    
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
