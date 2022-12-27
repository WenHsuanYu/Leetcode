// Using the BFS method via queue
// TC: O(4^n)
// SC: O(4^n)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) {
            return {};
        }
        vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        queue<string> q;
        q.push("");
        while (q.size() && q.front().size() != digits.size()) {
            auto front = q.front();
            q.pop();
            auto pool = letters[digits[front.size()] - '2'];
            for (auto ch : pool) {
                q.push(front+ch);
            }
        }
        while (q.size()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;

    }
};