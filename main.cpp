
#include <iostream>
#include <cstdlib>
#include "Model.h"
#include "TicTacView.h"
#include "TicTacController.h"
#include "ComputerPlayer.cpp"
#include "HumanPlayer.cpp"
using namespace std;

int main(int argc, char** argv) {

    bool startAgain = false;
  
        class TicTacModel *ticTacHuman=new HumanPlayer;
        class TicTacView *ticTacVH=new TicTacView;
        class TicTacController* ticTacControllerH=new TicTacController(ticTacHuman, ticTacVH);
		class TicTacModel *ticTacComputer=new ComputerPlayer;
        class TicTacView *ticTacVC=new TicTacView;
        class TicTacController *ticTacControllerC=new TicTacController(ticTacComputer, ticTacVC);
		int done_human=1;
		int done_computer=1;
		while((done_human<=2 or done_computer<=2) and (done_human!=0 and done_computer!=0)){
			int index;
			cout<< "1 for human vs human , 2 for comp vs human\n";
			cin>>index;
			if(index==1){
				if(done_human==1){
				ticTacHuman=new HumanPlayer;
				ticTacVH=new TicTacView;
				ticTacControllerH=new TicTacController(ticTacHuman, ticTacVH);
				ticTacControllerH->initializePlayer();
				}
				done_human= ticTacControllerH->startGame();
				cout<<"done human code :"<<done_human<<"\n";
			}
			else{
				if(done_computer==1){
				ticTacComputer=new ComputerPlayer;
				ticTacVC=new TicTacView;
				ticTacControllerC=new TicTacController(ticTacComputer, ticTacVC);
				ticTacControllerC->initializePlayer();
				}
				done_computer= ticTacControllerC->startGame();
				cout<<"done computer code :"<<done_computer<<"\n";
			}
		}
		
     
    return 0;

}

