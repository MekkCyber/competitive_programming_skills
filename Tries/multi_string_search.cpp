/*
    Write a function that takes in a big string and an array of small strings,
    all of which are smaller in length than the big string. The function should
    return an array of booleans, where each boolean represents whether the small
    string at that index in the array of small strings is contained in the big
    string.
    Ex : bigString = "this is a big string"
    smallStrings = ["this", "yo", "is", "a", "bigger", "string", "kappa"]
    output : [true, false, true, true, false, true, false]
*/

// First approach : construct a Trie for the big string, and for every small string check if it exists in this trie : O(b²+ns) time and O(b²+n)
// where b the size of the big string, n the number of small strings, and s the length of the longest small string
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie(string str)
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void populateSuffixTrieFrom(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            string substring = str.substr(i);
            insert(substring);
        }
    }
    void insert(string str)
    {
        TrieNode *currentNode = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (currentNode->children.find(str[i]) == currentNode->children.end())
            {
                currentNode->children[str[i]] = new TrieNode();
            }
            currentNode = currentNode->children[str[i]];
        }
        if (currentNode->children.find(endSymbol) == currentNode->children.end())
        {
            currentNode->children[endSymbol] = nullptr;
        }
    }
    bool contains(string str)
    {
        int i = 0;
        TrieNode *currentNode = root;
        while (i < str.length())
        {
            if (currentNode->children.find(str[i]) == currentNode->children.end())
            {
                return false;
            }
            currentNode = currentNode->children[str[i]];
            i++;
        }

        return true;
    }
};
vector<bool> multiStringSearch(string bigString, vector<string> smallStrings)
{
    vector<bool> result;
    SuffixTrie *trie = new SuffixTrie(bigString);
    for (int i = 0; i < smallStrings.size(); i++)
    {
        result.push_back(trie->contains(smallStrings[i]));
    }
    return result;
}

/* Second approach : construct a Trie of small strings, and iterate over the big string. for each index
we check if from this index we have a substring in the trie. O(ns+bs) time and O(ns) space
When checking for substrings, we keep checking while the characters are equal, and in every iteration we need
to check wether there is an end symbol, if its the case we can assume that we found a substring, and we add it to a hashmap
that keeps track of substrings that have been found, and we keep traversing the trie if the characters keep to be equal
Ex : if we have ['big','bigger'] and bigString=["bigger"] */

    /*Python version of the explained approach :
    
    def multiStringSearch(bigString, smallStrings):
    trie = Trie()
    for string in smallStrings:
        trie.insert(string)
    containedString = {}
    for i in range(len(bigString)):
        findSmallStringsIn(bigString, i, trie, containedString)
    return [string in containedString for string in smallStrings]

    def findSmallStringsIn(string, startIdx, trie, containedStringns):
        currentNode = trie.root
        for i in range(startIdx, len(string)):
            currentChar = string[i]
            if currentChar not in currentNode:
                break
            currentNode = currentNode[currentChar]
            if trie.endSymbol in currentNode:
                containedStringns[currentNode[trie.endSymbol]] = True

    class Trie:
        def __init__(self):
            self.root =
        {}
            self.endSymbol = '*'

        def insert(self, string):
            current = self.root
            for i in range(len(string)):
                if string[i] not in current:
                    current[string[i]] = {}
                current = current[string[i]]
            current[self.endSymbol] = string
*/