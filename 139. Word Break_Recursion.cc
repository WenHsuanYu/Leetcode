//Using Recursion with memorization
//TC: O(n^3)
//SC: O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<int> mem(s.size(), 0);
        return wordRecur(s, st, 0, memo);
    }
    
    bool wordRecur(string& s, set<string>& st, int start, vector<int>& memo) {
        if (start == s.size()) {
            return true;
        }
        
        if (memo[start] != 0) {
            return memo[start];   
        }
        //range of index: [start, end)
        for (int end = start + 1; end <= s.size(); end++) {
            if (st.find(s.substr(start, end - start)) != st.end() && wordRecur(s, st, end, memo)) {
                return memo[start] = true;
            }
        }
        
        return memo[start] = false;
    } 
    
};

//Brute force
//TC: O(2^n)
//SC: O(n)
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        // In the memo table, -1 stands for the state not yet reached,
        // 0 for false and 1 for true
        vector<int> memo(s.length(), -1);
        return wordBreakMemo(s, word_set, 0, memo);
    }

    bool wordBreakMemo(string& s, set<string>& word_set, int start, vector<int>& memo) {
        if (start == s.length()) {
            return true;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (word_set.find(s.substr(start, end - start)) != word_set.end() and
                wordBreakMemo(s, word_set, end, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
};
*/