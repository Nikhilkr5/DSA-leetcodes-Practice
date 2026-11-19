/*
Key Observation:

Negative numbers become positive after squaring.
Example:

-4 -> 16
10 -> 100

Largest square can come from:
left side (large negative)
right side (large positive)

This hints toward Two Pointers.
*/




//Brute force Approach:
// class Solution {
// public: 
//     vector<int> sortedSquares(vector<int> & nums){
//         for(int i=0; i< nums.size(); i++){
//             nums[i] = nums[i] * nums[i];

//         }
//         sort(nums.begin(), nums.end());

//         return nums;
//     }    
// };

/*
Complexity
Time: O(n log n)
Space: O(1) (ignoring output)
*/



/*
2. Better / Optimal Approach (Two Pointers)
Idea

Since array is already sorted:
Largest absolute value is at either end

Compare:

abs(nums[left]) vs abs(nums[right])
Put larger square at the end of answer array
Move pointers inward
*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();

        int i=0;
        int j= nums.size()-1;
        int k= nums.size()-1;
        vector<int> res(n);

        while(i<=j){
            int a = nums[i]* nums[i];
            int b= nums[j]* nums[j];

            if(a>b){
                res[k]= a;
                i++;
            }
            else{
                res[k]=b;
                j--;
            }
            k--;
        }
        return res;        
    }
};

/*
Complexity
Optimal
Time: O(n)
Space: O(n)
*/
/*
Why Two Pointers Works?

Because:
array is already sorted
largest square always lies at extremes
So we can build answer from back to front efficiently.
*/
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        int j = n - 1;
        int k = n - 1;

        while(i <= j) {

            if(abs(nums[i]) > abs(nums[j])) {
                ans[k] = nums[i] * nums[i];
                i++;
            }
            else {
                ans[k] = nums[j] * nums[j];
                j--;
            }

            k--;
        }

        return ans;
    }
};

*/
