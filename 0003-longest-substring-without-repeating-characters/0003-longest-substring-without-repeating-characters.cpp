// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {

//         int n = s.size();
//         int maxLen = 0;

//         for(int i = 0; i < n; i++) {

//             unordered_set<char> st;

//             for(int j = i; j < n; j++) {

//                 // duplicate found
//                 if(st.count(s[j]))
//                     break;

//                 st.insert(s[j]);

//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }

//         return maxLen;
//     }
// };
/*
Outer loop → O(n)
Inner loop → O(n)
Total → O(n²)


Time:
O(n²)

Space:
O(n)
*/


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> mp;
//         int i =0, j=0;
//         int maxlen =0;
//         int n =s.size();

//         while(j< n){
//             char c = s[j];

//             //if character seen and inside current window
//             if(mp.count(c) && mp[c] >= i){
//                 i = mp[c] + 1;
//             }

//             //Update last seen index
//             mp[c] = j;

//             maxlen = max(maxlen, j-i+1);
//             j++;
//         }
//         return maxlen;
//     }
// };

/*
Time:O(n)
Space:O(n)
*/

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int low =0, high =0;
//         int Maxlen = 0;
//         unordered_map<char, int> mp;

//         while(high < n){
//             char c = s[high];


//             if(mp.find(c) != mp.end() && mp[c] >= low){
//                 low = mp[c]+1;
//             }

//             mp[c] = high;

//             Maxlen = max(Maxlen, high - low + 1);
//             high++;
            
//         }
//         return Maxlen;        
//     }
// };

/*
Complexity:
Time:O(n)
Space:O(n)
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low =0, high =0;
        //int res = INT_MIN;
        int res = 0;

        unordered_map<char , int > f;

        while(high < n){
            f[s[high]]++;

            int k = high - low  + 1;

            while(f.size() < k){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
                k = high - low  + 1;
            }

            int len = high - low + 1;
            res = max(res, len);
            high++;
        }
        //return res == INT_MIN ? 0 : res;
        return res;        
    }
};



/*
Cleaner version :
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> f;

        int low = 0;
        int res = 0;

        for(int high = 0; high < s.size(); high++) {

            f[s[high]]++;

            while(f[s[high]] > 1) {

                f[s[low]]--;

                if(f[s[low]] == 0)
                    f.erase(s[low]);

                low++;
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};


*/