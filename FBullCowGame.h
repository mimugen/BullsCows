#pragma once

#include<iostream>

// To be consistent with UnrealEngine API
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

enum class EWordStatus
{
  OK,
  NOT_ISOGRAM,
  WRONG_LEGTH,
  NOT_VALID_INPUT
};

class FBullCowGame
{
public:
  FBullCowGame();
  void Reset();
  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const;
  bool IsGameWon() const;
  EWordStatus CheckGuessValidity(FString) const;
  FBullCowCount SubmitGuess(FString);
  // TODO add a method to provide feedback during game
  // number of bulls & cows
  // and try increment
private:
  int32 CurrentTry;
  int32 MaxTries;
  FString HiddenWord;
};
