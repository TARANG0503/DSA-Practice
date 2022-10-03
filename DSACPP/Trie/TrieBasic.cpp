#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    map<char, TrieNode *> *children;
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        this->children = new map<char, TrieNode *>();
        this->isTerminal = false;
    }
};

void insert(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char firstCh = word[0];
    if (root->children->find(firstCh) == root->children->end())
    {
        auto p = make_pair(firstCh, new TrieNode(firstCh));
        root->children->insert(p);
    }

    insert(root->children->at(firstCh), word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char firstCh = word[0];
    if (root->children->find(firstCh) == root->children->end())
        return false;

    return searchWord(root->children->at(firstCh), word.substr(1));
}

void deleteUTIL(TrieNode *root, string word, bool &deleteNext)
{
    if (word.length() == 0)
    {
        if (root->children->size() == 0)
        {
            deleteNext = true;
        }
        root->isTerminal = false;
        return;
    }

    deleteUTIL(root->children->at(word[0]), word.substr(1), deleteNext);
    if (deleteNext == true)
    {
        root->children->erase(word[0]);

        if (root->isTerminal || root->children->size() > 0)
            deleteNext = false;
    }
}

void deleteWord(TrieNode *root, string word)
{
    if (searchWord(root, word))
    {
        bool deleteNext = false;
        deleteUTIL(root, word, deleteNext);
    }
    else
    {
        cout << word << " is NOT FOUND and can't be Deleted!!" << endl;
    }
}

int main()
{
    TrieNode *root = new TrieNode('\0');
    int ch;
    string word;
    do
    {
        cout << "YOUR CHOICES:\n(1)INSERT a Word,  (2)SEARCH a Word,  (3)DELETE a Word  (4)EXIT" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the Word to be inserted: ";
            cin >> word;
            insert(root, word);
            break;
        case 2:
            cout << "Enter the Word to Search: ";
            cin >> word;
            if (searchWord(root, word))
            {
                cout << word << " is PRESENT !!" << endl;
            }
            else
            {
                cout << word << " is NOT FOUND !!" << endl;
            }
            break;
        case 3:
            cout << "Enter the Word to Delete: ";
            cin >> word;
            deleteWord(root, word);
            break;
        case 4:
            cout << "Exiting the Program !!";
            break;
        default:
            cout << "Enter a Wrong Choice !!" << endl;
        }
        cout << endl;

    } while (ch != 4);

    return 0;
}