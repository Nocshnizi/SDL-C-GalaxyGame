/**
 * \file graphic.c
 * \brief 
 * \author Starykova Iryna
 * \version 0.1
 * \date 03 mai 2023
*/

#include "graphic.h"
#include <stdio.h>
#include <stdlib.h>



void init_data(world_t * world){
    //on n'est pas à la fin du jeu
    world->gameover = 0;
    
}


void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->spaceship);
    clean_texture(textures->finish_line);
    clean_texture(textures->meteorite);
    clean_font(textures->font);
}

/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
    textures->spaceship = load_image( "ressources/spaceship.bmp",renderer);
    textures->finish_line = load_image("ressources/finish_line.bmp",renderer);
    textures->meteorite = load_image("ressources/meteorite.bmp", renderer);
    textures->font = load_font("ressources/arial.ttf", 14);
}


void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

//drwing sprite
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
    //give coordinates from left top point
    apply_texture(texture, renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
}

//function aplly_wall for drawing wall 
void apply_wall(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *wall){
        //drawing in x
    for(int i = 0; i < (wall->w/METEORITE_SIZE); i++){
        //drawing in y
        for(int j = 0; j < (wall->h/METEORITE_SIZE); j++){
            
            //drawing one by one meteorites from texture`s left top point 
            apply_texture(texture, renderer, (wall->x - wall->w/2)+i*METEORITE_SIZE, (wall->y - wall->h/2)+j*METEORITE_SIZE);
        }
    }
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
     
    //application des textures dans le renderersprite_t
    apply_background(renderer, textures->background);
    
    //drawing spaceship, finishline and meteorite textures 
    apply_sprite(renderer, textures->spaceship, &world->spaceship);
    apply_sprite(renderer, textures->finish_line, &world->finishline);
    apply_walls(renderer, textures->meteorite, world);
    apply_time(renderer, textures->font);
    
    // on met à jour l'écran
    update_screen(renderer);

    
}

void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}



void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}

//drawing several walls with have been given coordinates from logic.c/init_walls
void apply_walls(SDL_Renderer *renderer, SDL_Texture *texture, world_t* world){
    for (size_t i = 0; i < 6; i++){
       apply_wall(renderer, texture, &world->wall[i]); 
    }
}

void apply_time(SDL_Renderer *renderer, TTF_Font *font){
    char *time;
    time  = malloc(4*sizeof(char));
    sprintf(time, "time in game: %d", ((int)(SDL_GetTicks()/1000)));
    apply_text(renderer, 10, 0, 120, 20, time, font);
}


