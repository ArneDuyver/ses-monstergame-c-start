#include <stdio.h>
#include "game.h"

int main()
{
  Character player = {10}; // Speler start met 10 HP
  Monster monster = {10};  // Monster start met 10 HP

  printf("Welkom bij het gevechtsspel!\n");

  while (player.hp > 0 && monster.hp > 0)
  {
    int keuze;
    printf("\nJouw HP: %d | Monster HP: %d\n", player.hp, monster.hp);
    printf("Kies een actie:\n");
    printf("1. Aanvallen\n");
    printf("2. Blokkeren\n");
    printf("3. Lucky Potion drinken\n");
    printf("Voer je keuze in: ");
    scanf("%d", &keuze);

    play_turn(&player, &monster, keuze);
  }

  if (player.hp > 0)
  {
    printf("\nGefeliciteerd! Je hebt het monster verslagen!\n");
  }
  else
  {
    printf("\nHelaas! Het monster heeft jou verslagen...\n");
  }

  return 0;
}
