/*
  This is a template for MCD4720_Assignment 2
  Created by: Haidar AL-Khalidi
 */
#include "mainDriver.h"

int main() {
    srand(time(0));
    runMenu();
    // Player p1("Alice");
    // p1.displayCard();
    // p1.saveCard();
    return 0;
}

void runMenu() {
    int option;
    do {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "    Programming Fundamental Concepts" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "[1] Ending The Program" <<endl;
    cout << "[2] Display \"Game Rules\" Information" << endl;
    cout << "[3] Generate Bingo Card(s)" << endl;
    cout << "[4] Creat Virtual Players" << endl;
    cout << "[5] Bingo Caller (Call for numbers)" << endl;
    cout << "[6]Display the Reflection Report" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Which option would you like (1-6): ";
    cin >> option;

    //run the option that you choose
    switch (option) {
        case 1: {
            break;
        }
        case 2: {
            displayText();
            break;
        }
        case 3: {
            int cardNumber;
            cout << "How many card would you like to generate? : " ;
            cin >> cardNumber;
            generateBingoCard(cardNumber, {});
            break;
        }
        case 4: {
            createVirtualPlayers();
            break;
        }
        case 5: {
            bingoCaller();
            break;
        }
        case 6: {
            displayReport();
            break;
        }
        default:
            cout << "Please choose one of the above option" << endl;
    }
    }while (option != 1);
}            //while option is not 1 then continue

void displayText() {
    ifstream readFile;
    string str;
    readFile.open("../gameRules.txt");

    if(readFile.is_open()){

        while(!readFile.eof()){                //'end of file'

            getline(readFile,str);      //read the whole line
            cout << str << endl;
        }
        readFile.close();
    }
    else
        cout << "Please check the file" << endl;
}

void generateBingoCard(int cardNumber, vector<Player> players) {
    vector<Card> cards;
    ofstream file("../CardsGenerated.txt");
    for (int i = 0; i < cardNumber; i++) {
        cout << "Card " << i+1 << endl;
        cout << "**********************" << endl;
        Card card;
        card.printCard();
        card.saveCardToFile("Card " + to_string(i+1) );
        cout << "**********************" << endl;
        cout << "\n---------------------------" << endl;
        cards.push_back(card);

        if (file.is_open()) {
            if (!players.empty()) {
                file << players[i].getName() << endl;
            }

            file << "****************************" << endl;
            file << " B   I   N   G   O" << endl;
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    file << card.getCard() << "\t";
                }
                file << endl;
            }
            file << "****************************" << endl;
            file << endl;
            file.close();
        }
        if (!players.empty()) {
            players[i].setcard(card);
        }
    }
    cout << "These " << cardNumber << " card(s) now saved into CardGenerated.txt files" << endl;
}

void createVirtualPlayers() {
    int playerNumber;
    vector<Player> players;
    vector<string> playerNames;
    cout << "Welcome to Bingo-75" << endl;
    cout << "How many player would you like to generate? : " ;
    cin >> playerNumber;
    cin.ignore();
    for (int i=0; i<playerNumber; i++) {
        string name;
        cout << "Please enter the name of Player " << i+1 << " : ";
        getline(cin, name);
        playerNames.push_back(name);
        players.push_back(Player(name));
    }
    for (int i = 0; i < playerNumber; i++) {
        int cardNumber;

        cout << "Player " << i+1 << endl;
        cout << "****************************" << endl;
        cout << "* Player Name is: " << playerNames[i] << endl;

        cout << "How many card would you like to generate? : " ;
        cin >> cardNumber;

        cout << "* Card is: " << endl;

        //generateBingoCard(cardNumber);

        for (int j=0; j<cardNumber; j++) {

            cout << "Card " << j+1 << endl;
            Card c;
            c.printCard();
            cout << endl;
        }
        cout << "****************************" << endl;
    }
}

void bingoCaller() {
    vector<int> calledNumbers;
    bool used[76] = {false}; //initial used[76] to 'false'
    char choice = 'y'; //initial choice to y

    //if you haven't called all numbers from 1-75 and choice = y or Y, do the while loop
    while (calledNumbers.size() < 75 && (choice == 'y' || choice == 'Y')) {
        int number;
        do {
            number = rand() % 75+1;
        }while (used[number]);  //if the number is already used the do it again

        //turn the number that have been called to true
        used[number] = true;
        calledNumbers.push_back(number);

        //Display the final called numbers with their prefix letter (B, I, N, G, O).
        char charBingo;
        if (number <= 15)
            charBingo = 'B';
        else if (number <= 30)
            charBingo = 'I';
        else if (number <= 45)
            charBingo = 'N';
        else if (number <= 60)
            charBingo = 'G';
        else
            charBingo = 'O';

        cout << "The called number is " << charBingo << number << " cross it on your card" << endl;
        cout << "These number have been called" << endl;

        //sort the numbers in vector from small to big
        for (int i = 0; i < calledNumbers.size()-1; i++) {
            for (int j = 0; j < calledNumbers.size()- 1-i; j++) {
                if (calledNumbers[j] > calledNumbers[j + 1]) {
                    // switch
                    int num = calledNumbers[j];
                    calledNumbers[j] = calledNumbers[j + 1];
                    calledNumbers[j + 1] = num;
                }
            }
        }

        for (int i = 0; i < calledNumbers.size(); i++) {
            cout << "******";
        }

        cout << endl;

        //print the vector
        for (int i = 0; i < calledNumbers.size(); ++i) {
            int num = calledNumbers[i];
            char prefix;
            if (num <= 15)
                prefix = 'B';
            else if (num <= 30)
                prefix = 'I';
            else if (num <= 45)
                prefix = 'N';
            else if (num <= 60)
                prefix = 'G';
            else
                prefix = 'O';
            cout << "  " << prefix << num << " ";
        }

        cout << endl;

        for (int i = 0; i < calledNumbers.size(); i++) {
            cout << "******";
        }

        cout << "\nCall Next Number Press [y] or BINGO Press [any key] ";
        cin >> choice;
    }

    //print BINGO
    ifstream readFile;
    string str;
    readFile.open("../BINGO.txt");

    if(readFile.is_open()){

        while(!readFile.eof()){                //'end of file'

            getline(readFile,str);      //read the whole line
            cout << str << endl;
        }
        readFile.close();
    }
    else
        cout << "Please check the file" << endl;

    //show who is the winner
    string winnerName;
    cout << "Who is the winner? ";
    cin >> winnerName;
    cout << "Congratulations " << winnerName << " you did it" << endl;
    cout << "All of the players: thank you for playing BINGO" << endl;
}

void displayReport() {
    ifstream readFile;
    string str;
    readFile.open("../ReflectionReport.txt");

    if(readFile.is_open()){

        while(!readFile.eof()){                //'end of file'

            getline(readFile,str);      //read the whole line
            cout << str << endl;
        }
        readFile.close();
    }
    else
        cout << "Please check the file" << endl;
}
