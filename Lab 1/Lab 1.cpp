// Lab 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

int m_icomNum; 
int m_iPlayerAns;
bool m_bAnsCorrect = false;
bool m_bGame = true;
char m_playGame;

void ErrorCheckingChoice()
{
	std::cout << "You have entered the wrong key, please enter either Y or N" << std::endl;
	std::cin >> m_playGame;

};


void ErrorCheckingGame()
{
	std::cout << "You have entered a wrong key, please enter the a number" << std::endl;
	std::cin >> m_iPlayerAns;
};


int main()
{
	std::cout << "Do you want to play a game? Y/N" << std::endl;

	while (m_bGame == true)
	{
		
		std::cin >> m_playGame;
		system("CLS");
		bool m_Won = false;
		if (m_playGame == 'y' || m_playGame == 'Y')
		{
			
			srand(time(NULL));
			m_icomNum = rand() % 100 + 1;
			std::cout << "I've thought of a number. It is between 1 and 100." << std::endl;
			std::cin >> m_iPlayerAns;
			
			for (int i = 0; i < 5; i++)
			{

				system("cls");

				if (m_iPlayerAns == m_icomNum)
				{
					std::cout << "Congratulations you guessed it!" << std::endl;
					m_Won = true;
					i = 6;
					system("pause");
					system("cls");
				}
				else
				{
					if (m_iPlayerAns > m_icomNum)
					{
						std::cout << "The answer is lower. " << "You have " << 5 - i << " tries left." << std::endl;
						std::cin >> m_iPlayerAns;
					}
					else
					{
						std::cout << "The answer is higher." << "You have " << 5 - i << " tries left." << std::endl;
						std::cin >> m_iPlayerAns;
					}

				}

			}
			if (m_Won == false)
			{
				m_playGame = NULL;
				std::cout << "The answer was " << m_icomNum << std::endl;
				std::cout << "Better luck next time! Do you wanna play again? Y/N" << std::endl;
			}
			else
			{
				m_playGame = NULL;
				std::cout << "Well you beat me. Wanna play again? Y/N" << std::endl;
			}
		}
		else if(m_playGame == 'n' || m_playGame == 'N')
		{
			m_bGame = false;
		}
		else
		{
			ErrorCheckingChoice();
		}


	}






    return 0;
}

/*
Click the Solution explorer tab and add a new source file. Refresh your basic abilities with C++ by creating a simple console-based game.
•	Let the computer select a random number between 1 and 100 with the player having to guess the number in 5 guesses.
•	The player’s questions are specific guesses in the form of numbers between 1 and 100 but answers are in the form of higher/lower or yes if the guess is correct.
•	It is good practice to plan out the flow of your code via pseudo code and not worry about the details initially.
•	Use the rand() function for the number choice. Check if it is actually random every time you compile the program (what is the role of the srand() function?)






*/