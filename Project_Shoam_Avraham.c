/*********************************
* Class: MAGSHIMIM C1			 *
* Week 10          				 *
*Project_Shoam_Avraham.c         *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void splashScreen();

void difficultyLevels ();

int checkRndNum(int creditNum1, int creditNum2, int creditNum3, int creditNum4);

int checkInput(int num1, int num2, int num3, int num4);

int areValidNumbers(int creditNum1,int creditNum2, int creditNum3);

int checkInput(int num1, int num2, int num3, int num4);

int parameterEquality(int creditNum1, int creditNum2, int creditNum3, int creditNum4,int num1, int num2, int num3, int num4);

int checkEquality (int opportunity);

char againChallange(char again);


int main(void)
{	
	int opportunity = 0;
	
	int creditNum1 = 0;
	int creditNum2 = 0;
	int creditNum3 = 0;
	int creditNum4 = 0;
	
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	
	int easy = 20;
	int moderate = 15;
	int hard = 10;
	int crazy = rand()%(25 - 5 + 1) + 5;
	srand(time(NULL));
	int temp = 0;
	int chance = 0;
	int hitsAndMiss = 0;
	int miss = 0;
	int hits = 0;
	
	char again = 0;
	
	
	do
	{
		splashScreen();
		difficultyLevels ();
		do //choose the levels To play
		{
			printf("Make a choice:");
			scanf("%d", &opportunity);
			
		} while(opportunity > 4 || opportunity < 1);
	
		//The numbers are repeated until they qualify.
		do
		{
			creditNum1 = rand()%(6 - 1 + 1) + 1;
			creditNum2 = rand()%(6 - 1 + 1) + 1;
			creditNum3 = rand()%(6 - 1 + 1) + 1;
			creditNum4 = rand()%(6 - 1 + 1) + 1;
			srand(time(NULL));
		
		} while(checkRndNum(creditNum1, creditNum2, creditNum3, creditNum4));
		
		switch (opportunity) //Compares the level of difficulty chosen to the appropriate conditions
		{
			case 1:
		
				for (easy = 20; easy > 0; easy--) //Loop repeating until the loop's chance number is over
				{
					do //check if the input number Meets the conditions
					{

						printf("Write your guess (only 1-6)\n%d guesses left\n", easy);
						num1 = getch()-48;
						printf("%d", num1);
						
						num2 = getch()-48;
						printf("%d", num2);
						
						num3 = getch()-48;
						printf("%d", num3);
						
						num4 = getch()-48;
						printf("%d\n", num4);

						if (checkInput(num1, num2, num3, num4))
						{
							printf("\nOnly 1-6 are allowed, try again!\n");		
						}
				
					} while(checkInput(num1, num2, num3, num4));
						
						
					hitsAndMiss = parameterEquality(creditNum1, creditNum2, creditNum3, creditNum4, num1, num2, num3, num4);
					miss =  hitsAndMiss % 10; //To calculate the Miss, we'll take the remainder from the return of the function.
					hits =  hitsAndMiss / 10; //To calculate the hits, onsidered the return of the tens digit so we divide by ten without a residue.

					if (hits == 4) //falg to stop the loop if the users get 4 hits before he finished several chances 
					{
						chance = easy;
						easy = 0;			
					}
						
					printf("Hits = %d Miss = %d\n", hits, miss);
				}
				
				if (hits == 4) //Message if the game ended with a win 4 hits
				{
					
					printf("\n4 HITS YOU WON!!! \nIt took you only %d guesses, you are a professional code breaker!\n", chance);	
					
				}
				
				if (hits < 4) //Message if the game ended with a lose hits small from 4 hits
				{
					
					printf("OOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts. \nNothing left for you... \n secret: %d%d%d%d", creditNum1, creditNum2, creditNum3, creditNum4);
					
				}
				
				break;
				
			case 2:
				for (moderate = 15; moderate > 0; moderate--) //Loop repeating until the loop's chance number is over
				{
					do //check if the input number Meets the conditions
					{
						printf("Write your guess (only 1-6)\n%d guesses left\n", moderate);
						num1 = getch()-48;
						printf("%d", num1);
						
						num2 = getch()-48;
						printf("%d", num2);
						
						num3 = getch()-48;
						printf("%d", num3);
						
						num4 = getch()-48;
						printf("%d\n", num4);

						if (checkInput(num1, num2, num3, num4))
						{
							printf("\nOnly 1-6 are allowed, try again!\n");
						}
			
					} while(checkInput(num1, num2, num3, num4));
					
					hitsAndMiss = parameterEquality(creditNum1, creditNum2, creditNum3, creditNum4, num1, num2, num3, num4);
					miss =  hitsAndMiss % 10; //To calculate the Miss, we'll take the remainder from the return of the function.
					hits =  hitsAndMiss / 10; //To calculate the hits, onsidered the return of the tens digit so we divide by ten without a residue.

					if (hits == 4) //falg to stop the loop if the users get 4 hits before he finished several chances 
					{
						chance = moderate;
						moderate = 0;			
					}
					
					printf("Hits = %d Miss = %d\n", hits, miss);
				}
				
				if (hits == 4) //Message if the game ended with a win 4 hits
				{
					
					printf("\n4 HITS YOU WON!!! \nIt took you only %d guesses, you are a professional code breaker!\n", chance);	
					
				}
				
				if (hits < 4) //Message if the game ended with a lose hits small from 4 hits
				{
				
					printf("OOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts. \nNothing left for you... \n secret: %d%d%d%d", creditNum1, creditNum2, creditNum3, creditNum4);
					
				}
				
				break;
				
			case 3:			
				for (hard = 10; hard  > 0; hard--) //Loop repeating until the loop's chance number is over
				{
					do //check if the input number Meets the conditions
					{
						printf("Write your guess (only 1-6)\n%d guesses left\n", hard);
						num1 = getch()-48;
						printf("%d", num1);
						
						num2 = getch()-48;
						printf("%d", num2);
						
						num3 = getch()-48;
						printf("%d", num3);
						
						num4 = getch()-48;
						printf("%d\n", num4);
						

						if (checkInput(num1, num2, num3, num4))
						{
							printf("\nOnly 1-6 are allowed, try again!\n");
						}
			
					} while(checkInput(num1, num2, num3, num4));
					
					hitsAndMiss = parameterEquality(creditNum1, creditNum2, creditNum3, creditNum4, num1, num2, num3, num4);
					miss =  hitsAndMiss % 10; //To calculate the Miss, we'll take the remainder from the return of the function.
					hits =  hitsAndMiss / 10; //To calculate the hits, onsidered the return of the tens digit so we divide by ten without a residue.

					if (hits == 4) //falg to stop the loop if the users get 4 hits before he finished several chances 
					{
						chance = hard;
						hard = 0;			
					}
					
					printf("Hits = %d Miss = %d\n", hits, miss);
				}
				
				if (hits == 4) //Message if the game ended with a win 4 hits
				{
					
					printf("\n4 HITS YOU WON!!! \nIt took you only %d guesses, you are a professional code breaker!\n", chance);	
					
				}
				
				if (hits < 4) //Message if the game ended with a lose hits small from 4 hits
				{
					
					printf("OOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts. \nNothing left for you... \n secret: %d%d%d%d", creditNum1, creditNum2, creditNum3, creditNum4);
					
				}
				
				break;

			case 4:
				for (crazy = crazy; crazy > 0; crazy--) //Loop repeating until the loop's chance number is over
				{
					do //check if the input number Meets the conditions
					{
						printf("Write your guess (only 1-6)\n CRAZY MOOD!!!\n");
						num1 = getch()-48;
						printf("%d", num1);
						
						num2 = getch()-48;
						printf("%d", num2);
						
						num3 = getch()-48;
						printf("%d", num3);
						
						num4 = getch()-48;
						printf("%d\n", num4);

						if (checkInput(num1, num2, num3, num4))
						{
							printf("\nOnly 1-6 are allowed, try again!\n");
						}
			
					} while(checkInput(num1, num2, num3, num4));
					
					hitsAndMiss = parameterEquality(creditNum1, creditNum2, creditNum3, creditNum4, num1, num2, num3, num4);
					miss =  hitsAndMiss % 10; //To calculate the Miss, we'll take the remainder from the return of the function.
					hits =  hitsAndMiss / 10; //To calculate the hits, onsidered the return of the tens digit so we divide by ten without a residue.

					if (hits == 4) //falg to stop the loop if the users get 4 hits before he finished several chances 
					{
						chance = crazy;
						crazy = 0;			
					}
					
					printf("Hits = %d Miss = %d\n", hits, miss);
				}
				
				if (hits == 4) //Message if the game ended with a win 4 hits
				{
					
					printf("\n4 HITS YOU WON!!! \nIt took you only %d guesses, you are a professional code breaker!\n", chance);
					
				}
				
				if (hits < 4) //Message if the game ended with a lose hits small from 4 hits
				{
					
					printf("OOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts. \nNothing left for you... \n secret: %d%d%d%d", creditNum1, creditNum2, creditNum3, creditNum4);
					
				}
				break;
		}
	
		do	//Loop that checks w if the user wants to play again or not
		{
			again = getchar();
			printf("\nWould you like to play again? (y/n):");
			scanf("%c", &again);
			
		} while(again != 'y' && again != 'n');
	
	} while (again == 'y');
	
	if (again == 'n') //When the player asks not to do again
	{
		printf("\nBye Bye!\n");
	}
	
	system("pause");
	return 0;
}

/*
This function print openning screen game
input: none
output: none
*/
void splashScreen()
{
	printf("Welcome to 'MAGSHIMIM CODE-BREAKER'!!! \nA secret password was chosen to protect the credit card of Pancratius,\nthe descendant of Antiochus. \nYour mission is to stop Pancratius by revealing his secret password.");
	printf("\nThe rules are as follows: \n1. In each round you try to guess the secret password (4 distinct digits)");
	printf("\n2. After every guess you'll receive two hints about the password \nHITS:   The number of digits in your guess which were exactly right. \nMISSES: The number of digits in your guess which belongs to the password but were miss-placed.");
	printf("\n3. If you'll fail to guess the password after a certain number of rounds \nPancratius will buy all the gifts for Hanukkah!!!\n");
}

/*
This function does the function meet the conditions
input: random credit numbers
output: meet the conditions or not
*/
int checkRndNum(int creditNum1, int creditNum2, int creditNum3, int creditNum4)
{
	int valid = 0;
	
	if ((creditNum1 == creditNum2 || creditNum1 == creditNum3 || creditNum1 == creditNum4) || (creditNum2 == creditNum1 || creditNum2 == creditNum3 || creditNum2 == creditNum4) || (creditNum3 == creditNum1 || creditNum3 == creditNum2 || creditNum3 == creditNum4)) //
	{
		valid = 1;
	}
	
	return valid;
}

/*
This function print the difficulty levels we have in game
input: none
output:  none
*/
void difficultyLevels ()
{
	int opportunity = 0;
	
	printf("Please choose the game level: \n1 - Easy (20 rounds) \n2 - Moderate (15 rounds) \n3 - Hard (10 rounds) \n4 - Crazy (random number of rounds 5-25)\n");
}


/*
This function does the function meet the conditions
input: number from the users
output: meet the conditions or not
*/
int checkInput(int num1, int num2, int num3, int num4)
{
	int valid = 0;
	
	if ((num1 < 1 || num1 > 6 ) || (num2 < 1 || num2 > 6) || (num3 >6 || num3 < 1) || (num4 < 1 || num4 > 6)) //
	{
		valid = 1;
	}
	
	return valid;
}

/*
This function Checks the equality between the credit card numbers 
and the input numbers and checks how many times it is hits or miss
input: number from the users and the random credit card number 
output: the number hit and number miss 
*/

int parameterEquality(int creditNum1, int creditNum2, int creditNum3, int creditNum4,int num1, int num2, int num3, int num4)
{
	int hits = 0;
	int miss = 0;
	int hitsAndMiss = 0;
	
	if (creditNum1 == num1)
	{
		hits++;
	}
	else if (creditNum1 == num2 || creditNum1 == num3 || creditNum1 == num4)
	{
		miss++;
	}
	
	if (creditNum2 == num2)
	{
		hits++;
	}
	else if (creditNum2 == num1 || creditNum2 == num3 || creditNum2 == num4)
	{
		miss++;
	}
	
	if (creditNum3 == num3)
	{
		hits++;
	}
	else if (creditNum3 == num1 || creditNum3 == num2 || creditNum3 == num4)
	{
		miss++;
	}
	
	if (creditNum4 == num4)
	{
		hits++;
	}
	else if (creditNum4 == num1 || creditNum4 == num2 || creditNum4 == num3)
	{
		miss++;
	}
	
	hitsAndMiss = hits * 10 + miss; //So we can return hits and miss we do hits number * 10 and add miss.
	
	return hitsAndMiss;
}