
#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H

#include "Model.h"
#include "TicTacView.h"

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#define COMPUTERMOVE 1
#define HUMANMOVE 2
#define NOMOVE 3

class TicTacController {
public:
    TicTacController();
    TicTacController(TicTacModel *ticTacModel, TicTacView *ticTacView);
    virtual ~TicTacController();
	int ExitGame=0;
    void initializePlayer();
    int startGame();
    
private:
    char player2ID;
    char player1ID;
    bool nextMoveIsByHuman = true ;

    class TicTacModel *ticTacModel;
    class TicTacView *ticTacView;
    
    void askWhoStarts();
    void askPlayerToMove();
    
    void calculateAndDoYourMove();
    int getUserNextMove();
    
    void askComputerToMove();
    void askPlayersSign();
    bool askToPlayAgain();
    
    void doRandomMove();  /// TODO: For future use only
};

#endif /* TICTACCONTROLLER_H */

