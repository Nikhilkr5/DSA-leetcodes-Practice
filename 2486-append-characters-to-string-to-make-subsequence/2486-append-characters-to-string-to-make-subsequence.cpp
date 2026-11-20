/*
❓ Is There Brute Force?
Yes, but unnecessary.
Brute Idea:
Try appending 0, 1, 2… characters
Check if t becomes subsequence
Very inefficient
Time complexity ≈ O(n * m)
Since constraints go up to 10⁵, brute force will TLE ❌
*/



//Optimal
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;

        //Iterate throgh both strings
        while(i< s.length() && j<t.length()){
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }
        //remaininig characters neede to match t
        return t.length()-j;                
    }
};






/*
🧠 Brute Force Idea

We try:
Append 0 characters → check if t is subsequence
Append 1 character → check again
Append 2 characters → check again

…

Until it works::::::

Since we can only append characters from t,
we append the remaining suffix of t each time.

🔹 Step-by-Step Logic::
For k = 0 → t.length():
Append last k characters of t to s
Check if t is subsequence of new string

Return smallest k

✅ Brute Force Code (C++):::

class Solution {
public:
    
    // Function to check if t is subsequence of s
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.length() && j < t.length(); i++) {
            if (s[i] == t[j]) {
                j++;
            }
        }
        return j == t.length();
    }
    
    int appendCharacters(string s, string t) {
        
        // Try appending 0 to t.length() characters
        for (int k = 0; k <= t.length(); k++) {
            
            // Append last k characters of t
            string newS = s + t.substr(t.length() - k);
            
            if (isSubsequence(newS, t)) {            
                return k;
            }
        }        
        return t.length();
    }
};



*/