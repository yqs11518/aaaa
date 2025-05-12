#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
    name = "Unknown";
}

Player::Player(string playerName) {
    name = playerName;
}

Player::~Player(){}

Card Player::getcard() {
    return card;
}

void Player::setcard(Card newcard) {
    card = newcard;
}

void Player::displayCard() {
    cout << "Player: " << name << endl;
    card.printCard();
}

void Player::saveCard() {
    card.saveCardToFile(name);
}

void Player::setName(string newName) {
    name = newName;
}

string Player::getName() {
    return name;
}

