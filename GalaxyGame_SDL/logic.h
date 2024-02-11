/**
 * \file logic.h
 * \brief 
 * \author Starykova Iryna
 * \version 0.1
 * \date 3 mai 2023
*/


#ifndef __logic__H__
#define __logic__H__


#include <SDL.h>
#include "define.h"
#include "sdl2-light.h"

struct sprite_s{
    int x;
    int y;
    int h;
    int w;
};
typedef struct sprite_s sprite_t;

struct world_s{
    sprite_t wall[6];
    sprite_t finishline;
    sprite_t spaceship;
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */

};
typedef struct world_s world_t;


/**
 * \brief Type qui correspond aux textures du jeu
*/


void handle_events(SDL_Event *event,world_t* world);
void update_data(world_t *world);
int is_game_over(world_t *world);
void init_sprite(sprite_t *sprite, int x, int y, int w, int h);
int sprites_collide(sprite_t *sp1, sprite_t *sp2);
void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world);
void init_walls(world_t* world);
#endif