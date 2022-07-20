#include "hyper.h"

Hyper::Hyper(const Position& pos) : Infected(pos, 'H'){}

void Hyper::move(const char move){
    
    // Generate a random number in range [1, 4] for a direction
    // || 1: S || 2: N || 3: E || 4, W ||
    int direction = rand() % 4 + 1;

    Position new_pos (pos -> x, pos -> y);

    // Try moving the hyper
    // If a move causes the hyper to go out of bound, it moves in the opposite direction instead
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

    // Update the current position of the hyper
    *pos = new_pos;
}