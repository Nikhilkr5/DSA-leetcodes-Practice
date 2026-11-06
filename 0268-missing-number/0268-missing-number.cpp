//Bruteforce Approach:

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int N = nums.size();
//         //Outer loop that runs from 1 to N:
//         for(int i =0;i<=N;i++){
//             int flag =0;
//             for(int j=0;j<N;j++){
//                 if(nums[j] == i){
//                     flag = 1;
//                     break;
//                 }
//             }
//             if(flag == 0) return i;
//         } 
//         return 0;       
//     }
// };


//Better Soln : Using Hashing
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>hash(n+1,0);

//         for(int x:nums){
//             hash[x] = 1;
//         }

//         for(int i=0;i<=n;i++){
//             if(hash[i] == 0)
//                 return i;
//         }
        
//         return -1;
//     }
// };

        
//Optimised Solution- Using sum

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum1 = n*(n+1)/2;
        int sum2 = 0;
        for(int i=0;i<n;i++){
            sum2+=nums[i];
        }

        int missing = sum1-sum2;

        if(missing != 0) return missing;

        return 0;        
    }
};


//Anther optimised solution will be using Xor



/*
LC 268 – Missing Number

Brute Force:
TC: O(N²)
SC: O(1)

Hashing:
TC: O(N)
SC: O(N)

Sum:
TC: O(N)
SC: O(1)

XOR:
TC: O(N)
SC: O(1)

*/