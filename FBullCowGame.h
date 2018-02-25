#pragma once

#include<iostream>

class FBullCowGame
{
public:
  void Reset();
  int GetMaxTries();
  int GetCurrentTry();
  bool IsGameWon();
  bool CheckGuessValidity(std::string);

private:
  int CurrentTry;
  int MaxTries;
};
