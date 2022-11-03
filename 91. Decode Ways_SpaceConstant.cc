//TC:O(N)
//SC:O(1)
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') 
            return 0;
        //when position is at index i, first_front means the number of way of decoding at i - 1 
        int first_front = 1;
        //when position is at index i, first_front means the number of way of decoding at i - 2 
        int second_front = 1;
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            if (s[i] == '0') 
                first_front = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                //renew
                first_front = first_front + second_front;
                second_front = first_front - second_front;
            } else {
                second_front = first_front;
            }
        }
        return first_front;
    }
};
