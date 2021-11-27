#ifndef STRUCTS_H
#define STRUCTS_H

#include<string>
#include<vector>

using namespace std;

struct player{
	string surname;
	string lastname;
};

struct team{
	vector<player> members;
	float score=0;
	char name;
};

#endif