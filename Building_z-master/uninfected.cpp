#include "uninfected.h"

Uninfected::Uninfected(const Position& pos, char type) : Person(pos, type) {}

void Uninfected::move(const char move){

    // Create new pos after moving 
    Position new_pos (*pos);
    bool invalid = false;

    // Try to move
    switch (move)
    {
        case 'N':
            new_pos.y -= 1;
            break;
        case 'S':
            new_pos.y += 1;
            break;
        case 'E':
            new_pos.x += 1;
            break;
        case 'W':
            new_pos.x -= 1;
            break;
        case 'P':
            break;
        default:
            invalid = true;
            break;
    }

    // If the move cause the uninfected to go out of bound, it is invalid
    if (new_pos.x < 0 || new_pos.y < 0 || new_pos.x > 7 || new_pos.y >9)
        invalid = true;

    // Throw an invalid_argument exception if the move is invalid
    if (invalid)
        throw std::invalid_argument("Invalid move!");
    
    *pos = new_pos;
}