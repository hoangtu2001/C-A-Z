// who: Hoang Tu Huynh
// what: Board Game: Aldrac Dungeon Simulator
// why: Lab Project 2
// when: May 3
#ifndef ODIUMS_MANSION_H
#define  ODIUMS_MANSION_H
// If you are on a Microsoft Windows PC, set this to true
//  otherwise, leave it as false
#define WINDOWS false  
void clearScreen();
void clearInstream();
void initialize_player( std::string player[8][8], int, int);
void initialize_item(std::string items[8][8], int, int, int, int, int, int, int arr1[12], int arr2[12]);
void game_on();
void printIntro();


struct GridObject
{
	int x;
	int y;
};

struct AldracObject
{
	int a;
	int b;
};
struct PitObjects
{
	int x1[12];
	int y1[12];
};

struct GoldObject
{
	int gx;
	int gy;
};


struct Grid
{
	int totalX;
	int totalY;
	
	void Render(std::string items[8][8], GridObject obj)
	{
		
		std::string player[8][8];
		initialize_player(player, obj.x, obj.y);

		for (int col = 0; col < totalY; col++)
        {
            for (int row = 0; row < totalX; row++)
                std::cout<<"-----";
            std::cout<<"\n";
            for (int row = 0; row < totalX; row++)
            {   std::cout<<"|";
                std::cout<<items[row][col];
            }
            std::cout<<"|";             
			std::cout<<"\n";
            for (int row = 0; row < totalX; row++)
            {    
                std::cout<<"|";  
			   	std::cout<<player[row][col];
                
            } 
			std::cout<<"|";  
            std::cout<<"\n";
			
        } 
		std::cout<<"-----------------------------------------"<<std::endl;
	}
};

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

struct Random_obj
{
	int arr1[2][14];
	
	void create_random_object()
	{
		srand(static_cast<unsigned int>(time(NULL)));
		for(int r = 0; r<2; r++)
		{
			for(int c = 0; c<14; c++)
			{
				arr1[r][c] = 1+ (rand() % 7);
				
			}
		}
	}

};

#endif