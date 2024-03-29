#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "game_io.h"
#define SIZE 12

uint nbCoupMax = 12;

struct game_s * game_default  () {
    color cells [] = {          0,0,0,2,0,2,1,0,1,0,3,0,
                                0,3,3,1,1,1,1,3,2,0,1,0,
                                1,0,1,2,3,2,3,2,0,3,3,2,
                                2,3,1,0,3,2,1,1,1,2,2,0,
                                2,1,2,3,3,3,3,2,0,1,0,0,
                                0,3,3,0,1,1,2,3,3,2,1,3,
                                1,1,2,2,2,0,0,1,3,1,1,2,
                                1,3,1,3,1,0,1,0,1,3,3,3,
                                0,3,0,1,0,0,2,1,1,1,3,0,
                                1,3,1,0,0,0,3,2,3,1,0,0,
                                1,3,3,1,1,2,2,3,2,0,0,2,
                                2,0,2,3,0,1,1,1,2,3,0,1} ;
    struct game_s * game = game_new (cells, nbCoupMax) ;
    return game ;
}

void game_display(cgame g){

    printf("nb coups joués : %d ; nb coup max : %d \n", game_nb_moves_cur(g),game_nb_moves_max(g));

    for (int y = 0; y<SIZE ; y++){

        for (int x = 0 ; x<SIZE ; x++){

            printf("%d", game_cell_current_color(g ,x ,y));

        }printf("\n");

    }printf("Jouer un coup: (0,1,2,3,r ou q ; r pour redémarrer ou q pour quitter)\n");

}


int main(int argc, char* argv[])
{

  game recolor = game_default();

  while (game_nb_moves_cur(recolor)<= game_nb_moves_max(recolor) || game_is_over(recolor) == false)
  {
    game_display(recolor);
    char reponse = getchar();
    if (reponse == 'r') 
    {
      game_restart(recolor);
    }
    else if (reponse == 'q')
    {
      printf("DOMMAGE\n");
      game_delete(recolor);
      break;
    }
    else if (reponse == '0' || reponse == '1' || reponse == '2' || reponse == '3')
    {
      game_play_one_move(recolor, atoi(&reponse));
      if (game_is_over(recolor))
      {
        game_display(recolor);
        printf ("BRAVO\n");
        game_delete(recolor);
        break;
      }
    }
    

  }

  EXIT_SUCCESS;
}