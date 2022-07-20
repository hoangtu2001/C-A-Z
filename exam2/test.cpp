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
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <climits>
#define WINDOWS false

using namespace std;

void clearScreen();
void clearInstream();
void pickRandom(char A[][4]);
int checkNeighbour(char A[][4], int x,int y);
void relax (int x, int y, char A[][4], char C[][4][5]);
int main()
{
        char A[4][4];
        char C[4][4][5], c;
        memset(A[0], ' ', 16);
        memset(C[0][0], ' ', 80);
        for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                        C[i][j][4] = '\0';
        pickRandom(A);
        int valid = 0;
        int x=0, y=0;
        while(true)
        {
                clearScreen();
                cout << "BooBah Dungeon Simulator" << endl;
                cout << "Avoid at all costs the pits and the evil BooBah, cursed be his name" << endl;
                
                C[x][y][0] = 'U';
                relax(x, y, A, C);
                
                for(int i=0; i<4; i++){
                        for(int j=0; j<4; j++)
                                printf("---------");
                        printf("\n");
                        printf("|");
                        for(int j=0; j<4; j++)
                                printf("%8s|", C[i][j]);
                        printf("\n");
                }
                for(int j=0; j<4; j++)
                        printf("---------");
                printf("\n");
                if(valid==1)
                {
                        cout << "Invalid input" << endl;
                        valid = 0;
                }
                else if(valid==2)
                {
                        cout << "picked up the gold" << endl;
                        valid = 3;
                        C[x][y][0] = ' ';
                        x = 0;
                        y = 0;
                        continue;
                }
                else if(valid==3)
                {
                        cout << "You have found the gold" << endl;
                        exit(0);
                }
                cout << "Enter your move" << endl << "(R)ight  (L)eft  (U)p  (D)own (P)ick up gold" << endl;
                
                cin >> c;
                switch(c)
                {
                        case 'D' :      if(x+1 >=4)
                                                        valid = 1;
                                                else
                                                {
                                                        C[x][y][0] = ' ';
                                                        x++;
                                                }
                                                break;
                        case 'U' :      if(x-1 < 0)
                                                        valid = 1;
                                                else
                                                {
                                                        C[x][y][0] = ' ';
                                                        x--;
                                                }
                                                break;
                        case 'L' :      if(y-1 < 0)
                                                        valid = 1;
                                                else
                                                {
                                                        C[x][y][0] = ' ';
                                                        y--;
                                                }
                                                break;
                        case 'R' :      if(y+1 >= 4)
                                                        valid = 1;
                                                else
                                                {
                                                        C[x][y][0] = ' ';
                                                        y++;
                                                }
                                                break;
                        case 'P' :      if(A[x][y]=='G')
                                                        valid = 2;
                                                else
                                                        valid = 1;
                                                break;
                        default  : valid = 1;
                } 
                clearInstream();
        }
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
        cin.clear();
        cin.ignore(INT_MAX, '\n');
}
void pickRandom(char A[][4])
{
        int x, y;
        
        srand(time(NULL));
        for(int i=0; i< 3; i++)
        {
                x = rand()%4;
                y = rand()%4;
                if((x<=1 && y<=1) && (x!=1 || y!=1))
                {
                        i--;
                        continue;
                }
                if(checkNeighbour(A, x, y)==1)
                        A[x][y] = 'X';
                
                else
                {
                        i--;
                        continue;
                }
        }
        while(1)
        {
                x = rand()%4;
                y = rand()%4;
                if((x<=1 && y<=1) && (x!=1 || y!=1))
                        continue;
                
                if(A[x][y]==' ')
                {
                        A[x][y] = 'B';
                        break;
                }
        }
        while(1)
        {
                x = rand()%4;
                y = rand()%4;
                if((x<=1 && y<=1) && (x!=1 || y!=1))
                        continue;
                
                if(A[x][y]==' ')
                {
                        A[x][y] = 'G';
                        break;
                }
        }
}
int checkNeighbour(char A[][4], int x, int y)
{
        if(A[x][y]!=' ')
                return 0;
        if((x-1 >= 0)&&(A[x-1][y]!=' '))
                return 0;
        
        if((x+1 < 4)&&(A[x+1][y]!=' '))
                return 0;
                
        if((y-1 >= 0) && (A[x][y-1]!=' '))
                return 0;
        
        if((y+1 < 4)&&(A[x][y+1]!=' '))
                return 0;
        
        return 1;
}
void relax (int x, int y, char A[][4], char C[][4][5])
{
        if(A[x][y]=='G')
                C[x][y][1] = 'G';
        if((A[x][y]=='B')||(A[x][y]=='X'))
        {
                cout << "GAME OVER" << endl;
                exit(0);
        }
        if(x-1 >= 0)
        {
                if(A[x-1][y] == 'X')
                        C[x][y][2] = 'B';
                if(A[x-1][y] == 'B')
                        C[x][y][3] = 'S';
        }
        if(x+1 < 4)
        {
                if(A[x+1][y] == 'X')
                        C[x][y][2] = 'B';
                if(A[x+1][y] == 'B')
                        C[x][y][3] = 'S';
        }
        if(y-1 >= 0)
        {
                if(A[x][y-1] == 'X')
                        C[x][y][2] = 'B';
                if(A[x][y-1] == 'B')
                        C[x][y][3] = 'S';
        }
        if(y+1 < 4)
        {
                if(A[x][y+1] == 'X')
                        C[x][y][2] = 'B';
                if(A[x][y+1] == 'B')
                        C[x][y][3] = 'S';
        }
}
