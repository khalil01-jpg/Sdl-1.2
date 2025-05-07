#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_rotozoom.h>
#include <time.h>
#define NUMM_FRAMES 31

/**************************GENERER*******************************/
void shuffle(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
void genererEnigme(enigme *e, char *nomfichier) {
    static int shuffled_lines[10] = {1, 6, 11, 16, 21, 26, 31, 36, 41, 46};
    static int current_index = 0;
    static int initialized = 0;

    if (!initialized) {
        srand(time(NULL));
        shuffle(shuffled_lines, 10);
        initialized = 1;
    }

    // Reset and reshuffle when all 10 have been used
    if (current_index >= 10) {
        shuffle(shuffled_lines, 10);
        current_index = 0;
    }

    int num = shuffled_lines[current_index];
    current_index++;

    printf("Question from line: %d\n", num);

    FILE *f = fopen(nomfichier, "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

    int i = 0, carac;
    // Skip lines to reach the desired question
    do {
        if (num != 1) {
            do {
                carac = fgetc(f);
            } while (carac != '\n');
            i++;
        }
    } while ((fgetc(f) != EOF) && (i != num - 1));

    char texte[255];
    fgets(texte, 255, f);
    strcpy(e->question, texte);

    fgets(texte, 255, f);
    strcpy(e->reponse1, texte);

    fgets(texte, 255, f);
    strcpy(e->reponse2, texte);

    fgets(texte, 255, f);
    strcpy(e->reponse3, texte);

    fgets(texte, 255, f);
    e->numrep = atoi(texte);

    fclose(f);
}
/******************************AFFICHAGE***********************************/

void init_affichage(enigme *e)
{
     e->police=TTF_OpenFont("mechanik-Bold.ttf",20);
    e->back=NULL;
    e->posback.x = 0; 
    e->posback.y = 0;
    e->back2=NULL;
    e->posback2.x = 0; 
    e->posback2.y = 0;
    e->posq.x=450;
    e->posq.y=320;
    e->posrep1.x=400;
    e->posrep1.y=420;
    e->posrep2.x=700;
    e->posrep2.y=420;
    e->posrep3.x=530;
    e->posrep3.y=560;

    e->back =IMG_Load("background.jpg");
     e->back2 =IMG_Load("background_q.png");
    SDL_Color couleurNoir= {255,255,255};
    e->q =TTF_RenderText_Blended(e->police,e->question,couleurNoir);
    e->rep1 =TTF_RenderText_Blended(e->police,e->reponse1,couleurNoir);
    e->rep2 =TTF_RenderText_Blended(e->police,e->reponse2,couleurNoir);
    e->rep3 =TTF_RenderText_Blended(e->police,e->reponse3,couleurNoir);
   
}

void afficherEnigme(enigme e, SDL_Surface *screen)
{
    SDL_BlitSurface(e.back2,NULL,screen,&(e.posback));
    SDL_BlitSurface(e.q, NULL, screen, &(e.posq));
    SDL_BlitSurface(e.rep1, NULL, screen, &(e.posrep1));
    SDL_BlitSurface(e.rep2, NULL, screen, &(e.posrep2));
    SDL_BlitSurface(e.rep3, NULL, screen, &(e.posrep3));
}

void afficherback1(enigme e, SDL_Surface *screen)
{
   SDL_BlitSurface(e.back,NULL,screen,&(e.posback));
   }


/******************************RESOLUTION*******************************/

int resultat(int choix,enigme *e)
{
  if (choix==e->numrep)
	{

		return 1;
	}
  else 
	{
		return 0;
	}
}

void affichresultat(SDL_Surface *Vrai,SDL_Surface *Faux,SDL_Rect positionV,SDL_Rect positionF,SDL_Surface *screen,int choix,enigme e,int r)
{
Vrai=NULL,Faux=NULL;
positionV.x =  370 ;
positionV.y =  325 ; 
positionF.x =  370 ;
positionF.y =  325 ;
if (r==1)
  {
	Vrai =IMG_Load("win.png");
	SDL_BlitSurface(Vrai,NULL,screen,&positionV);
  }
else if (r==0)
  {
	Faux =IMG_Load("wrong.png");
	SDL_BlitSurface(Faux,NULL,screen,&positionF);
  }
}


int affichertempsen(float elapsed_time, SDL_Surface *screen) {
    SDL_Color color_temp = {255, 255, 255};
    TTF_Font* police_time = NULL;
    police_time = TTF_OpenFont("OriginTech personal use.ttf", 23);
    if (police_time == NULL) {
        fprintf(stderr, "Failed to load font: %s\n", TTF_GetError());
        return 0;
    }
    char temp[100];
    int temps = 30000 - (int) elapsed_time * 1000; 
    if(temps < 0)
    {
        temps = 0;
    }
    int secondes = temps / 1000;
    int minutes = secondes / 60;
    secondes = secondes % 60;
    sprintf(temp, "%02d:%02d", minutes, secondes); 

 
    SDL_Surface* temps_surface = NULL;
    temps_surface = TTF_RenderUTF8_Solid(police_time, temp, color_temp);
    if (temps_surface == NULL) {
        fprintf(stderr, "Failed to create surface: %s\n", TTF_GetError());
        return 0;
    }

   
    SDL_Rect pos_temp;
    pos_temp.x = 100;
    pos_temp.y = 50;


    SDL_BlitSurface(temps_surface, NULL, screen, &pos_temp);
    
    SDL_FreeSurface(temps_surface);
    TTF_CloseFont(police_time);


    if (temps == 0) {
        return 1;
    } else {
        return 0;
    }
}

void initialiser_image2(enigme *imgsecond)
{
	imgsecond->url="Timesup.jpg";
	imgsecond->img=IMG_Load(imgsecond->url);
	if (imgsecond->img == NULL)
	{
		printf("unable to load background image %s\n",SDL_GetError());
		return;
	}
	imgsecond->pos_img_affiche.x=0;
	imgsecond->pos_img_affiche.y=0;
	imgsecond->pos_img_affiche.h=864;
	imgsecond->pos_img_affiche.w=1152;
	imgsecond->pos_img_ecran.x=0;
	imgsecond->pos_img_ecran.y=0;
}

void afficher_image2(SDL_Surface *screen,enigme imgsecond)
{
	SDL_BlitSurface(imgsecond.img,NULL,screen,&imgsecond.pos_img_ecran);
}

/******************************ANIMATION*******************************/

int init_animation(struct Animation* anim) {
    char filename[50];
    for (int i = 0; i < NUMM_FRAMES; ++i) {
        snprintf(filename, sizeof(filename), "animation/background%d.png", i);
        anim->anim[i] = IMG_Load(filename);
        if (!anim->anim[i]) {
            printf("Error loading frame %d: %s\n", i, SDL_GetError());
            return 0;
        }
    }

    anim->current_frame = 0;
    anim->last_update_time = SDL_GetTicks(); // Initialize timing here
    return 1;
}



// Function to display animation frames
void afficher_animation(struct Animation* anim, SDL_Surface* screen) {
    Uint32 current_time = SDL_GetTicks();
    int total_duration_ms = 30000;
    int frame_duration = total_duration_ms / NUMM_FRAMES;

    if (current_time > anim->last_update_time + frame_duration) {
        anim->last_update_time = current_time;
        anim->current_frame++;
        if (anim->current_frame >= NUMM_FRAMES)
    anim->current_frame = NUMM_FRAMES - 1;  // Stay on the last frame
    }

    SDL_BlitSurface(anim->anim[anim->current_frame], NULL, screen, &anim->pos);
}


void reset_animation(struct Animation* anim) {
    anim->current_frame = 0;
    anim->last_update_time = SDL_GetTicks();
}


// Function to free resources used by animation frames
void liberer_animation(struct Animation* anim) {
    for (int i = 0; i < NUMM_FRAMES; ++i) {
        SDL_FreeSurface(anim->anim[i]);
    }
}

/******************************HEARTS SYSTEM*******************************/

void init_hearts(HeartsSystem* hearts) {
    hearts->hearts[0] = IMG_Load("v3.png");
    hearts->hearts[1] = IMG_Load("v2.png");
    hearts->hearts[2] = IMG_Load("v1.png");
    hearts->hearts[3] = IMG_Load("gameover.jpg");
    
    // Set position (top right corner)
    hearts->pos_hearts.x = 50;
    hearts->pos_hearts.y = 20;
    
    hearts->remaining_lives = 3;  // Start with 1 life (minimum)
}

void update_hearts(HeartsSystem* hearts, int is_correct) {
    if (is_correct) {
        // Only increase lives if not already at maximum
        if (hearts->remaining_lives < 3) {
            hearts->remaining_lives++;
        }
    } else {
        hearts->remaining_lives--;
        if (hearts->remaining_lives < 0) {
            hearts->remaining_lives = 0;
        }
    }
}

void draw_hearts(HeartsSystem* hearts, SDL_Surface* screen) {
    if (hearts->remaining_lives <= 0) {
        // Game over - full screen
        SDL_Rect fullscreen = {0, 0, screen->w, screen->h};
        SDL_BlitSurface(hearts->hearts[3], NULL, screen, &fullscreen);
    } else {
        // Draw appropriate hearts image (1-3 lives)
        int index = hearts->remaining_lives - 1;
        SDL_BlitSurface(hearts->hearts[index], NULL, screen, &hearts->pos_hearts);
    }
}

void free_hearts(HeartsSystem* hearts) {
    for (int i = 0; i < 4; i++) {
        if (hearts->hearts[i]) {
            SDL_FreeSurface(hearts->hearts[i]);
        }
    }
}

///////////////////////////////// rotozoom //////////////////////////////////

void rotozoom(SDL_Surface *screen)
{
    SDL_Surface *loaded_image = IMG_Load("win.png");
    SDL_Surface *optimized_image = NULL;
    SDL_Surface *background = NULL;
        Uint32 start_time = SDL_GetTicks();

    if (loaded_image != NULL)
    {
        optimized_image = SDL_DisplayFormatAlpha(loaded_image);
        SDL_FreeSurface(loaded_image);
    }

    background = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA, screen->w, screen->h, screen->format->BitsPerPixel,
                                       screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, screen->format->Amask);
    SDL_FillRect(background, NULL, SDL_MapRGBA(background->format, 0, 0, 0, 0));

    if (optimized_image != NULL)
    {
        SDL_Rect dstrect;
        dstrect.w = optimized_image->w;
        dstrect.h = optimized_image->h;
        dstrect.x =0;
        dstrect.y =0;

        double angle = 0;
        double zoom = 1;
        double rotation_speed = 1;
        double zoom_speed = 0.01;
        SDL_Event event;
        int quit = 0;

        while (!quit)
        {
     
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    quit = 1;
                }
            }

            angle += rotation_speed;
            zoom += zoom_speed;

            // Clear the previous position of the image
            SDL_BlitSurface(background, &dstrect, screen, &dstrect);

            // Rotozoom the image
            SDL_Surface *rotozoomed_image = rotozoomSurface(optimized_image, angle, zoom, SMOOTHING_ON);
            SDL_Rect image_rect = {0, 0, rotozoomed_image->w, rotozoomed_image->h};

            // Draw the rotozoomed image with alpha transparency
            SDL_SetAlpha(rotozoomed_image, SDL_SRCALPHA, 128);
            SDL_BlitSurface(rotozoomed_image, &image_rect, screen, &dstrect);

            SDL_FreeSurface(rotozoomed_image);

            SDL_Flip(screen);
            SDL_Delay(10);
            if (SDL_GetTicks() - start_time >= 10000)
            {
                quit = 1;
            }

        }
       
        SDL_FreeSurface(optimized_image);
    }

    SDL_FreeSurface(background);
}
void rotozoom2(SDL_Surface *screen)
{
    SDL_Surface *loaded_image = IMG_Load("wrong.png");
    SDL_Surface *optimized_image = NULL;
    SDL_Surface *background = NULL;
        Uint32 start_time = SDL_GetTicks();

    if (loaded_image != NULL)
    {
        optimized_image = SDL_DisplayFormatAlpha(loaded_image);
        SDL_FreeSurface(loaded_image);
    }

    background = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA, screen->w, screen->h, screen->format->BitsPerPixel,
                                       screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, screen->format->Amask);
    SDL_FillRect(background, NULL, SDL_MapRGBA(background->format, 0, 0, 0, 0));

    if (optimized_image != NULL)
    {
        SDL_Rect dstrect;
        dstrect.w = optimized_image->w;
        dstrect.h = optimized_image->h;
        dstrect.x =0;
        dstrect.y =0;

        double angle = 0;
        double zoom = 1;
        double rotation_speed = 1;
        double zoom_speed = 0.01;
        SDL_Event event;
        int quit = 0;

        while (!quit)
        {
     
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    quit = 1;
                }
            }

            angle += rotation_speed;
            zoom += zoom_speed;

            // Clear the previous position of the image
            SDL_BlitSurface(background, &dstrect, screen, &dstrect);

            // Rotozoom the image
            SDL_Surface *rotozoomed_image = rotozoomSurface(optimized_image, angle, zoom, SMOOTHING_ON);
            SDL_Rect image_rect = {0, 0, rotozoomed_image->w, rotozoomed_image->h};

            // Draw the rotozoomed image with alpha transparency
            SDL_SetAlpha(rotozoomed_image, SDL_SRCALPHA, 128);
            SDL_BlitSurface(rotozoomed_image, &image_rect, screen, &dstrect);

            SDL_FreeSurface(rotozoomed_image);

            SDL_Flip(screen);
            SDL_Delay(10);
            if (SDL_GetTicks() - start_time >=10000)
            {
                quit = 1;
            }

        }
       
        SDL_FreeSurface(optimized_image);
    }

    SDL_FreeSurface(background);
}













