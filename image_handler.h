
/**
 * @brief Esse módulo é reponsável por manipular a estrutura da imagem, com seus a intensidade de cada pixel, 
 * além de salva-la em disco
 * 
 */


#ifndef IMAGE_H

#define IMAGE_H
#include "geometrical_utilities.h"
#include "constants.h"
typedef struct image_ Image;

/**
 * @brief Cria uma estrutura para manipular a imagem com width por heigth de tamanho
 * 
 * @param width largura da imagem
 * @param heigth altura da imagem
 * @return Image* ponteiro para a estrutura imagem
 */
Image * image_handler_create(int width,int heigth);

/**
 * @brief responsável por gravar a imagem em disco no formato pgm
 * 
 * @param img imagem a ser gravada, a estrutura deve estar inicializada
 * @param name o nome do arquivo
 */
void image_handler_export(Image * img, char * name);

/**
 * @brief desenha uma linha de c1 até c2 em img de cor color
 * 
 * @param img imagem
 * @param c1  ponto 1
 * @param c2 ponto 2
 * @param color cor que será desenhada
 */
void image_handler_draw_line(Image * img, Coordinate c1,Coordinate c2,int color);

/**
 * @brief libera o espaço alocado para a estrutura imagem
 */
void image_handler_free_img(Image ** img);

#endif