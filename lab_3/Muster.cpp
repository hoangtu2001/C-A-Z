/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what: Exam 1 project: Muster game
// why: Exam 1
// when: 3/4/2022
// includes go here
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <random>

int random_generator(void);
void gameProcess(void);
int player1_roll(int);
int savePlayer1(int);
int player2_roll(int);
int savePlayer2(int);


int main(int argc, char const *argv[])
{
    bool play = true;
    char c;
    int point1, point2;
    srand(static_cast<unsigned int>(time(NULL)));

    //introduction
    std::cout<<"Welcome to Muster!"<<std::endl;
    std::cout<<"The first player to reach 1000 and exceed the other players score wins."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Scoring: "<<std::endl;
    std::cout<<"\t1\t\t\t 2 points"<<std::endl;
    std::cout<<"\t5\t\t\t 5 points"<<std::endl;
    std::cout<<"\tThree 1's\t\t 10 points"<<std::endl;
    std::cout<<"\tThree 2's\t\t 20 points"<<std::endl;
    std::cout<<"\tThree 3's\t\t 30 points"<<std::endl;
    std::cout<<"\tThree 4's\t\t 40 points"<<std::endl;
    std::cout<<"\tThree 5's\t\t 50 points"<<std::endl;
    std::cout<<"\tThree 6's\t\t 60 points"<<std::endl;
    std::cout<<"\t1-2-3-4-5-6\t\t 300 points"<<std::endl;
    std::cout<<"\t3 Pairs\t\t\t 150 points (including 4-of-a-kind and a pair)"<<std::endl;
    std::cout<<std::endl;

    // Game starts
    while(play)
    {
        std::cout<<"Would you like to play (Y/N)? ";
        std::cin>>c;
        if (c == 'Y')
        {
            char cont;
            gameProcess(); // If yes, play game in function
            std::cout<<std::endl;
            std::cout<<"Would you like to play again (Y/N)? ";
            std::cin>>cont;
            if(cont == 'Y') continue;
            else break;
        }
        else
        {
            play = false; // break out of the loop
            break;
        }
        
    }
    //conclusion
    std::cout<<std::endl;
    std::cout<<"---- Hasta La Vista Baby ----"<<std::endl;
    return 0;
}

// random generator with 6-sided dice
int random_generator()
{
    static std::random_device rd;
    static std::default_random_engine rndEng(rd());
    static std::uniform_int_distribution<int> uniformDist(1, 6);

    return uniformDist(rndEng);
}

// taking the name and time for rolling the dice
void gameProcess()
{
    std::string name1;
    std::string name2;
    int point1 = 0, point2 = 0;
    int turn = 1;
    int time1, time2;
    int point_one_final = 0, point_two_final = 0;

    // taking player's name
    std::cout<<"Enter the first player's name: ";
    std::cin>>name1;
    std::cout<<"Enter the second player's name: ";
    std::cin>>name2;
    std::cout<<std::endl;

    //printing the initial score
    std::cout<<"The scores are: "<<std::endl;
    std::cout<<"\t"<<name1<<": "<<"\t\t"<<point1<<std::endl;
    std::cout<<"\t"<<name2<<": "<<"\t\t"<<point2<<std::endl;

    while(point1 < 1000 || point2 < 1000)
    {
        std::cout<<"Turn "<<turn<<std::endl;
        std::cout<<"--------"<<std::endl;
        std::cout<<std::endl;

        std::cout<<"\tHow many times would "<<name1<<" like to shake the dice? "; //asking for times
        std::cin>>time1;
        point1 = savePlayer1(player1_roll(time1)); //using the savePlayer function to keep the point of player after the value return from player1_roll function
        std::cout<<"\t"<<name1<<" earns "<<point1<<" point(s)"<<std::endl;
        std::cout<<std::endl;
        point_one_final+=point1;

        std::cout<<"\tHow many times would "<<name2<<" like to shake the dice? "; // asking for times
        std::cin>>time2;
        point2 = savePlayer1(player2_roll(time2)); //using the savePlayer function to keep the point of player after the value return from player2_roll function
        std::cout<<"\t"<<name2<<" earns "<<point2<<" point(s)"<<std::endl;
        std::cout<<std::endl;
        point_two_final+=point2;

        std::cout<<"The scores are: "<<std::endl;
        std::cout<<"\t"<<name1<<": "<<"\t\t"<<point_one_final<<std::endl;
        std::cout<<"\t"<<name2<<": "<<"\t\t"<<point_two_final<<std::endl;

        if(point_one_final>=1000 || point_two_final>=1000) //compare two player'spoint
        {
            if(point_one_final == point_two_final)
            {
                continue; // continue if their point is the same
            }
            else break;
        }
        turn++;
    }

    // chosing the winner
    std::cout<<std::endl;
    if(point_one_final>point_two_final) std::cout<<name1<<" wins!"<<std::endl;
    else std::cout<<name2<<" wins!"<<std::endl; 
}

int player1_roll(int n)
{
    
    int list[6]; // using array
    int new_list[6]; // the second array for saving the array having the greatest possible point
    int point  = 0;
    int temp = 0;

    for(int i = 1; i<=n; i++) // roll n times, 6 dice for each time
    {
        int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
        int pair = 0;
        for(int j = 0; j <= 5; j++) // roll 6 dice
        {
            list[j] = random_generator();
            if(list[j] == 1) one++;
            else if(list[j] == 2) two++;
            else if(list[j] == 3) three++;
            else if(list[j] == 4) four++;
            else if(list[j] == 5) five++;
            else six++;
        }

        // counting for the 3-pair situation
        if(one == 2)pair++;
        else if(one == 4) pair = pair+2;
        if(two == 2)pair++;
        else if(two == 4) pair = pair+2;
        if(three == 2)pair++;
        else if(three == 4) pair = pair+2;
        if(four == 2)pair++;
        else if(four == 4) pair = pair+2;
        if(five == 2)pair++;
        else if(five == 4) pair = pair+2;
        if(six == 2)pair++;
        else if(six == 4) pair = pair+2;
        
        // assign from the big to the small
        if(list[0] == 1 && list[1] == 2 && list[2] == 3 && list[3] == 4 && list[4] == 5 && list[5] == 6) point = 300;
        else if(pair == 3) point = 150;
        else if(six >= 3) point = 60;
        else if(five >= 3) point = 50;
        else if(four>=3) point = 40;
        else if(three >= 3) point = 30;
        else if(two >= 3) point = 20;
        else if(one >= 3) point = 10;
        else if(five <= 2 && five>0) point = 5;
        else if(one <= 2 && one>0) point = 2;

        if (temp < point)
        {
            
            temp = point; // temp will hold the biggest value
            point = 0; // reset point
            for(int l = 0; l <= 5; l++)
            {
                new_list[l] = list[l]; // keep the list having greatest possible point
            }
        }
    }

    std::cout<<"\tThe roll is: ";
    for(int k = 0; k<=5; k++) std::cout<<new_list[k]<<" "; // printing the list
    std::cout<<std::endl;
   
    return temp;
}

// player 2 using the same method as above
int player2_roll(int n)
{
    
    int list[6];
    int new_list[6];
    int point  = 0;
    int temp = 0;

    for(int i = 1; i<=n; i++)
    {
        int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
        int pair = 0;

        for(int j = 0; j <= 5; j++)
        {
            list[j] = random_generator();
            if(list[j] == 1) one++;
            else if(list[j] == 2) two++;
            else if(list[j] == 3) three++;
            else if(list[j] == 4) four++;
            else if(list[j] == 5) five++;
            else six++;
        }
        
        if(one == 2)pair++;
        else if(one == 4) pair = pair+2;
        if(two == 2)pair++;
        else if(two == 4) pair = pair+2;
        if(three == 2)pair++;
        else if(three == 4) pair = pair+2;
        if(four == 2)pair++;
        else if(four == 4) pair = pair+2;
        if(five == 2)pair++;
        else if(five == 4) pair = pair+2;
        if(six == 2)pair++;
        else if(six == 4) pair = pair+2;
        
        if(list[0] == 1 && list[1] == 2 && list[2] == 3 && list[3] == 4 && list[4] == 5 && list[5] == 6) point = 300;
        else if(pair == 3) point = 150;
        else if(six >= 3) point = 60;
        else if(five >= 3) point = 50;
        else if(four>=3) point = 40;
        else if(three >= 3) point = 30;
        else if(two >= 3) point = 20;
        else if(one >= 3) point = 10;
        else if(five <= 2 && five>0) point = 5;
        else if(one <= 2 && one>0) point = 2;

        if (temp < point)
        {
            temp = point; // temp will hold the biggest value
            point = 0; // reset point
            for(int l = 0; l <= 5; l++)
            {
                new_list[l] = list[l];
            }
        }
    }

    std::cout<<"\tThe roll is: ";
    for(int k = 0; k<=5; k++) std::cout<<new_list[k]<<" ";
    std::cout<<std::endl;
    
    return temp;
}

// save the point for player 1
int savePlayer1(int temp)
{
    int point = 0;
    point = temp;
    return point;
}

// save the point for player 2
int savePlayer2(int temp)
{
    int point = 0;
    point = temp;
    return point;
}