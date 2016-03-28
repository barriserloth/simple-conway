#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random>
#include <string>
#include <stdlib.h>
#include <windows.h>

void live(int arrayLife[82][162]){

	int temp[82][162];

	for (int i = 0; i < 82; ++i){
		for (int j = 0; j < 162; ++j){
			temp[i][j] = arrayLife[i][j];	
		}
	}

	int count = 0;
	for (int i = 1; i < 81; ++i){
		for (int j = 1; j < 161; ++j){
			count = temp[i + 1][j] + temp[i - 1][j] + temp[i][j + 1] + temp[i][j - 1] + temp[i + 1][j + 1] + temp[i - 1][j + 1] + temp[i + 1][j - 1] + temp[i - 1][j - 1];

			if (count < 2 || count > 3){
				temp[i][j] = 0;
			}
			if (count == 2){
				temp[i][j] = arrayLife[i][j];
			}
			if (count == 3){
				temp[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 82; ++i){
		for (int j = 0; j < 162; ++j){
			arrayLife[i][j] = temp[i][j];
		}
	}

}

void displayGame(int arrayGame[82][162]){
	for (int i = 1; i < 81; ++i){
		for (int j = 1; j < 161; ++j){
			if (arrayGame[i][j] == 1){
				std::cout << 'A';
			}
			else{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}

int main(){
	int startSim[82][162];
	int tempSim[82][162];
	char thing;

	system("cls");
	int counter = 0;

	std::cout << "Begin? (y/n): ";
	std::cin >> thing;
	if (thing == 'y'){
		do{
			
			srand(time(nullptr));

			for (int i = 1; i < 81; ++i){
				for (int j = 1; j < 161; ++j){
					startSim[i][j] = rand() % 2;
				}
			}
			

			if (counter == 0){
				for (int i = 0; i < 82; ++i){
					for (int j = 0; j < 162; ++j){
						tempSim[i][j] = startSim[i][j];
					}
				}
			}

			displayGame(tempSim);
			live(tempSim);
			counter++;

			system("ping 192.0.2.2 -n 1 -w 1 > nul");
			system("cls");

		} while (counter < 1000);
	}
}