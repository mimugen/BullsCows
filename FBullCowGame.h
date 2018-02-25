#pragma once

#include<iostream>

// To be consistent with UnrealEngine API
using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
  FBullCowGame();
  void Reset();
  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  bool IsGameWon() const;
  bool CheckGuessValidity(FString) const;
  // TODO add a method to provide feedback during game
  // number of bulls & cows
  // and try increment
private:
  int32 CurrentTry;
  int32 MaxTries;
};
