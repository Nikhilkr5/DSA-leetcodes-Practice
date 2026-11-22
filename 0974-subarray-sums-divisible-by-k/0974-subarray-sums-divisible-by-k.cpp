//  BruteForce Approach
/*
🗣️ What to SAY:
Check all subarrays and count those whose sum is divisible by k.
⏱ Complexity: O(n²)
*/
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         for(int i = 0; i < n; i++) {
//             int sum = 0;
//             for(int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if(sum % k == 0)
//                     count++;
//             }
//         }

//         return count;
//     }
// };

/*
🟢 2. Optimal (Prefix + HashMap + Modulo) ⭐:
👉 Expected interview solution

🗣️ What to SAY:
We use prefix sum and store frequency of (sum % k).
If two prefix sums have same remainder, their difference is divisible by k.
*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();
        int res =0;
        int sum =0;
        unordered_map<int, int> f;
        f[0] =1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum%k;
            if(rem <0){            
                rem +=k;
            }
            res += f[rem];
            f[rem]++;
        }
        return res;
        
    }
};