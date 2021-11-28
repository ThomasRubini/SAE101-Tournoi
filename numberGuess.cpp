#include <string>
#include <iostream>
#include<structs.h>

using namespace std;

unsigned askNumber(){
    string verify;
    while(true){
        cin >> verify;
        try {
            return stoi(verify);
        }catch(logic_error& e) {
            cout << "nombre invalide !" << endl;
        }
    }
}

unsigned guessTheNumber(const player& p1, const player& p2){

    // number to find
    unsigned numberToFind = rand()%500;

    // answer that the players input
    unsigned answer = 0;

    // current player's id (will switch every turn)
    unsigned playerNumber = 1;

    cout << "il faut trouver un nombre" << endl ;
    while (true){

        if (playerNumber==1){
            cout << p1.surname << " écrit ta proposition : ";
        }else{
            cout << p2.surname << " écrit ta proposition : ";
        }

        answer = askNumber(); // ask the player to input a number

        // checking if the answer if right, too high or too low
        if (answer > numberToFind ){
            cout << "Plus petit" << endl ;
        }else if (answer < numberToFind ){
            cout << "Plus grand" << endl ;
        }else if (answer == numberToFind){
            if (playerNumber == 1){
                cout << p1.surname << " gagne !" << endl ;
            }else{
                cout << p2.surname << " gagne !" << endl ;
            }
            return playerNumber; // return winner's id
        }

        playerNumber = 3 - playerNumber; // switch player (if 1 then 2, and if 2 then 1)
    }

}
