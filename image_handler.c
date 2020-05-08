#include "image_handler.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "constants.h"

#define MAGIC_NUMBER "P2"

/**
 * @brief a estrutura representando a imagem com seus pixels e a largura e altura
 * 
 */
struct image_{
    int **pixel_intensities;
    int width;
    int heigth;
};

/**
 * @brief seta o valor de um pixel
 * 
 * @param img imagem
 * @param position posição
 * @param color cor
 */
void set_pixel(Image * img,Coordinate position ,int color){
    if( img!=NULL  && position.x>= 0&&position.x<img->width  &&  position.y>= 0&&position.y<img->heigth ){
        img->pixel_intensities[position.y][position.x] = color;
    }
}


/**
 * @brief Cria uma estrutura para manipular a imagem com width por heigth de tamanho
 * 
 * @param width largura da imagem
 * @param heigth altura da imagem
 * @return Image* ponteiro para a estrutura imagem
 */
Image * image_handler_create(int width,int heigth){
    if(width <= 0 || heigth <=0 ){
        printf("FATAL ERROR-Tamanho da imagem inválido!\n");
        return NULL;
    }
    Image * image = (Image *) malloc(sizeof(Image));
    image->width = width;
    image->heigth = heigth;
    Coordinate position;position.x=0;position.y=0;
    image->pixel_intensities = (int **)malloc(sizeof(int *)*heigth);
    for(int i=0;i<heigth;i++){
        image->pixel_intensities[i] = (int *) malloc(width*sizeof(int));
        for(int j = 0;j<width;j++){
            position.x = j;
            position.y = i;
            set_pixel(image,position,255);
        }
    }
    return image;
}

/**
 * @brief responsável por gravar a imagem em disco no formato pgm
 * 
 * @param img imagem a ser gravada, a estrutura deve estar inicializada
 * @param name o nome do arquivo
 */
void image_handler_export(Image * img, char * name){
    if(img == NULL){
        printf("FATAL ERROR - The image is not defined\n");
        return;
    }
    FILE * fp = fopen(name,"w");
    if(fp == NULL){
        printf("FATAL ERROR-Problema ao abrir o arquivo\n");
        return;
    }
    fprintf(fp,"%s\n",MAGIC_NUMBER);
    fprintf(fp,"%d %d\n%d\n",img->width,img->heigth,255);
    for(int i=0;i< img->heigth;i++){
        for(int j=0;j<img->width;j++){
            fprintf(fp,"%d ",img->pixel_intensities[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}


/**
 * @brief libera o espaço alocado para a estrutura imagem
 */
void image_handler_free_img(Image ** img){
    if((*img)!=NULL){
        for(int i=0;i<(*img)->heigth;i++)
            free((*img)->pixel_intensities[i]);
        free((*img)->pixel_intensities);
        free(*img);
        img=NULL;
    }
}

/**
 * @brief desenha uma linha de c1 até c2 em img de cor color
 * 
 * @param img imagem
 * @param c1  ponto 1
 * @param c2 ponto 2
 * @param color cor que será desenhada
 */
void image_handler_draw_line(Image * img, Coordinate c1,Coordinate c2,int color){
    if(img != NULL){
        Coordinate * line = geometrical_utilities_line(c1,c2);
        for(int i = 0;i<NUMBER_OF_LINE_COORDINATES;i++){
            set_pixel(img,line[i],color);
        }
        free(line);
    }
}


/**
 * @brief desenha um retangulo centrado em center de com largura width e altura heigth com cor color
 * 
 * @param img  imagem onde sera desenhado
 * @param center centro
 * @param width largura
 * @param heigth altura
 * @par
 */
void image_handler_draw_rect(Image * img, Coordinate center,int width, int heigth,int color){
    if(img != NULL){
        Coordinate * rect = geometrical_utilities_rect(center,width,heigth);
        for(int i = 0;i<NUMBER_OF_LINE_COORDINATES*heigth;i++){
            set_pixel(img,rect[i],color);
        }
        free(rect);
    }
}


/**
 * @brief Desenha um círculo centrado em center de raio radius e cor color
 * 
 * @param img a imagem
 * @param center centro
 * @param radius raio
 * @param color cor
 */
void image_handler_draw_circle(Image * img,Coordinate center,int radius,int color){
    if(img!=NULL){
        Coordinate * circle = geometrical_utilities_circle(center,radius);
        for(int i = 0;i<NUMBER_OF_CIRCLE_COORDINATES;i++){
            set_pixel(img,circle[i],color);
        }
        free(circle);
    }
}

/**
 * @brief Desenha um disco centrado em center de raio radius e cor color
 *          Para tanto desenha varios circulos cocentricos e de raio progressivamente maior
 * @param img a imagem
 * @param center o centro
 * @param radius raio
 * @param color cor
 */
void image_handler_draw_disk(Image * img,Coordinate center,int radius,int color){
    if(img != NULL){
        for(int i=0;i<=radius;i++){
            image_handler_draw_circle(img,center,i,color);
        }
    }
}