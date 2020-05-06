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

#define C_MAX 20
#define N_MAX 100

int main(){
    char command[C_MAX];
    Image * image;
    do{
        scanf(" %s",command);
        
        if( strcmp(command,"CREATE") == 0  ){
            int width,heigth;
            scanf(" %d %d",&width,&heigth);
            image = image_handler_create(width,heigth);
        }

        if( strcmp(command,"EXPORT") == 0  ){
            char name[N_MAX];
            scanf(" %s",name);
        }

        if( strcmp(command,"LINE") == 0  ){
            Coordinate c1,c2;
            int color;
            scanf(" %d %d %d %d %d", &c1.x,&c1.y,&c2.x,&c2.y,&color);
        }

        if( strcmp(command,"CIRCLE") == 0  ){
            Coordinate center;
            int radius,color;
            scanf(" %d %d %d %d", &center.x,&center.y,&radius,&color);
        }
        
        if( strcmp(command,"DISK") == 0  ){
            Coordinate center;
            int radius,color;
            scanf(" %d %d %d %d", &center.x,&center.y,&radius,&color);
        }

        if( strcmp(command,"RECT") == 0  ){
            Coordinate center;
            int width,heigth,color;
            scanf(" %d %d %d %d %d", &center.x,&center.y,&width,&heigth,&color);
        }

    }while( strcmp(command,"EXPORT") != 0);
}