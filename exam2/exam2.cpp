// who: <your name and Mt SAC username goes here>
// what: <the function of this program>
// why: <the name of the lab>
// when: <the due date of this lab.>
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <random>
#include "odiums_mansion.h"
void move();
void clearScreen();
void clearInstream();


struct PlayerInput
{
	std::string yourString;

	char GetInput()
	{
		std::cout << "Enter Your move "<<std::endl;
		std::cout<<" (R)ight, (L)eft, (U)p, (D)own, (P)ickup gold:";
		std::cin >> yourString;


		clearInstream(); 

		std::cout << std::endl;

		return yourString[0];
	}
};

int main(int argc, char const *argv[])
{
	std::array<std::array <string, 8>,8 > upper_grid;
    std::array<std::array <string, 8>,8 > lower_grid;
    char obj[8][8];
	
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            
        }
    }
	
   	
	move();
	
	
	
    return 0;
}
void clearScreen()
{
    if(WINDOWS)
        system("CLS");
    else
        system("clear");
}


void clearInstream()
{
    std::cin.clear();
    // Wrong input remains on the stream, so you need to get rid of it
    std::cin.ignore(10, '\n');
}