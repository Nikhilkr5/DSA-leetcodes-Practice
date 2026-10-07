class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prefixSum =0;
        int n = nums.size();
        vector<int>runningSum(n);

        for(int i=0;i<n;i++){
            runningSum[i] = nums[i] + prefixSum;
            prefixSum += nums[i];
        }
        return runningSum;
    }
};