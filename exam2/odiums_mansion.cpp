// who: Hoang Tu Huynh
// what: Board Game: Aldrac Dungeon Simulator 
// why: Lab Project 2
// when: May 3
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <random>
#include <array>
#include "odiums_mansion.h"

#define ROW 8
#define COLUME 8
#define START 0


int main(int argc, char const *argv[])
{
	clearScreen();
	game_on();
    return 0;
}

void game_on()
{

	Grid grid;
	grid.totalX = ROW;
	grid.totalY = COLUME;


	GridObject obj;
	obj.x = START;
	obj.y = START;

	Random_obj pits_evil_gold;
	pits_evil_gold.create_random_object();

	AldracObject aldrac;
	aldrac.a = pits_evil_gold.arr1[0][13];
	aldrac.b = pits_evil_gold.arr1[1][13];

	GoldObject gold;
	gold.gx = pits_evil_gold.arr1[0][12];
	gold.gy = pits_evil_gold.arr1[1][12];

	PitObjects pits;
	for (int i = 0; i<12; i++){
		pits.x1[i] = pits_evil_gold.arr1[0][i];
		pits.y1[i] = pits_evil_gold.arr1[1][i];
	}
	
	PlayerInput playerInput;
	char input = '0';
	int holdgold = 0;
	bool set = true;
	int valid = 0;

	std::string items[8][8];
	for(int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
        {
            items[i][j] = "    ";   			
        }
    }
	
	while (set)
	{
		printIntro();
		initialize_item(items, obj.x, obj.y, aldrac.a, aldrac.b, gold.gx, gold.gy, pits.x1, pits.y1);
		grid.Render(items, obj);
		if(valid == 1) std::cout<<"Invalid Input!\n";
		
		valid = 0;
		if(holdgold == 1) std::cout<<"You are holding the gold!!!\n";
		input = playerInput.GetInput();

		
		if (toupper(input) == 'L')
		{
			obj.x -= 1;
			if(obj.x<0) obj.x+=1;
		}
		else if (toupper(input) == 'R')
		{
			obj.x += 1;
			if(obj.x>7) obj.x-=1;
		}
		else if (toupper(input) == 'U')
		{
			obj.y -= 1;
			if(obj.y<0) obj.y+=1;
		}
		else if (toupper(input) == 'D')
		{
			obj.y += 1;
			if(obj.y>7) obj.y-=1;
		}
		else if(toupper(input) == 'P')
		{
			if(obj.x == gold.gx && obj.y == gold.gy)
			{
				holdgold = 1;
			}
			else std::cout<<"No gold in this position!\n";
			
		}
		else
		{
			clearScreen();
			valid = 1;
			continue;
		}

		if (obj.x == aldrac.a && obj.y == aldrac.b) set = false;
			
		for(int k = 0; k< 12; k++)
			if(obj.x == pits.x1[k] && obj.y == pits.y1[k])
				set = false;

		if(obj.x == START && obj.y == START)
		{
			if(holdgold == 1) {
				clearScreen();
				printIntro();
				grid.Render(items, obj);
				std::cout<<" You've escaped with the gold, well done! \n";
				break;
			}
			else if (holdgold == 0) 
			{
				clearScreen();
				continue;
			}
		}	
		clearScreen();	
	}
	
	if(set == false)
	{
		printIntro();
		grid.Render(items, obj);
		std::cout<<"You have died in the dungeon!\n";
	}	
}

void initialize_player(std::string player[8][8], int x, int y)
{

	for(int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
        {
            player[i][j] = "    ";   
				if (player[x][y] == "    ") player[x][y] = " U  ";
        }
    }
					
}
void initialize_item(std::string items[8][8], int x, int y, int ax, int ay, int gx, int gy, int arr1[12], int arr2[12])
{
	if((x == ax+1 && y ==ay) || (x == ax-1 && y == ay)||(x == ax && y ==ay+1)||(x == ax && y ==ay-1))
		items[x][y] = " S  ";
	
	if (x == gx && y== gy)
	{
		items[x][y] = "  G ";
		if((x == ax+1 && y ==ay) || (x == ax-1 && y == ay)||(x == ax && y ==ay+1)||(x == ax && y ==ay-1))
			items[x][y] = " SG ";
	}
		
	for (int i = 0; i<12; i++)
	{
		if((x == arr1[i]+1 && y ==arr2[i]) || (x == arr1[i]-1 && y == arr2[i])||(x == arr1[i] && y ==arr2[i]+1)||(x == arr1[i] && y ==arr2[i]-1))
		{	
			items[x][y] = "B   ";
			if (x == gx && y== gy)
			{
				items[x][y] = "B G ";
				if((x == ax+1 && y ==ay) || (x == ax-1 && y == ay)||(x == ax && y ==ay+1)||(x == ax && y ==ay-1)) items[x][y] = "BSG ";
			}
			if((x == ax+1 && y ==ay) || (x == ax-1 && y == ay)||(x == ax && y ==ay+1)||(x == ax && y ==ay-1))
			{
				items[x][y] = "BS  ";
				if (x == gx && y== gy) items[x][y] = "BSG ";
			}
		}
	}
}
void printIntro()
{
	std::cout<<"Aldrac Dungeon Simulator\n";
	std::cout<<"Avoid at all costs the pits and the evil Aldrac, cursed be his name.\n";
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


