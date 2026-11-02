//Better Solution:

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         if(n == 0) return;
//         k = k % n;
//         if(k == 0) return;

//         int temp[k];                //S.C: O(k)

//         for(int i = n-k;i < n; i++){        //O(k)
//             temp[i - n + k] = nums[i];
//         }

//         for(int i = n -k-1; i >= 0; i--){     //O(n - k)
//             nums[i + k] = nums[i];
//         }
//         for(int i=0;i<k;i++){               //O(k)
//             nums[i] = temp[i];
//         }        
//     }
// };

//T.C: O(k) + O(n-k) + O(k)  = = O(n + k)
//S.C: O(k)


//Optimal approach:  Reversal Algorithm


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;
        if (k == 0) return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         if(n == 0) return;

//         k = k %n;
//         if(k == 0) return;

//         reverse(nums.end()-k, nums.end());
//         reverse(nums.begin(), nums.end()-k);
//         reverse(nums.begin(),nums.end());
//     }
// };

/*
Complexity
Time: O(n)
Space: O(1)

Optimal.
*/