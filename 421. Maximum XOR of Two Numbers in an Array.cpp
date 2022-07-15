// TC: O(n)
// SC: O(1)
struct Node{
public:
    Node* next[2];

    Node()
    {
        next[0] = next[1] = nullptr;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int data){
        Node* r = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (data >> i) & 1;
            if (r->next[bit] == NULL) {
                r->next[bit] = new Node();
            }
            r = r->next[bit];
        }
    }
    
    int max_xor_helper(int data) {
        Node* r = root;
        int max_val = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (data >> i) & 1;
            if(r->next[!bit]) {
                max_val += (1 << i);
                r = r->next[!bit];
            } else {
                r = r->next[bit];
            }
                
        }
        return max_val;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* myNums = new Trie();
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            myNums->insert(nums[i]);
            res = max(res, myNums->max_xor_helper(nums[i]));
        }
        delete myNums;
        return res;
    }
};