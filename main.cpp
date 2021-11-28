#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<structs.h>

using namespace std;

// structures used

// function used to sort teams
bool orderByScore(const team& left, const team& right) {
    return left.score < right.score;
}

// include games from their files
unsigned shifumi(const player& p1, const player& p2);
unsigned connect4(const player& p1, const player& p2);
unsigned pendu(const player& p1, const player& p2);
unsigned guessTheNumber(const player& p1, const player& p2);

#define GAMES_NUMBER 5

// battle two teams and update their scores
void randomBattle(unsigned gameID, team& team1, team& team2){
    player& p1 = team1.members[rand()%team1.members.size()];
    player& p2 = team2.members[rand()%team2.members.size()];
    cout << p1.surname << " " << p1.lastname << " et " << p2.surname << " " << p2.lastname << " s'affronteront dans ";
    unsigned winner=0; // this value should never be used, but Qt Creator complains about it because of no default case
    switch(gameID){ // game selector
        case 0:{
            cout << "Shifumi" << endl;
            winner = shifumi(p1, p2);
            break;
        }
        case 1:{
            cout << "Puissance 4" << endl;
            winner = connect4(p1, p2);
            break;
        }
        case 2:{
            cout << "Pendu" << endl;
            winner = pendu(p1, p2);
            break;
        }
        case 3:{
            cout << "Juste Prix" << endl;
            winner = guessTheNumber(p1, p2);
            break;
        }
        case 4:{
            cout << "Pile ou Face" << endl ;
            if(rand()%2==1)winner=1;
            else winner=2;
            break;
        }
    }

    // manage the teams' scores
    if(winner==1){
        cout << p1.surname << " gagne !" << endl;
        ++team1.score;
    }else if(winner==2){
        cout << p2.surname << " gagne !" << endl;
        ++team2.score;
    }else{
        cout << "Egalité !" << endl;
        team1.score+=0.5;
        team2.score+=0.5;
    }
}

// Swiss system

int main(){
    cout << "Entrer la seed : ";
    int seed;
    cin >> seed;
    srand(seed);

    getchar(); // thx cin to not remove the newline character. it is detected by the getline()

    cout << "Début de la configuration des équipes" << endl;

    vector<team> teams;
    char teamName = 'A';

    // loop to create teams
    while(true){
        cout << "Team " << teamName << " : " << endl;
        team currentTeam;
        currentTeam.name = teamName;

        // loop to create players inside teams
        while(true){
            player currentPlayer;
            cout << "Entrer nom de famille (vide pour passer à l'équipe suivante)" << endl;
            getline(cin, currentPlayer.lastname);
            if(currentPlayer.lastname.empty())break;

            cout << "Entrer prénom" << endl;
            getline(cin, currentPlayer.surname);

            currentTeam.members.push_back(currentPlayer);
        }

        if(currentTeam.members.empty()){
            cout << "OK, fin de la configuration des équipes. " << teams.size() << " équipes." << endl;
            break;
        }

        ++teamName;
        teams.push_back(currentTeam);
    }

    // if the number of teams is not even, we'll have trouble doing the swiss system, and we don't have to handle that case, so we won't do it
    if(teams.size()%2==1){
        cout << "FATAL : Le nombre d'équipes n'est pas pair !" << endl;
        return 1;
    }

    cout << "Let the games begin !" << endl;

    unsigned gameID=0;
    while(true){
        if(gameID==GAMES_NUMBER){
            cout << "Fin ! Classement : " << endl;
            sort(teams.begin(), teams.end(), &orderByScore);

            size_t i=teams.size();
            while(i>0){
                --i;
                cout << "team " << teams[i].name << " : " << teams[i].score << " points" << endl;
            }
            break;
        }

        cout << endl << "Tour numéro " << (gameID+1) << " !" << endl << endl;
        // would have liked to use iterators but... ):
        for(size_t i=0; i+1<teams.size(); i+=2){
            randomBattle(gameID, teams[i], teams[i+1]);
        }

        // sort teams to battle for the next turn
        sort(teams.begin(), teams.end(), &orderByScore);

        ++gameID;
    }
}
