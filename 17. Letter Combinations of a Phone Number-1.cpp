class Solution {
public:
    const vector<string> d = {"", "", "abc", "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //BFS version
    //Time complexity: O(4^n)
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> res = {""};
        
        for (auto &digit : digits) { // max length: 4
            vector<string> tmp;
            for (auto ch : d[digit - '0']) { // all possible numbers of length n
                for (auto s : res) {
                    tmp.push_back(s + ch);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};