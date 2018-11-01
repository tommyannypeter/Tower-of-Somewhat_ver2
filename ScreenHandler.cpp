#include "ScreenHandler.h"
#include <iostream>

void setDefaultColor() {
    setConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void setFrameColor() {
    SaetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
}
void setTitleColor() {
    setConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 118);
}
void setChosenIndexColor() {
    setConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 236);
}
void setUnchosenIndexColor() {
    setConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 73);
}

void printChoiceSymbol() {
    setDefaultColor();
    std::cout << "\b\b●";
    setChosenIndexColor();
}

void printTitle() {
    setFrameColor();
    std::cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
    std::cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
    std::cout << "ww";
    setDefaultColor();
    std::cout << "                             ";
    setFrameColor();
    std::cout << "ww\n";
    std::cout << "ww";
    setDefaultColor();
    std::cout << "           ";
    setTitleColor();
    std::cout << "什麼之塔" << '\n';
    setDefaultColor();
    std::cout << "          ";
    setFrameColor();
    std::cout << "ww\n";
    std::cout << "ww";
    setDefaultColor();
    std::cout << "                             ";
    setFrameColor();
    std::cout << "ww\n";
    std::cout << "ww";
    setDefaultColor();
    std::cout << "                             ";
    setFrameColor();
    std::cout << "ww\n";
}

void printMenu() {
    int cursor{0};

    for (int index = 0; index < NUM_MENU; index++) {
        setFrameColor();
        std::cout << "ww";
        setDefaultColor();
        std::cout << "           ";
        setUnchosenIndexColor();
        if (cursor == index) printChoiceSymbol();
        switch (index) {
            case START:
                std::cout << "開始遊戲";
                break;
            case SCORE:
                std::cout << "最佳排行";
                break;
            case EXIT:
                std::cout << "離開遊戲";
                break;
            default:
                std::cout << "Error in printMenu() of ScreenHandler.cpp";
                break;
        }
        setDefaultColor();
        std::cout << "          ";
        setFrameColor();
        printf("ww\n");
    }

	printf("ww");
    setDefaultColor();
    printf("                             ");
    setFrameColor();
    printf("ww\n");
    printf("ww");
    setDefaultColor();
    printf("                             ");
    setFrameColor();
    printf("ww\n");
	printf("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
   	printf("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n");
   	setConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // What is this? lol
}

void printHome() {
    system("cls");
    printTitle();
    printMenu();
}
