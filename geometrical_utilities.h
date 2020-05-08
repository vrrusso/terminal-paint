/**
 * @file geometrical_utilities.h
 * @author Victor Russo
 * 
 * @brief Esse módulo é responsável pela manipulação de objetos geométricos 
 * 
 * @version 0.1
 * @date 2020-05-08
 * 
 * 
 */




#ifndef GEOMETRICAL_H
#define GEOMETRICAL_H
#include "constants.h"

/**
 * @brief representa uma coordenada em forma de par ordenado
 * 
 */
typedef struct coordinate_{
    int x;
    int y;
}Coordinate;


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
Coordinate * geometrical_utilities_line(Coordinate c1,Coordinate c2);




/**
 * @brief constrói e retorna um retângulo preenchido se utilizando da geometrical_utilities_line, varre a área do retângulo
 * 
 * @param center centro
 * @param width largura
 * @param heigth altura
 * @return Coordinate* um array de Coordinate de tamanho NUMBER_OF_LINE_COORDINATES*heigth representando o retângulo
 */
Coordinate * geometrical_utilities_rect(Coordinate center,int width,int heigth);



 /**
  * @brief controi um circulo de raio radius centrado em center
  *         para tanto usa a parametrização do círculo 
  *         C(t) = (center.x+radius*seno(t),center.y+radius*cos(t)) 0<t<2*pi
  * 
  * @param center centro do círculo
  * @param radius raio 
  * @return Coordinate*  um array de Coordinate de tamanho NUMBER_OF_CIRCLE_COORDINATES*heigth representando o círculo
  */
Coordinate * geometrical_utilities_circle(Coordinate center,int radius);


/**
 * @brief Seta a coordenada c a partir de um par de inteiros x e y
 * 
 * @param c coordenada a ser setada
 * 
 * @param x 
 * @param y 
 */
void set_coordinate(Coordinate * c, int x, int y);


/**
 * @brief seta a coordenada c1 a partir de c2
 * 
 * @param c1 
 * @param c2 
 */
void coordinate_atribution(Coordinate   * c1, Coordinate * c2);






#endif