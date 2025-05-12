#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Card.h"
using namespace std;

class Player {
private:
    string name;
    Card card;

public:
    Player();
    Player(string playerName);
    ~Player();
    Card getcard();
    void setcard(Card card);
    void displayCard();
    void saveCard();
    string getName();
    void setName(string newName);
};

#endif