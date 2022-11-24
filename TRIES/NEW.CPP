#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Recursive function to delete a key from given Trie
TrieNode *remove(TrieNode *root, string key, int depth = 0)
{
    // If tree is empty
    if (!root)
        return NULL;

    // If last character of key is being processed
    if (depth == key.size())
    {

        // This node is no more end of word after
        // removal of given key
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // If given is not prefix of any other word
        if (isEmpty(root))
        {
            delete (root);
            root = NULL;
        }

        return root;
    }

    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] =
        remove(root->children[index], key, depth + 1);

    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isEndOfWord == false)
    {
        delete (root);
        root = NULL;
    }

    return root;
}

bool isLeafNode(struct TrieNode *root)
{
    return root->isEndOfWord != false;
}

void display(struct TrieNode *root, char str[], int level)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (isLeafNode(root))
    {
        str[level] = '\0';
        cout << str << endl;
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

// Driver
int main()
{

    /*


    */
    // Input keys (use only 'a' through 'z'
    // and lower case)
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n\t\t\t\t\t\tWELCOME TO THE NAME DIRECTORY";
    cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    int choice;
    cout << "\n\n1.Press for Adding name to directory";
    cout << "\n2.press for searching any name in the directory";
    cout << "\n3.press for deleting and name from the directory";
    cout << "\n4.press for displaying all the names in thye directory";
    cout<<"\n\n\t\t\t\tEnter you choice: ";
    cin>>choice;
    // switch(choice)
    // {
    //     case 1: cout<<"\nEnter the name to be added :";
    //     break;
    //     case 2: cout<<"\nEnter the name to be searched : ";
    //     break;
    //     case 3: cout<<"\nEnter the name to be deleted : ";
    //     break;
    //     // case 4: display(root, str, level);
    //     break;

    // }
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their", "hero", "heroplane"};
    int n = sizeof(keys) / sizeof(keys[0]);
      
    struct TrieNode *root = getNode();
    cout << "\n\n\n";
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    char output[][32] = {"Not present in trie", "Present in trie"};

    // Search for different keys
    cout << "the"
         << " --- " << output[search(root, "the")] << endl;
    cout << "these"
         << " --- " << output[search(root, "these")] << endl;
    cout << "their"
         << " --- " << output[search(root, "their")] << endl;
    cout << "thaw"
         << " --- " << output[search(root, "thaw")] << endl;

    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";

    //removing any name 
    remove(root, "heroplane");
    search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n";

    int level = 0;
    char str[20];

    // Displaying content of Trie
    cout << "Content of Trie: " << endl;
    display(root, str, level);

    return 0;
}