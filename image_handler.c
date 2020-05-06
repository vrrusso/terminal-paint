#include "image_handler.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "geometrical_utilities.h"

struct image_{
    int **pixel_intensities;
    int width;
    int heigth;
};

Image * image_handler_create(int width,int heigth){
    if(width <= 0 || heigth <=0 ){
        printf("FATAL ERROR");
        exit(0);
        return NULL;
    }
    Image * i = (Image *) malloc(sizeof(Image));
    i->pixel_intensities = (int **)malloc(sizeof(int *)*heigth);
    for(int j=0;j<heigth;j++)
        i->pixel_intensities[j] = (int *) calloc(width,sizeof(int));
    i->width = width;
    i->heigth = heigth;
    return i;
}