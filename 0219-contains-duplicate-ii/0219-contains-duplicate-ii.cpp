// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();      

//         for(int i=0;i<n;i++){
//             unordered_set<int> st;
//             for(int j=i;j<=min(i+k, n-1);j++){
//                 if(st.count(nums[j]))
//                     return true;
//                 st.insert(nums[j]);    
//             }
//         }
//         return false;        
//     }
// };


/*
Complexity:
Outer loop: n
Inner loop: up to k

👉 Time = O(n * k)

Problem:
If n = 10^5 and k = 10^5
👉 This becomes 10^10 operations → TLE ❌
*/


// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {

//         int n= nums.size();
//         unordered_set<int> st;

//         for(int i=0;i<=min(k, n-1);i++){
//             if(st.count(nums[i])){
//                 return true;                
//             }
//             st.insert(nums[i]);
//         }

//         for(int i=k+1;i<n; i++){            
//             st.erase(nums[i-k-1]);      // remove old first
//             if(st.count(nums[i])){      // check BEFORE insert
//                 return true;
//             }
//             st.insert(nums[i]);         // then insert
            
//         }
//         return false;        
//     }
// };



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_set<int> st;

        // 🔹 Step 1: First window (size = k+1)
        for(int j = 0; j <= min(k, n - 1); j++) {
            if(st.count(nums[j])) {
                return true;
            }
            st.insert(nums[j]);
        }

        // 🔹 Step 2: Slide window
        int i = 0;
        for(int j = k + 1; j < n; j++) {
            st.erase(nums[i]);   // remove leftmost
            i++;

            if(st.count(nums[j])) {  // check BEFORE insert
                return true;
            }

            st.insert(nums[j]);  // insert new
        }

        return false;
    }
};