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

Image * image_handler_create(int width,int heigth){
    if(width <= 0 || heigth <=0 ){
        printf("FATAL ERROR-Tamanho da imagem inválido!\n");
        return NULL;
    }
    Image * image = (Image *) malloc(sizeof(Image));
    image->pixel_intensities = (int **)malloc(sizeof(int *)*heigth);
    for(int i=0;i<heigth;i++){
        image->pixel_intensities[i] = (int *) malloc(width*sizeof(int));
        for(int j = 0;j<width;j++)
            image->pixel_intensities[i][j] = 255;
    }
    image->width = width;
    image->heigth = heigth;
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
    Coordinate * line = geometrical_utilities_line(c1,c2);
    for(int i = 0;i<NUMBER_OF_COORDINATES;i++){
        if(line[i].x>0&&line[i].x<img->width  &&  line[i].y>0&&line[i].y<img->heigth )
            img->pixel_intensities[line[i].x][line[i].y] = color;
    }
    free(line);
}