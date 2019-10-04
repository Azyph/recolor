#include <stdio.h>
#include "game.h"
#include "game_io.h"

int nbCoupMax = 0;

game_default() {
  return game_new_empty();
}
void game_display() {
  printf("coucou");
}

int main(int argc, char* argv[])
{

    game recolor = game_default();
    game_display(recolor);
    int reponse = getchar();

while (nbCoupMax =< 12 || game_is_over(recolor) == false)
  {
    if(reponse == '0' || '1' || '2' || '3')
        {
          nbCoupMax++;
          game_play_one_move(recolor, reponse);
          if(game_is_over(recolor))
            {
              printf("BRAVO")
            }
        }

    else if (reponse == 'r')
        {
          game_restart(recolor);
          nbCoupMax = 0;
        }

    else if (reponse == 'q')
        {
          printf("DOMMAGE")
        }

    else
        {
        printf("je n ai pas compris votre reponse")
        }
  }
  game_delete(recolor);


    return EXIT_SUCCESS;
}
