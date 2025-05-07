#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct{
    int right,left;
    int jump;
    int attack;
    int acceleration;
    int defense;
}Input;

typedef struct 
{
    int num_avatar;
    SDL_Surface *img_left;
    SDL_Surface *img_right;

    SDL_Rect pos_ecran;
    SDL_Rect pos_affichage;
    
    Input input;
    int etat_right,etat_left;
    int etat_jump;
    int etat_attack;
    int etat_acceleration;
    int etat_defense;
    
    float vitesse,acceleration;
    int direction; //0 perso aucun movement 1 right -1 left
    int derniere_direction; //1 right, -1 left
    int compteur_animation;

    //jump
    int en_saut; //vers haut
    int en_chute; // vers bas
    float vitesse_y;
    float gravite; // 0.5 
    int pos_sol;

}Joueur;

void init_joueur(Joueur *j,int avatar,int input);
void afficher_joueur(Joueur j,SDL_Surface *ecran);

void gerer_event_joueur(Joueur *j,SDL_Event event);


void deplacer_joueur(Joueur *j);

void animer_joueur(Joueur *j);

void jump_joueur(Joueur *j);

#endif