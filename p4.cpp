#include<iostream>
#include<vector>
#include<structs.h>

using namespace std;

// function to show the board
void show(vector<vector<char>> tab){
    for (unsigned i=0; i<6; ++i) {
        for (unsigned j=0; j<7; ++j) {
            cout << tab[i][j];
        }
        cout << endl;
    }
    cout << "1234567  ";
}

// check for a particular direction how many 'playerChar' pieces we have
unsigned subCheckWin(vector<vector<char>> tab, char playerChar, int row, int col, int vecX, int vecY){
    unsigned subCount=0;
    while(true) {
        row += vecX;
        col += vecY;
        if (0 <= row && row < 6 && 0 <= col && col < 7) { // bound checking
            if (tab[row][col] == playerChar) {
                ++subCount;
                continue;
            }
        }
        return subCount;
    }
}

unsigned connect4(const player& p1, const player& p2){
    unsigned currentPlayer=1;
    vector<vector<char>> tab(6, vector<char>(7, ' '));

    int row, col;
    while (true) {
        cout << "Au tour de ";
        if(currentPlayer==1)cout << p1.surname;
        else cout << p2.surname;
        cout << endl;

        show(tab);
        cin >> col;
        --col;

        // bound checking + check if column is already full
        if(col < 0 || col > 6 || tab[0][col]!=' '){
            continue;
        }

        // checking where to put the piece
        row = 5;
        while(tab[row][col] != ' '){
            --row;
        }

        char currentChar;
        if(currentPlayer==1){
            currentChar  = 'x';
        }else{
            currentChar = 'o';
        }
        tab[row][col] = currentChar;


        int vecs[4][2] = { {1,0}, {0,1}, {1,1}, {1, -1} }; // vectors of direction to check to win
        unsigned count;
        for(unsigned i=0;i<4;++i){
            count=1;
            count+=subCheckWin(tab, currentChar, row, col, vecs[i][0], vecs[i][1]);
            count+=subCheckWin(tab, currentChar, row, col,-vecs[i][0],-vecs[i][1]);
            if(count>=4){ // the line is 4 or more ? you win !
                show(tab);

                if(currentPlayer==1) {
                    cout << p1.surname << " gagne !" << endl;
                }else{
                    cout << p2.surname << " gagne !" << endl;
                }
                return currentPlayer;
            }
        }
        currentPlayer = 3 - currentPlayer; // switch player
    }
}
