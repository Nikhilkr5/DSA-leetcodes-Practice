//Brute Force:::Time: O(n²)   Space: O(1)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {

//         int n = nums.size();

//         for (int i = 0; i < n; i++) {

//             for (int j = i + 1; j < n; j++) {

//                 if (nums[i] == nums[j]) {
//                     return nums[i];
//                 }
//             }
//         }

//         return -1;
//     }
// };


//Better:  HashSet
//Store elements that we have already seen.
//If an element is already present, it's the duplicate.

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {

//         unordered_set<int> seen;

//         for (int num : nums) {

//             if (seen.find(num) != seen.end()) {
//                 return num;
//             }

//             seen.insert(num);
//         }

//         return -1;
//     }
// };
// Time: O(n) average
// Space: O(n)

/*
3. Optimal — Floyd's Cycle Detection ⭐⭐⭐
This is the important part.
The problem gives:
nums.length = n + 1
numbers are from 1 to n
exactly one number is repeated

We can treat the array like a linked list.
For example:
nums = [1, 3, 4, 2, 2]
Think of:
index → nums[index]
So:
0 → 1
1 → 3
2 → 4
3 → 2
4 → 2
This creates a cycle:
2 → 4 → 2
The duplicate number is the entrance of this cycle.
Therefore, we can use Floyd's Cycle Detection, exactly like linked-list cycle problems.

Phase 1 — Detect the cycle
slow = nums[slow];
fast = nums[nums[fast]];
slow moves 1 step.
fast moves 2 steps.

When:
slow == fast
we know a cycle exists.
Phase 2 — Find cycle entrance

Reset:
slow = nums[0];
Then move both one step:

slow = nums[slow];
fast = nums[fast];

When they meet again:
slow == fast
that value is the duplicate.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Phase 1: Detect cycle
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Phase 2: Find cycle entrance
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};