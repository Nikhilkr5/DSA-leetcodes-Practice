// //Brute FOrce Solution:
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             int cnt = 0;

//             for(int j = 0; j < n; j++) {
//                 if(nums[j] == nums[i])
//                     cnt++;
//             }

//             if(cnt == 1)
//                 return nums[i];
//         }

//         return -1;
//     }
// };


//Better Solution:USing unordered map    , arrayhashing will not work for arr containing negative numbers 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto &v: mp){
            if(v.second == 1) return v.first;
        }

        // for(int i = 0; i < n; i++) {
        //     if(mp[nums[i]] == 1)
        //         return nums[i];
        // }        
        return 0;        
    }
};


//Optimal Solution: Using xorr

/*
136. Single Number:
Brute → O(N²), O(1)
Better (Hashing) suning unordered map → O(N), O(N) average
Optimal (XOR) → O(N), O(1)
*/