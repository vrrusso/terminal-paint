#include "geometrical_utilities.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "constants.h"


Coordinate * geometrical_utilities_line(Coordinate c1,Coordinate c2){
    Coordinate * line = (Coordinate * )malloc(sizeof(Coordinate)*NUMBER_OF_COORDINATES);
    double parameter = MINIMUM_PARAMETER;
    for(int i=0;i<NUMBER_OF_COORDINATES;i++){
        line[i].x = (int) (c1.x +parameter*(c2.x-c1.x));
        line[i].y = (int) (c1.y +parameter*(c2.y-c1.y));
        parameter += MINIMUM_PARAMETER;
    }
    return line;
}