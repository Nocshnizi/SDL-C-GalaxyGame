/**
 * \file main.c
 * \brief Programme principal initial du niveau 3
 * \author Starykova Iryna
 * \version 1.0
 * \date 13 mai 2023
 */
#include <stdio.h>
#include "sdl2-light.h"
#include "graphic.h"
#include "logic.h"
#include "sdl-ttf.h"
#include <SDL_ttf.h>

/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ttf();
    init_data(world);
    
    init_textures(*renderer,textures);
    init_sprite(&world->spaceship, SCREEN_WIDTH/2, SCREEN_HEIGHT-SHIP_SIZE - 10, SHIP_SIZE, SHIP_SIZE);
    init_sprite(&world->finishline, 0, -800, 0, 0);
    init_walls(world);
    //TTF_Init();
   
}


/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;
   // SDL_Init(SDL_INIT_EVERYTHING);
    //TTF_Init();
    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    //Uint32 startTime = SDL_GetTicks();

    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini


        //gestion des évènements
        handle_events(&event,&world);
        
        //mise à jour des données liée à la physique du monde
        update_data(&world);

        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures);
        //apply_time(renderer, textures.font);
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    
    return 0;
}
