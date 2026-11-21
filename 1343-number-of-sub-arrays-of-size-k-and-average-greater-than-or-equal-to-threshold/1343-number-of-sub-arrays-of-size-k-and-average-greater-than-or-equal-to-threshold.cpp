class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //brute force approach:
        // int n = arr.size();
        //if (k>n) return 0;
        // 
        // 
        // int count =0;
        //  long long target = 1LL * k * threshold;

        // for(int i=0;i<=n-k;i++){
        //     long long sum = 0; 
        //     for(int j=i;j<i+k;j++){
        //         sum += arr[j];
        //     }
        //     if(sum >= target){
        //         count++;
        //     }
        // }
        // return count;

        //Optimal Approach:

        int n= arr.size();   
        if (k > n) return 0;   

        long long target = 1LL * k * threshold;  
        long long sum = 0;
        int count =0;


        for(int i=0;i<k;i++){
            sum += arr[i];
        }
        if(sum >= target){
            count++;            
        }
        for(int i=k;i<n;i++){
            sum+= arr[i] - arr[i-k];
            if(sum >= target){
                count++;            
            }
        }
        return count;                
    }
};


/*
Why target = 1LL * k * threshold ?

Condition:
    average >= threshold
=>  sum / k >= threshold
=>  sum >= k * threshold   // Avoid division

Use 1LL to prevent integer overflow:
    long long target = 1LL * k * threshold;

Then simply check:
    if (sum >= target) count++;
*/  