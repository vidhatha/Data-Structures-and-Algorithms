#include <iostream>
#define ALPHABET_SIZE 26
using namespace std;

typedef struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
     //isEndofWord is true if the node represents
    // end of a word
    bool isEndofWord;
}TrieNode;

TrieNode* getNode()
{
    TrieNode *node = new TrieNode();
    for(int i=0;i<ALPHABET_SIZE;i++) 
        node->children[i] = NULL;
    
    node->isEndofWord = false;
}

void insert(TrieNode* root,string word)
{
    for(int i=0;i<word.length();i++)
    {
        int letter_index = word[i] - 'a';
        if(root->children[letter_index]==NULL)
            root->children[letter_index] = getNode();
        
        root = root->children[letter_index];
    }
    // mark last node as end of word
    root->isEndofWord = true;
}

bool search(TrieNode *root,string word)
{
    for(int i=0;i<word.length();i++)
    {
        int letter_index = word[i] - 'a';
        if(root->children[letter_index] == NULL)
            return false;
        
        root = root->children[letter_index];
    }
    
    if((root!=NULL) && (root->isEndofWord == true))
        return true;
}
bool areChildrenPresent(TrieNode *root)
{
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->children[i] != NULL)
            return true;
    }
    return false;
}
bool deleteWord(TrieNode* root,string word,int level)
{
    if(root!=NULL)
    {
        if(level == word.length())
        {
            if(root->isEndofWord == true) 
            {
                root->isEndofWord = false;
                //if no children are present
                //then node can be deleted
                if(!areChildrenPresent(root))
                    return true;
                    
                return false;
            }
        }
        else
        {
            int letter_index = word[level] - 'a';
            if(deleteWord(root->children[letter_index],word,level+1))
            {
                //last node marked, delete it
                free(root->children[letter_index]);
                root->children[letter_index] = NULL;
                
                // recursively climb up, and delete eligible nodes
                return((!root->isEndofWord) && (!areChildrenPresent(root)));
            }
                
        }
    }
    return false;
}
    // Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    string keys[8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
 
    TrieNode *root = getNode();
    //TrieNode *root = head;
 
    // Construct trie
    int i;
    for (i = 0; i < 8; i++){
        insert(root, keys[i]);
        //cout<<"Insert: "<<keys[i]<<endl;
    }
    //TrieNode rootd;
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
    
    deleteWord(root,"the",0);
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    insert(root,"the");
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    
    return 0;
}

Time Complexity:
Insert: O(Word_Length)
Search: O(Word_Length)
Delete: O(Word_length)

Space Complexity: O(word_length*no_of_words*ALPHABET_SIZE)

//Output
the --- Present in trie
these --- Not present in trie
their --- Present in trie
thaw --- Not present in trie
the --- Not present in trie
the --- Present in trie
