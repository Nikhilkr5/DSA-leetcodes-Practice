// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
        
//         int n= nums.size();
//         int i = 0 , j =1;
//         int res =1;


//         while(j<n){
//             if(nums[j] == nums[j-1]){
//                 j++;
//                 continue;
//             }
//             nums[i+1] = nums[j];
//             i++;
//             res++;
//             j++;
//         }
//         return res;
        
//     }
// };


// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         int i = 0, j = 1;
//         int res = 1;

//         while (j < n) {
//             if (nums[j] != nums[j - 1]) {
//                 i++;                  // 🔥 missing line
//                 nums[i] = nums[j];
//                 res++;
//             }
//             j++;
//         }
//         return res;
//     }
// };

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int n= nums.size();
        if(n==0) return 0;

        int k = 1; //position for next unique character

        for(int i=1;i<n;i++){   //because first element is already unique
            if(nums[i]!=nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }    
};


//Time : O(n)
//S.C: O(1)