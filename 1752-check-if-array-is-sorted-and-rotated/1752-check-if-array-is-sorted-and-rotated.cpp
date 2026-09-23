class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] > nums[(i+1)%n]){
                count++;
            }
        }
        return count <= 1;        
    }
};

/*
// Count the number of "drops" where nums[i] > nums[i+1].
// Use (i+1)%n to compare the last element with the first.
// If drops > 1 → Not sorted & rotated.
// Else → Valid sorted & rotated array.

Complexity
Time: O(n)
Space: O(1)
Why (i + 1) % n?
nums[(i + 1) % n]

allows the last element to be compared with the first.

Example:
nums = [3,4,5,1,2]

3 < 4 ✅
4 < 5 ✅
5 > 1 ❌ (1st drop)
1 < 2 ✅
2 < 3 ✅

Drops = 1 → True

Example:
nums = [2,1,3,4]

2 > 1 ❌ (1st drop)
1 < 3 ✅
3 < 4 ✅
4 > 2 ❌ (2nd drop)

Drops = 2 → False

This is the standard optimal interview solution.
*/