/*
直接開一個256(ASCII總數)的向量去存所有字元先前出現過的位置，並藉此計算字串長度。
需要空間較大，但計算為O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> recode(256, -1);
        int i, head=0, distance=0, max=0;
        for(i=0;i<s.length();i++){
            if(recode[s[i]] != -1){
                if(recode[s[i]]+1 > head)
                    head = recode[s[i]]+1;
                distance = i-head+1;
            }else{
                distance++;
            }
            recode[s[i]] = i;
            if(distance > max)
                max = distance;
        }
        return max;
    }
};
