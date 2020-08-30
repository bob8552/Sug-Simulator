// Sug Simulator v0.0.4 - Main.cpp
// Made by Bob8552 and Drags890

//Include Header Files
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <unistd.h>
//Terminal Colours
#include "headers/colours.h"

//Declase state var
using namespace std;
int state = 0;

//Particle defenitions
string particles[] = {
	"Sig", 
	"Suc", 
	"Jargle A",
	"Janky", 
	"Sug", 
	"Jix",
  "Su",
	"Succ",
	"Jargle B"
};

//Particle properties
string particles_properties[] = {
	"Sig is a heavier variant of a particle. It's unstable however, and will decay into a more lighter particle.",
	"Suc is the 2nd heaviest particle. It is slightly unstable and will decay over a very long time.", 
	"Jargle A is a harmless particle for transferring energy.",
	"Janky is a heavier, highly unstable particle.",
	"Sug is a strange particle that will decay into j~. It has 3 states - heavy, calm and weak.",
	"Jix is a strange particle that is created during the decay of a p~.",
	"Su is the lightest p~ and most abundant particle.",
	"Succ is the heavist and rarest p~.",
	"Jargle B is a highly unstable and harmful variant of j~."
};

//Variables
int funds = 100000;
int points = 0;
string particlesDiscovered = "";

//Difficulty Selector
void select_difficulty() 
{

	cout << RED("\nPlease select a difficulty - 'easy', 'medium', 'hard'\n\n");
	state = 2;

	do {

		//Variables
		string input;

		//Input cursor
		cout << ">";
		//Input
		getline(cin, input);

		if (input == "easy") {

			funds = 500000;
			cout << RED("\nDifficulty Set!\n\n");
			state = 0;

		}
		else if (input == "medium") {

			funds = 100000;
			cout << RED("\nDifficulty Set!\n\n");
			state = 0;

		}
		else if (input == "hard") {

			funds = 50000;
			cout << RED("\nDifficulty Set!\n\n");
			state = 0;

		} else {

			cout << RED("That is not a valid option.\n");

		}

	} while (state == 2);

}

//--RESEARCH--
void research() 
{

	cout << YEL("\nYou got your experiments ready and waited to detect a new particle...\n");
	sleep(1);

	//Funds used
	int randomfunds = rand() % 2000 + 500;

	if (randomfunds > funds) { 

		cout << RED("Seems like you have no funds. Try exchanging points for funds.\n\n");

	} else {

		//Index
		int randomN = rand() % 2; 
		//Points recieved
		int randomPoints = rand() % 10 + 5; 
		//Name of found particle (random index of defined possible particles)
		int foundptc = rand() % 8;

		//Found particle 
		string found_particle = particles[foundptc];
		//Properties of that particle
		string found_particle_properties = particles_properties[foundptc];

		//If particle is new and index is 0
		if (randomN == 0 && found_particle != "DISCOVERED") {

			cout << YEL("\nYou and your team have discovered a new particle.\n");
			cout << YEL("You decide to name it the " << found_particle << ".\n");
			cout << YEL("" << found_particle_properties << "\n");

			//Set particle as discovered
			particles[foundptc] = "DISCOVERED";

			//give some points
			points += randomPoints;

			cout << YEL("Congratulations! You have recieved " << randomPoints << " points!\n");

			//append to discovered particles
			particlesDiscovered += " " + found_particle;
			//remove money from funds
			funds -= randomfunds;

			sleep(1);

			//tell the user how much funds used
			cout << "\nYour team have used " << randomfunds << " in funds.\n";
			cout << "So far you have discovered:" << particlesDiscovered << ".\n\n";

		} else { //Failed in research

			//Decide a disaster
			int randomN = rand() % 50; 
			if (randomN == 0) {

			cout << SetBackWHT << SetForeRED << "Your team got in a serious accident and a succ vortex was spawned. You lost 25,000 in funds." << RESETTEXT << "\n\n";

				if (funds >= 25000) {
					funds -= 25000;
				} else {
					funds = 0;
				}

			} else {

				//You could not detect particles.
				cout << YEL("You could not detect any particles this time, sorry.\n");
				funds -= randomfunds;

				sleep(1);

				//tell the user how much funds used
				cout << "\nYour team have used " << randomfunds << " in funds.\n";
				cout << "So far you have discovered:" << particlesDiscovered << ".\n\n";
			}

		}

	}

}

//--STATS--
void stats() {

	cout << YEL("\n >>> STATS\n");
	cout << "\nSo far you have discovered:" << particlesDiscovered << ".\n";
	cout << "You have " << funds << " in funds.\n";
	cout << "You have " << points << " points.\n\n";

}

//--Main--
int main() {

	//Welcome screen
  cout << "Welcome to Sug Simulator v0.0.4!\n";
	cout << RED("Options\n");
	cout << RED("-Play (1)\n");
	cout << RED("-Info (2)\n");
	cout << RED("-Configure Difficulty (3)\n");
	cout << RED("-Quit (4)\n");
	cout << "Please input your choice.\n";	
	cout << "=========================\n";

	//Loop
	do {

		//Input
		string input;

		//Get input
		cout << ">";
		getline(cin, input);

		//play SUG SIMULATOR
		if (input == "1") {

			//Change state
			state = 1;

			//Prolog
			cout << "\n \x1B[33m>>> Loading...\033[0m\t\t\n";

			sleep(2);

			//Story
			cout << "\n \x1B[33m>>>     SUG SIMULATOR     <<<\033[0m\t\t\n\n";
			cout << "You recently started work as a succ particle researcher in kirbistaraniaburg. You have been given 100k in funds to discover new particles with your group.\n\n";

			sleep(1);

			//OPTIONS
			cout << GRN("Options\n");
			cout << GRN("-Research (1)\n");
			cout << GRN("-Stats (2)\n");
			cout << GRN("-Transfer points into funds (3)\n");
			cout << GRN("-Quit (4)\n");
			cout << "Please input your choice.\n";	
			cout << "=========================\n";

			//Basically all the content.
			do {

				//Variables
				string input;

				//Input cursor
				cout << ">";
				//Input
				getline(cin, input);

				//ELSEIF
				if (input == "1") { //research

					research();

				}				
				else if (input == "2") { //Stats

					stats();

				}  
				else if (input == "3") { //Transfer points to funds

					cout << GRN("\nYou have transferred all your points into funding (Keep in mind that 1 point = 10 funds).\n\n");

					//1 point = 10 funds
					funds += points * 10;
					//User has used all points for funds.
					points = 0;

				}  
				else if (input == "4") { //quit

					//Exit
					state = 0;
					points = 0;
					funds = 100000;
					particlesDiscovered = "";
					cout << "\nPress any key to continue...\n";
					getchar();

				} else {

					cout << RED("That is not a valid option.\n");

				}

			} while (state==1);		


		// Continue back onto main else if

		} else if (input == "2") {

			cout << "Sug Simulator is a game based on the fantasy succ particles. Made by Bob8552 and Drags890!\n";

		} else if (input == "3") {

			select_difficulty();

		} else if (input == "4") {

			//exit
			cout << "\nPress any key to continue...\n";
			getchar();
			return 0;

		} else {

			cout << RED("That is not a valid option.\n");

		}

	} while (state == 0);


}