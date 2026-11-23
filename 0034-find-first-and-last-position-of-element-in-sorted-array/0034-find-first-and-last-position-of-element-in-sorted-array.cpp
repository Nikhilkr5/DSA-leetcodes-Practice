class Solution {
public:
    int first(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0, high = n-1;
        int result = -1;
        while(low<=high){
            int guess = (low + high)/2;

            if(nums[guess] < x){
                low = guess + 1;
            }
            else if(nums[guess] > x){
                high = guess -1;
            }
            else{
                result = guess;
                high = guess -1;
            }
            
        }
        return result;

    }
    int last(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0, high = n-1;

        int result = -1;
        while(low<= high){
            int guess =  (low + high)/2;
            if(nums[guess]<x){
                low = guess + 1;
            }
            else if(nums[guess] > x){
                high = guess -1;
            }else{
                result = guess;
                low = guess + 1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int starting = first(nums,target);
        int ending = last(nums, target);

        vector<int>res;
        res.push_back(starting);
        res.push_back(ending);

        return res;
        
    }
};