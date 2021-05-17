#include "TicTacView.h"

TicTacView::TicTacView() {
}

TicTacView::~TicTacView() {
}

void TicTacView::drawBoardLine(char * boardStatus, int lastRowNum) {
    if (((lastRowNum + 1) % ROWCOUNT) == 0) return;
    string noDataLine = "";
    for (int j = 0; j < COLUMNCOUNT; j++) {
        noDataLine += "---";
        if (((j + 1) % COLUMNCOUNT) != 0)
            noDataLine += "|";
    }
    cout << noDataLine << "\n";
}

void TicTacView::drawBoardCellRow(char * dataArray, int lastRowNum) {

    string boardRow = "";
    string s;

    for (int j = 0; j < COLUMNCOUNT; j++) {
        s = dataArray[lastRowNum * 3 + j];
        boardRow += " " + s + " ";
        if (((j + 1) % COLUMNCOUNT) != 0)
            boardRow += "|";
    }
    cout << boardRow << "\n";
}

void TicTacView::drawBoard(char * boardDataArray) {
    for (int i = 0; i < ROWCOUNT; i++) {
        drawBoardCellRow(boardDataArray, i);
        drawBoardLine(boardDataArray, i);
    }
}

void TicTacView::showGameBoard(char * boardStatus) {
    cout << "============\n";
    cout << " Computer: X \n";
    cout << "  Player: O \n";
    cout << "============\n";
    cout << " Game Board \n";
    cout << "============\n";
    drawBoard(boardStatus);
    cout << "\n\n";
}

void TicTacView::drawGameBoardHint(char * boardStatus) {
    char boardHintData[9];
    int dataArraySize = ROWCOUNT * COLUMNCOUNT;

    cout << "\n\n";
    cout << "===============\n";
    cout << "Game Board Map \n";
    cout << "===============\n";

    for (int i = 0; i < dataArraySize; i++) {
        if (boardStatus[i] == ' ')
            boardHintData[i] = to_string(i + 1)[0];
        else
            boardHintData[i] = ' ';
    }

    drawBoard(boardHintData);
    cout << "\n\n";
}


void TicTacView::renderGameScreen(char * boardStatus, bool drawHint) {
    showGameBoard(boardStatus);
    if (drawHint)
        drawGameBoardHint(boardStatus);

}

void TicTacView::preparePlayerMoveQuestion(string freeCellNumber) {
    cout << "Select a cell number " << freeCellNumber <<" for your next move -> ";
}

void TicTacView::prepareAskToPlayAgainQuestion() {
    cout << "Do you want to play again? (Y or N) ";
}


int TicTacView::getUserNextMove(){
    int playerNextCellNumber;
    cin >> playerNextCellNumber;
    return playerNextCellNumber - 1;
}

void TicTacView::announceWinner(char winnerID, string winnerName) {
    char noUseChar;
    cout << "\n*******************************\n";
    cout << "*** " << winnerName << " (" << winnerID << ") is winner! ***\n";
    cout << "*******************************\n\n";
}

void TicTacView::announceNoWinner() {
    char noUseChar;
    cout << "\n ------------------------\n";
    cout << " Tie! No one is winner!\n";
    cout << " ------------------------\n";
}
