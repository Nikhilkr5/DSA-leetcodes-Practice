//Brute Force Approach::  TC = O(N²), SC = O(1).   //Time Limit Exceeded
// class Solution {
// public:
//     bool linearSearch(vector<int>&nums, int num){
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i] == num){
//                 return true;
//             }            
//         }
//         return false;
//     }
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0) return 0;
//         int longest =1;
//         for(int i=0;i<n;i++){
//             int x = nums[i];
//             int cnt =1;

//             while(linearSearch(nums,x+1)== true){
//                 x+=1;
//                 cnt+=1;
//             }
//             longest = max(longest,cnt);
//         }
//         return longest;
        
//     }
// };


//Better Approach: TC = O(N log N), SC = O(1) //Using sorting->Traversing -> Updating Count
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0) return 0;

//         //sort the array
//         sort(nums.begin(),nums.end());
//         int lastSmaller = INT_MIN;
//         int cnt =0;
//         int longest =1;

//         //find longest sequence:
//         for(int i=0;i<n;i++){
//             if(nums[i]-1 == lastSmaller){
//                 cnt +=1;
//                 lastSmaller = nums[i];
//             }
//             else if(nums[i] != lastSmaller){
//                 cnt =1;
//                 lastSmaller = nums[i];
//             }
//             longest = max(longest, cnt);
//         }
//         return longest;
//     }
// };


//Optimal Approach: Hashing Set : TC = O(N), SC = O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n ==0) return 0;

        int longest = 1;
        unordered_set<int>st;

        //put all the array elements into the set
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it -1) == st.end()){
                int cnt =1;
                int x =it;
                while(st.find(x+1) != st.end()){
                    x=x+1;
                    cnt+=1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;        
    }
};
