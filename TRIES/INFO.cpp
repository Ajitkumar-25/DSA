#include<iostream>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;

    }
};

class Trie
{
     public: 
     TrieNode* root;
     Trie(){
        root=new TrieNode('\0');
     }

     void insertUtil(TrieNode* root,string word)
     { 
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return ;
        }
        //assuming entered word to be in caps
        int index=word[0]-'A';
        TrieNode* child;

        //if present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //if not prrsent;
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //now recursion
        insertUtil(child,word.substr(1));
         
     }
     void insertword(string word)
     {
        insertUtil(root,word);
     }

      bool searchUtil(TrieNode* root,string word)
      {
        if(word.length()==0)
        {
            return root->isTerminal;
        }
          int index=word[0]-'A';
          TrieNode* child;
          //if present
          if(root->children[index]!=NULL)
          {
            child=root->children[index];
          }
          //if absent
          else
          {
           return false;
          }
          //recursion
          return searchUtil(child,word.substr(1));

      }
     bool searchword(string word)
     {
      return searchUtil(root,word); 
     }





bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < 26; i++)
        if (root->children[i])
            return false;
    return true;
}



TrieNode* remove(TrieNode* root, string word)
{
    // If tree is empty
    if (!root)
        return NULL;
 
    // If last character of key is being processed
    if (word.size()==0) {
 
        // This node is no more end of word after
        // removal of given key
        if (root->isTerminal)
            root->isTerminal = false;
 
        // If given is not prefix of any other word
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
 
    int index = word[0] - 'A';
    root->children[index] =
          remove(root->children[index], word.substr(1));
 
   
    if (isEmpty(root) && root->isTerminal == false) {
        delete (root);
        root = NULL;
    }
 
    return root;
}
     TrieNode* remove(string word)
     {
        return remove(root,word);
     }


};
int main()
{
     Trie *t =new Trie();
t->insertword("AJIT");
t->insertword("PRITHVI");
t->insertword("DAVANSH");
t->insertword("ANSH");
t->insertword("AJITI");
 cout<<"present or not "<<t->searchword("AJITI")<<endl;
 cout<<"present or not "<<t->searchword("PRITHVI")<<endl;
 cout<<"present or not "<<t->searchword("AJIT")<<endl;
 cout<<"present or not "<<t->searchword("AJEET")<<endl;
 cout<<"present or not "<<t->searchword("DEV")<<endl;
 cout<<"present or not "<<t->searchword("ANSH")<<endl;

  remove("AJITI");
cout<<"present or not "<<t->searchword("AJITI")<<endl;
  cout<<"present or not "<<t->searchword("AJIT")<<endl;


 printAllWords(word);
   return 0; 
}