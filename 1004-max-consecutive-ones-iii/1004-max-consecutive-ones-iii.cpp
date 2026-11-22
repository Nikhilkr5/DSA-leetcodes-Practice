class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low =0,  high =0;
        int res = 0;

        int zeroCount = 0;

        while(high < n){
            if(nums[high] == 0) zeroCount++;
            
            while(zeroCount > k){
                if(nums[low] == 0) zeroCount--;
                low++;
            }
            int len = high - low + 1;
            res = max(res,len);

            high++;
        }
        return res;
        
    }
};