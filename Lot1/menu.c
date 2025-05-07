#include "menu.h"


void init_menu(Menu *m){
    m->bg = IMG_Load("images/menu/bg.png");

    //btn jouer
    m->btn_jouer[0] = IMG_Load("images/menu/Jouer1.png");
    m->btn_jouer[1] = IMG_Load("images/menu/Jouer2.png");

    m->pos_jouer.x = 1920/2 - (m->btn_jouer[0]->w/2);
    m->pos_jouer.y = 250;
    m->pos_jouer.w = m->btn_jouer[0]->w;
    m->pos_jouer.h = m->btn_jouer[0]->h;

    m->etat_btn_jouer = 0;
    //btn option 
    m->btn_option[0] = IMG_Load("images/menu/option1.png");
    m->btn_option[1] = IMG_Load("images/menu/option2.png");

    m->pos_option.x = 1920/2 - (m->btn_option[0]->w/2);
    m->pos_option.y = 250+150;
    m->pos_option.w = m->btn_option[0]->w;
    m->pos_option.h = m->btn_option[0]->h;

    m->etat_btn_option = 0;
    //btn meilleur 
    m->btn_meilleur[0] = IMG_Load("images/menu/meilleur1.png");
    m->btn_meilleur[1] = IMG_Load("images/menu/meilleur2.png");

    m->pos_meilleur.x = 1920/2 - (m->btn_meilleur[0]->w/2);
    m->pos_meilleur.y = 250+150+150;
    m->pos_meilleur.w = m->btn_meilleur[0]->w;
    m->pos_meilleur.h = m->btn_meilleur[0]->h;

    m->etat_btn_meilleur = 0;
    //btn histoire 
    m->btn_histoire[0] = IMG_Load("images/menu/histoire1.png");
    m->btn_histoire[1] = IMG_Load("images/menu/histoire2.png");

    m->pos_histoire.x = 1920/2 - (m->btn_histoire[0]->w/2);
    m->pos_histoire.y = 250+150+150+150;
    m->pos_histoire.w = m->btn_histoire[0]->w;
    m->pos_histoire.h = m->btn_histoire[0]->h;

    m->etat_btn_histoire = 0;
    //btn quitter 
    m->btn_quitter[0] = IMG_Load("images/menu/quitter1.png");
    m->btn_quitter[1] = IMG_Load("images/menu/quitter2.png");

    m->pos_quitter.x = 1920/2 - (m->btn_quitter[0]->w/2);
    m->pos_quitter.y = 250+150+150+150+150;
    m->pos_quitter.w = m->btn_quitter[0]->w;
    m->pos_quitter.h = m->btn_quitter[0]->h;

    m->etat_btn_quitter = 0;

    //-------------------------Sous Menu Joueur---------------------------------------
    //btn mono 
    m->btn_mono[0] = IMG_Load("images/menu/mono1.png");
    m->btn_mono[1] = IMG_Load("images/menu/mono2.png");

    m->pos_mono.x = 300;
    m->pos_mono.y = 475;
    m->pos_mono.w = m->btn_mono[0]->w;
    m->pos_mono.h = m->btn_mono[0]->h;

    m->etat_btn_mono = 0;

    //btn multi 
    m->btn_multi[0] = IMG_Load("images/menu/multi1.png");
    m->btn_multi[1] = IMG_Load("images/menu/multi2.png");

    m->pos_multi.x = 1084;
    m->pos_multi.y = 475;
    m->pos_multi.w = m->btn_multi[0]->w;
    m->pos_multi.h = m->btn_multi[0]->h;

    m->etat_btn_multi = 0;

    //btn retour 
    m->btn_retour[0] = IMG_Load("images/menu/retour1.png");
    m->btn_retour[1] = IMG_Load("images/menu/retour2.png");

    m->pos_retour.x = 1370;
    m->pos_retour.y = 850;
    m->pos_retour.w = m->btn_retour[0]->w;
    m->pos_retour.h = m->btn_retour[0]->h;

    m->etat_btn_retour = 0;
    m->mode_jeux = 0;
    m->indice_page_joueur = 0;

    //page 2 sous menu joueur

    //btn avatar1 
    m->btn_avatar1[0] = IMG_Load("images/menu/avatar1_1.png");
    m->btn_avatar1[1] = IMG_Load("images/menu/avatar1_2.png");

    m->pos_avatar1.x = 300;
    m->pos_avatar1.y = 475;
    m->pos_avatar1.w = m->btn_avatar1[0]->w;
    m->pos_avatar1.h = m->btn_avatar1[0]->h;

    m->etat_btn_avatar1 = 0;
    m->selecter_btn_avatar1 =0;

    //btn input1 
    m->btn_input1[0] = IMG_Load("images/menu/input1_1.png");
    m->btn_input1[1] = IMG_Load("images/menu/input1_2.png");

    m->pos_input1.x = 300;
    m->pos_input1.y = 475+200;
    m->pos_input1.w = m->btn_input1[0]->w;
    m->pos_input1.h = m->btn_input1[0]->h;

    m->etat_btn_input1 = 0;
    m->selecter_btn_input1 = 0;

    //btn avatar2 
    m->btn_avatar2[0] = IMG_Load("images/menu/avatar2_1.png");
    m->btn_avatar2[1] = IMG_Load("images/menu/avatar2_2.png");

    m->pos_avatar2.x = 1084;
    m->pos_avatar2.y = 475;
    m->pos_avatar2.w = m->btn_avatar2[0]->w;
    m->pos_avatar2.h = m->btn_avatar2[0]->h;

    m->etat_btn_avatar2 = 0;
    m->selecter_btn_avatar2 = 0;

    //btn input2 
    m->btn_input2[0] = IMG_Load("images/menu/input2_1.png");
    m->btn_input2[1] = IMG_Load("images/menu/input2_2.png");

    m->pos_input2.x = 1084;
    m->pos_input2.y = 475+200;
    m->pos_input2.w = m->btn_input2[0]->w;
    m->pos_input2.h = m->btn_input2[0]->h;

    m->etat_btn_input2 = 0;
    m->selecter_btn_input2 = 0;

    //btn valider 
    m->btn_valider[0] = IMG_Load("images/menu/valider1.png");
    m->btn_valider[1] = IMG_Load("images/menu/valider2.png");

    m->pos_valider.x = 1920/2 - m->btn_valider[0]->w/2;
    m->pos_valider.y = 475+200 + 150;
    m->pos_valider.w = m->btn_valider[0]->w;
    m->pos_valider.h = m->btn_valider[0]->h;

    m->etat_btn_valider = 0;
    


}


void afficher_menu(Menu m,SDL_Surface *ecran){
    SDL_BlitSurface(m.bg,NULL,ecran,NULL);

    SDL_BlitSurface(m.btn_jouer[m.etat_btn_jouer],NULL,ecran,&m.pos_jouer);
    SDL_BlitSurface(m.btn_option[m.etat_btn_option],NULL,ecran,&m.pos_option);
    SDL_BlitSurface(m.btn_meilleur[m.etat_btn_meilleur],NULL,ecran,&m.pos_meilleur);
    SDL_BlitSurface(m.btn_histoire[m.etat_btn_histoire],NULL,ecran,&m.pos_histoire);
    SDL_BlitSurface(m.btn_quitter[m.etat_btn_quitter],NULL,ecran,&m.pos_quitter);


}
void afficher_smenu_joueur(Menu m,SDL_Surface *ecran){
    SDL_BlitSurface(m.bg,NULL,ecran,NULL);

    if(m.indice_page_joueur == 0){
        SDL_BlitSurface(m.btn_mono[m.etat_btn_mono],NULL,ecran,&m.pos_mono);
        SDL_BlitSurface(m.btn_multi[m.etat_btn_multi],NULL,ecran,&m.pos_multi);
    }else{
        SDL_BlitSurface(m.btn_avatar1[m.selecter_btn_avatar1],NULL,ecran,&m.pos_avatar1);
        SDL_BlitSurface(m.btn_avatar2[m.selecter_btn_avatar2],NULL,ecran,&m.pos_avatar2);
        SDL_BlitSurface(m.btn_input1[m.selecter_btn_input1],NULL,ecran,&m.pos_input1);
        SDL_BlitSurface(m.btn_input2[m.selecter_btn_input2],NULL,ecran,&m.pos_input2);
        SDL_BlitSurface(m.btn_valider[m.etat_btn_valider],NULL,ecran,&m.pos_valider);

    }
    SDL_BlitSurface(m.btn_retour[m.etat_btn_retour],NULL,ecran,&m.pos_retour);

}

void mise_a_jour_menu(Menu *m){

    m->etat_btn_jouer = collision_avec_souris(m->pos_jouer);
    m->etat_btn_option = collision_avec_souris(m->pos_option);
    m->etat_btn_meilleur = collision_avec_souris(m->pos_meilleur);
    m->etat_btn_histoire = collision_avec_souris(m->pos_histoire);
    m->etat_btn_quitter = collision_avec_souris(m->pos_quitter);

}

int collision_avec_souris(SDL_Rect pos){
    int mouse_x,mouse_y;
    SDL_GetMouseState(&mouse_x,&mouse_y);


    if(mouse_x > pos.x && mouse_x < (pos.x+pos.w) && mouse_y > pos.y && mouse_y < (pos.y + pos.h) ){
        return 1;
    }else{
        return 0;
    }

}

void gerer_event_menu(Menu *m,SDL_Event event,int *quitter,int *indice_ecran){
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
                *quitter = 1;
            break;
        case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT){
                    if(m->etat_btn_quitter == 1){
                        *quitter = 1;
                    }else if(m->etat_btn_jouer == 1){
                        *indice_ecran = 1;
                    }
                }
                
            break;
        
        default:
            break;
        }
    }
}



void mise_a_jour_smenu_joueur(Menu *m){
    if(m->indice_page_joueur == 0){
        m->etat_btn_mono = collision_avec_souris(m->pos_mono);
        m->etat_btn_multi = collision_avec_souris(m->pos_multi);
    }else if(m->indice_page_joueur == 1){
        m->etat_btn_avatar1 = collision_avec_souris(m->pos_avatar1);
        m->etat_btn_avatar2 = collision_avec_souris(m->pos_avatar2);
        m->etat_btn_input1 = collision_avec_souris(m->pos_input1);
        m->etat_btn_input2 = collision_avec_souris(m->pos_input2);
        m->etat_btn_valider = collision_avec_souris(m->pos_valider);

    }
    m->etat_btn_retour = collision_avec_souris(m->pos_retour);

}


void gerer_event_smenu_joueur(Menu *m,SDL_Event event,int *quitter,int *indice_ecran){
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
                *quitter = 1;
            break;
        case SDL_MOUSEBUTTONDOWN:

                if(event.button.button == SDL_BUTTON_LEFT){
                    if(m->indice_page_joueur == 0){
                        if(m->etat_btn_retour == 1){
                            *indice_ecran = 0;
                        }
                        if(m->etat_btn_multi == 1){
                            m->mode_jeux =1;
                            m->indice_page_joueur=1;
                        }else if(m->etat_btn_mono ==1){
                            m->mode_jeux = 0;
                            m->indice_page_joueur =1;
                        }
                    }else{

                        if(m->etat_btn_retour == 1){
                            m->indice_page_joueur = 0;
                        }

                        if(m->etat_btn_avatar1 == 1){
                            m->selecter_btn_avatar1 = 1;
                            m->selecter_btn_avatar2 = 0;
                        }else if(m->etat_btn_avatar2 == 1){
                            m->selecter_btn_avatar1 = 0;
                            m->selecter_btn_avatar2 = 1;
                        }

                        if(m->etat_btn_input1 == 1){
                            m->selecter_btn_input1 = 1;
                            m->selecter_btn_input2 = 0;
                        }else if(m->etat_btn_input2 == 1){
                            m->selecter_btn_input1 = 0;
                            m->selecter_btn_input2 = 1;
                        }

                        if(m->etat_btn_valider == 1 && (m->selecter_btn_input1 == 1 || m->selecter_btn_input2 ==1 ) && (m->selecter_btn_avatar1 == 1 || m->selecter_btn_avatar2 ==1 ) ){
                            *indice_ecran = 10; //tache joueur



                            //init perso

                            
                        }
                        
                    }
                }
            break;
        
        
        default:
            break;
        }
    }
}