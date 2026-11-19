//Brute Force Approach
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         // Copy nums2 into nums1
//         for (int i = 0; i < n; i++) {
//             nums1[m + i] = nums2[i];
//         }

//         // Sort nums1
//         sort(nums1.begin(), nums1.end());
//     }
// };


/*
⏱ Complexity:
Time: O((m+n) log (m+n))
Space: O(1)
*/

//Better Solution

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> res(m + n);

//         int i = 0, j = 0, k = 0;

//         while (i < m && j < n) {
//             if (nums1[i] <= nums2[j]) {
//                 res[k] = nums1[i];
//                 k++;
//                 i++;
//             } else {
//                 res[k] = nums2[j];
//                 k++;
//                 j++;
//             }
//         }

//         while (i < m) {
//             res[k] = nums1[i];
//             k++;
//             i++;
//         }

//         while (j < n) {
//             res[k] = nums2[j];
//             k++;
//             j++;
//         }

//         for (int p = 0; p < res.size(); p++) {
//             nums1[p] = res[p];
//         }
//     }
// };

// /*
// Time Complexity: O(m+n)
// Because we traverse both arrays once while merging.

// Space Complexity: O(m+n)  but O(1) as we are returning it
// Because an extra array res of size m + n is used.
// */


//Optimal Solution:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m -1;
        int j= n-1;
        int k= m+n -1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            } else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }        
    }
};


/*
⏱ Time Complexity:
Let
m = number of valid elements in nums1
n = number of elements in nums2

1️⃣ First while loop
while(i>=0 && j>=0)
Each iteration decreases either i or j.
Maximum iterations = m + n (at most), but actually ≤ min(m,n) + extra comparisons.
In worst case we compare until one array finishes.
So this loop runs O(m + n) in total across both loops.

2️⃣ Second while loop
while(j>=0)
Runs only if elements remain in nums2.
Maximum iterations = n
But note: these operations are already counted within the overall merge process.
✔ Final Time Complexity: O(m+n)
Because each element from both arrays is processed once.
🧠 Space Complexity:

We only use three extra variables:   int i, j, k;
No extra arrays or data structures are created.
All merging happens inside nums1.

✔ Space Complexity: O(1)

Constant extra space.

📊 Summary
Metric	Complexity
Time Complexity	O(m + n)
Space Complexity	O(1)
Type	In-place merge
Technique	Two pointers from the end
💡 Why merging from the end works

nums1 already has extra space at the back, so inserting from the largest index (k) prevents overwriting existing values.

Example:
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
We fill from the rightmost side.
*/
