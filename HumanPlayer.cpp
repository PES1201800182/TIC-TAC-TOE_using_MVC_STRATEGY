#include<map>
#include<string>
#include "Model.h"
using namespace std;
class HumanPlayer: public  TicTacModel {
	 void setPlayer1ID(){
		char id;
		cout << "enter player1 id\n";
		cin >> id ;
		Player1ID = id;
	}
	void setPlayer1Name(){
		string Name;
		cout << "enter player 1 name\n";
		cin>>Name;
		Player1Name=Name;
	}
	void doPlayer1Move(){
		int playerNextCellIndex = 0;
		 do {
			cout << "Select a cell number " << getFreeBoardCellsNumbers() <<" for your next move -> ";
			cin >> playerNextCellIndex;
			
		} while (!isPlayerMoveValid(playerNextCellIndex-1));
	recordMove(playerNextCellIndex-1, Player1ID);
	}
};
			
		
				
		