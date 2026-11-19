/*Key Observation

Normally palindrome uses:
left pointer
right pointer
 
If mismatch occurs:
either remove left char
OR remove right char

Check if remaining substring is palindrome.
*/


// substr(start, length) → returns 'length' characters from start
// substr(start) → returns characters from start to the end
//
// Example: s = "abcdef"
// s.substr(2, 3) → "cde"
// s.substr(2)    → "cdef"

/*
1. Brute Force Approach
Idea:::::
Try deleting every character one by one.

For each deletion::::
    create new string
    check palindrome
*/

// class Solution {
// public:

//     bool isPal(string str) {

//         int left = 0;
//         int right = str.size() - 1;

//         while(left < right) {

//             if(str[left] != str[right]) {
//                 return false;
//             }

//             left++;
//             right--;
//         }

//         return true;
//     }

//     bool validPalindrome(string s) {

//         for(int i = 0; i < s.size(); i++) {

            // string temp = s.substr(0, i) + s.substr(i + 1);   //  Take the part before index i + take the part after index i = string with the ith character removed.

//             if(isPal(temp)) {
//                 return true;
//             }
//         }

//         return isPal(s);
//     }
// };


/*
What You Should Do in Interview
Step 1 → Mention Brute Force Briefly

Just say:
One brute force approach is trying deletion of every character and checking palindrome each time, which would be O(n²).
बस इतना enough है.
No need to write brute-force code unless interviewer asks.
Step 2 → Move to Optimal
Then say:
We can optimize using two pointers.
Step 3 → Explain Main Insight
Most important line:
At first mismatch, we only have two choices:
skip left OR skip right.

This is the actual interview value.

Step 4 → Code Optimal Directly
*/




class Solution {
public:
    bool checkHelp(int i, int j, string &s){
        while(i<j){
            if(s[i]!= s[j]){
                return false;

            } else {
                i++;
                j--;
            }            
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i= 0;
        int j= s.size()-1;
        while(i<j){
            
            if(s[i] != s[j]){
                return checkHelp(i+1, j, s)|| checkHelp(i, j-1,s); 
            } else {
                i++;
                j--;
            }            
        }
        return true;        
    }
};

/*
1. Start With Brute Force:
Say something like:
“First thought is to try deleting every character one by one and check whether the remaining string is palindrome.”

Explain Complexity:::::
For every deletion -> O(n)
Palindrome check -> O(n)

Total -> O(n²)
Then say:

“We can do better using two pointers.”
This shows problem-solving progression.

2. Observe the Pattern::::
Say:
“A normal palindrome can be checked using two pointers from both ends.”
Then:
“The only complication here is we are allowed to delete at most one character.”
3. Key Insight (Most Important)
When mismatch occurs:
s[i] != s[j]

You say:
“At the first mismatch, there are only two possibilities:

skip left character
skip right character”

This is the core interview insight.

4. Explain Why Only One Mismatch Matters

Very important.

Say:
“Since only one deletion is allowed, once we encounter mismatch, we must immediately decide which character to remove.”

5. Explain Helper Function

Say:

“After skipping one side, the remaining substring must be a normal palindrome.”

So create:

check(i, j)
6. Then Write Code Cleanly

Interviewers love:

small helper functions
readable variables
minimal nesting
Ideal Interview Explanation

You can literally say:

I'll use two pointers.

If characters match, move inward.

If mismatch occurs, I have only two choices:
1. Ignore left character
2. Ignore right character

Then check if remaining substring is palindrome.
If either works, answer is true.
That explanation alone sounds very strong.

Complexity Discussion

Always end with:

Time Complexity: O(n)
Space Complexity: O(1)

Then explain:

each character visited at most few times
no extra data structures used
Biggest Interview Mistake

Many candidates say:

I'll try removing every character.
and stop there.

Good candidates:

start brute force
optimize
explain why optimization works
Interview Mindset

For palindrome/two-pointer problems:

Always think:
Can I compare from both ends?
If question says:
sorted array
palindrome
pair sum
reverse
container
remove duplicates

→ Two pointers should immediately come to mind.

What Makes Your Current Solution Good
Your code already shows:
two-pointer thinking
helper abstraction
optimal logic
So your next improvement is mostly:
communication + explaining thought process
That’s what converts “can code” into “clears interviews.”
*/