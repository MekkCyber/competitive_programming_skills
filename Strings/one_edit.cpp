/*
    
    You're given two strings stringOne and stringTwo.
    Write a function that determines if these two strings can be made equal
    using only one edit.
    You're given two strings stringOne and stringTwo.
    Write a function that determines if these two strings can be made equal
    using only one edit.
    There are 3 possible edits:
        Replace: One character in one string is swapped for a different
        character.
        Add: One character is added at any index in one string.
        Remove: One character is removed at any index in one string.
    Note that both strings will contain at least one character. If the strings
    are the same, your function should return true.
    Ex : 
    stringOne = "hello"
    stringTwo = "hollo"

    Output : True // A single replace at index 1 of either string can make the strings equal

*/

#include <cstdlib>
using namespace std;

bool oneEdit(string stringOne, string stringTwo) {
  if (abs(int(stringOne.size()-stringTwo.size()))>1) return false;
  if (stringOne.size()==stringTwo.size()){
    int i = 0;
    int update = 0;
    while (i<stringOne.size()){
      if (stringOne[i]!=stringTwo[i] && update==1) return false;
      if (stringOne[i]!=stringTwo[i] && update==0) update++;
      i++;
    }
  }
  if (stringOne.size()<stringTwo.size()){
    swap(stringOne,stringTwo);
  }
  if (stringOne.size()-stringTwo.size()==1){
    int firstp = 0;
    int secondp = 0;
    int update = 0;
    while (firstp<stringOne.size() && secondp<stringTwo.size()){
      if (stringOne[firstp]!=stringTwo[secondp] && update==1) return false;
      else if (stringOne[firstp]!=stringTwo[secondp] && update==0){
        firstp++;
        update++;
      } else {
        firstp++;
        secondp++;
      }
    }
  }
  return true;
}

// we could have had grouped all the cases in one while loop regardless of the length,and inside the while change the indexes according to the length