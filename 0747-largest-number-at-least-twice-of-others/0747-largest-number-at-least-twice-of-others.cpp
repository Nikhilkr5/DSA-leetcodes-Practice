class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int largest = -1;
        int secondLargest = -1;
        int index = -1;

        for(int i = 0;i<n;i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
                index = i;
            }
            else if(nums[i] > secondLargest){
                secondLargest = nums[i];
            }            
            
        }
        if(largest >= 2 * secondLargest){
            return index;
        }
        return -1;
        
    }
};

/*
T.C: O(n)
S.C: O(1)
*/

/*
Key learning:

max_element(begin,end) gives iterator
Index can be obtained by:
max_element(nums.begin(), nums.end()) - nums.begin()

Example:

int idx = max_element(nums.begin(), nums.end()) - nums.begin();

But for this problem, you still need second largest logic.
*/

/*
// max_element() returns an iterator.
// Use * to get the value.
// Subtract begin() to get the index.

int mx  = *max_element(nums.begin(), nums.end());
int idx = max_element(nums.begin(), nums.end()) - nums.begin();
*/