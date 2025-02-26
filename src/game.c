#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_turn(Character *player, Monster *monster, int choice)
{
  srand(time(NULL));                     // Zorgt voor willekeurigheid per spelronde
  int monster_attack = (rand() % 4) + 1; // 1 tot 4 schade

  switch (choice)
  {
  case 1:
  {                                       // Aanvallen
    int attack_damage = (rand() % 2) + 1; // 1 of 2 schade
    monster->hp -= attack_damage;
    printf("Je valt aan en doet %d schade!\n", attack_damage);
    break;
  }
  case 2:
  { // Blokkeren
    if ((rand() % 100) < 80)
    { // 80% kans op succesvolle blokkering
      monster_attack = 0;
      printf("Je blokkeert de aanval succesvol!\n");
    }
    else
    {
      printf("Je blokkeerpoging faalt!\n");
    }
    break;
  }
  case 3:
  {                             // Lucky potion
    int outcome = rand() % 100; // Willekeurig getal 0-99
    if (outcome < 10)
    {
      player->hp += 4;
      printf("De potion is super krachtig! +4 HP!\n");
    }
    else if (outcome < 20)
    {
      monster->hp += 2;
      printf("Oeps! Je hebt het monster genezen! +2 HP voor het monster!\n");
    }
    else if (outcome < 30)
    {
      player->hp -= 2;
      printf("De potion was giftig! -2 HP!\n");
    }
    else
    {
      player->hp += 2;
      printf("De potion werkt! +2 HP!\n");
    }
    break;
  }
  default:
    printf("Ongeldige keuze, probeer opnieuw!\n");
    return;
  }

  // Monster valt aan als het nog leeft
  if (monster->hp > 0)
  {
    player->hp -= monster_attack;
    printf("Het monster valt aan en doet %d schade!\n", monster_attack);
  }
}
