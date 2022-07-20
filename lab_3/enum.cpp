/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what: Simple math operations
// why: lab 1b
// when: 6/3/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>

enum class WPlayer{KING, QUEEN, BISHOP, ROOK, KNIGHT, PAWN};
enum class BPlayer{KING, QUEEN, BISHOP, ROOK, KNIGHT, PAWN};
enum Side{WHITE, BALCK};
void initBoard(WPlayer[8][8], WPlayer);
int main(int argc, char const *argv[])
{
    std::cout<<"Warning"<<std::endl;
    return 0;
}
void initBoard(WPlayer b[8][8], WPlayer p)
{
    for(size_t i = 0; i<8; ++i)
        for(size_t j = 0; j< 8; ++j)
            b[i][j] = (p == WPlayer::KING) ? WPlayer::QUEEN : p;
}

