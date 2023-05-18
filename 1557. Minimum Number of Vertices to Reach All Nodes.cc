class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> st(n);
        for (const auto& e : edges) {
            st[e[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (st[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};