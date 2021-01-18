#pragma once
#ifndef InBetweenSims
#define InBetweenSims

#include <stdlib.h>
using namespace std;
#include <iostream>
#include <ctime>

struct Player
{
	int betweenNumber;
	int startingCash;
	int currentCash;
	int maxBet;
	int maxLoss;
	
};

//int endCash[8][1];
int averageEndCash[8];

void StoreInformation (Player inPlayers[], int currentSimulation)
{
	for (int i = 0; i < 8; i++)
	{
		//endCash[i][currentSimulation] = inPlayers[i].currentCash;
		//cout << "Current average end cash for player " << i <<": " << averageEndCash[i] << endl;
		averageEndCash[i] = ((averageEndCash[i] * (currentSimulation)) + inPlayers[i].currentCash) / (currentSimulation + 1);
		//cout << "Average end cash after updaing for current simulation: " << averageEndCash[i] << endl;
	}	
}

void DisplayInfo(int currentSimulation)
{
	/*cout << "Current round results: " << endl;
	cout << "Player 0: " << endCash[0][currentSimulation]
		<< " Player 1: " << endCash[1][currentSimulation]
		<< " Player 2: " << endCash[2][currentSimulation]
		<< " Player 3: " << endCash[3][currentSimulation]
		<< " Player 4: " << endCash[4][currentSimulation]
		<< " Player 5: " << endCash[5][currentSimulation]
		<< " Player 6: " << endCash[6][currentSimulation]
		<< " Player 7: " << endCash[7][currentSimulation]
		<< endl;*/
	cout << "Average results now: " << endl;
	cout << "Player 0: " << averageEndCash[0]
		<< " Player 1: " << averageEndCash[1]
		<< " Player 2: " << averageEndCash[2]
		<< " Player 3: " << averageEndCash[3]
		<< " Player 4: " << averageEndCash[4]
		<< " Player 5: " << averageEndCash[5]
		<< " Player 6: " << averageEndCash[6]
		<< " Player 7: " << averageEndCash[7]
		<< endl << endl;
}

int PlayHand(int currentCash, Player inPlayer, int currentPot, bool inDebugBool)
{
	int handResult = 0;
	int firstCard = rand() % 13 + 1;	
	int secondCard = rand() % 12 + 2;
	
	int inBetweenNumber = abs(firstCard - secondCard - 1);
	

	if (inDebugBool)
	{
		cout << "Current cash is: " << currentCash << endl;
		cout << "Current pot is: " << currentPot << endl;
		cout << "First card is: " << firstCard << endl;
		cout << "Second card is: " << secondCard << endl;
		cout << "Number of cards between is: " << inBetweenNumber << endl;
		cout << "Player number of cards needed to be in between is: " << inPlayer.betweenNumber << endl;
	}
	
	if (inBetweenNumber >= inPlayer.betweenNumber)
	{
		
		int currentBet = 0;
		if ((-(currentPot * 2) + currentCash) < -inPlayer.maxLoss)
		{
			currentBet = (inPlayer.maxLoss - abs(currentCash)) / 2;
		}
		else
		{
			currentBet = currentPot;
		}

		if (currentBet > inPlayer.maxBet)
		{
			currentBet = inPlayer.maxBet;
		}
		int thirdCard = rand() % 12 + 2;

		if (inDebugBool)
		{
			cout << "Making a bet!" << endl;
			cout << "The bet is: " << currentBet << endl;
			cout << "Third card is: " << thirdCard << endl;
		}
		
		if (firstCard > secondCard)
		{
			if ((thirdCard > firstCard || thirdCard < secondCard))
			{
				return -currentBet;
			}
			else if (thirdCard == firstCard || thirdCard == secondCard)
			{
				return -(currentBet * 2);
			}
			else
			{
				return currentBet;
			}
		}
		else
		{
			if ((thirdCard > secondCard || thirdCard < firstCard))
			{
				return -currentBet;
			}
			else if (thirdCard == firstCard || thirdCard == secondCard)
			{
				return -(currentBet * 2);
			}
			else
			{
				return currentBet;
			}			
		}		
	}
	else
	{
		return 0;
	}
}

#endif