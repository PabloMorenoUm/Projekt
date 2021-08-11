//
// Created by Pablo Moreno Um on 09.08.21.
//

#include "Board.hpp"
#include <sstream>
using namespace sf;
using namespace std;

Board::Board() {
    for (int j = 0; j < ncols; ++j) {
        // Münzen auf dem Spielfeld mit GUI-Koordinaten relativ zu den Bildschirmmaßen versehen:
        for (int i = 0; i < nrows; ++i) {
            Coin &coin = coins[i][j];
            coin.makeNeutral();
            coin.setRadius(100);
            coin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                             m_WindowSize.getY() * ((float) i + 1.8) / (nrows + 2));
        }
        // Beschriftung unter den Spielfeldmünzen:
        std::stringstream ss;
        ss << j + 1;
        Words &number = numbers[j];
        number.setString(ss.str());
        number.setSize(70);
        number.setPosition(m_WindowSize.getX() * ((float) j + .45) / ncols,
                           m_WindowSize.getY() * 19 / 20);

        // Anzeige "Auswahlmöglichkeit Spalte" über dem Spielfeld:
        Coin &hiddenCoin = hiddenCoins[j];
        hiddenCoin.makeHidden();
        hiddenCoin.setRadius(100);
        hiddenCoin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                               m_WindowSize.getY() * .8 / (nrows + 2));
    }
}

int Board::goRight(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && j < ncols - 1) {
        if (coins[i][j + 1] == coins[i][j]) {
            return goRight(i, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goLeft(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && j > 0) {
        if (coins[i][j - 1] == coins[i][j]) {
            return goLeft(i, j - 1, t + 1);
        }
    }
    return t;
}

int Board::goUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0) {
        if (coins[i - 1][j] == coins[i][j]) {
            return goUp(i - 1, j, t + 1);
        }
    }
    return t;
}

int Board::goDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1) {
        if (coins[i + 1][j] == coins[i][j]) {
            return goDown(i + 1, j, t + 1);
        }
    }
    return t;
}

int Board::goRightUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0 && j < ncols - 1) {
        if (coins[i - 1][j + 1] == coins[i][j]) {
            return goRightUp(i - 1, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goRightDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1 && j < ncols - 1) {
        if (coins[i + 1][j + 1] == coins[i][j]) {
            return goRightDown(i + 1, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goLeftUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0 && j > 0) {
        if (coins[i - 1][j - 1] == coins[i][j]) {
            return goLeftUp(i - 1, j - 1, t + 1);
        }
    }
    return t;
}

int Board::goLeftDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1 && j > 0) {
        if (coins[i + 1][j - 1] == coins[i][j]) {
            return goLeftDown(i + 1, j - 1, t + 1);
        }
    }
    return t;
}

int Board::evaluatePositionWinLoose(const int &coinsInLine, const Coin &coin) {
// get the fill color
    const sf::Color &coinColor = coin.getShape().getFillColor();
    const sf::Color &questColorPlayer = coin.getPlayerColor();
    const sf::Color &questColorOpponent = coin.getOpponentColor();
    const sf::Color &questColorNeutral = coin.getNeutralColor();

    if (coinColor == questColorPlayer){
        if (coinsInLine == 4){
            return BESTEVAL;
        }
    } else if (coinColor == questColorOpponent) {
        if (coinsInLine == 4){ // besser: if winningConstellation
            return WORSTEVAL;
        }
    }
    return 0;
}

int Board::checkBoardWinLoose() {
    int tStart = 1;
    double value {};
    for(int i = 0 ; i < nrows ; ++i) {
        for (int j = 0; j < ncols; ++j) {
            Coin &actualCoin = coins[i][j];
            value = evaluatePositionWinLoose(goRight(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goLeft(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goUp(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goDown(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goRightUp(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goRightDown(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goLeftUp(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goLeftDown(i, j, tStart),actualCoin);
            if (value == WORSTEVAL){
                return value;
            }

            // if no losing configuration is detected, check for winning configuration
            value = evaluatePositionWinLoose(goRight(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goLeft(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goUp(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goDown(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goRightUp(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goRightDown(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goLeftUp(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }

            value = evaluatePositionWinLoose(goLeftDown(i, j, tStart),actualCoin);
            if (value == BESTEVAL){
                return value;
            }
        }
    }
    return 0;
}

double Board::evaluatePosition(const int &coinsInLine, const Coin &coin) {
    // get the fill color
    const sf::Color &coinColor = coin.getShape().getFillColor();
    const sf::Color &questColorPlayer = coin.getPlayerColor();
    const sf::Color &questColorOpponent = coin.getOpponentColor();
    const sf::Color &questColorNeutral = coin.getNeutralColor();

    if (coinColor == questColorPlayer){
        if (coinsInLine == 3){
            return SECONDBESTEVAL;
        } else if (coinsInLine == 2){
            return THIRDBESTEVAL;
        }
    } else if (coinColor == questColorOpponent) {
        if (coinsInLine == 3){
            return SECONDWORSTEVAL;
        } else if (coinsInLine == 2){
            return THIRDWORSTEVAL; // 0.02 on purpose different from 0.01 because negative positions are rated harder
        }
    } else if (coinColor == questColorNeutral) {
        return 0;
    }
}

double Board::evaluateBoard() {
    int tStart = 1;
    double value {};
    for(int i = 0 ; i < nrows ; ++i) {
        for (int j = 0; j < ncols; ++j) {
            Coin &actualCoin = coins[i][j];
            value = value + evaluatePosition(goRight(i, j, tStart),actualCoin) +
                    evaluatePosition(goLeft(i, j, tStart),actualCoin) +
                    evaluatePosition(goUp(i, j, tStart),actualCoin) +
                    evaluatePosition(goDown(i, j, tStart),actualCoin) +
                    evaluatePosition(goRightUp(i, j, tStart),actualCoin) +
                    evaluatePosition(goRightDown(i, j, tStart),actualCoin) +
                    evaluatePosition(goLeftUp(i, j, tStart),actualCoin) +
                    evaluatePosition(goLeftDown(i, j, tStart),actualCoin); // check all lines
        }
    }
    return value;
}

int Board::findBestPosition() {

}

void Board::markColumn(const int &col) {
    // Wie viele neutral gefärbte Münzen sind in der Spalte?
    int countNeutralCoins = 0;
    for (auto &coinsRow : coins) {
        Coin &coin = coinsRow[col];
        countNeutralCoins += (coin == coin.getNeutralColor()) ? 1 : 0;
    }
    /* Falls es keine neutralen Münzen gibt, ist die Spalte voll
     * => Die Spalte soll NICHT markiert werden
     * => Die folgende if-Bedingung soll NICHT aufgerufen werden.
     * Ansonsten soll die Spalte schon markiert werden.
     */
    if (countNeutralCoins) {
        for (auto & hiddenCoin : hiddenCoins) {
            hiddenCoin.makeHidden();
        }
        hiddenCoins[col].makePlayer();
    }
}

void Board::markColumnComputer(const int &col) {
    // Wie viele neutral gefärbte Münzen sind in der Spalte?
    int countNeutralCoins = 0;
    for (auto &coinsRow : coins) {
        Coin &coin = coinsRow[col];
        countNeutralCoins += (coin == coin.getNeutralColor()) ? 1 : 0;
    }
    /* Falls es keine neutralen Münzen gibt, ist die Spalte voll
     * => Die Spalte soll NICHT markiert werden
     * => Die folgende if-Bedingung soll NICHT aufgerufen werden.
     * Ansonsten soll die Spalte schon markiert werden.
     */
    if (countNeutralCoins) {
        for (auto & hiddenCoin : hiddenCoins) {
            hiddenCoin.makeHidden();
        }
        hiddenCoins[col].makeOpponent();
    }
}

void Board::addCoin(const unsigned int &col, const bool &playersTurn) {
    for (int i = nrows - 1; i >= 0; --i) {
        Coin &coin = coins[i][col];
        if (coin == coin.getNeutralColor()) {
            if (playersTurn)
                coin.makePlayer();
            else
                coin.makeOpponent();
            break;
        }
    }
}

void Board::removeCoin(const unsigned int &col) {
    for (auto & coinsRow : coins) {
        Coin &coin = coinsRow[col];
        if (coin != coin.getNeutralColor()) {
            coin.makeNeutral();
            break;
        }
    }
}

void Board::input() {
    if (Keyboard::isKeyPressed(Keyboard::Num1))
        markColumn(0);

    if (Keyboard::isKeyPressed(Keyboard::Num2))
        markColumn(1);

    if (Keyboard::isKeyPressed(Keyboard::Num3))
        markColumn(2);

    if (Keyboard::isKeyPressed(Keyboard::Num4))
        markColumn(3);

    if (Keyboard::isKeyPressed(Keyboard::Num5))
        markColumn(4);

    if (Keyboard::isKeyPressed(Keyboard::Num6))
        markColumn(5);

    if (Keyboard::isKeyPressed(Keyboard::Num7))
        markColumn(6);

    if(Keyboard::isKeyPressed(Keyboard::Enter)){
        // Player wirft Münze ein.
        for (int j = 0; j < ncols; ++j) {
            // Suche nach der markierten Spalte:
            Coin &hiddenCoin = hiddenCoins[j];
            if(hiddenCoin == hiddenCoin.getPlayerColor()) {
                hiddenCoin.makeHidden();
                addCoin(j, true);
                break;
            }
        }

        // Computer's turn
        int c = std::rand()%6; // Hier ist das Problem. Da die Enter-Taste für den rechner vielfach gedrückt wird,
        // wird auch vielfach markCollumnComputer aufgerufen. Hier brauchen wir ein Workaround.
        markColumnComputer(c);
        for (int j = 0; j < ncols; ++j) {
            // Suche nach der markierten Spalte:
            Coin &hiddenCoin = hiddenCoins[j];
            if (hiddenCoin == hiddenCoin.getOpponentColor()) {
                hiddenCoin.makeHidden();
                addCoin(j, false);
                break;
            }
        }
    }
}

void Board::draw(RenderWindow &window) {
    for (int j = 0; j < ncols; ++j) {
        // Spielfeldmünzen in die GUI bringen
        for (auto &coinsRow : coins) {
            window.draw(coinsRow[j].getShape());
        }
        // Spaltenbeschriftung in die GUI bringen
        window.draw(numbers[j].getText());
        // Spaltenmarker in die GUI bringen
        window.draw(hiddenCoins[j].getShape());
    }
}