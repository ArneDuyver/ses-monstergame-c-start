#ifndef GAME_H
#define GAME_H

typedef struct {
    int hp;
} Character;

typedef struct {
    int hp;
} Monster;

void play_turn(Character *player, Monster *monster, int choice);

#endif // GAME_H
