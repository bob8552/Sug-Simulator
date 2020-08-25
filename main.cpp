//Include Header Files
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <unistd.h>

//Declase state var
using namespace std;
int state = 0;

//Particle defenitions
string particles[] = {
	"Succ", 
	"Suc", 
	"Jargle",
	"Janky"
};

//Variables
int funds = 100000;
int points = 0;
int particlesFound = 0;
string particlesDiscovered = "";

//Functions
void research() 
{

	cout << "\x1B[33mYou got your experiments ready and waited to detect a new succ particle...\033[0m\t\t\n";
	sleep(1);
	int randomN = rand() % 3; 
	int foundptc = rand() % 3; 
	if (randomN == 0) {

		cout << "\x1B[33mYou and your team have discovered a new particle.\033[0m\t\t\n";
		cout << "\x1B[33mYou decide to name it the " << particles[foundptc] << ".\033[0m\t\t\n";

	}

}


int main() {

	//Welcome screen
  cout << "Welcome to sug simulator!\n";
	cout << "\x1B[31mOptions \033[0m\t\t\n";
	cout << "\x1B[31m-Play (1) \033[0m\t\t\n";
	cout << "\x1B[31m-Info (2) \033[0m\t\t\n";
	cout << "\x1B[31m-Quit (3) \033[0m\t\t\n";
	cout << "Please input your choice.\n";	
	cout << "=========================\n";

	//Loop
	do {

		//Input
		string input;

		//Get input
		cout << ">";
		getline(cin, input);

		if (input == "1") {

			//Change state
			state = 1;

			//Prolog
			cout << "\n \x1B[33m>>> Loading...\033[0m\t\t\n";

			sleep(2);

			cout << "\n \x1B[33m>>>     SUG SIMULATOR     <<<\033[0m\t\t\n\n";
			cout << "You recently started work as a succ particle researcher in kirbistaraniaburg. You have been given 100k in funds to discover new particles with your group.\n\n";

			sleep(1);

			//OPTIONS
			cout << "\x1B[32mOptions \033[0m\t\t\n";
			cout << "\x1B[32m-Research (1) \033[0m\t\t\n";
			cout << "\x1B[32m-Quit (2) \033[0m\t\t\n";
			cout << "Please input your choice.\n";	
			cout << "=========================\n";

			do {

				//Variables
				string input;

				//Input cursor
				cout << ">";
				//Input
				cin >> input;

				//ELSEIF
				if (input == "1") {

					research();

				} else if (input == "2") {

					//exit
					state = 0;
					cout << "\nPress any key to continue...\n";
					getchar();

				} else {

					cout << "\x1B[31mThat is not a valid option. \033[0m\t\t\n";

				}

			} while (state==1);		

		} else if (input == "2") {

			cout << "Sug Simulator is a game based on the fantasy succ particles. Made by Bob8552 and lore by Drags890.\n";

		} else if (input == "3") {

			//exit
			cout << "\nPress any key to continue...\n";
			getchar();
			return 0;

		} else {

			cout << "\x1B[31mThat is not a valid option. \033[0m\t\t\n";

		}

	} while (state == 0);


}