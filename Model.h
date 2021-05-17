#ifndef TICTACMODEL_H
#define TICTACMODEL_H

#include <ctime>
#include <iostream>
using namespace std;

#define MAXCELLCOUNT 9
#define NOTVALIDINDEX -1
#define STARTCELLINDEX 0
#define ENDCELLINDEX MAXCELLCOUNT - 1
#define NOBODY 'N'
#define TIE 'T'
#define NOTSTARTED -1
#define CONFIRM 'Y'
#define NODATACHAR ' '


#define PLAYER1 true
#define PLAYER2 false

class TicTacModel {
public:
		TicTacModel();

		virtual ~TicTacModel();
		char * getBoardStatusCopy(char * boardLayoutCopy);
		bool isPlayerMoveValid(int cellNumber);

		bool isFull();
		void recordMove(int cellIndex, char playerID);
		char checkWinner();
    
		void setStarter(char userStarter);
		bool getNextMove();
		void changeNextMove();
    
		virtual void doPlayer1Move();
		virtual void setPlayer1ID();
		void setPlayer2ID();
    
		char getPlayer1ID();
		char getPlayer2ID();
    
		string getPlayer1Name();
		string getPlayer2Name();
		virtual void setPlayer1Name();
		void setPlayer2Name();
    
		string getFreeBoardCellsNumbers();
		char Player1ID;
		char Player2ID;
	
		string Player1Name;
		string Player2Name;
    
    char boardLayout[MAXCELLCOUNT] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    
    int moveSequence[9]; 
    int lastMoveIndex = -1;
    
    bool nextMove;
    bool startingPlayer;
    
    
		bool isCellIndexValid(int index);
		bool isCellEmpty(int cellNumber);
        
		int findRandomBlock();

};

#endif