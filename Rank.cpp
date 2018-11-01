#include "Rank.h"
#include <windows.h>
#include <conio.h>
#include <cstdio>

int rank() {
    int best[10];
    int i;
    char topname[10][20];
    FILE* rankr;

    rankr = fopen("rank.txt","r");
    for (i = 0; i < 10; i++) {
        fscanf(rankr,"%d", &best[i]);
    }
    for (i = 0; i < 10; i++) {
        fscanf(rankr,"%s", &topname[i]);
    }
    fclose(rankr);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\tSomewhat Ranking\n");
    for ( i = 0; i < 10; i++) {
        printf("%d.\t%s\t\t\t\t\t%d\n", i + 1, topname[i], best[i]);
    }
    printf("\n\n<Press any button to go back the menu>\n\nPress R to reset the ranking");
    if (getch() == 114)
        reset();
    return 0;
}

void reset() {
    FILE* rankw;
    int i;
    rankw = fopen("rank.txt","w");
    for (i = 0; i < 10; i++) {
        fprintf(rankw,"0 ");
    }
    for (i = 0; i < 10; i++){
        fprintf(rankw,"\nAAA");
    }
    fclose(rankw);
}
