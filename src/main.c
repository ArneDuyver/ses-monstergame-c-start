#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

int main(int argc, char *argv[])
{
  int starting_hp = 10; // Standaard HP

  // Zoek naar de flag "--hp" en haal de volgende parameter als start HP
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "--hp") == 0 && i + 1 < argc)
    {
      starting_hp = atoi(argv[i + 1]);
      break;
    }
  }

  Character player = {starting_hp};
  Monster monster = {10};

  printf("Welkom bij het gevechtsspel!\n");
  printf("Jouw start HP is: %d\n", player.hp);

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
