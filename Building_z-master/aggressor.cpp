#include "aggressor.h"

Aggressor::Aggressor(const Position& pos, const Uninfected& hero):Infected(pos, 'A'), hero(&hero){}

bool Aggressor::heroInRange(){
    bool in_range = false;
    Position hero_pos (hero -> getPosition().x, hero -> getPosition().y);

    int x_diff = abs((int) hero_pos.x - (int) pos -> x);
    int y_diff = abs((int) hero_pos.y - (int) pos -> y);

    // if x_diff <= 2 AND y_diff <=2, the Aggressor can sense the spec-op
    if (x_diff <= 2 && y_diff <= 2)
        in_range = true;

    return in_range;
}

void Aggressor::move(const char move){

    // the direction to move to
    // || 1: S || 2: N || 3: E || 4, W ||
    int direction;

    // If the hero is in range, pursue them
    if (heroInRange()){
        Position hero_pos (hero -> getPosition().x, hero -> getPosition().y);
        if (hero_pos.x == pos -> x){
            if (hero_pos.y > pos -> y)
                direction = 2;
            else
                direction = 1;
        }
        else{
            if (hero_pos.x > pos -> x)
                direction = 3;
            else
                direction = 4;
        }
    }
    // else, choose a random direction to move to 
    else direction = rand() % 4 + 1;

    Position new_pos (pos -> x, pos -> y);

    // Try moving the aggressor
    // If a move causes the aggressor to go out of bound, it moves in the opposite direction instead
    switch (direction)
    {
        case 1:
            if (new_pos.y > 0)
                new_pos.y -= 1;
            else new_pos.y += 1;
            break;

        case 2:
            if (new_pos.y < 9)
                new_pos.y += 1;
            else new_pos.y -= 1;
            break;

        case 3:
            if (new_pos.x < 7)
                new_pos.x += 1;
            else new_pos.x -= 1;
            break;

        case 4:
            if (new_pos.x > 0)
                new_pos.x -= 1;
            else new_pos.x += 1;
            break;
    }

    // Update the current position of the aggressor
    *pos = new_pos; 
}