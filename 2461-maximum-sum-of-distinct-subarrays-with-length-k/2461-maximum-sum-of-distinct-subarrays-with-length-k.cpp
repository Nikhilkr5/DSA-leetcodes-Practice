//Optimised Approach:

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, Maxm =0;
        unordered_map<int, int> mp;
        int dups =0;

        //Initialise first window

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            sum += nums[i];
            if(mp[nums[i]] > 1){
                dups++;
            }
        }

        if(dups == 0){
            Maxm = max(Maxm, sum);
        }

        //Sliding Window
        for(int i=k;i< nums.size(); i++){
            int numToAdd =nums[i];
            int numToRemove = nums[i -k];

            mp[numToAdd]++;
            if(mp[numToAdd] > 1){
                dups++;
            }
            sum += numToAdd;

            if(mp[numToRemove] > 1){
                dups--;
            }
            mp[numToRemove]--;
            sum-=numToRemove;

            if(dups == 0){
                Maxm = max(Maxm, sum);
            }
        }
        return Maxm;        
    }
};
/*
Time Complexity: ⏱️
O(n)

Each element is added once and removed once from the sliding window.
Hash map operations (unordered_map insert/update) are O(1) average.

Space Complexity: 💾
O(k) (worst case O(n))

The hashmap stores frequencies of elements inside the window of size k.
If all elements are unique, it holds k entries.

✅ Summary:
Time: O(n)
Space: O(k) (≤ O(n))

*/



//BruteForce Approach
//T.C :
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n= nums.size();
//         long long Maxm = 0 , sum =0;
        

//         for(int i=0;i<=n-k;i++){
//             bool isDuplicate = false;
//             sum =0;
//             unordered_set<int> st;
//             for(int j=i;j<i+k;j++){
//                 if(st.find(nums[j]) != st.end()){
//                     isDuplicate = true;
//                     break;
//                 }
//                 st.insert(nums[j]);
//                 sum += nums[j];
//             }
//             if(!isDuplicate){
//                 Maxm = max(Maxm, sum);
//             }

//         }
//         return Maxm;
//     }
// };