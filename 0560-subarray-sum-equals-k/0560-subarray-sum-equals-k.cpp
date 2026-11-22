/*
🟥 1. Brute Force
🗣️ What to SAY:
Check all subarrays and count those whose sum equals k.
⏱ Complexity:  O(n²)
*/


// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         for(int i = 0; i < n; i++) { 
//             int sum = 0;
//             for(int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if(sum == k)
//                     count++;
//             }
//         }
//         return count;
//     }
// };



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int sum =0;
        int res =0;
        unordered_map<int,int> f;

        f[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int ques = sum-k;
            int freq = f[ques];
            res += freq;
            f[sum]++;
        }
        return res;
    }
};

/*
⏱ Complexity:
Time: O(n)
Space: O(n) (worst case all prefix sums unique)

Optimal solution.
*/