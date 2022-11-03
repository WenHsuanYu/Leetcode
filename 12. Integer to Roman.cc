// TC: O(n), where n is the number of digits of num
// SC: O(1)
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> vec = {
            {1000, "M"}, //0
            {500, "D"}, //1
            {100, "C"},  // 2
            {50, "L"}, //3
            {10, "X"}, // 4
            {5, "V"},  // 5
            {1, "I"}  //6
        };
        
        string res = "";
        /* digits of number can be divided into four groups as following
        *  X, XX, XXX group one
        *  XL, group two
        *  L LX, LXX, LXXX group three
        *  XC  group four
        */
        
        for (int i = 0; i < vec.size(); i += 2) {
            int digit = num / vec.at(i).first;
            if (digit < 4) {
                for (int j = 1; j <= digit; ++j) {
                    res += vec[i].second;
                }
            } else if (digit == 4){
                res = res + vec[i].second + vec[i - 1].second;
            } else if (digit > 4 && digit < 9) {
                // cout << "digit: " << digit << endl;
                res += vec[i - 1].second;
                for (int j = 6; j <= digit; j++) {
                    res += vec[i].second;
                }
            } else if (digit == 9){
                res = res + vec[i].second + vec[i - 2].second;
            }
            num %= vec[i].first;
        }        
        
        return res;
    }
};