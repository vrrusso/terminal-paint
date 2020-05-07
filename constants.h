#ifndef CONSTANTS_H

#define CONSTANTS_H

#define C_MAX 20
#define N_MAX 100

#define MAGIC_NUMBER "P2"

/**
 * @brief minimum parameter determina a precisão da discretização, quanto maior a imagem menor deve ser seu valor
 * 
 */
#define MINIMUM_PARAMETER 0.0001

#define CIRCLE_PARAMETER 0.001

#define PI 3.14159265

#define MAX_CIRCLE_PARAMETER 2*PI

#define MAX_PARAMETER 1

#define NUMBER_OF_CIRCLE_COORDINATES (int)(MAX_CIRCLE_PARAMETER/CIRCLE_PARAMETER)

#define NUMBER_OF_LINE_COORDINATES (int)(MAX_PARAMETER/MINIMUM_PARAMETER)

#define NUMBER_OF_RECT_COORDINATES 4*NUMBER_OF_LINE_COORDINATES

#endif