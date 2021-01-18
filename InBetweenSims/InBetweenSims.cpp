// InBetweenSims.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "InBetweenSims.h"


int main()
{
	
	int numberOfPlayers = 8;
	int numberOfSimulations = 1;

	Player players[8];

	bool bCustomize;
	char customizeCharacter;
	cout << "Would you like to customize the simulation? Y or N: ";
	cin >> customizeCharacter;
    if (customizeCharacter == 'Y')
    {
		bCustomize = true;
    }
	else
	{
		bCustomize = false;
	}

	bool bDebug;
	char debugCharacter;
	cout << "Would you like to debug? This displays each hand result rather than just showing the results of the simulation. Y or N: ";
	cin >> debugCharacter;
	if (debugCharacter == 'Y')
	{
		bDebug = true;
	}
	else
	{
		bDebug = false;
	}

    if (bCustomize)
    {
		for (int i = 0; i < numberOfPlayers; i++)
		{
			cout << "For player " << i << ", enter the following:" << endl;
			cout << "What their minimum between numbers is: ";
			cin >> players[i].betweenNumber;

			cout << "What their max bet is: ";
			cin >> players[i].maxBet;

			cout << "What their maxLoss is: ";
			cin >> players[i].maxLoss;

			players[i].startingCash = 10;
			players[i].currentCash = players[i].startingCash;
		}
    }
	else
	{
		players[0].betweenNumber = 5;
		players[0].maxBet = 5000;
		players[0].maxLoss = 5000;
		players[0].startingCash = 10;
		players[0].currentCash = players[0].startingCash;
		
		players[1].betweenNumber = 6;
		players[1].maxBet = 5000;
		players[1].maxLoss = 5000;
		players[1].startingCash = 10;
		players[1].currentCash = players[0].startingCash;

		players[2].betweenNumber = 7;
		players[2].maxBet = 5000;
		players[2].maxLoss = 5000;
		players[2].startingCash = 10;
		players[2].currentCash = players[0].startingCash;

		players[3].betweenNumber = 8;
		players[3].maxBet = 5000;
		players[3].maxLoss = 5000;
		players[3].startingCash = 10;
		players[3].currentCash = players[0].startingCash;

		players[4].betweenNumber = 9;
		players[4].maxBet = 5000;
		players[4].maxLoss = 5000;
		players[4].startingCash = 10;
		players[4].currentCash = players[0].startingCash;

		players[5].betweenNumber = 10;
		players[5].maxBet = 5000;
		players[5].maxLoss = 5000;
		players[5].startingCash = 10;
		players[5].currentCash = players[0].startingCash;

		players[6].betweenNumber = 11;
		players[6].maxBet = 5000;
		players[6].maxLoss = 5000;
		players[6].startingCash = 10;
		players[6].currentCash = players[0].startingCash;

		players[7].betweenNumber = 11;
		players[7].maxBet = 25;
		players[7].maxLoss = 100;
		players[7].startingCash = 10;
		players[7].currentCash = players[0].startingCash;
	}
	
	

	int currentSimulation = 0;

	int totalHands = 500;
	// while loop running through simulations
	srand(time(NULL));
	while (currentSimulation < numberOfSimulations)
	{
		int currentHand = 0;
		int playerTurn = 0;

		// while loop running through each hand
		int currentPot = 0;
		int antesDrawn = 0;
		
		while (currentHand < totalHands)
		{
			if (currentPot == 0)
			{
				if (bDebug)
				{
					cout << "Ante number: " << ++antesDrawn << endl;
				}
				
				for (int i = 0; i < numberOfPlayers; i++)
				{
					if (players[i].currentCash > -players[i].maxLoss)
					{
						players[i].currentCash -= 1;
						currentPot += 1;
					}
					
					
				}
			}
			Player currentPlayer = players[playerTurn];
			int handResult = PlayHand(players[playerTurn].currentCash, players[playerTurn], currentPot,bDebug);
			if (bDebug)
			{
				cout << "Hand Result on turn " << currentHand << " is: " << handResult << endl;
				cout << endl;
			}			
			currentPot -= handResult;
			players[playerTurn].currentCash += handResult;


			currentHand++;
			playerTurn++;
			
			
			if (playerTurn > numberOfPlayers -1)
			{
				playerTurn = 0;
			}
		}

		
		StoreInformation(players, currentSimulation);

		for (int i = 0; i < numberOfPlayers; i++)
		{
			players[i].currentCash = players[i].startingCash;			
		}

		
		currentSimulation++;
		
	}

	DisplayInfo(currentSimulation);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
