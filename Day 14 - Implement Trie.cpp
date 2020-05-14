class Trie {
public:
    
    // IMPLEMENTED THE TRIE SUCCESSFULLY FROM SCRATCH IN MY FIRST ATTEMPT
    // THIS IS SO COOL
    
    typedef struct TrieNode
    {
       unordered_map<char, struct TrieNode*> child;
       unordered_map<char, bool> end;
    }*TRPTR;
    
    TRPTR root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    
    void addWord(TRPTR& root, string word, int i)
    {
        // basecase
        if(i==word.length()-1)
        {
            // cout<<"At the end!\n";
            // you're at the end of the string
            root->end[word[i]] = true;
            
            // create the last node if not already existing, and complete 
            if((root->child).find(word[i])==(root->child).end())
            {
                // cout<<"Couldn't find "<<word[i]<<endl;
                root->child[word[i]] = new TrieNode();
            }
            else
            {
                // cout<<"Found "<<word[i]<<endl;
            }
            return;
        }
        
        if((root->child).find(word[i])==(root->child).end())
        {
            // cout<<"Couldn't find "<<word[i]<<endl;
            root->child[word[i]] = new TrieNode();
            addWord(root->child[word[i]], word, i+1);
        }
        else
        {
            // if child is already present
            // cout<<"Found "<<word[i]<<endl;
            addWord(root->child[word[i]], word, i+1);
        }
    }
    
    bool searchWord(TRPTR root, string word, int i)
    {
        
        if((root->child).find(word[i])==(root->child).end())
        {
            // couldn't find the right child, not present
            // cout<<word[i]<<" not there!\n";
            return false;
        }
        else
        {
            if(i==word.length()-1)
            {
                // cout<<"At the end!\n";
                if(root->end[word[i]])
                {
                    // cout<<word[i]<<" present!\n";
                    return true;
                }
                else
                {
                    // cout<<word[i]<<" not present!\n";
                    return false;
                }
            }
            else
            {
                // cout<<"Continuing chain "<<word[i]<<endl; 
                return searchWord(root->child[word[i]], word, i+1);
            }
        }
        
    }
    
    bool startsWithWord(TRPTR root, string word, int i)
    {
        
        if((root->child).find(word[i])==(root->child).end())
        {
            // couldn't find the right child, not present
            return false;
        }
        else
        {
            if(i==word.length()-1)
            {
                // don't check for end, we're done
                return true;
            }
            else
            {
                return startsWithWord(root->child[word[i]], word, i+1);
            }
        }
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TRPTR original = root;
        addWord(root, word, 0);
        root = original;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchWord(root, word, 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithWord(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */