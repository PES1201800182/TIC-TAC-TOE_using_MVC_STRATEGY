
#include <string>

#include "Model.h"

TicTacModel::TicTacModel() {

    lastMoveIndex = NOTSTARTED;
    for (int i = 0; i < MAXCELLCOUNT; i++)
        moveSequence[i] = NOTSTARTED;
}

TicTacModel::~TicTacModel() {
}

char * TicTacModel::getBoardStatusCopy(char * boardLayoutCopy) {
    for (int i = 0; i < MAXCELLCOUNT; i++)
        boardLayoutCopy[i] = boardLayout[i];

    return boardLayoutCopy;
}

bool TicTacModel::isPlayerMoveValid(int cellIndex) {
    if (isCellIndexValid(cellIndex) && isCellEmpty(cellIndex))
        return true;
    else
        return false;
}

void TicTacModel::recordMove(int cellIndex, char playerID) {
    boardLayout[cellIndex] = playerID;
    moveSequence[++lastMoveIndex] = cellIndex;
}


bool TicTacModel::isCellEmpty(int CellIndex) {
    if (boardLayout[CellIndex] == ' '){
		
        return true;
	}
    else{
        return false;
	}
}

bool TicTacModel::isCellIndexValid(int cellIndex) {
    if (cellIndex < STARTCELLINDEX || cellIndex > ENDCELLINDEX){
        return false;
	}
    else{
        return true;
	}
}

bool TicTacModel::isFull() {
    for (int i = 0; i < MAXCELLCOUNT; i++) {
        if (boardLayout[i] == ' ')
            return false;
    }
    return true;
}

char TicTacModel::checkWinner() {

    if (boardLayout[0] == boardLayout[1] && boardLayout[0] == boardLayout[2] &&
            boardLayout[0] != NODATACHAR) return boardLayout[0];
    if (boardLayout[3] == boardLayout[4] && boardLayout[3] == boardLayout[5] &&
            boardLayout[3] != NODATACHAR) return boardLayout[3];
    if (boardLayout[6] == boardLayout[7] && boardLayout[6] == boardLayout[8] &&
            boardLayout[6] != NODATACHAR) return boardLayout[6];

    if (boardLayout[0] == boardLayout[3] && boardLayout[0] == boardLayout[6] &&
            boardLayout[0] != NODATACHAR) return boardLayout[0];
    if (boardLayout[1] == boardLayout[4] && boardLayout[1] == boardLayout[7] &&
            boardLayout[1] != NODATACHAR) return boardLayout[1];
    if (boardLayout[2] == boardLayout[5] && boardLayout[2] == boardLayout[8] &&
            boardLayout[2] != NODATACHAR) return boardLayout[2];

    if (boardLayout[0] == boardLayout[4] && boardLayout[0] == boardLayout[8] &&
            boardLayout[0] != NODATACHAR) return boardLayout[0];

    if (boardLayout[2] == boardLayout[4] && boardLayout[2] == boardLayout[6] &&
            boardLayout[2] != NODATACHAR) return boardLayout[2];

    if (isFull())
        return TIE;

    return NOBODY;
}

void TicTacModel::setStarter(char userStarter) {
    if (userStarter == Player1ID) {
        nextMove = PLAYER1;
        startingPlayer = PLAYER1;
    } else {
        nextMove = PLAYER2;
        startingPlayer = PLAYER2;
    }
}

bool TicTacModel::getNextMove() {
    return nextMove;
}

void TicTacModel::changeNextMove() {
    if (nextMove == PLAYER1) {
        nextMove = PLAYER2;
    } else {
        nextMove = PLAYER1;
    }
}


void TicTacModel::setPlayer2ID() {
	char id;
	cout << "enter player2 id\n";
	cin >> id ;
    Player2ID = id;
}

char TicTacModel::getPlayer1ID() {
    return Player1ID;
}

char TicTacModel::getPlayer2ID() {
    return Player2ID;
}

string TicTacModel::getPlayer1Name() {
    return Player1Name;
}

string TicTacModel::getPlayer2Name() {
    return Player2Name;
}

void TicTacModel::setPlayer2Name(){
	string Name;
	cout << "enter player 2 name\n";
	cin>>Name;
	Player2Name=Name;
}
int TicTacModel::findRandomBlock() {
    int playerCellIndex;
    do {
        playerCellIndex = rand() % 9;
    } while (!isCellEmpty(playerCellIndex));

    return playerCellIndex;
}

void TicTacModel::setPlayer1ID(){
}
void TicTacModel::doPlayer1Move(){
}
void TicTacModel::setPlayer1Name(){
}
string TicTacModel::getFreeBoardCellsNumbers() {
    
    string freeBoardCellsNumbers = "(";
    bool first = true;

    for (int i = 0; i < MAXCELLCOUNT; i++) {
        if (boardLayout[i] == ' '){
            if(first != true){
                freeBoardCellsNumbers += ", ";
            }
            else{
                first = false;
            }
            freeBoardCellsNumbers += to_string(i + 1);
        }
    }

    freeBoardCellsNumbers += ")";
    
    return freeBoardCellsNumbers;
}
