/*
  This is a template for MCD4720_Assignment 2
  Created by: Haidar AL-Khalidi
 */

#ifndef MAINDRIVER_H
#define MAINDRIVER_H
#include <iostream>
#include <fstream>
#include "Card.h"
#include "Player.h"
using namespace std;
void runMenu();
void displayText();
void generateBingoCard(int cardNumber, vector<Player> players);
void createVirtualPlayers();
void bingoCaller();
void displayReport();
#endif //MAINDRIVER_H
