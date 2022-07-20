#include "lounger.h"

Lounger::Lounger(const Position& pos) : Infected(pos, 'L'){}

void Lounger::move(const char move){
    // get a random number in range [1, 100]
    int moving_rate = rand() % 100 + 1;

    // if moving rate <= 20, the Lounger moves
    bool moving = (moving_rate <= 20);

    // if the lounger is not moving, just return
    if (!moving)
        return;
    
    // else, choose a random direction for it to move to
    // || 1: S || 2: N || 3: E || 4, W ||
    int direction = rand() % 4 + 1;

    Position new_pos (pos -> x, pos -> y);

    // Try moving the lounger
    // If a move causes the lounger to go out of bound, it moves in the opposite direction instead
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

    // Update the current position of the lounger
    *pos = new_pos; 
}