class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int i;
        for(i =0;i<n;i++){
            mp[s[i]]++;
        }
        for(i =0;i<n;i++){
            if(mp[s[i]] == 1)
                return i;
        }
        return -1;        
    }
};
/*
⏱ Time Complexity:
First loop:
for(i = 0; i < n; i++)

Runs n times → O(n)

Second loop:
for(i = 0; i < n; i++)

Runs n times → O(n)

Hash map operations:
    mp[s[i]]++
    mp[s[i]]

These are O(1) average time (unordered_map uses hashing).

✔ Final Time Complexity: O(n)+O(n)=O(n)

👉 Overall: O(n)

💾 Space Complexity:
You use:
    unordered_map<char, int> mp;

In worst case:
Every character in string is different.
So map stores n entries.
Worst case: O(n)
⚠ But Important Observation
In this problem:
The string contains only lowercase English letters ('a' to 'z').
That means at most 26 unique characters.

So technically:
Space=O(26)=O(1)

🎯 Final Answer (Interview Ready)
Complexity	Value:
Time	O(n)
Space	O(1) (since max 26 characters)
*/

/*
🔥 Even Better Optimization:
Since only lowercase letters exist, you can replace unordered_map with an array:

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

Why this is better:
Faster than hashmap
True O(1) space
No hashing overhead
Interviewers like this improvement.
💡 Summary:
Your solution:
✔ Correct
✔ O(n) time
✔ O(1) space (given constraints)

🔥 Can be slightly optimized using array instead of unordered_map
*/