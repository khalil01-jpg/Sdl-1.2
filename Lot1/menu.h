#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



typedef struct 
{
    SDL_Surface *bg;
    //btn jouer
    SDL_Surface *btn_jouer[2];
    SDL_Rect pos_jouer;
    int etat_btn_jouer;
    //btn option
    SDL_Surface *btn_option[2];
    SDL_Rect pos_option;
    int etat_btn_option;
    //btn meilleur
    SDL_Surface *btn_meilleur[2];
    SDL_Rect pos_meilleur;
    int etat_btn_meilleur;
    //btn histoire
    SDL_Surface *btn_histoire[2];
    SDL_Rect pos_histoire;
    int etat_btn_histoire;
    //btn quitter
    SDL_Surface *btn_quitter[2];
    SDL_Rect pos_quitter;
    int etat_btn_quitter;


    //-------------------------Sous Menu Joueur---------------------------------------

    //btn mono
    SDL_Surface *btn_mono[2];
    SDL_Rect pos_mono;
    int etat_btn_mono;
    //btn multi
    SDL_Surface *btn_multi[2];
    SDL_Rect pos_multi;
    int etat_btn_multi;
    //btn retour
    SDL_Surface *btn_retour[2];
    SDL_Rect pos_retour;
    int etat_btn_retour;

    int mode_jeux; //0:mono 1:multi
    int indice_page_joueur;

    //btn avatar1
    SDL_Surface *btn_avatar1[2];
    SDL_Rect pos_avatar1;
    int etat_btn_avatar1;
    int selecter_btn_avatar1;
    //btn avatar2
    SDL_Surface *btn_avatar2[2];
    SDL_Rect pos_avatar2;
    int etat_btn_avatar2;  
    int selecter_btn_avatar2;
    //btn input1
    SDL_Surface *btn_input1[2];
    SDL_Rect pos_input1;
    int etat_btn_input1; 
    int selecter_btn_input1;
    //btn input2
    SDL_Surface *btn_input2[2];
    SDL_Rect pos_input2;
    int etat_btn_input2;   
    int selecter_btn_input2; 

    //btn valider
    SDL_Surface *btn_valider[2];
    SDL_Rect pos_valider;
    int etat_btn_valider;   
    int selecter_btn_valider; 

    
    

}Menu;

void init_menu(Menu *m);
void afficher_menu(Menu m,SDL_Surface *ecran);
void mise_a_jour_menu(Menu *m);


void afficher_smenu_joueur(Menu m,SDL_Surface *ecran);
void mise_a_jour_smenu_joueur(Menu *m);

int collision_avec_souris(SDL_Rect pos);
void gerer_event_menu(Menu *m,SDL_Event event,int *quitter,int *indice_ecran);
void gerer_event_smenu_joueur(Menu *m,SDL_Event event,int *quitter,int *indice_ecran);
#endif