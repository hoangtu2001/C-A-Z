#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include "dungeon.h"
#include "position.h"


Dungeon::Dungeon(){init();}

void Dungeon::init()
{
    user = {0, 0};
    initPercept();
    initArtifacts();
    hasGold = false;
    state  = IN_PLAY;
}

void Dungeon::initPercept()
{
    for(size_t row{0}; row < ROW_QTY; ++row)
        for(size_t col{0}; col < COL_QTY; ++col)
            percept[row][col] = "     ";
}

void Dungeon::initArtifacts()
{
    Position p;

    initDungeon();
    initPits();
    p = getrandomPosition();
    artifacts[p.x][p.y] = ALDRAC;
    p = getrandomPosition();
    artifacts[p.x][p.y] = GOLD;

}

void Dungeon::initPits()
{
    Position p;

    for(size_t i{0}; i < PIT_QTY; ++i)
    {
        p = getrandomPosition();
        artifacts[p.x][p.y] = PIT;
    }    

}

void Dungeon::update()
{
   //set game state (win lose inplay)
   //update percepts
   updateState();
   updatePercepts();
}

void Dungeon::initDungeon()
{
    for(size_t row  =0; row<ROW_QTY; ++row)
        for(size_t col  =0; col<COL_QTY; ++col)
            artifacts[row][col] = EMPTY;
}

Position Dungeon::getrandomPosition() const
{
    int count{0};
    int px;
    int py;

    do
    {
        px = randomRange(0, ROW_QTY);
        py = randomRange(0, COL_QTY);
    }while(artifacts[px][py] != EMPTY || px + py <= 1);

    return {px, py};
}

int Dungeon::randomRange(int start, int end) const { return rand() % (end - start + 1) + start; }

bool Dungeon::isValidMove(const Position& dest) const
{
    return (abs(user.x - dest.x) + abs(user.y - dest.y) < 2)
        && dest.x >= 0 && dest.y >= 0
        && dest.x < ROW_QTY && dest.y < COL_QTY;
}

void Dungeon::move(const Position& dest)
{
    if(!isValidMove(dest))
        throw std::invalid_argument("Bad move!");
    user = dest;
    update();

}

void Dungeon::pickup()
{
    if(artifacts[user.x][user.y] != GOLD)
        throw std::invalid_argument("Bad move!");
    hasGold = true;   
}
std::string getDivider()
{
    std::stringstream ss;
    for (size_t i = 0; i < COL_QTY; ++i)
    {
        ss<"-----";
    }
    ss<<'-';
    return ss.str();
    
}
std::string Dungeon::toString()
{
    std::stringstream ss;
    for (size_t row = 0; row < ROW_QTY; ++row)
    {
        ss<< getDivider() << std::endl;
        for (size_t col = 0; col < COL_QTY; ++col)
        {
            ss<< '|'<<percept[row][col]
        }
        ss<< '|';

        for (size_t col = 0; col < COL_QTY; ++col)
        {
            ss<<((user.x == row && user.y == col)? "| U  ": "|    ");
        }
        ss<<'|\n';
    }
    ss<<getDivider()<<std::endl;
    ss <<((hasGold)?"You are carrying the gold\n"::"\n");
    return ss.str();
}

void Dungeon::updateState()
{
    if(artifacts[user.x][user.y] == EMPTY || artifacts[user.x][user.y] == GOLD) state = IN_PLAY;
    else if(artifacts[user.x][user.y] != EMPTY) state = LOSE;

    if(hasGold && user.x == 0 && user.y == 0) state = WIN;
}
void Dungeon::updatePercepts()
{
    Position p{user};
    Artifact a[4]{};
    std::string* userPecept{&percept[user.x][user.y]};

    if(artifacts[p.x][p.y] == GOLD) userPecept[2] = 'G' ;

    for (size_t i = -1; i < 2; i+=2)
    {
        if(isValidMove({p.x+i, p.y}))
        {
            if(artifacts[p.x+i][p.y] == ALDRAC) userPecept[0] = 'S' ;
            if(artifacts[p.x+i][p.y] == PIT) userPecept[4] = 'B' ;
        }
        if(isValidMove({p.x, p.y+i}))
        {
            if(artifacts[p.x][p.y+i] == ALDRAC) userPecept[0] = 'S' ;
            if(artifacts[p.x][p.y +i] == PIT) userPecept[4] = 'B' ;
        }
    
    }
}

friend std::ostream& operator<<(std::ostream& out, Dungeon& d)
{
    return (out<< d.toString());
}