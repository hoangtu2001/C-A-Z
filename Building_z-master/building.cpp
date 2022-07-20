#include "building.h"

Building::Building(){
    // create a random seed for randomization
    srand( time(NULL) );

    // The spec-op (O) always start at (0, 0)
    specOp = new Uninfected(Position(0, 0), 'O');

    // The scientist (S) is in 1 of the four rooms in the middle
    size_t scientist_x = rand()%2 + 3;
    size_t scientist_y = rand()%2 + 4;
    scientist = new Uninfected(Position(scientist_x, scientist_y), 'S');

    // 6 Loungers randomly distributed around the building
    for (int i = 0; i < LOUNGES; i ++){
        size_t lounger_x = rand()%8;
        size_t lounger_y = rand()%10;
        // a lounger shouldn't start at (0, 0), if it does, move it to the right room
        if (lounger_x == 0 && lounger_y == 0)
            lounger_x = 1;
        
        guards.push_back( new Lounger( Position(lounger_x, lounger_y)) );
    }

    // 4 Hypers randomly distributed around the building
    for (int i = 0; i < HYPERS; i ++){
        size_t hyper_x = rand()%8;
        size_t hyper_y = rand()%10;
        // a hyper shouldn't start at (0, 0), if it does, move it to the right room
        if (hyper_x == 0 && hyper_y == 0)
            hyper_x = 1;
        
        guards.push_back( new Hyper( Position(hyper_x, hyper_y)) );
    }

    // 2 Aggressors randomly distributed around the building
    for (int i = 0; i < AGRESSOR; i ++){
        size_t aggressor_x = rand()%8;
        size_t aggressor_y = rand()%10;
        // an aggressor shouldn't start at (0, 0), if it does, move it down a room
        if (aggressor_x == 0 && aggressor_y == 0)
            aggressor_y = 1;
        
        guards.push_back( new Aggressor( Position(aggressor_x, aggressor_y), *specOp) );
    }

    // The state at the start of the mission is ONGOING
    current_state = MISSION_STATE::ONGOING;

}

void Building::move(char move){
    // if the move is not pause/ carry, call the specOp move()
    if (move != 'C')
        specOp -> move(move);
    // if the move is "Carry", check
    else{
        // if the scientist is not being carried
        if (!carrying_scientist){
            // and if specOp is in the same room with the scientist
            if (*specOp == *scientist)
                // then start carrying the scientist
                carrying_scientist = true;          
        }
        // else do nothing
    }

    // if the scientist is being carried and the move is not 'C'
    if (carrying_scientist && move != 'C'){
        // then move the scientist with the specOp
        scientist -> move (move);
    }

    // after the specOp moved, all the guards try to move as well
    for (auto guard: guards){
        guard -> move();
        // if a guard moves into the room with the specOp, the mission is failed
        if (*guard == *specOp){
            current_state = MISSION_STATE::FAILED;
        }
    }

    // If the scientist reach (0, 0), the mission is completed
    Position scientist_pos (scientist -> getPosition().x, scientist -> getPosition().y);
    if (scientist_pos.x == 0 && scientist_pos.y == 0){
        current_state = MISSION_STATE::SUCCESS;
    }
}

MISSION_STATE Building::get_mission_state(){
    return current_state;
}

Building::~Building(){
    delete specOp;
    delete scientist;
    for (int i = 0; i < guards.size(); i++)
        delete guards[i];
}

std::ostream& operator<<(std::ostream& os, const Building& building){

    // create a marker vector to mark the current position of all people in the building
    std::vector< std::vector<int> > marker (ROW_QTY, std::vector<int> (COL_QTY, 1));

    // We associate each type of person with a prime number
    /*
        specOp   : 2
        scientist: 3
        lounger  : 5
        hyper    : 7
        aggressor: 11
    */
   // if a person is in a room, multiply the marker number by that person's associated number
    Position specOp_pos ( building.specOp -> getPosition().x, building.specOp -> getPosition().y);
    marker[specOp_pos.y][specOp_pos.x] *= 2;

    Position scientist_pos ( building.scientist -> getPosition().x, building.scientist -> getPosition().y);
    marker[scientist_pos.y][scientist_pos.x] *= 3;

    for (auto guard : building.guards){
        Position guard_pos (guard -> getPosition().x, guard -> getPosition().y);
        switch(guard -> getType()){
            case 'L':
                marker[guard_pos.y][guard_pos.x] *= 5;
                break;
            case 'H':
                marker[guard_pos.y][guard_pos.x] *= 7;
                break;
            case 'A':
                marker[guard_pos.y][guard_pos.x] *= 11;
                break;
        }
    }

    // input into the outstream
    os << "Rescue mission in progress\n";
    os << std::string (33, '-') << "\n";
    for (int i = 0; i < ROW_QTY; i++){
        // if the marker at [i][j] divides a person's associated number, that person is in the room

        os << "|";
        for (int j = 0; j < COL_QTY; j++){
            if (marker[i][j] % 5 == 0) os << 'L';
            else os << ' ';

            if (marker[i][j] % 7 == 0) os << 'H';
            else os << ' ';

            if (marker[i][j] % 11 == 0) os << 'A';
            else os << ' ';
             
            os << "|";
        }

        os << "\n|";
        for (int j = 0; j < COL_QTY; j++){
            if (marker[i][j] % 2 == 0) os << 'O';
            else os << ' ';

            if (marker[i][j] % 3 == 0) os << 'S';
            else os << ' ';
             
            os << " |";
        }
        os << "\n" << std::string (33, '-') << "\n";
    }

    return os;
}