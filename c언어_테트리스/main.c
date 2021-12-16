#include "value_storage_file.h"
#include "output_function_storage_file.h"
#include "calculation_function_storage_file.h"

int main(void){
	system("title TETRIS"); 
	start: 
	
	cursorView();
	if(0==mainMenu()) return 0; 
	system("cls");//메인 화면 지우기    
	
	//점수 및 게임 진행 관련 변수  
	int score=0,level=1,line=10,combo;//각각 현재 점수, 현재 레벨, 다음단계로 넘어가기위해 남은 라인수, 현재 콤보수 
	int best=inputBestScore();//최고점수 저장 변수  
	
	register int count=0,speed=160;//게임 속도 관련 변수 
	int key;//입력받는 버튼 저장 변수 
	
	//블록 관련 변수  
	TetrisBlock T={2,4};//현재 컨트롤하는 블록의 위치 
	int th=0,shape;//몇번째 0~3, 무슨 모양 0~6 
	
	int stockShape[1]={-1};//현재 저장중인 블록 모양  
	int stockSwitch=0; 

	int next=1; 
	int point=0; 
	int log[14]={0,1,2,3,4,5,6,0,1,2,3,4,5,6}; //테트리스 다음블록을 저장하는 배열  
	
	//초기 세팅 
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
    	
    	//블록파괴 확인및 점수 변동  
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
		
		//키입력을 통한 컨트롤  
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
    	
		//속도조절과 블록 내리기및 다음블록과 블록 세팅  
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
		
		//게임 오버 확인  
		
    	if(cheackGameOver()){
    		printGameOver(best,score);
    		goto start;
		}
	}
}

