/*
    Trie can brought search complexities to an optimal limit. If we store keys in BST it will need time M * log N,
    where M is maximum string length and N is number of keys in tree.
    With Trie, we can search the key in O(M) time.
*/

#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

class TrieNode
{
public:
    TrieNode **children;
    bool isEndOfWord;
    TrieNode()
    {
        children = new TrieNode *[ALPHABET_SIZE];
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

void insert(TrieNode *root, string str)
{
    TrieNode *current = root;
    for (int i = 0; i < str.length(); i++)
    {
        int ch = int(str[i] - (int)'a');
        if (current->children[ch] == NULL)
        {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->isEndOfWord = true;
}

bool find(TrieNode *root, string str)
{
    TrieNode *current = root;
    int i;
    for (i = 0; i < str.length(); i++)
    {
        int ch = int(str[i] - (int)'a');
        if (current->children[ch] == NULL)
            break;
        current = current->children[ch];
    }

    return i == str.length() && current->isEndOfWord;
}

int main()
{
    TrieNode *root = new TrieNode();
    insert(root, "the");
    insert(root, "arijit");
    insert(root, "ari");
    insert(root, "arijijtChowdhury");

    if (find(root, "arijit"))
    {
        cout << "Found -> arijit\n";
    }
    else
    {
        cout << "Not Found\n";
    }
}