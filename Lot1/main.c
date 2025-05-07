//include libs SDL
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

//include .h ...
#include "menu.h"
#include "joueur.h"

int main(){
//init SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 8192) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        exit(1); //tnajem ta3mel nafes el verification lel kol
    }

    TTF_Init();

//init game

    SDL_Surface *ecran;
    ecran = SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

    int quitter = 0;
    SDL_Event event;

    int indice_ecran=0; //menu Principal

    Menu menu;
    init_menu(&menu);
    
    Joueur* joueurs = NULL;
    int nb_joueur = 1;


    Uint32 dt,t_prev;

    SDL_Surface *bg_joueur;
    bg_joueur = IMG_Load("images/joueur/bg.png");

    while(quitter == 0){
        t_prev = SDL_GetTicks();
        switch (indice_ecran)
        {
        case 0:
                //code Menu Principal ala 3 partie (1Afficher 2gestion event 3mise a jour)
                //afficher:
                afficher_menu(menu,ecran);
                SDL_Flip(ecran);

                //gestion event:
                gerer_event_menu(&menu,event,&quitter,&indice_ecran);
                

                //mise a jour:
                mise_a_jour_menu(&menu);
            
            break;
        case 1: //sous menu joueur
                afficher_smenu_joueur(menu,ecran);
                SDL_Flip(ecran);

                gerer_event_smenu_joueur(&menu,event,&quitter,&indice_ecran);

                mise_a_jour_smenu_joueur(&menu);

                printf("mode de jeux %d \n",menu.mode_jeux);
            
                if(indice_ecran == 10){
                    if(menu.mode_jeux == 0){
                        nb_joueur = 1;
                    }else{
                        nb_joueur = 2;
                    }

                    int avatar[2];
                    if(menu.selecter_btn_avatar1 == 1){
                        avatar[0] = 1;
                        avatar[1] = 2;
                    }
                    else{
                        avatar[0] = 2;
                        avatar[1] = 1;
                    }
                    int input[2];
                    if(menu.selecter_btn_input1 == 1){
                        input[0] = 1;
                        input[1] = 2;
                        printf("choix d q \n");
                    }
                    else{
                        input[0] = 2;
                        input[1] = 1;
                        printf("choix fleches \n");
                    }

                    joueurs = malloc( nb_joueur * sizeof(Joueur));
                    
                    for(int i=0;i<nb_joueur;i++){
                        init_joueur(&joueurs[i],avatar[i],input[i]);
                    }


                }
            

            break;
        


        case 10:

                //affichage 
                //SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
                SDL_BlitSurface(bg_joueur,NULL,ecran,NULL);

                for(int i=0;i<nb_joueur;i++){
                    afficher_joueur(joueurs[i],ecran);
                }
                SDL_Flip(ecran);

                //gestion d'evenement
                while(SDL_PollEvent(&event)){
                    switch (event.type)
                    {
                    case SDL_QUIT:
                            quitter = 1;
                        break;
                    
                    default:
                        break;
                    }

                    for(int i=0;i<nb_joueur;i++){
                        gerer_event_joueur(&joueurs[i],event);
                    }
                }

                //mise a jour

                for(int i=0;i<nb_joueur;i++){
                    deplacer_joueur(&joueurs[i]);
                    jump_joueur(&joueurs[i]);
                }
                
                for(int i=0;i<nb_joueur;i++){
                    animer_joueur(&joueurs[i]);
                }

                if(dt< 16){
                    SDL_Delay(16-dt);
                    dt=16;
                }

                

            break;

        default:
            break;
        }
    

    dt = SDL_GetTicks() - t_prev;
    }

    
    
    //Liberer memoire (RAM)

    SDL_FreeSurface(ecran);   
    SDL_Quit();

}