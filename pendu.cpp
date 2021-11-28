#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<structs.h>

using namespace std;

vector<string> readFile(const string & path)
{
    vector<string> allLines;
    ifstream ifs (path);
    if (!ifs){
        cerr << "FATAL : Fichier " << path << " non trouvé !" << endl;
        exit(0);
    }

    for (string line; getline(ifs, line);){
        allLines.push_back(line);
    }
    return allLines;
}

unsigned playGame(){

    vector<string> words(readFile("mots_pendu.txt"));

    string word = words[rand()%words.size()];
    string foundWord(word.size(), '_');


    size_t foundNumber = 0;
    int triesLeft = 10;
    char inputFromUser;
    bool found;

    while(true){
        found = false;

        cout << "Mot : " << foundWord << endl << endl;
        cout << "Entrer un caractère : ";
        cin >> inputFromUser;
        inputFromUser  = tolower(inputFromUser);
        cout << endl;

        for(size_t i=0;i<word.size();++i){
            if(inputFromUser==word[i]){
                found = true;
                if(foundWord[i]=='_'){
                    foundWord[i] = word[i];
                    foundNumber++;
                }
            }
        }
        if(found){
            if(foundNumber == word.size()){
                cout << "Bravo, tu as gagné ! Mot : " << foundWord << endl;
                cout << "Il te restait " << triesLeft << " essais" << endl;
                break;

            }else{
                cout << "Le mot contient la lettre '" << inputFromUser << "'" << endl;
            }
        }else{
            --triesLeft;

            if(triesLeft==0){
                cout << "Game over ! Le mot était '" << word << "'" << endl;
                break;

            }else{
                cout << "Le mot contient ne contient pas la lettre '" << inputFromUser << "'. " << triesLeft << " essais restants" << endl;
            }
        }
    }
    return triesLeft;
}

unsigned pendu(const player& p1, const player& p2) {
    cout << "A ton tour " << p1.surname << endl;
    unsigned score1 = playGame();
    cout << "A ton tour " << p2.surname << endl;
    unsigned score2 = playGame();
    cout << "Les scores sont de " << score1 << ":" << score2 << endl;
    if (score1 > score2) return 1;
    else if (score2 > score1) return 2;
    else return 0;
}
