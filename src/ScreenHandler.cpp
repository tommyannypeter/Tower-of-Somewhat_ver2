#include "ScreenHandler.h"
#include "Rank.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

void setDefaultColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void setFrameColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
}
void setTitleColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 118);
}
void setChosenIndexColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 236);
}
void setUnchosenIndexColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 73);
}

void printChoiceSymbol() {
    setDefaultColor();
    std::cout << "[[";
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
    std::cout << "      ";
    setTitleColor();
    std::cout << "Tower of Somewhat";
    setDefaultColor();
    std::cout << "      ";
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

void printMenu(int cursor) {
    for (int index = 0; index < NUM_MENU; index++) {
        setFrameColor();
        std::cout << "ww";
        setDefaultColor();
        std::cout << "         ";
        if (cursor == index) printChoiceSymbol();
        else std::cout << "  ";
        setUnchosenIndexColor();
        switch (index) {
            case START:
                std::cout << "Start";
                break;
            case RANK:
                std::cout << "Rank ";
                break;
            case EXIT:
                std::cout << "Exit ";
                break;
            default:
                std::cout << "Error in printMenu() of ScreenHandler.cpp";
                break;
        }
        setDefaultColor();
        std::cout << "             ";
        setFrameColor();
        printf("ww\n");
    }

    // the bottom of the frame
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
   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // What is this? lol
}

void printHome(int cursor) {
    system("cls");
    printTitle();
    printMenu(cursor);
}

void cursorController() {
    int enter{0};
    int cursor{0};
    printHome(cursor);
    while(1){
        if(kbhit() != 0) {
            enter = getch();
            // Cheating code for the developers
            // if(enter == 49)
            //     stage1();
            // if(enter == 50)
            //     stage2();
            // if(enter == 51)
            //     stage3();
            // if(enter == 52)
            //     stage4();
            // if(enter == 53)
            //     stage5();
            // if(enter == 54)
            //     stage6();
            if(enter == 224) {
				enter = getch();
                // up
				if(enter == 72) {
                    if(cursor != 0) {
                	    cursor--;
                    	printHome(cursor);
                	}
                }
                // down
				if(enter == 80) {
                    if(cursor < (NUM_MENU - 1)) {
            	        cursor++;
                	    printHome(cursor);
            		}
				}
            }
            if(enter == 13) {
                // mark[0][0] = 1;		// press enter
                if(cursor == 0) break;
                if(cursor == 1) {
                	rank();
                	printHome(cursor);
                }
                if(cursor == 2)
                	exit(1);
            }
        }
    }
}
