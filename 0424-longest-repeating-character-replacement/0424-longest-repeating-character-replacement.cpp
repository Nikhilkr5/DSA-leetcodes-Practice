// class Solution {
// public:
//     int characterReplacement(string s, int k) {

//         //Brute Force Approach
//         // int n= s.size();
//         // int maxLen =0;

//         // for(int i=0;i<n;i++){
//         //     int maxC =0;
//         //     vector<int> counts(26,0); //Frequency of A_Z;

//         //     for(int j=i;j<n;j++){
//         //         char c = s[j];
//         //         counts[c-'A']++;        

//         //         maxC = max(maxC, counts[c - 'A']);
//         //         int windowLen = j- i +1;
//         //         int ops = windowLen - maxC; //replacements needed

//         //         if(ops > k) {
//         //             break;
//         //         }

//         //         maxLen = max(maxLen, windowLen);

//         //     }           

//         // }
//         // return maxLen;

//         //Optimised Approach:
//         int n= s.size();
//         int i=0,j=0;
//         int maxLen = 0;
//         int maxC = 0;

//         vector<int> counts(26, 0);

//         while(j<n){
//             char c = s[j];
//             counts[c - 'A']++;
//             maxC =max(maxC, counts[c-'A']);

//             //if replacements needed exceed k, shrink window
//             while((j-i+1) - maxC > k){
//                 char d =  s[i];
//                 counts[d - 'A']--;
//                 i++; 

//                 //Recalculate maxC 
//                 maxC = 0;
//                 for(int l=0; l<26;l++){
//                     maxC = max(maxC, counts[l]);
//                 }               
//             }
//             maxLen = max(maxLen, j-i+1);
//             j++;
//         }
//         return maxLen;        
//     }
// };



class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low =0, high =0;
        int res =0;

        vector<int> counts(26, 0);

        while(high < n){
            counts[s[high] - 'A']++;

            int len = high - low + 1;
            int maxC = 0;
            for(int i =0;i<26;i++){
                maxC = max(maxC, counts[i]);
            }
            int diff = len - maxC;

            while(diff > k){
                counts[s[low]-'A']--;
                low++;
                maxC = 0;
                for(int i =0;i<26;i++){
                    maxC = max(maxC, counts[i]);
                }
                len = high - low + 1;
                diff = len - maxC;
            }
            len = high - low + 1;
            res = max(res, len);
            high++;
        }
        return res;        
    }
};