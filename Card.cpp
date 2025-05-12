/*
  This is a template for MCD4720_Assignment 2
  Created by: Haidar AL-Khalidi
 */

#include "Card.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

Card::Card() {
    // initialisze
    generateCard();
}

Card::~Card() {}

int* Card::getCard() {
    int* ptrGrid = new int[5];
    for (int i = 0; i < 5; i++) {
        // ptrGrid[i] = grid[i];
        int* partGrid = new int[5];
        for (int j = 0; j < 5; j++) {
            partGrid[j] = grid[i][j];
        }
        ptrGrid[i] = *partGrid;
    }
    return ptrGrid;
}

void Card::generateCard() {
    for (int col = 0; col < 5; col++) {
        int min = col * 15 + 1;
        int max = min + 14;
        int numbers[5];
        int count = 0;

        while (count < 5) {
            int num = rand() % (max - min + 1) + min;
            bool exists = false;

            // check is the number in the array or not
            for (int i = 0; i < count; i++) {
                if (numbers[i] == num) {
                    exists = true;
                    break;
                }
            }

            // if not exist then store
            if (!exists) {
                numbers[count] = num;
                count++;
            }
        }
        grid[2][2] = 0;  // center free space
        // for (int row = 0; row < 5; row++) {
        //     if (col == 2 && row == 2) {
        //
        //     } else {
        //         if (numbers[row] < 10) {
        //             grid[row][col] = "0" + to_string(numbers[row]); //if number<10 then add 0 in the beginning
        //         } else {
        //             grid[row][col] = to_string(numbers[row]);
        //         }
        //     }
        // }
    }
}

void Card::printCard() {
    cout << " B   I   N   G   O" << endl;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            cout << grid[row][col] << "\t";
        }
        cout << endl;
    }
}

void Card::saveCardToFile(string playerName) {

}


