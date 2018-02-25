#include <iostream>
#include "FBullCowGame.h"

// To be consistent with UnrealEngine API
using FText = std::string;
using int32 = int;

void PrintIntro(int32);
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

// main entry point of the game
int32 main()
{
  do
    {
      PlayGame();
    } while (AskToPlayAgain());
  return 0;
}


// Introduce the Game and get user input
void PrintIntro(int32 HiddenWordLength)
{
  // TODO add ascii art or some decoration
  std::cout << "Welcome to Bulls and Cows!!"<< std::endl;
  std::cout << "Can you guess a "<< HiddenWordLength <<" character letter I'm thinking of?\n";
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
  PrintIntro(BCGame.GetHiddenWordLength());
  for(int32 count = 0; count<NUMBER_OF_TURNS; count++) //TODO change to while loop
  {
      Guess = GetGuess();
      FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
      //TODO validate input
      std::cout<<"Bulls =  " <<BullCowCount.Bulls<<", Cows =  " <<BullCowCount.Cows<<std::endl;
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
