/**
 * \file logic.c
 * \brief 
 * \author Starykova Iryna
 * \version 0.1
 * \date 03 mai 2023
*/

#include "logic.h"
#include <stdio.h>
#include <stdlib.h>

int vy = INITIAL_SPEED;
int num = 6;
void update_data(world_t *world){
    //automatic wall move 
    if(world->finishline.y != SCREEN_HEIGHT-2*SHIP_SIZE){ //conditional to stop finishline before spaceship
        
        for(int i = 0; i < num; i++){
            handle_sprites_collision(&world->spaceship, &world->wall[i], world);
        }
        world->finishline.y += vy;
        for(int i = 0; i < num; i++){
            world->wall[i].y += vy; 
        }
    }
    else{
        world->finishline.y == SCREEN_HEIGHT-2*SHIP_SIZE;
        pause(200);
        world->gameover = 1;
    }
}
    

void handle_events(SDL_Event *event,world_t* world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1;
        }
       
         //si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.sym == SDLK_RIGHT && world->spaceship.x < SCREEN_WIDTH - SHIP_SIZE/2){
                world->spaceship.x += MOVING_STEP;       
            }
    
            if(event->key.keysym.sym == SDLK_LEFT && world->spaceship.x > 0 + SHIP_SIZE/2 ){
                world->spaceship.x -= MOVING_STEP;
            }
        
            //all move none automaticly
            //wall going dowm
            if(event->key.keysym.sym == SDLK_DOWN){
                vy += 3;
                world->finishline.y += vy; 
                for(int i = 0; i < num; i++){
                    world->wall[i].y += vy;
                }
            }
            //wall going up
            if(event->key.keysym.sym == SDLK_UP){
                vy = -2;
                world->finishline.y -= vy;
                for(int i = 0; i < num; i++){
                    world->wall[i].y -= vy;
                }
            }
        } 
    }
}


int is_game_over(world_t *world){
    return world->gameover;
}

//put values from function to struct sprite
void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h; 
}

//formul with making rectangle collision with 2 objects
int sprites_collide(sprite_t *sp1, sprite_t *sp2){
    if(abs(sp1->x - sp2->x) <= (sp1->w + sp2->w)/2 && abs(sp1->y - sp2->y) <= (sp1->h + sp2->h)/2){
        return 1;
    }
    return 0;   
}

//stoping wall when objects have collision and gameover in 2 sec
void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world){
    int make_desapear = 0;
    if(sprites_collide(sp1,sp2) == 1){
        world->spaceship.y = -20; 
        vy = 0;
        world->finishline.y += vy;
        for(int i = 0; i < num; i++){
            world->wall[i].y += vy;
        }
        make_desapear = 1;

        
    }
    if(make_desapear == 1){
        pause(200);
        world->gameover = 1;
    }

}

//put coordinates for walls
void init_walls(world_t* world){
    init_sprite(&world->wall[0], 48, 0, 96, 192);
    init_sprite(&world->wall[1], 252, 0, 96, 192);
    init_sprite(&world->wall[2], 16, -352, 32, 160);
    init_sprite(&world->wall[3], 188, -352, 224, 160);
    init_sprite(&world->wall[4], 48, -672, 96, 192);
    init_sprite(&world->wall[5], 252, -672, 96, 192);
}


