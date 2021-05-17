
#include "TicTacController.h"

TicTacController::TicTacController() {
}

TicTacController::TicTacController(TicTacModel *ticTacModel, TicTacView *ticTacView) {
    this->ticTacModel = ticTacModel;
    this->ticTacView = ticTacView;
}

TicTacController::~TicTacController() {
}

void TicTacController::initializePlayer() {

	ticTacModel->setPlayer1ID();
	ticTacModel->setPlayer2ID();
	ticTacModel->setPlayer1Name();
	ticTacModel->setPlayer2Name();
	askWhoStarts();
}

void TicTacController::askWhoStarts() {
    cout << "enter player id who wants to start\n";
	char  playerID;
	cin>>playerID;
	ticTacModel->setStarter(playerID);
}

int TicTacController::startGame() {
    char winner = NOBODY;
    string winnerName;
    char boardLayoutCopy[MAXCELLCOUNT];
    while (winner == NOBODY) {
        if (ticTacModel->getNextMove()){
			cout<<"ur turn player :"<<ticTacModel->getPlayer1ID()<<"\n";
			ticTacView->renderGameScreen(ticTacModel->getBoardStatusCopy(boardLayoutCopy), true);
            ticTacModel->doPlayer1Move();
            ticTacModel->changeNextMove();
        } else {
			cout<<"ur turn player :"<<ticTacModel->getPlayer2ID()<<"\n";
            askPlayerToMove();
            ticTacModel->changeNextMove();
        }
        winner = ticTacModel->checkWinner();
		
		cout <<"if u wanna join another game  press 1 else 0\n ";
		cin >> ExitGame;
		if(ExitGame){
			ExitGame=0;
			return 2;
		}
    }
	if(ExitGame==0){
    ticTacView->renderGameScreen(ticTacModel->getBoardStatusCopy(boardLayoutCopy), false);

    if(winner == TIE){
        ticTacView->announceNoWinner();
        return askToPlayAgain();
    }
    
    if(winner == ticTacModel->getPlayer1ID())
        ticTacView->announceWinner(ticTacModel->getPlayer1ID(), 
                                    ticTacModel->getPlayer1Name());
    else
        ticTacView->announceWinner(ticTacModel->getPlayer2ID(), 
                                    ticTacModel->getPlayer2Name());
    
    return askToPlayAgain();
	}
	return 0;
}

bool TicTacController::askToPlayAgain(){
    string playerAnswer = "";

    ticTacView->prepareAskToPlayAgainQuestion();
    ticTacModel->setStarter((char)toupper(playerAnswer[0]));
    
    cin >> playerAnswer;
    
    return ((char)toupper(playerAnswer[0]) == CONFIRM);
}


void TicTacController::askPlayerToMove() {
    int playerNextCellIndex = 0;
    char boardLayoutCopy[MAXCELLCOUNT];
    
    do {
        ticTacView->renderGameScreen(ticTacModel->getBoardStatusCopy(boardLayoutCopy));
        ticTacView->preparePlayerMoveQuestion(ticTacModel->getFreeBoardCellsNumbers());

        playerNextCellIndex = ticTacView->getUserNextMove();

    } while (!ticTacModel->isPlayerMoveValid(playerNextCellIndex));

    ticTacModel->recordMove(playerNextCellIndex,ticTacModel->getPlayer2ID());
}

void TicTacController::askComputerToMove() {
    ticTacModel->doPlayer1Move();
}

void TicTacController::doRandomMove(){
    int playerCellIndex;
    srand(time(0));
    do {
        playerCellIndex = rand() % 10;
    } while (!ticTacModel->isPlayerMoveValid(playerCellIndex));
    ticTacModel->recordMove(playerCellIndex, player1ID);
}
