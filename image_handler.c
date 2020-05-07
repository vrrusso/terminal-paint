#include "image_handler.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "constants.h"

#define MAGIC_NUMBER "P2"

struct image_{
    int **pixel_intensities;
    int width;
    int heigth;
};

void set_pixel(Image * img,Coordinate position ,int color){
    if( img!=NULL  && position.x>= 0&&position.x<img->width  &&  position.y>= 0&&position.y<img->heigth ){
        img->pixel_intensities[position.y][position.x] = color;
    }
}

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

void image_handler_free_img(Image ** img){
    if((*img)!=NULL){
        for(int i=0;i<(*img)->heigth;i++)
            free((*img)->pixel_intensities[i]);
        free((*img)->pixel_intensities);
        free(*img);
        img=NULL;
    }
}

void image_handler_draw_line(Image * img, Coordinate c1,Coordinate c2,int color){
    if(img != NULL){
        Coordinate * line = geometrical_utilities_line(c1,c2);
        for(int i = 0;i<NUMBER_OF_LINE_COORDINATES;i++){
            set_pixel(img,line[i],color);
        }
        free(line);
    }
}


void image_handler_draw_rect(Image * img, Coordinate center,int width, int heigth,int color){
    if(img != NULL){
        Coordinate * rect = geometrical_utilities_rect(center,width,heigth);
        for(int i = 0;i<NUMBER_OF_LINE_COORDINATES*heigth;i++){
            set_pixel(img,rect[i],color);
        }
        free(rect);
    }
}