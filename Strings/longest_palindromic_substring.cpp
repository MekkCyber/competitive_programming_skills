/*

    Write a function that, given a string, returns its longest palindromic substring.
    A palindrome is defined as a string that's written the same forward and
    backward. Note that single-character strings are palindromes.
    Ex : string = "abaxyzzyxf"
    output : "xyzzyx"
*/

/*
    The bruteforce is looking for all the substrings and checking for palindroms O(n^3)
    a more sophisticated idea is to consider every character and every space between characters (for even length palindroms)
    as the center of a palindrom and try to expand to the right and to the left to verify if thats true or not, this is a O(n²) approach
*/

using namespace std;

vector<int> getLongestPalindrom(string str,int i,int j){
  while (i>=0 && j<str.size()){
    if (str[i]!=str[j]){
      break;
    }
    i--;
    j++;
  }
  return {i+1,j};
}

string longestPalindromicSubstring(string str) {
  vector<int> longestString = {0,1};
  for (int i = 1; i<str.size(); i++){
    vector<int> odd = getLongestPalindrom(str,i-1,i+1);
    vector<int> even = getLongestPalindrom(str,i-1,i);
    vector<int> longest = odd[1]-odd[0] > even[1]-even[0] ? odd : even;
    longestString = longest[1]-longest[0] > longestString[1]-longestString[0] ? longest : longestString;
  }
  return str.substr(longestString[0],longestString[1]-longestString[0]);
  
}