#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

	//Welcome screen
  cout << "Welcome to sug simulator!\n";
	cout << "\x1B[31mOptions \033[0m\t\t\n";
	cout << "\x1B[31m-Select chapter & play (1) \033[0m\t\t\n";
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


		} else if (input == "2") {

			cout << "Sug Simulator is a game based on the fantasy succ particles. Made by Bob8552 and lore by Drags890.\n";

		} else if (input == "3") {



		} else {

				cout << "\x1B[31mThat is not a valid option. \033[0m\t\t\n";

		}

	} while (true);


}