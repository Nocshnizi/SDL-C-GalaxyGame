/**
 * \file graphic.h
 * \brief 
 * \author Starykova Iryna
 * \version 0.1
 * \date 3 mai 2023
*/



#ifndef __graphic__H__
#define __graphic__H__

#include <SDL.h>
#include "logic.h"
#include "define.h"
#include "sdl2-light.h"
#include "sdl-ttf.h"

struct textures_s{
    SDL_Texture* meteorite;
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* spaceship;
    SDL_Texture* finish_line;
    TTF_Font* font;
    /* A COMPLETER */
};
typedef struct textures_s textures_t;



void init_data(world_t * world);
void clean_textures(textures_t *textures);
void  init_textures(SDL_Renderer *renderer, textures_t *textures);
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);
void apply_wall(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *wall);
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);
void clean_data(world_t *world);
void apply_walls(SDL_Renderer *renderer, SDL_Texture *texture, world_t* world);
void apply_time(SDL_Renderer *renderer, TTF_Font *font);

#endif