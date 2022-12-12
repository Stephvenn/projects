/*
A spreadsheet basketball game that simulates a game of basketball between 2 teams
Player ratings based on https://www.2kratings.com/
*/
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

struct player { // player struct

  char name[30];
  int attrSho;
  int attrDef;
  int attrPla;
  int attrReb;	
};

struct team{ // team struct

	char teamName[30];
  	player roster[5];
};

//the following 5 functions randomly decides a stat based on the corresponding attribute
//the pow() function was used from the following source 
//https://cplusplus.com/reference/cmath/pow/

int playerPoint(team *x, int i) {

  int temp = 5 + pow(1.5, x->roster[i].attrSho);
  return rand() % (temp) + 0;
}

int playerBlock(team *x, int i) { 
	int temp = (x->roster[i].attrDef) / 2;
	if (temp == 0)
		temp = 1;
	return rand() % (temp) + 0; 
}

int playerSteal(team *x, int i) { 
	int temp = (x->roster[i].attrDef) / 2;
	if (temp == 0)
		temp = 1;
	return rand() % (temp) + 0; 
}

int playerAssist(team *x, int i) {
  if (x->roster[i].attrPla <= 5 && x->roster[i].attrPla > 0)
    return rand() % (1) + 0;
  else if (x->roster[i].attrPla <= 7 && x->roster[i].attrPla > 5)
    return rand() % (4) + 0;
  else if (x->roster[i].attrPla <= 9 && x->roster[i].attrPla > 7)
    return rand() % (10) + 0;
  else if (x->roster[i].attrPla == 10)
    return rand() % (13) + 0;

	return 0;
}

int playerRebound(team *x, int i) {
  int temp;
  temp = 1 + pow(1.31, x->roster[i].attrReb);
  return rand() % (temp) + 0;
}

void runGame(team *x, team *y, int statX[][5], int statY[][5]){
	
	for (int i = 0; i < 5; i++){
		statX[i][0] = playerPoint(x, i);
		statY[i][0] = playerPoint(y, i);
	}
	for (int i = 0; i < 5; i++){
		statX[i][1] = playerBlock(x, i);
		statY[i][1] = playerBlock(y, i);
	}
	for (int i = 0; i < 5; i++){
		statX[i][2] = playerSteal(x, i);
		statY[i][2] = playerSteal(y, i);
	}
	for (int i = 0; i < 5; i++){
		statX[i][3] = playerAssist(x, i);
		statY[i][3] = playerAssist(y, i);
	}
	for (int i = 0; i < 5; i++){
		statX[i][4] = playerRebound(x, i);
		statY[i][4] = playerRebound(y, i);
	}
	
}

void initializeTeams(){	//initializes the text files to the correct player attributes
	int initialAttr1[5][4] = 
	{{10, 7, 10, 8}, 
	{9, 7, 8, 5},
	{8, 7, 6, 9},
	{8, 6, 5, 9},
	{8, 8, 6, 6}};

	int initialAttr2[5][4] = 
	{{10, 7, 6, 10}, 
	{8, 9, 6, 8},
	{9, 8, 6, 8},
	{7, 9, 7, 9},
	{9, 6, 5, 9}};

	int initialAttr3[5][4] = 
	{{9, 10, 7, 9}, 
	{9, 9, 9, 8},
	{9, 6, 6, 7},
	{8, 8, 6, 9},
	{8, 7, 10, 6}};

	int initialAttr4[5][4] = 
	{{9, 9, 7, 9}, 
	{9, 8, 6, 9},
	{8, 8, 9, 6},
	{9, 8, 8, 7},
	{8, 8, 5, 9}};
	
{
	fstream fout("team1.txt", ios::out);
	
	if (fout.fail()) {
		cout << "Error opening file" << endl;
	}
	
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 4; j++){
			fout << initialAttr1[i][j]<< endl;
		}
	}
	
	if (fout.fail())
		cout << "Error writing file" << endl;
	
	fout.close();
	
	if (fout.fail())
		cout << "Error closing file" << endl;
}

{
	fstream fout("team2.txt", ios::out);
	
	if (fout.fail()) {
	  	cout << "Error opening file" << endl;
	}
	
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 4; j++){
			fout << initialAttr2[i][j]<< endl;
		}
	}
	
	if (fout.fail())
	  	cout << "Error writing file" << endl;
	
	fout.close();
	
	if (fout.fail())
	  	cout << "Error closing file" << endl;

}

{
	fstream fout("team3.txt", ios::out);
	
	if (fout.fail()) {
	  	cout << "Error opening file" << endl;
	}
	
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 4; j++){
			fout << initialAttr3[i][j]<< endl;
		}
	}
	
	if (fout.fail())
	  	cout << "Error writing file" << endl;
	
	fout.close();
	
	if (fout.fail())
	  	cout << "Error closing file" << endl;
}
	
{
	fstream fout("team4.txt", ios::out);
	
	if (fout.fail()) {
	  	cout << "Error opening file" << endl;
	}
	
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 4; j++){
			fout << initialAttr4[i][j]<< endl;
		}
	}
	
	if (fout.fail())
	  	cout << "Error writing file" << endl;
	
	fout.close();
	
	if (fout.fail())
	  	cout << "Error closing file" << endl;
}
	
}

void initializeTeam1(team *ini){	//opens team 1 file and adds attribute to each player
	
	fstream fin("team1.txt", ios::in);
    
    if (fin.fail()) {
      cout << "Error opening file" << endl;
    }

	int num;
	
    for (int i = 0; i < 5; i++){
		
		fin >> ini->roster[i].attrSho;
		fin >> ini->roster[i].attrDef;
		fin >> ini->roster[i].attrPla;
        fin >> ini->roster[i].attrReb;
        if (fin.fail()) {
            cout << "Error reading file" << endl;
        }
    }
    
    fin.close();
    if (fin.fail()) {
        cout << "Error closing file" << endl;
		
    }
	
}

void initializeTeam2(team *ini){	//opens team 2 file and adds attribute to each player
	
	fstream fin("team2.txt", ios::in);
    
    if (fin.fail()) {
      cout << "Error opening file" << endl;
    }

	int num;
	
    for (int i = 0; i < 5; i++){
		
		fin >> ini->roster[i].attrSho;
		fin >> ini->roster[i].attrDef;
		fin >> ini->roster[i].attrPla;
        fin >> ini->roster[i].attrReb;
        if (fin.fail()) {
            cout << "Error reading file" << endl;
        }
    }
    
    fin.close();
    if (fin.fail()) {
        cout << "Error closing file" << endl;
		
    }
	
}

void initializeTeam3(team *ini){	//opens team 3 file and adds attribute to each player
	
	fstream fin("team3.txt", ios::in);
    
    if (fin.fail()) {
      cout << "Error opening file" << endl;
    }

	int num;
	
    for (int i = 0; i < 5; i++){
		
		fin >> ini->roster[i].attrSho;
		fin >> ini->roster[i].attrDef;
		fin >> ini->roster[i].attrPla;
        fin >> ini->roster[i].attrReb;
        if (fin.fail()) {
            cout << "Error reading file" << endl;
        }
    }
    
    fin.close();
    if (fin.fail()) {
        cout << "Error closing file" << endl;
		
    }
	
}

void initializeTeam4(team *ini){	//opens team 4 file and adds attribute to each player
	
	fstream fin("team4.txt", ios::in);
    
    if (fin.fail()) {
      cout << "Error opening file" << endl;
    }

	int num;
	
    for (int i = 0; i < 5; i++){
		
		fin >> ini->roster[i].attrSho;
		fin >> ini->roster[i].attrDef;
		fin >> ini->roster[i].attrPla;
        fin >> ini->roster[i].attrReb;
        if (fin.fail()) {
            cout << "Error reading file" << endl;
        }
    }
    
    fin.close();
    if (fin.fail()) {
        cout << "Error closing file" << endl;
		
    }
	
}

void displayStats(int statX[][5], int statY[][5], team *x, team*y){

	//calculates total score for each team
	int score[2] = {0, 0};
	for (int i = 0; i < 5; i++){
		score[0] += statX[i][0];
		score[1] += statY[i][0];	
	}

	//displays if player won or lost
	cout << "The score is " << score[0] << " - " << score[1] << endl;
	
	if (score[0] > score[1])
		cout << "Your team won!" << endl;
	else
		cout << "Your team lost..." << endl;

	//displays each player's statistics
	cout << "\nGame Stats\n";
	for (int l = 0; l < 2; l++){
		if (l == 0)
			cout << "Player Team: " << x->teamName << endl;
		else
			cout << "CPU Team: " << y->teamName << endl;
		cout << "P\tB\tS\tA\tR\tName\n";
		for (int j = 0; j < 5; j++){
			for (int i = 0; i < 5; i++){
				if (l == 0)
					cout << statX[j][i] << "\t";
				else
					cout << statY[j][i] << "\t";
				if (i == 4){
					if (l == 0)
						cout << x->roster[j].name;
					else
						cout << y->roster[j].name;
				
					cout << endl;
				}
			}
			if (j == 4)
				cout << endl;
		}
	}
}

void displayAttribute(team a[4]){
	cout << "\nAttributes\n\n";

	for (int j = 0; j < 4; j++){
		cout << a[j].teamName << endl << "Sho\tDef\tPla\tReb\n";
		for (int i = 0; i < 5; i++){
			cout << a[j].roster[i].attrSho << "\t" << a[j].roster[i].attrDef << "\t" << a[j].roster[i].attrPla << "\t" << a[j].roster[i].attrReb << "\t" << a[j].roster[i].name << endl;
			if (i == 4)
				cout << endl;
		}
	}

}


int main() {
	
	
	srand(time(NULL));	//makes numbers random

	//create teams without player attributes
	team team1 = {"Dallas Mavericks",{
{"Luka Doncic"},
{"Christian Wood"},
{"Spencer Dinwiddie"},
{"Jalen Brunson"},
{"Dorian Finney-Smith"}}};
	
	team team2 = {"Golden State Warriors",{
{"Stephen Curry"},
{"Klay Thompson"},
{"Andrew Wiggins"},
{"Draymond Green"},
{"Jordan Poole"}}};

	team team3 = {"Miami Heat",{
{"Jimmy Butler"},
{"Bam Adebayo"},
{"Tyler Herro"},
{"Kyle Lowry"},
{"Omer Yurtseven"}}};

	team team4 = {"Boston Celtics",{
{"Jayson Tatum"},
{"Jaylen Brown"},
{"Robert Williams III"},
{"Al Horford"},
{"Derrick White"}}};

	//initializes save files with correct player attributes
	initializeTeams();

	//initializes player's attribute numbers based on save files
	initializeTeam1(&team1);
	initializeTeam2(&team2);
	initializeTeam3(&team3);
	initializeTeam4(&team4);

	//variables
	int statX[5][5];	//player team stats
	int statY[5][5];	//cpu team stats
	team *playerTeamPtr;	//pointer to player team
	team *cpuTeamPtr;		//pointer to cpu team
	
	while(true){	//game loop
		char input;
		cout << "Welcome to baskingball!\n";

		//creates an array containing all teams and displays each team's players and attributes
		team allTeams[4] = {team1, team2, team3, team4};
		displayAttribute(allTeams);
		
		while (true){	//loops until valid input for player team is given
			cout << "\nSelect a team to manage\n1.\t" << team1.teamName << "\n2.\t" << team2.teamName << "\n3.\t" << team3.teamName << "\n4.\t" << team4.teamName << endl;
			cin >> input;
			cin.clear();
      		cin.ignore(100,'\n');
			if (input == '1' || input == '2' || input == '3' || input == '4'){
				if (input == '1')
					playerTeamPtr = &team1;
				if (input == '2')
					playerTeamPtr = &team2;
				if (input == '3')
					playerTeamPtr = &team3;
				if (input == '4')
					playerTeamPtr = &team4;
				break;
			}
			else{
				cout << "Invalid Input" << endl;
				continue;
			}
		}

		cout << "You have selected the " << playerTeamPtr->teamName << endl;
		
		while (true){	//loops until valid input for cpu team is given
			cout << "Select a team to play against\n1.\t" << team1.teamName << "\n2.\t" << team2.teamName << "\n3.\t" << team3.teamName << "\n4.\t" << team4.teamName << endl;
			cin >> input;
			cin.clear();
	      	cin.ignore(100,'\n');
			
			if (input == '1' || input == '2' || input == '3' || input == '4'){
				if (input == '1')
					cpuTeamPtr = &team1;
				if (input == '2')
					cpuTeamPtr = &team2;
				if (input == '3')
					cpuTeamPtr = &team3;
				if (input == '4')
					cpuTeamPtr = &team4;
				break;
			}
			else{
				cout << "Invalid Input" << endl;
				continue;
			}
		}

		cout << "You will play against the " << cpuTeamPtr->teamName << endl;
		
		runGame(playerTeamPtr, cpuTeamPtr, statX, statY);	//calls game function to calculate stats
		displayStats(statX, statY, playerTeamPtr, cpuTeamPtr);	//displays winning team and player's stats

		while (true){	//loops until player gives valid input to keep playing or quit
			cout << "Would you like to continue?\nY.\tYes\nN.\tNo" << endl;
			cin >> input;
			cin.clear();
      		cin.ignore(100,'\n');
			if (input == 'y'){
				break;
			}
			else if (input == 'n'){
				cout << "Goodbye!" << endl;
				return 0;
			}
			else{
				cout << "Invalid Input" << endl;
				continue;
			}
			
		}
		
	}
	
  return 0;
}
