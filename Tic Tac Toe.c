#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Initialize global variables.
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void displayBoard();
int  freeMoves();
void player_();
void computer_();
char checkResults();
void printResults(char);



int main()
{
   char results = ' ';
   char answer = ' ';
   char name[100];   
   int x, y;

   printf("*************************************\n"); 
   printf("Tic Tac Toe\n"); 
   printf("COMP 2130 - Winter 2024\n"); 
   printf("You will be playing against a computer\n"); 
   printf("*************************************\n");


    // Prompts user for name. 
    printf("\nwhat is your name: \n"); 
    scanf("%s", name); 
    
    //Displays name and intializes game to begin
    printf("\nHello, %s... Let's have fun !!! You = X | Computer = O\n", name);

    // Loops the game until a winner or no more free spaces are available then breaks loop.
   do
   {
      results = ' ';
      answer = ' ';
      resetBoard();

      while(results == ' ' && freeMoves() != 0)
      {
         displayBoard();

         player_();
         results = checkResults();
         if(results != ' ' || freeMoves() == 0)
         {
            break;
         }

         computer_();
         results = checkResults();
         if(results != ' ' || freeMoves() == 0)
         {
            break;
         }
      }

      displayBoard();
      printResults(results);

   } while (answer == 'Y');

   return 0;
}
// Resets Tic Tac Toe board
void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
// Display Tic Tac Toe board
void displayBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
// Show how many spaces are still left on the board 
int freeMoves()
{
   int openSquares = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            openSquares--;
         }
      }
   }
   return openSquares;
}
// Players moves
void player_()
{
   int x;
   int y;

   do
   {    // Prompts user for row choice
        printf("Enter coordinates for x: ");
        scanf("%d", &x);
        x--;

        // Prompts user for column choice
        printf("Enter y coordinates: ");
        scanf("%d", &y);
        y--;

        // Prompts invalid move if x & y are out of the array, if not makes move and breaks loop
        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
   } while (board[x][y] != ' ');
   
}
// Computers move which is set up through a randomizer
void computer_()
{
   //Creates a seed based on current time to randomize computers moves
   srand(time(0));
   int x;
   int y;

   if(freeMoves() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');
      
      board[x][y] = COMPUTER;
   }
   else
   {
      printResults(' ');
   }
}
char checkResults()
{
   //Checking for winner by rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //Checking for winner by  columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //Checking for winner by diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
// Printing the results of either: You win, You lose or tie
void printResults(char winner)
{
   if(winner == PLAYER)
   {
      printf("\n**********\n");
      printf("YOU WIN!\n");
      printf("**********\n");

      displayBoard();
   }
   else if(winner == COMPUTER)
   {
      printf("\n**********\n");
      printf("YOU LOSE!\n");
      printf("**********\n");

      displayBoard();
   }
   else
   {
      printf("\n**********\n");
      printf("TIE!\n");
      printf("**********\n");

      displayBoard();
   }
}