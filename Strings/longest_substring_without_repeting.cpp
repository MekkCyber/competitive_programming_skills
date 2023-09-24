/*
    Given a string s, find the length of the longest substring without repeating characters.
*/
/*
    The idea is to start with left and right pointer, the right pointer starts moving, and whenever it encounters 
    a character that was already in the hashmap where we keep visited characters, the startIndex moves forward until
    s[startIndex]!=s[endIndex], we then increment startIndex once more, and keep moving endIndex.

    An interesting idea is instead of using a hashmap that only stores if a character is visited or not, we store instead
    the index of the character in the string, so we avoid using a while loop and startIndex can be directly equal to hashmap[character]+1
    The code that corresponds to this approach is written in comment in python below
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int startIndex = 0;
        int endIndex = 0;
        int longest = 0;
        int sub_length = 0;
        unordered_map<char,bool> exists;
        while (endIndex<s.size()){
            sub_length++;
            if (exists[s[endIndex]]){
                while(startIndex < endIndex && s[startIndex]!=s[endIndex]){
                    exists[s[startIndex]] = false;
                    startIndex++;
                    sub_length--;
                }
                startIndex++;
                sub_length--;
            } else {
                exists[s[endIndex]] = true;
            }
            longest = max(longest,sub_length);
            endIndex++;
        }
        return longest;
    }
};

/*
    class Solution(object):
    def lengthOfLongestSubstring(self, s):
        seen = {}
        l = 0
        length = 0
        for r in range(len(s)):
            char = s[r]
            if char in seen and seen[char] >= l:
                l = seen[char] + 1
            else:
                length = max(length, r - l + 1)
            seen[char] = r

        return length
*/
