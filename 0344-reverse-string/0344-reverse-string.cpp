/*
1. Brute Force Approach (Using Extra Array)
Idea:
Create another array and fill it from the back.

Complexity:
Time: O(n)
Space: O(n)
Why Brute?

Uses extra memory, so it does not satisfy the in-place requirement.
*/


// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         vector<char> temp;

//         for (int i = s.size() - 1; i >= 0; i--) {
//             temp.push_back(s[i]);
//         }

//         s = temp;
//     }
// };


/*
2. Better Approach (STL reverse)
Idea:
Use built-in STL function.:
Complexity:
Time: O(n)
Space: O(1)
Note

Good for interviews sometimes, but interviewers may ask for manual implementation.
*/

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         reverse(s.begin(), s.end());
//     }
// };


/*
3. Optimal Approach (Two Pointers)
Idea
One pointer at start
One pointer at end
Swap both
Move inward

This is the most expected interview solution.
Complexity
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j= s.size()-1;
        while(i<j){
            char temp = s[i];
            s[i]= s[j];
            s[j]= temp;
            i++;
            j--;
        }        
    }
};