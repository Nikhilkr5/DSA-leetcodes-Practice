//Brute Force Approach:
//Idea:
//Check every pair
// class Solution {
// public:
//     int countPairs(vector<int>& nums, int target){
//         int count = 0;

//         for(int i = 0; i < nums.size();i++){
//             for(int j = i + 1; j < nums.size(); j++){
//                 if(nums[i] + nums[j] < target){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }    
// };


/*
Complexity
Time: O(n²)
Space: O(1)
*/


//Optimal Approach:(Sorting + Two Pointers)
//Key Observation:::::
//if array is sorted:  nums[left] + nums[right] < target
// then :
// ALL elements between left and right
// also form valid pairs with left.



class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        int count = 0;

        // Two-pointer approach after sorting
        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum < target) {
                count += (j - i); // all pairs (i, i+1 ... j)
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
};

/*
TC: O(n log n)
S.C: O(1)


After sorting, if current pair is valid,
then every element between left and right
will also form a valid pair with left.

So instead of checking one-by-one,
we count all pairs at once.
*/