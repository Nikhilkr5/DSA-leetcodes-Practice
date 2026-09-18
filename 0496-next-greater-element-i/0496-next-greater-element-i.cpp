class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> mp;
        
        // Part 1: nums2 ke har element ka Next Greater Element find karo
        for(int i = nums2.size() - 1; i >= 0; i--) {
            
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }
            
            st.push(nums2[i]);
        }
        
        // Part 2: nums1 mein jin elements ke answers chahiye,
        // unke answers map se nikalo
        vector<int> ans;
        
        for(int x : nums1) {
            ans.push_back(mp[x]);
        }
        
        return ans;
    }
};