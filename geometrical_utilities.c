#include "geometrical_utilities.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "constants.h"


Coordinate * geometrical_utilities_line(Coordinate c1,Coordinate c2){
    Coordinate * line = (Coordinate * )malloc(sizeof(Coordinate)*NUMBER_OF_LINE_COORDINATES);
    double parameter = MINIMUM_PARAMETER;
    for(int i=0;i<NUMBER_OF_LINE_COORDINATES;i++){
        set_coordinate( &(line[i]), (int) (c1.x +parameter*(c2.x-c1.x)),(int) (c1.y +parameter*(c2.y-c1.y)) );
        parameter += MINIMUM_PARAMETER;
    }
    return line;
}

Coordinate * geometrical_utilities_rect(Coordinate center,int width,int heigth){
    Coordinate * rect = (Coordinate *) malloc(sizeof(Coordinate)*NUMBER_OF_LINE_COORDINATES*heigth);
    int x_offset = (int)(width/2);
    int y_offset = (int)(heigth/2);

    Coordinate p1,p2;
    set_coordinate(&p1,center.x-x_offset,center.y-y_offset);
    set_coordinate(&p2,center.x+x_offset,center.y-y_offset);
    Coordinate * auxiliar_line;

    int j =0;
    for(int i=0;i<heigth;i++){
        auxiliar_line = geometrical_utilities_line(p1,p2);

        for(int k=0;k<NUMBER_OF_LINE_COORDINATES;k++){
            coordinate_atribution(&rect[j],&auxiliar_line[k]);
            j++;
        }
        p1.y++;
        p2.y++;
        free(auxiliar_line);
    }
    



    return rect;

}

Coordinate * geometrical_utilities_circle(Coordinate center,int radius){
    Coordinate * circle = (Coordinate*)malloc(sizeof(Coordinate)*NUMBER_OF_CIRCLE_COORDINATES);
    double parameter = CIRCLE_PARAMETER;
    for(int i = 0 ;i<NUMBER_OF_CIRCLE_COORDINATES;i++){
        set_coordinate(&circle[i],center.x+(int)(radius*sin(parameter)),center.y+(int)(radius*cos(parameter)));
        parameter+=CIRCLE_PARAMETER;
    }
    return circle;
}

void set_coordinate(Coordinate * c, int x, int y){
        c->x = x;
        c->y = y;
}

void coordinate_atribution(Coordinate   * c1, Coordinate * c2){
    if( c1 != NULL && c2 !=NULL  ){
        c1->x = c2->x;
        c1->y = c2->y;
    }
}