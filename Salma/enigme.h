#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#define NUMM_FRAMES 31

typedef struct
{
char question[200]; /*!< caracter. */
char reponse1[200]; /*!< caracter. */
char reponse2[200]; /*!< caracter. */
char reponse3[200]; /*!< caracter. */
int numrep; /*!< number. */
SDL_Surface *back; /*!< Surface. */
SDL_Rect posback;  /*!< Rectangle*/
SDL_Surface *back2; /*!< Surface. */
SDL_Rect posback2;  /*!< Rectangle*/
SDL_Surface *q,*rep1,*rep2,*rep3; /*!< Surface. */
SDL_Rect posq,posrep1,posrep2,posrep3;  /*!< Rectangle*/
TTF_Font *police; /*!< font. */
char *url; /*!< caracter. */
SDL_Rect pos_img_affiche;   /*!< Rectangle*/
	SDL_Rect pos_img_ecran;  /*!< Rectangle*/
	SDL_Surface *img;  /*!< Surface. */
    Uint32 last_update_time;  // Track the last update time
}enigme;

typedef struct {
    SDL_Surface* hearts[4];  // 0=1heart, 1=2hearts, 2=3hearts, 3=gameover
    SDL_Rect pos_hearts;
    int remaining_lives;
} HeartsSystem;

struct Animation {
    SDL_Surface* anim[NUMM_FRAMES];
    SDL_Rect pos;
    int current_frame;        
    Uint32 last_update_time; 
};


void shuffle(int *array, int n);
void genererEnigme(enigme * e, char *nomfichier);

void init_affichage(enigme *e);
void afficherEnigme(enigme e, SDL_Surface *screen);
void afficherback1(enigme e, SDL_Surface *screen);
int resultat(int choix,enigme *e);
void affichresultat(SDL_Surface *Vrai,SDL_Surface *Faux,SDL_Rect positionV,SDL_Rect positionF,SDL_Surface *screen,int choix,enigme e,int r);
int affichertempsen(float elapsed_time, SDL_Surface *screen);
void initialiser_image2(enigme *imgsecond);
void afficher_image2(SDL_Surface *screen,enigme imgsecond);
int init_animation(struct Animation* anim);
void afficher_animation(struct Animation* anim, SDL_Surface* screen);
void reset_animation(struct Animation* anim);
void liberer_animation(struct Animation* anim);
void rotozoom(SDL_Surface *screen);
void rotozoom2(SDL_Surface *screen);

void init_hearts(HeartsSystem* hearts);
void update_hearts(HeartsSystem* hearts, int is_correct);
void draw_hearts(HeartsSystem* hearts, SDL_Surface* screen);
void free_hearts(HeartsSystem* hearts);




