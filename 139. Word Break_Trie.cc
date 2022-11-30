//Using Trie + DP method
//TC: O(max(N^2, S)), where N is the length of the string and S is the sum of length of all words in the dictionary
//SC: O(26*S + N)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for (auto str : wordDict) {
            trie->insert(str);
        }
        int len = s.size();
        vector<int> dp(len + 1, 0);
        dp[0] = true;
        for (int i = 0; i <= len; i++) {
            if (dp[i]) {
                TrieNode* ptr = trie->root;
                for (int j = i; j < len; j++) {
                    if (ptr->alpha[s[j] - 'a'] == nullptr) {
                        break;
                    }
                    ptr = ptr->alpha[s[j] - 'a'];
                    if (ptr->isEnd) {
                        dp[j + 1] = true;
                        //i = j;
                    }
                }
            }
        }
        return dp.back();
    }
    
private:
    class TrieNode {
        public:
            vector<TrieNode*> alpha;
            bool isEnd;
            TrieNode(): isEnd(false), alpha(vector<TrieNode*>(26, nullptr)) 
            {
                
            }
            
    };
      
    class Trie{
        public:
            TrieNode* root;
            Trie() {
                root = new TrieNode();
            }
            void insert(string word) {
                TrieNode* ptr = root;
                int len = word.size();
                for (int i = 0; i < len; i++) {
                    if (ptr->alpha[word[i] - 'a'] == nullptr) {
                        ptr->alpha[word[i] - 'a'] = new TrieNode();
                    }
                    ptr = ptr->alpha[word[i] - 'a'];
                }
                ptr->isEnd = true;
            }
        
           void free_all(TrieNode* curs){
               if (!curs) {
                  return;
               }
               for (int i = 0; i < 27; i++) {
                   free_all(curs->alpha[i]);
               }
               delete curs;
           }
            ~Trie(){
                free_all(root);
            }
    };
};