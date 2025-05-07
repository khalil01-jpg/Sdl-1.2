#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#define FRAME_TIME 16 
#define NUMM_FRAMES 31

int main(int argc, char* argv[])
{
int continuer=1;
SDL_Surface *screen=NULL;
enigme e;
SDL_Surface *img; 
enigme imgsecond;
char nomfichier[]="enigme.txt";
int choix,run,r=-1,aff=0;
SDL_Surface *Vrai, *Faux;
SDL_Rect positionV, positionF;
Uint32 frame_count = 0;
   Uint32 game_start_time = 0;
    Uint32 frame_start_time = 0;
    Uint32 start_time = 0;
    float elapsed_time = 0.0;
    Uint32 elapsed_frames = 0;
    TTF_Font* font = NULL;
    int test2=0;

TTF_Init();

   screen=SDL_SetVideoMode(1100, 733, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);  
   SDL_WM_SetCaption("Enigme", NULL);

genererEnigme(&e,nomfichier);

init_affichage(&e);
initialiser_image2(&imgsecond);

   struct Animation myAnimation;
    if (!init_animation(&myAnimation)) {
        printf("Failed to initialize animation.\n");
        SDL_Quit();
        return 1;
    }
      myAnimation.pos.x = 930;
    myAnimation.pos.y = 10;

 HeartsSystem hearts;
    init_hearts(&hearts);

while(continuer)
{
     Uint32 start_time = SDL_GetTicks();

    elapsed_time = (start_time - game_start_time) / 1000.0;


   afficherback1(e,screen);
  
        affichertempsen(elapsed_time, screen);
    afficherEnigme(e, screen);
        draw_hearts(&hearts, screen);

        afficher_animation(&myAnimation, screen);
 
  if (test2==1)
  {

             afficher_image2(screen,imgsecond);

             			
  }
 if (aff == 4)
{
continuer=0;
}
  
        if (aff == 1 || aff == 2 || aff == 3) {
            update_hearts(&hearts, r);
            
            // Check for game over
            if (hearts.remaining_lives <= 0) {
                draw_hearts(&hearts, screen);  // Show game over screen
                rotozoom2(screen);
                SDL_Flip(screen);
                SDL_Delay(3000);
                continuer = 0;
                break;
            }
            
            SDL_Delay(2000);
            
            // Reset for next question only if not game over
		if (r==1)
{
            if (continuer) {
                rotozoom(screen);
                choix = 0;
                aff = 0;
                r = -1;
                reset_animation(&myAnimation);
                game_start_time = SDL_GetTicks();
                genererEnigme(&e, nomfichier);
                init_affichage(&e);
            }
}
		else if (r==0)
{
            if (continuer) {
                choix = 0;
                aff = 0;
                r = -1;
                reset_animation(&myAnimation);
                game_start_time = SDL_GetTicks();
                genererEnigme(&e, nomfichier);
                init_affichage(&e);
            }
}
        }
        

   SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
	   case SDL_QUIT:
		continuer=0;
	    break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
   
	  		 case SDLK_a:

                    	   choix = 1;

                         break;

               		 case SDLK_b:

                           choix = 2;

                  	  break;
               		 case SDLK_c:

                  	   choix =3;

                  	  break;
}
		
	    break; 
	      case SDL_MOUSEBUTTONUP: 
if (event.button.button==SDL_BUTTON_LEFT &&(event.motion.y<=490 && event.motion.y>=368
                                                   && event.motion.x<=520 && event.motion.x>=292))
            {
	choix = 1;
            
            }			 
    if (event.button.button==SDL_BUTTON_LEFT &&(event.motion.y<=495 && event.motion.y>=373
          					     && event.motion.x<=820 && event.motion.x>=592))
            {
	choix = 2;
            
            }	
    if (event.button.button==SDL_BUTTON_LEFT &&(event.motion.y<=633 && event.motion.y>=503
          					     && event.motion.x<=669 && event.motion.x>=427))
            {
	choix = 3;
            
            }	
 	break; 
 
 	}
  	 if (choix==1)
		{	
			r=resultat(choix,&e);
			
			aff=1;
		}
		if (choix==2)
		{
		r=resultat(choix,&e);
			aff=2;
		}
		if (choix==3)
		{
		r=resultat(choix,&e);
			aff=3;
		}
	
	   affichresultat(Vrai,Faux,positionV,positionF,screen,choix,e,r);
	   
   SDL_Flip(screen);
  
}

         SDL_Flip(screen);
         if (elapsed_time >= 30.0) { 
test2=1;
               SDL_Delay(3000);
aff=4;
               //SDL_Delay(2000);
		//continuer=0;
            }
Uint32 elapsed_frames = SDL_GetTicks() - frame_start_time;
    if (elapsed_frames < FRAME_TIME) {
        SDL_Delay(FRAME_TIME - elapsed_frames);
    }
    frame_start_time = SDL_GetTicks();
}
TTF_Quit;
liberer_animation(&myAnimation);
return EXIT_SUCCESS;
}


