// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//             //Brute force Approach:

//             // int n= nums.size();
//             // sort(nums.begin(),nums.end());

//             // int maxFreq = 0;

//             // for(int i=0;i<n;i++){
//             //     long long sum =0;
//             //     for(int j=i;j<n;j++){
//             //         sum+=nums[j];
//             //         long long len = j-i+1;
//             //         long long required = (long long)nums[j] * len;

//             //         if(required - sum > k) break;

//             //         maxFreq = max(maxFreq, (int)len);    //Cast len to int since frequency can never exceed n anyway:
//             //     }
//             // }
//             // return maxFreq;


//             //Optimal Approach
//             if(nums.empty()) return 0;

//             sort(nums.begin(), nums.end());
//             int n = nums.size();

//             long long sum = 0;
//             int maxFreq = 0;
//             int i=0;

//             for(int j=0;j<n;j++){
//                 sum += nums[j];

//                 while((long long)nums[j] * (j-i+1) - sum > k){
//                     sum -= nums[i];
//                     i++;
//                 }

//                 maxFreq= max(maxFreq, j-i+1);
//             }
//             return maxFreq;
        
//     }
// };

class Solution{
public:
    int maxFrequency(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());   //taki max element right me aa jaye
        int n = nums.size();
        int low =0, high =0;

        long long sum = 0;
        int res =0;

        while(high < n){
            sum += nums[high];

            int len = high - low + 1;
            long long diff  = (long long)len * nums[high] - sum;

            while(diff > k){
                sum -= nums[low];
                low++;

                len = high - low + 1;
                diff = (long long)len * nums[high] - sum;
                
            }
            res = max( res, high- low + 1);
            high++;
        }
        return res;
    }    
};