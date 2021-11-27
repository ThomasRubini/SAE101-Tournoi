#include <iostream>
#include <string>
#include "structs.h"

using namespace std;

void stringToLower(string & str)
{
	unsigned i=0;
	while(i<=str.size())
	{
		str[i]= tolower(str[i]);
		++i;
	}
}

unsigned shifumi(const player& p1, const player& p2){

	string player1Choice;
	string player2Choice;
	int player1Score = 0;
	int player2Score = 0;
	float cpt = 0;

	while (cpt < 3)
	{
		cout << p1.surname << ", a vous de jouer (pierre/feuille/ciseaux)" << endl;
		cin >> player1Choice;
		stringToLower(player1Choice) ;
		cout << p2.surname << ", a vous de jouer (pierre/feuille/ciseaux)" << endl;
		cin >> player2Choice;
		stringToLower(player2Choice) ;

		if (player1Choice==player2Choice){
			cout << "Les deux joueurs ont joué la même chose. " << endl << "Egalite" << endl;
		}
		else if ((player1Choice == "feuille" && player2Choice == "pierre")||(player1Choice == "ciseaux" && player2Choice == "feuille") || (player1Choice == "pierre" && player2Choice == "ciseaux"))
		{
			cout << p1.surname << " gagne" << endl;
			++player1Score;
			++cpt;
		}
		else if ((player2Choice == "feuille" && player1Choice == "pierre") || (player2Choice == "ciseaux" && player1Choice == "feuille") || (player2Choice == "pierre" && player1Choice == "ciseaux"))
		{
			cout << p2.surname << " gagne" << endl;
			++player2Score;
			++cpt;
		}
		else
		{
			cout << "Erreur de saisie" << endl;
		}


	}
	cout << "Le score est de " << player1Score << " : " << player2Score << endl;
	if (player1Score > player2Score)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}