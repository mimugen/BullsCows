#include <iostream>
#include "FBullCowGame.h"

// To be consistent with UnrealEngine API
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

// main entry point of the game
int32 main()
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
  // TODO add ascii art or some decoration
  constexpr int32 WORD_LENGTH = 5;
  std::cout << "Welcome to Bulls and Cows!!"<< std::endl;
  std::cout << "Can you guess a "<< WORD_LENGTH <<" character letter I'm thinking of?\n";
  return;
}

// Get user input string
FText GetGuess()
{
  FText Guess = "";
  std::cout << "Enter your guess : ";
  std::getline(std::cin, Guess);
  return Guess;
}

// Game logic
void PlayGame()
{
  FBullCowGame BCGame;
  BCGame.Reset(); // current Try = 1, max Tries = 5
  const int32 NUMBER_OF_TURNS = BCGame.GetMaxTries();
  FText Guess = "";
  for(int32 count = 0; count<NUMBER_OF_TURNS; count++) //TODO change to while loop
  {
      Guess = GetGuess();
      //TODO validate input
      std::cout<<"You entered : " <<Guess<<std::endl;
  }
  // TODO add a game summary
}


bool AskToPlayAgain()
{
  std::cout<<"Do you want to play again? [Y/N]";
  FText Response = "";
  std::getline(std::cin, Response);
  if(Response[0] == 'y'|| Response[0] == 'Y')
    return true;
  std::cout<<"That's cool. You can launch the game again! See you then :)";
  return false;
}
