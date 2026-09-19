class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.size();
        stack<pair<char, int>> st;
        
        for(int i = 0; i < n; i++) {
            
            char c = s[i];
            
            if(st.empty()) {
                st.push({c, 1});
                continue;
            }
            
            if(st.top().first != c) {
                st.push({c, 1});
                continue;
            }
            
            if(st.top().second < k - 1) {
                
                pair<char, int> p = st.top();
                st.pop();
                
                st.push({p.first, p.second + 1});
                continue;
            }
            
            // count is k-1, current character makes it k
            st.pop();
        }
        
        string res = "";
        
        while(!st.empty()) {
            
            pair<char, int> p = st.top();
            st.pop();
            
            while(p.second--) {
                res.push_back(p.first);
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

// PRIMARY: Tutor's approach
// Stack stores {character, frequency}
// Same character -> increase frequency
// When frequency reaches k -> remove group

// ALTERNATIVE: Simpler implementation
// Same character -> count++
// count == k -> pop


// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
        
//         stack<pair<char, int>> st;
        
//         for(char ch : s) {
            
//             // Same character → increase its count
//             if(!st.empty() && st.top().first == ch) {
                
//                 st.top().second++;
                
//                 // k consecutive characters → remove them
//                 if(st.top().second == k) {
//                     st.pop();
//                 }
//             }
//             else {
//                 // New character
//                 st.push({ch, 1});
//             }
//         }
        
//         string ans = "";
        
//         // Build result from stack
//         while(!st.empty()) {
//             ans += string(st.top().second, st.top().first);
//             st.pop();
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         return ans;
//     }
// };