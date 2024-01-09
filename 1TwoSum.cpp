/*
- ordered_map用法：以雜湊表為data structure的型態。因此搜尋、新增或刪減的時間複雜度都為O(1)
- iterator(it)若指向二為，例如ordered_map，則it->second = q[index]; (當it指向q中index的位置)
*/

/*
Solution3: 跟2的解法差不多只是用count不用各地查找，因此時間複雜度O(1)，但其實ans[0]也會需要查找，等於count會被當作額外計算。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int i;
        unordered_map<int, int> q;
        vector<int> ans(2, 0);

        int index;
        for (i = 0; i < nums.size(); i++) {     
            if(q.count(target-nums[i])>0){
                ans[0] = q[target - nums[i]];
                ans[1] = i;
                break;
            }
            q[nums[i]] = i;
        }
        return ans;
    }
};

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
                ans[0] = it->second; //可以直接取出iterator所指的值, 用q[target-num[i]]等於重複寄算找位置。
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
