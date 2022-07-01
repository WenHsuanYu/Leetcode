class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> vec(26, 0);
        //let a be 0, b be 1....
        //vec[a = 0] = last occurance
        for(int i = 0; i < n; i++) {
            vec[s[i] - 'a'] = i;
        }
        
        int last = 0;
        int first = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            //expand partition from last or not
            last = last > vec[s[i] - 'a'] ? last : vec[s[i] - 'a'];
            if (i == last) {
                ans.push_back(last - first + 1);
                first = i + 1;
            }
        }
        return ans;
        
    }
};