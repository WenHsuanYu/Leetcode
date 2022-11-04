//TC: O(n)
//SC: O(1)
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        int sum = 0;
        for (const auto &i: nums) {
            cout << i << endl;
            if ((i & 1) == 0 && i % 3 == 0) {
                cout << i << endl;
                sum += i;
                count++;
            }
            
        }
        return count != 0 ? sum / count : count ;
    }
};