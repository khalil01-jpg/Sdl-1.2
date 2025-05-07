#include "joueur.h"

void init_joueur(Joueur *j,int avatar,int input){

    j->num_avatar = avatar;

    if(avatar == 1){
        j->img_left = IMG_Load("images/joueur/avatar1/left.png");
        j->img_right = IMG_Load("images/joueur/avatar1/right.png");
    }else{
        j->img_left = IMG_Load("images/joueur/avatar2/left.png");
        j->img_right = IMG_Load("images/joueur/avatar2/right.png");
    }

    int w_joueur;
    int h_joueur;
    if(j->num_avatar == 1){
        w_joueur = 120;
        h_joueur = 175;
    }else{
        w_joueur = 120;
        h_joueur = 132;
    }

    j->pos_ecran.x = 0;
    j->pos_ecran.y = 975 - h_joueur;
    j->pos_ecran.w = w_joueur;
    j->pos_ecran.h = h_joueur;

    j->pos_affichage.x = 0;
    j->pos_affichage.y = 0;
    j->pos_affichage.w = w_joueur;
    j->pos_affichage.h = h_joueur;

    j->direction = 0;


    if(input == 1){
        j->input.right = SDLK_d;
        j->input.left  = SDLK_q;
        j->input.jump = SDLK_SPACE;
        j->input.attack = SDLK_x;
        j->input.defense = SDLK_c;
        j->input.acceleration = SDLK_LSHIFT;
    }else{
        j->input.right = SDLK_RIGHT;
        j->input.left  = SDLK_LEFT;
        j->input.jump = SDLK_UP;
        j->input.attack = SDLK_l;
        j->input.defense = SDLK_k;
        j->input.acceleration = SDLK_j;
    }

    j->etat_right = 0;
    j->etat_left  = 0;
    j->etat_jump = 0;
    j->etat_attack = 0;
    j->etat_defense = 0;
    j->etat_acceleration = 0;

    j->vitesse = 0;
    j->acceleration = 0;
    j->direction = 0;
    j->derniere_direction=1;

    j->compteur_animation=0;

    j->en_chute = 0;
    j->en_saut = 0;

    j->vitesse_y = -12;
    j->gravite = 0.5;

    j->pos_sol = 975 - h_joueur;


}


void afficher_joueur(Joueur j,SDL_Surface *ecran){
    if(j.derniere_direction == 1 ){
        SDL_BlitSurface(j.img_right,&j.pos_affichage,ecran,&j.pos_ecran);
    }else if(j.derniere_direction == -1){
        SDL_BlitSurface(j.img_left,&j.pos_affichage,ecran,&j.pos_ecran);
    }else{
        SDL_BlitSurface(j.img_right,&j.pos_affichage,ecran,&j.pos_ecran);
    }
}

void gerer_event_joueur(Joueur *j,SDL_Event event){
    switch (event.type)
    {
    case SDL_KEYDOWN:
            if(event.key.keysym.sym == j->input.right){
                j->etat_right = 1;
                j->direction = 1;
                j->derniere_direction = 1;
            }

            if(event.key.keysym.sym == j->input.left){
                j->etat_left = 1;
                j->direction = -1;
                j->derniere_direction = -1;
            }

            if(event.key.keysym.sym == j->input.attack){
                j->etat_attack = 1;
            }

            if(event.key.keysym.sym == j->input.defense){
                j->etat_defense = 1;
            }

            if(event.key.keysym.sym == j->input.jump){
                j->etat_jump = 1;
            }
            if(event.key.keysym.sym == j->input.acceleration){
                j->etat_acceleration = 1;
            }

        break;
    case SDL_KEYUP:
            if(event.key.keysym.sym == j->input.right){
                j->etat_right = 0;
                j->derniere_direction = 1;
            }

            if(event.key.keysym.sym == j->input.left){
                j->etat_left = 0;
                j->derniere_direction = -1;
            }

            if(event.key.keysym.sym == j->input.acceleration){
                j->etat_acceleration = 0;
            }


        break;
    
    default:
        break;
    }
}


void deplacer_joueur(Joueur *j){



    if(j->etat_left ==0 && j->etat_right == 0){
        j->vitesse -= 0.15;
        if(j->vitesse < 0){
            j->vitesse = 0;
        }
    }else{
        j->vitesse += 0.15;
        if(j->vitesse > 2){
            j->vitesse = 2;
        }
    }

    if(j->etat_acceleration == 1){
        j->acceleration += 0.2;
        if(j->acceleration > 3){
            j->acceleration = 3;
        }
    }else{
        j->acceleration -= 0.15;
        if(j->acceleration < 0){
            j->acceleration = 0;
        }
    }

    if(j->vitesse ==0){
        j->direction = 0;
    }

    float vitesse_total = j->acceleration + j->vitesse;

    j->pos_ecran.x += vitesse_total * j->direction;




}


void animer_joueur(Joueur *j){
j->compteur_animation ++;

  if(j->en_saut == 0 && j->en_chute ==0){
    if(j->etat_attack == 0){

        if(j->direction == 0 && j->derniere_direction == 1  && j->compteur_animation % 10 == 0){
            if(j->pos_affichage.y != 0){
                j->pos_affichage.x = 0;
                j->pos_affichage.y = 0;
                j->pos_affichage.w = 120;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x += 235;
            if(j->pos_affichage.x > 940){
                j->pos_affichage.x = 0;
            }
        
        }else if(j->direction == 0 && j->derniere_direction == -1 && j->compteur_animation % 10 == 0){
            if(j->pos_affichage.y != 0){
                j->pos_affichage.x = 1885;
                j->pos_affichage.y = 0;
                j->pos_affichage.w = 120;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x -= 235;
            if(j->pos_affichage.x > 1885 - (235 * 4)){
                j->pos_affichage.x = 1885;
            }
        
        }

        if(j->direction == 1 && j->etat_acceleration ==0 && j->compteur_animation % 7 == 0){
            if(j->pos_affichage.y != 238){
                j->pos_affichage.x = 0;
                j->pos_affichage.y = 238;
                j->pos_affichage.w = 120;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x += 235;
            if(j->pos_affichage.x > 235 * 8){
                j->pos_affichage.x = 0;
            } 
        }
        else if(j->direction == -1 && j->etat_acceleration ==0 && j->compteur_animation % 7 == 0){
            if(j->pos_affichage.y != 238){
                j->pos_affichage.x = 1880;
                j->pos_affichage.y = 238;
                j->pos_affichage.w = 120;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x -= 235;
            if(j->pos_affichage.x < 0){
                j->pos_affichage.x = 1880;
            } 
        }

        if(j->direction == 1 && j->etat_acceleration ==1 && j->compteur_animation % 7 == 0){
            if(j->pos_affichage.y != 476){
                j->pos_affichage.x = 0;
                j->pos_affichage.y = 476;
                j->pos_affichage.w = 120;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x += 235;
            if(j->pos_affichage.x > 235 * 7){
                j->pos_affichage.x = 0;
            } 
        }
        else if(j->direction == -1 && j->etat_acceleration ==1 && j->compteur_animation % 7 == 0){
            if(j->pos_affichage.y != 476){
                j->pos_affichage.x = 1880;
                j->pos_affichage.y = 476;
                j->pos_affichage.w = 120;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x -= 235;
            if(j->pos_affichage.x < 1880-(235*6)){
                j->pos_affichage.x = 1885;
            } 
        }
    }
    //attack
    else{

        if(j->derniere_direction == 1  && j->compteur_animation % 7 == 0){
            if(j->pos_affichage.y != 714){
                j->pos_affichage.x = 0;
                j->pos_affichage.y = 714;
                j->pos_affichage.w = 189;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x += 235;
            if(j->pos_affichage.x > 235 * 3){
                j->pos_affichage.x = 0;
                j->etat_attack = 0;
            } 
        }
        else if(j->derniere_direction == -1 && j->compteur_animation % 7 == 0){
            if(j->pos_affichage.y != 712){
                j->pos_affichage.x = 1816;
                j->pos_affichage.y = 712;
                j->pos_affichage.w = 189;
                j->pos_affichage.h = 175;
            }
        
            j->pos_affichage.x -= 235;
            if(j->pos_affichage.x < 1816-(235*3)){
                j->pos_affichage.x = 1816;
                j->etat_attack = 0;
            } 
            
        }


    }

  }else{  //jump

    if(j->derniere_direction == 1  && j->compteur_animation % 10 == 0){
        if(j->pos_affichage.y != 1653){
            j->pos_affichage.x = 0;
            j->pos_affichage.y = 1653;
            j->pos_affichage.w = 120;
            j->pos_affichage.h = 175;
        }
        if(j->en_saut == 1){
            j->pos_affichage.x += 235;
            if(j->pos_affichage.x > (235*3)){
                j->pos_affichage.x = 235*3;
            }
        }else if(j->en_chute == 1){
            j->pos_affichage.x += 235;
            if(j->pos_affichage.x > (235*6)){
                j->pos_affichage.x = 235*6;
            }
        }
    
    }else if(j->derniere_direction == -1 && j->compteur_animation % 10 == 0){
        if(j->pos_affichage.y != 1653){
            j->pos_affichage.x = 1885;
            j->pos_affichage.y = 1653;
            j->pos_affichage.w = 120;
            j->pos_affichage.h = 175;
        }
    
        if(j->en_saut == 1){
            j->pos_affichage.x -= 235;
            if(j->pos_affichage.x < 1885-(235*3)){
                j->pos_affichage.x = 1885-(235*3);
            }
        }else if(j->en_chute == 1){
            j->pos_affichage.x -= 235;
            if(j->pos_affichage.x < 1885-(235*6)){
                j->pos_affichage.x =  1885-(235*6);
            }
        }
    
    }


  }




if(j->compteur_animation > 10000){
    j->compteur_animation = 0;
}


}


void jump_joueur(Joueur *j){

    //declenchement saut 
    if(j->etat_jump == 1 && j->en_saut == 0 && j->en_chute ==0){
        j->en_saut = 1;
        j->vitesse_y = -12;
        j->etat_jump = 0;
    }

    //si le joueur est en saut ou bien en chute

    if(j->en_saut == 1 || j->en_chute == 1){

        j->vitesse_y += j->gravite;
        j->pos_ecran.y += (int)j->vitesse_y;

        if(j->vitesse_y >= 0 && j->en_saut == 1){
            j->en_saut =0;
            j->en_chute = 1;
        }

        if(j->pos_ecran.y >= j->pos_sol){
            j->pos_ecran.y = j->pos_sol;
            j->vitesse_y = 0;
            j->en_saut =0;
            j->en_chute =0;
        }
        



    }



}



