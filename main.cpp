#include <iostream>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

// main entry point of the game

int main()
{
  do
    {
      PrintIntro();
      PlayGame();
    } while (AskToPlayAgain());
  return 0;
}


// Introduce the Game and get user input
void PrintIntro()
{
  constexpr int WORD_LENGTH = 5;
  std::cout << "Welcome to Bulls and Cows!!"<< std::endl;
  std::cout << "Can you guess a "<< WORD_LENGTH <<" character letter I'm thinking of?\n";
  return;
}

// Get user input string
std::string GetGuess()
{
  std::string Guess = "";
  std::cout << "Enter your guess : ";
  std::getline(std::cin, Guess);
  return Guess;
}

// Game logic
void PlayGame()
{
  FBullCowGame BCGame;
  constexpr int NUMBER_OF_TURNS = 5;
  std::string Guess = "";
  for(int count = 0; count<NUMBER_OF_TURNS; count++)
  {
      Guess = GetGuess();
      std::cout<<"You entered : " <<Guess<<std::endl;
  }
}


bool AskToPlayAgain()
{
  std::cout<<"Do you want to play again? [Y/N]";
  std::string Response = "";
  std::getline(std::cin, Response);
  if(Response[0] == 'y'|| Response[0] == 'Y')
    return true;
  std::cout<<"That's cool. You can launch the game again! See you then :)";
  return false;
}
