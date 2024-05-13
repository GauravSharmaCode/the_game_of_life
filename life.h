#ifndef LIFE_H
#define LIFE_H

#define MAXROW 20  // maximum row range
#define MAXCOL 60  // maximum column range

typedef enum { DEAD, ALIVE } State;

typedef State Grid[MAXROW + 2][MAXCOL + 2];

void CopyMap(Grid map, Grid newmap);
int UserSaysYes(void);
void Initialize(Grid map);
int NeighbourCount(Grid map, int row, int column);
void WriteMap(Grid map);

#endif /* LIFE_H */