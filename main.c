/**
 * @file main.c
 * @author Victor R. Russo
 * @brief Esse programa é um gerador de imagens pgm a partir de comandos de texto - mais detalhes ver o pdf no diretório
 * @version 0.1
 * @date 2020-05-05
 * 
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "geometrical_utilities.h"
#include "image_handler.h"
#include "constants.h"


int main(){
    char command[C_MAX];
    char name[N_MAX];
    int width,heigth,color,radius;
    Coordinate c1,c2;
    Image * image = NULL;
    do{
        scanf(" %s",command);
        
        if( strcmp(command,"CREATE") == 0  ){
            scanf(" %d %d",&width,&heigth);
            image = image_handler_create(width,heigth);
        }

        if( strcmp(command,"EXPORT") == 0  ){
            scanf(" %s",name);
            image_handler_export(image,name);
            image_handler_free_img(&image);
        }

        if( strcmp(command,"LINE") == 0  ){
            scanf(" %d %d %d %d %d", &c1.x,&c1.y,&c2.x,&c2.y,&color);
            image_handler_draw_line(image,c1,c2,color);
        }

        if( strcmp(command,"CIRCLE") == 0  ){
            scanf(" %d %d %d %d", &c1.x,&c1.y,&radius,&color);
            image_handler_draw_circle(image,c1,radius,color);
        }
        
        if( strcmp(command,"DISK") == 0  ){
            scanf(" %d %d %d %d", &c1.x,&c1.y,&radius,&color);
            image_handler_draw_disk(image,c1,radius,color);
        }

        if( strcmp(command,"RECT") == 0  ){
            scanf(" %d %d %d %d %d", &c1.x,&c1.y,&width,&heigth,&color);
            image_handler_draw_rect(image,c1,width,heigth,color);
        }

    }while( strcmp(command,"EXPORT") != 0);
}