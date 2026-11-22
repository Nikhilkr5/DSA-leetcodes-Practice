class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxEnding = nums[0];
        int minEnding = nums[0];

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
 
        for(int i=1;i<n;i++){
            maxEnding = max(nums[i], maxEnding +nums[i]);
            maxSoFar = max(maxSoFar, maxEnding);
            

            minEnding = min(nums[i], minEnding + nums[i]);
            minSoFar = min(minSoFar, minEnding);
        }
        return max(abs(maxSoFar), abs(minSoFar));
        
    }
};
/*
;
🧠 Key Learning:
For 1749:
Do NOT merge max and min transitions.
Run two independent Kadanes.

⏱ Complexity:
Time: O(N)
Space: O(1)
*/