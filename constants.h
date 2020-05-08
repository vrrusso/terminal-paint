/**
 * @file constants.h
 * @author Victor Russo
 * @brief Constantes do projeto terminal_paint 
 * 
 * @version 0.1
 * @date 2020-05-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CONSTANTS_H

#define CONSTANTS_H

//tamanho maximo de um comando
#define C_MAX 20

//tamanho maximo do nome de um arquivo
#define N_MAX 100

//magic number a ser salvo no cabeçalho pgm
#define MAGIC_NUMBER "P2"

/**
 * @brief minimum parameter determina a precisão da discretização, quanto maior a imagem menor deve ser seu valor
 * 
 */
#define MINIMUM_PARAMETER 0.0001

//menor parametro e tamanho do salto no círculo
#define CIRCLE_PARAMETER 0.001

// pi 
#define PI 3.14159265


//maior parametro pro circulo
#define MAX_CIRCLE_PARAMETER 2*PI

//maior parametro pra reta
#define MAX_PARAMETER 1


/**
 * @brief os abaixos são intuitivos
 * 
 */

#define NUMBER_OF_CIRCLE_COORDINATES (int)(MAX_CIRCLE_PARAMETER/CIRCLE_PARAMETER)

#define NUMBER_OF_LINE_COORDINATES (int)(MAX_PARAMETER/MINIMUM_PARAMETER)

#define NUMBER_OF_RECT_COORDINATES 4*NUMBER_OF_LINE_COORDINATES

#endif