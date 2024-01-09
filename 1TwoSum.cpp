/*
Solution2: 用雜湊的方式將需要的差值存起來，因雜湊查詢為常數，因此時間複雜度O(1)。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int i;
        unordered_map<int, int> q;
        vector<int> ans(2, 0);
        for (i = 0; i < nums.size(); i++) {           

            auto it = q.find(target-nums[i]);
            if(it != q.end()){
                ans[0] = q[target - nums[i]];
                ans[1] = i;
                break;
            }
            q[nums[i]] = i;
        }
        return ans;
    }
};

//Solution1: Two for loop O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> ans(2);
        for(i=0;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
