#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


/*C Exercise
-Define & implement 4 structs & 1 union
-Instantiate 5 structs
-Create 3 function (1 on top of the main() Function, 2 as subprograms)
- Use the main function
*/
struct personnage {
    char nom[50];
    int hp_pts;
    int atk_pts;
    int level;
    bool vivant;
};
struct boss {
    char nom[50];
    int hp_pts;
    int atk_pts;
    bool vivant;
};


    

int main(void){

  

    int choix;
    choix = 0;
    int choix2;
    choix2 = 0;
    
    struct personnage joueur;
    strcpy(joueur.nom, "Tarnished");
    joueur.hp_pts = 100;
    joueur.atk_pts = 10;
    joueur.level = 1;
    joueur.vivant = true;

  
    struct boss malenia;
    strcpy(malenia.nom, "Malenia Blade of Miquella");
    malenia.hp_pts = 500;
    malenia.atk_pts = 49;
    malenia.vivant = true;

    struct boss malenia2;
    strcpy(malenia2.nom, "Malenia Goddess of Rot");
    malenia2.hp_pts = 470;
    malenia2.atk_pts = 100;
    malenia2.vivant = true;
    
    printf("I am Malenia Blade of Miquella");
    while (joueur.vivant && malenia.vivant) {
        printf("Malenia s'approche lentement \n");
        printf("1) Roulade 2)attaquer 3)potion\n");
        scanf(" %d",&choix);
        switch (choix)
        {
        case 1:
            printf("Malenia s'approche en courant !\n");
            printf("1) Roulade 2)attaquer 3)potion\n");
            scanf(" %d", &choix2);
            switch (choix2) {
            case 1:
                printf("Vous avez esquive !\n");
            case 2:
                joueur.hp_pts = joueur.hp_pts - malenia.atk_pts;
                printf("Vous prenez un coup ! \nPV totaux: %d\n", joueur.hp_pts);
            }


        case 2:
            malenia.hp_pts = malenia.hp_pts - (joueur.atk_pts + joueur.level);
            printf("Malenia prend coup, PV totaux: %d \n\n", malenia.hp_pts);
            break;
        case 3:
            joueur.hp_pts = 100;
            printf("Vos pvs remontent a 100 \n\n");
            break;
        
        }
        if (joueur.hp_pts <= 0) {
            joueur.vivant = false;
            printf("Vous avez peri");
        }
        if (malenia.hp_pts <= 0) {
            malenia.vivant = false;
            printf("Uuuuuhhh (Meurt)\n");
            printf("Vous gagnez 15 niveaux !\n\n\n");
            joueur.level = 15; 

        }
    };
    if (joueur.vivant) {
        while(joueur.vivant && malenia2.vivant){
            printf("Malenia vous cours dessus\n");
            printf("1) Roulade 2)attaquer 3)potion\n");
            scanf(" %d", &choix);
            switch (choix) {
            case 1:
                printf("Vous esquivez le coup de pied\n");
                printf("Malenia reste au sol\n");
                printf("1) Roulade 2)attaquer 3)potion\n");
                scanf(" %d", &choix2);
                switch (choix2) {
                case 1:
                    printf("Rien ne se passe\n");
                    break;
                case 2:
                    malenia2.hp_pts = malenia2.hp_pts - (joueur.atk_pts + joueur.level);
                    printf("Malenia prends un coup PV: %d\n", malenia2.hp_pts);
                    break;
                case 3:
                    joueur.hp_pts = 100;
                    printf("Vos PV remontent a 100\n");
                    break;
                break;
                }
            case 2:
                joueur.hp_pts = joueur.hp_pts - malenia2.atk_pts;
                printf("Vous prenez un coup PV: %d\n", joueur.hp_pts);
                break;
            case 3:
                joueur.hp_pts = 100;
                printf("Vos PV remontent a 100\n");
                break;
            }
            if (joueur.hp_pts <= 0) {
                joueur.vivant = false;
                printf("Vous avez peri\n");
            }
            if (malenia2.hp_pts <= 0) {
                malenia2.vivant = false;
                printf("Your strengh... Extraordinary");
            }
        }
    }


    return 0;
}
