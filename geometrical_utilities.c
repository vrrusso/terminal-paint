#include "geometrical_utilities.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "constants.h"


/**
 * @brief Essa função constrói e retorna uma linha de c1 até c2
 *         Para descobrir essa linha a função se baseia na parametrização da reta:
 *          R(t) = c1 + t*(c2-c1) com 0<t<1
 *         Assim a precisão e a velocidade da execução depende do número de parâmetros, tal valor pode ser alterado em constants.h
 * 
 * 
 * @param c1 uma extremidade da linha
 * @param c2 outra extremidade da linha
 * @return Coordinate* um array de Coordinate de tamanho NUMBER_OF_LINE_COORDINATES representando a reta
 */
Coordinate * geometrical_utilities_line(Coordinate c1,Coordinate c2){
    Coordinate * line = (Coordinate * )malloc(sizeof(Coordinate)*NUMBER_OF_LINE_COORDINATES);
    double parameter = MINIMUM_PARAMETER;
    for(int i=0;i<NUMBER_OF_LINE_COORDINATES;i++){
        set_coordinate( &(line[i]), (int) (c1.x +parameter*(c2.x-c1.x)),(int) (c1.y +parameter*(c2.y-c1.y)) );
        parameter += MINIMUM_PARAMETER;
    }
    return line;
}






/**
 * @brief constrói e retorna um retângulo preenchido se utilizando da geometrical_utilities_line, varre a área do retângulo
 * 
 * @param center centro
 * @param width largura
 * @param heigth altura
 * @return Coordinate* um array de Coordinate de tamanho NUMBER_OF_LINE_COORDINATES*heigth representando o retângulo
 */
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





 /**
  * @brief controi um circulo de raio radius centrado em center
  *         para tanto usa a parametrização do círculo 
  *         C(t) = (center.x+radius*seno(t),center.y+radius*cos(t)) 0<t<2*pi
  * 
  * @param center centro do círculo
  * @param radius raio 
  * @return Coordinate*  um array de Coordinate de tamanho NUMBER_OF_CIRCLE_COORDINATES*heigth representando o círculo
  */
Coordinate * geometrical_utilities_circle(Coordinate center,int radius){
    Coordinate * circle = (Coordinate*)malloc(sizeof(Coordinate)*NUMBER_OF_CIRCLE_COORDINATES);
    double parameter = CIRCLE_PARAMETER;
    for(int i = 0 ;i<NUMBER_OF_CIRCLE_COORDINATES;i++){
        set_coordinate(&circle[i],center.x+(int)(radius*sin(parameter)),center.y+(int)(radius*cos(parameter)));
        parameter+=CIRCLE_PARAMETER;
    }
    return circle;
}

/**
 * @brief Seta a coordenada c a partir de um par de inteiros x e y
 * 
 * @param c coordenada a ser setada
 * 
 * @param x 
 * @param y 
 */
void set_coordinate(Coordinate * c, int x, int y){
        c->x = x;
        c->y = y;
}


/**
 * @brief seta a coordenada c1 a partir de c2
 * 
 * @param c1 
 * @param c2 
 */
void coordinate_atribution(Coordinate   * c1, Coordinate * c2){
    if( c1 != NULL && c2 !=NULL  ){
        c1->x = c2->x;
        c1->y = c2->y;
    }
}