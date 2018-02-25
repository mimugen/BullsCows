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
  constexpr int32 MAX_TRIES = 8;
  const FString HIDDEN_WORD = "Testword";

  CurrentTry = 1;
  MaxTries = MAX_TRIES;
  HiddenWord = HIDDEN_WORD;
  return;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
  return EWordStatus::OK;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
  // assumes this receives a valid guess
  CurrentTry++;
  int32 HiddenWordLength = HiddenWord.length();
  int32 GuessWordLength = Guess.length();

  FBullCowCount BullCowCount;

  for(int32 i = 0; i < HiddenWordLength; i++){
      if(Guess[i] == HiddenWord[i] && i < GuessWordLength){
          BullCowCount.Bulls++;
        }else{
          BullCowCount.Cows++;
        }
  }
  return BullCowCount;
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

int32 FBullCowGame::GetHiddenWordLength() const
{
  return HiddenWord.length();
}



