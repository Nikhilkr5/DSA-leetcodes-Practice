//Brute Force:
//T.C: O(n^2)
//S.C: O(1)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target){
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             for(int j =i+1;j<n;j++){
//                 int sum = nums[i] + nums[j];

//                 if(sum == target){
//                     return {i, j};
//                 }
//             }
//         }
//         return {-1,-1};
//     }     
// };



//Optimal Approach:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;   //Map to store element -> index
        int n= nums.size();
        for(int i=0;i<n;i++){
            int complement = target - nums[i];

            //if complement found , return indices
            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }

            //Store current element and index
            mp[nums[i]] = i;
        }
        return {-1,-1};  //or return {} //NO pair found       

    }
};

//T.C: O(n)
//S.C: O(n)