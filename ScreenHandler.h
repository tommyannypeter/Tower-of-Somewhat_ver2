#ifndef SCREENHANDLER_H
#define SCREENHANDLER_H

enum Menu {
    START,
    SCORE,
    EXIT,
    NUM_MENU
};

void setDefaultColor();
void setFrameColor();
void setTitleColor();
void setChosenIndexColor();
void setUnchosenIndexColor();

void printChoiceSymbol();

void printTitle();
void printMenu(int cursor);
void printHome(int cursor);

void cursorController();

#endif
