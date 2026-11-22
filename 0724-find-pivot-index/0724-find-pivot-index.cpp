//Brute Force Approach
/*🧠 Idea:

Har index ke liye:

left sum manually nikalo
right sum manually nikalo
✅ Code 
*/

/*
🟥 1. Brute Force
📌 What to say::::
For every index, calculate left and right sum separately using loops.
⏱ Complexity:
O(n²)

For each index, I calculate left and right sum using loops.
This leads to repeated computation.
*/

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             int left = 0, right = 0;

//             for(int j = 0; j < i; j++)
//                 left += nums[j];

//             for(int j = i + 1; j < n; j++)
//                 right += nums[j];

//             if(left == right)
//                 return i;
//         }

//         return -1;
//     }
// };



//Better Approach:

//To optimize, I precompute left and right sums using prefix and suffix arrays,
//so each index can be checked in O(1).

//⏱ Complexity:
//O(n) time, O(n) space

//Better Approach
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums){
//         int n= nums.size();
//         vector<int> prefix(n, 0);
//         vector<int> suffix(n,0);

//         //vector<int> prefix(n, 0), suffix(n, 0);

//         // prefix → left sum
//         for(int i=1;i<n;i++){
//             prefix[i] = prefix[i -1] + nums[i-1];

//         }

//         //suffix-> right sum
//         for(int i = n-2; i >= 0; i--){
//             suffix[i] = suffix[i+1] + nums[i + 1];
//         }

//         //find pivot
//         for(int i =0;i<n;i++){
//             if(prefix[i] == suffix[i])
//             return i;
//         }
//         return -1;
//     }
// };




//Optimal Approach(Best)

//Wa can Avoid extra space by using runniing sum 
//Right Sum can be derived from total sum

//Pattern: Prefix Sum Optimiszation(Running Sum)

/*
⏱ Complexity:
O(n) time, O(1) space ⭐
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        for(int i=0; i<n;i++){
            sum+= nums[i];
        }

        for(int i=0;i<n;i++){            
            int right = sum - nums[i] - left;
            if(left == right ) return i;
            left += nums[i];
        }
        return -1;       
    }
};


//if you wnat to use padho with pratush template then need to use an edge case at index 0 for inputs 2,1,-1
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         int left = 0;
//         int sum = 0;

//         for(int i = 0; i < n; i++){
//             sum += nums[i];
//         }

//         // ✅ Check index 0 separately
//         if(sum - nums[0] == 0)
//             return 0;

//         // Start from 1 (like your original code)
//         for(int i = 1; i < n; i++){
//             left += nums[i - 1];
//             int right = sum - nums[i] - left;
//             if(left == right)
//                 return i;
//         }

//         return -1;
//     }
// };



// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {

//         int n=nums.size();
//         int leftsum=0;
//         int rightsum=accumulate(nums.begin(),nums.end(),0);

//         for(int i=0;i<n;i++){
//             rightsum-=nums[i];
//             if(leftsum==rightsum){
//                 return i;
//             }
//             leftsum+=nums[i];
//         }
//         return -1;
        
//         // int n=nums.size();
//         // int rightsum=0;
//         // int leftsum=0;
        

//         // for(int i=0;i<n;i++){
//         //     rightsum+=nums[i];
//         // }
//         // for(int i=0;i<n;i++){
//         //     if(leftsum==rightsum-nums[i]){
//         //         return i;
//         //     }

//         //     leftsum+=nums[i];
//         //     rightsum-=nums[i];
//         // }
//         // return -1;            
//     }
// };


