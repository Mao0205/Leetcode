/*
依序加入字元，檢查該字元是否出現過，依照出現過的位置下去判斷子字串長度。
這是最節省空間但耗時的方式。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0, tail = 0, i, j, max = 1;
        vector<int> num(s.length());
        if(s.empty())
            return 0;
        num[0] = 1;
        for (i = 1; i < s.length(); i++) {
            for (j = head; j <= tail; j++) {
                if (s[i] == s[j]) {
                    num[i] = tail-j+1;
                    head = j + 1;
                    break;
                } else {
                    num[i] = num[i - 1] + 1;
                }
            }
            tail++;
            if (num[i] > max)
                max = num[i];
        }
        return max;
    }
};
