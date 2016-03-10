class TrieNode {
public:
    // Initialize your data structure here.
        bool isword;
        unordered_map<char,TrieNode* > children;
        TrieNode():isword(false){};
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        int len = word.length();
        for(int i=0; i<len; ++i){
            if(cur->children.find(word[i])==cur->children.end()){
            /tcur->children[word[i]] = new TrieNode();
/t        }
            cur = cur->children[word[i]];
        }
        cur->isword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return retreive(word,false);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return retreive(prefix,true);
    }
    
    inline bool retreive(string & word,bool tag){
        int len = word.length();
        bool exist = true;
        TrieNode *cur = root;
        for(int i=0; i<len; ++i){
            if(cur->children.find(word[i])==cur->children.end()){
                return false;
/t        }
            cur = cur->children[word[i]];
        }
        return tag?exist:cur->isword;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
  