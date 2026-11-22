// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {

//         //Brute force Approach:
//         // int n= fruits.size();
//         // int maxlen = 0;
//         // for(int i=0;i<n;i++){
//         //     unordered_set<int> st;
//         //     for(int j=i;j<n;j++){
//         //         st.insert(fruits[j]);
//         //         if(st.size() > 2){
//         //             break;
//         //         }

//         //         maxlen = max(maxlen, j-i+1);
//         //     }
//         // }
//         // return maxlen;

//         //better but can be optimised to T.C:O(n) from 2n:
//         //T.C: O(2n), S.C = O(1)
//         int n= fruits.size();
//         int i=0;
//         int j=0;
//         int maxlen = 0;
//         unordered_map<int,int> mp;
        
//         while(j<n){
//             mp[fruits[j]]++;  //increase the count of this fruit type in the hashmap

//             while(mp.size() > 2) {
//                 mp[fruits[i]]--;
//                 if(mp[fruits[i]]== 0){
//                     mp.erase(fruits[i]);
//                 }
//                 i++;
//             }

//             maxlen= max(maxlen, j-i+1);
//             j++;
//         }
//         return maxlen;
//     }
// };


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0;
        int high =0;
        int MaxLen = INT_MIN;
        unordered_map<int, int> mp;

        while(high < n){
            mp[fruits[high]]++;

            while(mp.size() > 2){
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0){
                    mp.erase(fruits[low]);
                }
                low++;
            }

            MaxLen = max(MaxLen, high - low + 1);
            high++;
        }
        return MaxLen == INT_MIN ? -1 : MaxLen;
    }
};
