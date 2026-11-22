class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = nums[0];

        //Normal Kadane (Maximum)
        int maxEnding = nums[0];
        int maxSoFar = nums[0];

        //Minimum Kadane
        int minEnding = nums[0];
        int minSoFar = nums[0];

        for(int i=1;i<n;i++){
            totalSum += nums[i];

            //Maximum Kadane
            maxEnding = max(nums[i], maxEnding + nums[i]);
            maxSoFar = max(maxSoFar, maxEnding);

            //Minimum Kadane
            minEnding = min(nums[i], minEnding+nums[i]);
            minSoFar = min(minSoFar, minEnding);


        }
        //if all elements are negative
        if(maxSoFar < 0){
            return maxSoFar;
        }
        //Circular case:
        return max(maxSoFar, totalSum - minSoFar);        
    }
};

/*
🔥 Why This Works
Case 1: Normal
Just standard Kadane.
Case 2: Circular
Instead of selecting middle part,
we remove the minimum subarray.
So:
max circular sum = total sum - minimum subarray

📌 Pattern Summary:
LeetCode 918 uses:
Kadane (max)+Kadane (min)+Total Sum Trick

⏱ Complexity:
Time: O(N)
Space: O(1)

Optimal.

🎯 One-Line Memory Trick:
Circular max = max(normal max, total − minimum subarray)
*/