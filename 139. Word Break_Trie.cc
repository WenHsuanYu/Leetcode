//Using Trie + DP method
//TC: O(max(N^2, S)), where N is the length of the string and S is the sum of length of all words in the dictionary
//SC: O(26*S + N)
class TrieNode {
public:
    vector<TrieNode*> alpha;
    bool isEnd;
    TrieNode(): isEnd(false), alpha(vector<TrieNode*>(26, nullptr)) {
        
    }
};

class Trie{

    public:
        TrieNode* node;
        Trie(){
            node = new TrieNode();
        }
    
        void insert(string word) {
            TrieNode* root = node;
            int n = word.size();
            for (int i = 0; i < n; i++) {
                if (root->alpha[word[i] - 'a'] == nullptr) {
                    root->alpha[word[i] - 'a'] = new TrieNode();
                }
                root = root->alpha[word[i] - 'a'];
            }
            root->isEnd = true;
        }
        
        
    
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for (string str: wordDict) {
            trie->insert(str);
        }
        int len = s.size();
        vector<int> dp(len + 1, false);
        dp[0] = true;
        for (int i = 0; i <= len; i++) {

            if (dp[i]) {
                TrieNode* ptr = trie->node;
                for (int j = i; j < len; j++) {
                    if (ptr->alpha[s[j] - 'a'] == nullptr) {
                        break;
                    }
                    ptr = ptr->alpha[s[j] - 'a'];
                    if (ptr->isEnd) {
                        dp[j + 1] = true;
                        
                    } 
                }
            }
        }

        
        return dp[len];
    }
};