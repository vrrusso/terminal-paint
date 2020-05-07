




#ifndef GEOMETRICAL_H
#define GEOMETRICAL_H
#include "constants.h"


typedef struct coordinate_{
    int x;
    int y;
}Coordinate;



Coordinate * geometrical_utilities_line(Coordinate c1,Coordinate c2);

Coordinate * geometrical_utilities_rect(Coordinate center,int width,int heigth);

void set_coordinate(Coordinate * c, int x, int y);

void coordinate_atribution(Coordinate   * c1, Coordinate * c2);





#endif