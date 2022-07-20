// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "uninfected.h"
#include "infected.h"
#include "lounger.h"
#include "hyper.h"
#include "aggressor.h"

#ifndef BUILDING_H
#define BUILDING_H

#define ROW_QTY  10
#define COL_QTY  8


#define LOUNGES  6
#define HYPERS   4
#define AGRESSOR 2

enum class MISSION_STATE { SUCCESS, FAILED, ONGOING };

// this class does not provide UI nor does it contain main. 
class Building
{
    /** stream insertion operator overload */
    friend std::ostream& operator<<(std::ostream&, const Building&);  
    
public:
    /** Building constructor. Initializes the Building */ 
    Building();

    /** move the position of the spec-op
     @ parameter move the direction in which the spec-op must move: must be a valid move
     @ throws invalid_argument exception if move is invalid */ 
    void move(char move);

    /* Get the current state of  the mission*/
    MISSION_STATE get_mission_state();

    /** Building destructor. Deletes all heap based objects (including guards) */
    ~Building();

private:
    std::vector<Infected*> guards;
    Uninfected* specOp;
    Uninfected* scientist;

    bool carrying_scientist;
    MISSION_STATE current_state;
};

#endif