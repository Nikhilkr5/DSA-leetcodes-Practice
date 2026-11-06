class Solution {
public:
    void sortColors(vector<int>& nums) {

        //Bruteforce Approach
        // sort(nums.begin(), nums.end());

        /*
        Time Complexity:
        std::sort() in C++ uses Introsort (QuickSort + HeapSort + InsertionSort).

        Average Case: O(n log n)
        Worst Case: O(n log n)

        🔹 Space Complexity:
            O(log n) (recursive stack space for sorting)
        */

        //Better approach: (Counting Sort – Two Passes)

        /*
            Steps:
                First pass → Count number of 0s, 1s, 2s → O(n)
                Second pass → Overwrite array based on counts → O(n)

            🔹 Time Complexity:
                    O(n) + O(n) = O(n)

            🔹 Space Complexity:
                    Only 3 integer counters used → O(1) (constant space)
        */

        // int count0 = 0, count1 = 0, count2 = 0;
        // //First pass:count the no of 0s , 1s and 2s
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]== 0) count0++;
        //     else if(nums[i]==1) count1++;
        //     else count2++;
        // }
        // /*        
        // for (int x : nums) {
        //     if (x == 0) count0++;
        //     else if (x == 1) count1++;
        //     else count2++;
        // }
        // */

        // //Second pass fill the array with 0s, 1s and 2s

        // for(int i=0;i<count0;i++) nums[i] = 0;
        // for (int i = count0; i < count0 + count1; i++) nums[i] = 1;
        // for (int i = count0 + count1 ; i < nums.size(); i++) nums[i] = 2;



        //Optimal Approach
         int low =0, mid = 0, high = nums.size() - 1;
         
         // Process elements until mid pointer crosses high pointer
         while(mid <= high){
            //If current element is 0 , swap with low and move both pointers forward
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            // If current element is 1, it's already in correct place → move mid forward
             else if(nums[mid] == 1){
                mid++;
            }
            // If current element is 2, swap with high and move only high pointer backward
            else{
                swap(nums[mid], nums[high]);
                high--;
            }            
         }           
    }
};

/*
Optimal Approach: 
    🔹 Time Complexity:O(n)
        Each element is processed at most once.
        Even though swaps happen, mid and high move in one direction only.

    O(n)

    
    🔹 Space Complexity
        Only 3 pointers used.
        No extra array.
        O(1) (in-place sorting)
*/