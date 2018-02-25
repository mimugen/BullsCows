#include "FBullCowGame.h"

// To be consistent with UnrealEngine API
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
  Reset();
}
void FBullCowGame::Reset()
{
  CurrentTry = 1;
  MaxTries = 5;
  return;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
  return true;
}

bool FBullCowGame::IsGameWon() const
{
  return false;
}

int32 FBullCowGame::GetMaxTries() const
{
  return MaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
  return CurrentTry;
}



