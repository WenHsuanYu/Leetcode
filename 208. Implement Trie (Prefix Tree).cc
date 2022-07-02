//insert
//TC: O(m), where m is the key length
//SC: O(m)
//Search for a key
//TC: O(m)
//SC: O(1)
//Search for a key prefix
//TC: O(m)
//SC: O(1)
class Trie {
    
    struct TrieNode {
        struct TrieNode *child[26] = {[0 ... 25] = nullptr};
        bool isEnd;
        TrieNode (): isEnd(false) {
            
        }
    };
    TrieNode* root;
    
    
    
public:
    Trie() {
        root = new TrieNode();   
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char i: word) {
            if (node->child[i - 'a'] == nullptr) {
                node->child[i - 'a'] = new TrieNode();
            }
            node = node->child[i - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char i: word) {
            if (node->child[i - 'a'] != nullptr) {
                node = node->child[i - 'a'];
            } else {
                return false;
            }
        }
        return  node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char i: prefix) {
            if (node->child[i - 'a'] != nullptr) {
                node = node->child[i - 'a']; 
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */