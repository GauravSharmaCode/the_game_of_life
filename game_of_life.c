#include "life.h"

void CopyMap(Grid map, Grid newmap) {
     int i, j;
    for (i = 0; i < MAXROW + 2; i++) {
        for (j = 0; j < MAXCOL + 2; j++) {
            newmap[i][j] = map[i][j];
        }
    }
}

int UserSaysYes(void) {
    char response;
    printf("\nDo you wish to continue viewing the new generations? (Y/N): ");
    scanf(" %c", &response);
    getchar(); // Consume newline character
    return (response == 'Y' || response == 'y');
}

void Initialize(Grid map) {
    int i, j;
    for (i = 0; i < MAXROW + 2; i++) {
        for (j = 0; j < MAXCOL + 2; j++) {
            map[i][j] = DEAD;
        }
    }
}

int NeighbourCount(Grid map, int row, int column) {
    int count = 0;
    int i, j;

    for (i = row - 1; i <= row + 1; i++) {
        for (j = column - 1; j <= column + 1; j++) {
            if (map[i][j] == ALIVE && !(i == row && j == column)) {
                count++;
            }
        }
    }

    return count;
}

void WriteMap(Grid map) {
     int i, j;
    for (i = 1; i <= MAXROW; i++) {
        for (j = 1; j <= MAXCOL; j++) {
            printf("%c", (map[i][j] == ALIVE) ? '*' : ' ');
        }
        printf("\n");
    }
}
