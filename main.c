#include <stdio.h>
#include "common.h"
#include "life.h"

int main(void) {
    int row, col;
    Grid map, newmap;

    Initialize(map);
    WriteMap(map);

    printf("This is the initial configuration you have chosen.\n"
           "Press <Enter> to continue.\n");
    while (getchar() != '\n');

    do {
        for (row = 1; row <= MAXROW; row++) {
            for (col = 1; col <= MAXCOL; col++) {
                switch (NeighbourCount(map, row, col)) {
                    case 0:
                    case 1:
                        newmap[row][col] = DEAD;
                        break;
                    case 2:
                        newmap[row][col] = map[row][col];
                        break;
                    case 3:
                        newmap[row][col] = ALIVE;
                        break;
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        newmap[row][col] = DEAD;
                        break;
                }
            }
        }
        CopyMap(map, newmap);
        WriteMap(map);

        printf("Do you wish to continue viewing the new generations?");
    } while (UserSaysYes());

    return 0;
}
