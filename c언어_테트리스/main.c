#include "value_storage_file.h"
#include "output_function_storage_file.h"
#include "calculation_function_storage_file.h"

int main(void){
	system("title TETRIS"); 
	start: 
	
	cursorView();
	if(0==mainMenu()) return 0; 
	system("cls");//���� ȭ�� �����    
	
	//���� �� ���� ���� ���� ����  
	int score=0,level=1,line=10,combo;//���� ���� ����, ���� ����, �����ܰ�� �Ѿ������ ���� ���μ�, ���� �޺��� 
	int best=inputBestScore();//�ְ����� ���� ����  
	
	register int count=0,speed=160;//���� �ӵ� ���� ���� 
	int key;//�Է¹޴� ��ư ���� ���� 
	
	//��� ���� ����  
	TetrisBlock T={2,4};//���� ��Ʈ���ϴ� ����� ��ġ 
	int th=0,shape;//���° 0~3, ���� ��� 0~6 
	
	int stockShape[1]={-1};//���� �������� ��� ���  
	int stockSwitch=0; 

	int next=1; 
	int point=0; 
	int log[14]={0,1,2,3,4,5,6,0,1,2,3,4,5,6}; //��Ʈ���� ��������� �����ϴ� �迭  
	
	//�ʱ� ���� 
	system("mode con cols=70 lines=30");
    cursorView();
    
    randBlock(log,12);
	randBlock(log,12);
	randBlock(log,12);
	randBlock(log,5);
	randBlock(log,5);
	randBlock(log,5);
	shape=log[point];
	
	mapFrame(best,score,level,line);
    nextOrHoldBlockPrint(next,log,1,0);
	
	while(1){
		setControlBlock(shape,th,T.xposS,T.yposS,1);
    	setGameMap(shape);
    	setControlBlock(shape,th,T.xposS,T.yposS,0);
    	
    	//����ı� Ȯ�ι� ���� ����  
    	combo=blockBreak();
		if(combo>0){
			score+=(combo*combo*level);
    		line-=combo;
    		if(line<1){
    			level++;
    			line=(level+1)*5;
    			if(speed>20) speed-=20;
			}
			
    		mapFrame(best,score,level,line);
    		nextOrHoldBlockPrint(0,stockShape,1,1);
    		nextOrHoldBlockPrint(next,log,1,0);
		} 
		
		//Ű�Է��� ���� ��Ʈ��  
    	Sleep(0.1);
    	if(kbhit()){
			controlBlockTurnMove(&T,&th,shape,&stockSwitch);
			
			if(stockSwitch==1){
				stockSwitch=2;
				T.xposS=2;
    			T.yposS=4;
    			
				if(stockShape[0]==-1){
					stockShape[0]=shape;
					nextOrHoldBlockPrint(0,stockShape,1,1);
					goto ch;
				}else{
					nextOrHoldBlockPrint(0,stockShape,0,1);
					int temp=shape;
					shape=stockShape[0];
					stockShape[0]=temp;
					nextOrHoldBlockPrint(0,stockShape,1,1);
				}
			}
		}
    	
		//�ӵ������� ��� ������� ������ϰ� ��� ����  
		Sleep(10);
		count+=10;
		if(count>=speed){
			if(blockStop(&T,&th,shape)){
				stockSwitch=0;
				ch:
				nextOrHoldBlockPrint(next,log,0,0);
				shape=log[next];
				randBlock(log,point);
				if(++point>13)point=0;
				if(point==13) next=0;
				else next=point+1;
				nextOrHoldBlockPrint(next,log,1,0);
			}
			count=0;
		}
		
		//���� ���� Ȯ��  
		
    	if(cheackGameOver()){
    		printGameOver(best,score);
    		goto start;
		}
	}
}

