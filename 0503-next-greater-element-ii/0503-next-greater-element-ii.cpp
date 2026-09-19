class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i = 2 * n - 1; i >= 0; i--) {
            
            int index = i % n;
            
            while(!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }
            
            if(i < n) {
                
                if(st.empty()) {
                    ans[index] = -1;
                }
                else {
                    ans[index] = st.top();
                }
            }
            
            st.push(nums[index]);
        }
        
        return ans;
    }
};



/*

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        
        // First pass: put all elements in stack
        for(int i = n - 1; i >= 0; i--) {
            st.push(nums[i]);
        }
        
        // Second pass: find NGE
        for(int i = n - 1; i >= 0; i--) {
            
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                res[i] = -1;
            }
            else {
                res[i] = st.top();
            }
            
            st.push(nums[i]);
        }
        
        return res;
    }
};



*/


/*
LC 503 – Next Greater Element II

Approach: Monotonic Decreasing Stack + Circular Array
Traversal: Right → Left, 2*n times
Circular index: i % n
Pop: st.top() <= nums[i]
Answer: Stack top = NGE, else -1
Time: O(n)
Space: O(n)
Pattern: Next Greater Element + Circular Array

*/









// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> ans(n, -1);
//         stack<int> st;
        
//         // Traverse 2*n elements
//         for(int i = 2 * n - 1; i >= 0; i--) {
            
//             int index = i % n;
            
//             while(!st.empty() && st.top() <= nums[index]) {
//                 st.pop();
//             }
            
//             // Only first n iterations correspond to actual indices
//             if(i < n) {
//                 if(!st.empty()) {
//                     ans[index] = st.top();
//                 }
//             }
            
//             st.push(nums[index]);
//         }
        
//         return ans;
//     }
// };