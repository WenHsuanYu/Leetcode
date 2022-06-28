//Using array method with optimized space
//TC: O(n)
//SC: O(1)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int hottest = 0;
        vector<int> ans(n, 0);
        for (int curr = n - 1; curr >= 0; curr--) {
            if (temperatures[curr] >= hottest) {
                hottest = temperatures[curr];
                continue;
            }
            //next or more days
            int day = 1;
            while (temperatures[curr] >= temperatures[curr + day]) {
                day += ans[curr + day];
            }
            ans[curr] = day;
        }
        return ans;
    }
};