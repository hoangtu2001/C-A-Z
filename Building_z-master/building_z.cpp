#include "building.h"

void mainLoop();
void missionLoop();

int main()
{
    mainLoop();
    return 0;
}

void mainLoop(){
    char running;
    std::cout << "Do you want to start BUILDING_Z? (y/n): "; std::cin >> running;

    while (running == 'y'){
        missionLoop();
        std::cout << "Do you want to play again? (y/n): "; std::cin >> running;
    }
}

void missionLoop(){
    Building buildingZ;
    std::string error_msg = "";
    while (buildingZ.get_mission_state() == MISSION_STATE::ONGOING){
        std::cout << "\x1B[2J\x1B[H";
        std::cout << buildingZ << std::endl;

        char move;
        std::cout << error_msg << "\n";
        std::cout << "Your move [N, S, W, E, P, C]: "; std::cin >> move;
        move  = toupper(move); // Upper case char 
        error_msg = "";
        try{
            buildingZ.move(move);
        }
        catch(std::invalid_argument& ia){
            error_msg = "Invalid argument: " + std::string (ia.what());
        }
    }

    std::cout << "\x1B[2J\x1B[H";
    std::cout << buildingZ << std::endl;

    if (buildingZ.get_mission_state() == MISSION_STATE::SUCCESS){
        std::cout << "CONGRATULATION! You have completed the mission and save the humanity!\n";
    }
    else
        std::cout << "OOPS! You were attacked by the infected and failed the mission.\nTry harder next time.\n";
}
