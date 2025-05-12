#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
private:
    int grid[5][5];

public:
    Card();
    ~Card();
    int* getCard();
    void generateCard();
    void printCard();
    void saveCardToFile(string playerName);
};

#endif
