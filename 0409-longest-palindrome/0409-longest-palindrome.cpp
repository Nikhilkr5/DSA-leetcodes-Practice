class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        // for(int i=0;i<n;i++){
        //     mp[s[i]]++;
        // }
        for(char c : s)
            mp[c]++;

        int res =0;
        bool odd = false;
        
        for(auto i: mp){
            int val = i.second;

            if(val % 2 == 0){
                res += val;
            }
            else{
                res += val - 1;   // add usable part immediately
                odd = true;
            }
        }
        if(odd)
            res +=1;

        return res;
    }
};

/*
⏱ Complexity Analysis:

Let n = length of the string s.
🔹 Time Complexity

Building the frequency map:
for(char c : s)
    mp[c]++;

This runs n times → O(n).

Iterating over the map:
The map can contain at most:
52 characters (uppercase + lowercase English letters)
So this loop runs at most 52 times → O(1).

✅ Total Time Complexity:
    O(n)+O(1)=O(n)

🔹 Space Complexity:
The unordered_map stores at most:
    52 different characters.

That does not depend on n.

✅ Space Complexity: O(1)

(Constant space because character set is fixed.)

🎯 Final Answer (Interview Ready):
Time Complexity: O(n)
Space Complexity: O(1)

If the interviewer asks:
What if the character set was not limited?
Then space complexity would become: O(n)
(because all characters could be unique).
*/