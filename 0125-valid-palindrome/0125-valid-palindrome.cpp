/*
1. Brute Force Approach
Idea
Create a cleaned string containing only alphanumeric chars
Convert to lowercase
Reverse it
Compare both strings


Complexity
Time: O(n)
Space: O(n)
*/
// class Solution {
// public:
//     bool isPalindrome(string s) {

//         string cleaned = "";

//         for(char ch : s) {

//             if(isalnum(ch)) {
//                 cleaned += tolower(ch);
//             }
//         }

//         string rev = cleaned;

//         reverse(rev.begin(), rev.end());

//         return cleaned == rev;
//     }
// };

/*
2. Better Approach (Manual Reverse Check)
Idea

Instead of creating reversed string:

Clean string once
Use two pointers to compare

*/

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string cleaned = "";

//         for(char ch : s){
//             if(isalnum(ch)){
//                 cleaned += tolower(ch);
//             }
//         }
//     }

//     int left = 0;
//     int right = cleaned.size() - 1;    

//     while(left < right){
//         if(cleaned[left] != cleaned[right]){
//             return false;
//         }
//         left++;
//         right--;
//     }
//     return true;
// }

//Complexity:
//TC : O(n)
//SC : O(n)





/*
3. Optimal Approach (Most Important)
Idea

Use Two Pointers directly on original string.

Steps
Left pointer from start
Right pointer from end
Skip non-alphanumeric chars
Convert both to lowercase
Compare

No extra string needed.
*/


class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0;
        int j= s.size()-1;

        while(i<j){
            char left = s[i];
            char right = s[j];
            if(!isalnum(left)){
                i++;
                continue;
            }
            if(!isalnum(right)){
                j--;
                continue;
            }
            if(tolower(left) != tolower(right)){
                return false;
            }
            i++;
            j--;           

        }
        return true;
    }
};

/*
Complexity
Time: O(n)
Space: O(1)

This is the expected interview solution.
*/








/*
class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            // Skip non-alphanumeric
            while(left < right && !isalnum(s[left])) {
                left++;
            }

            while(left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare lowercase chars
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};


*/