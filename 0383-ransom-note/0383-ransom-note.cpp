class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for(int i=0;i<ransomNote.size();i++){
            need[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            have[magazine[i]]++;
        }
        for(auto i: need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if(fhave<fneed)
                return false;           
        }
        return true;    
    }
};

/*
⏱ Complexity Analysis

Let:
n = ransomNote length
m = magazine length

Time Complexity:
Build need → O(n)
Build have → O(m)
Compare → O(26)
👉 O(n + m)

Space Complexity:
At most 26 lowercase letters →
👉 O(1)

*/


/*
✅ Cleaner & Optimal Solution (Recommended)

Instead of building two maps, just count from magazine and reduce while checking ransomNote.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);

        for(char c : magazine)
            count[c - 'a']++;

        for(char c : ransomNote){
            count[c - 'a']--;
            if(count[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};
🎯 Why This Is Better

Only one frequency array
One pass over magazine
One pass over ransomNote
No extra map comparison
Cleaner logic

⏱ Final Complexity (Optimal Version)
Complexity	Value
Time	O(n + m)
Space	O(1) (26 letters)



*/