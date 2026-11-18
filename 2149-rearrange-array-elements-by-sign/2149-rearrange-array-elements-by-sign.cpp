//Brute force Approach

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> pos;
//         vector<int> neg;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] > 0) pos .push_back(nums[i]);
//             else neg.push_back(nums[i]);
//         }
//         for(int i = 0;i< nums.size()/2;i++){
//             nums[2*i] = pos[i];
//             nums[2*i+1] = neg[i];
//         }
//         return nums;                        
//     }
// };
/*
Complexity
Time: O(n)
Space: O(n)
*/


//Optimal Solution:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int posIndex =0, negIndex = 1;
        for(int i=0;i<n;i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex +=2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex +=2;
            }
        }
        return ans;        
    }
};

//if unequal positives and negatives integers
/*
#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n){
    vector<int> pos;
    vector<int>neg;

    for(int i=0;i<n;i++){
        if(A[i]>0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }
    if(pos.size()<neg.size()){
        for(int i=0;i<pos.size();i++){
            A[2*i] = pos[i];
            A[2*i+1]= neg[i];
        }

        int index =pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            A[index] =neg[i];
            index++;
        }
    }
    else{
        for(int i=0;i<n;i++){
            A[2*i] = pos[i];
            A[2*i+1]= neg[i];
        }
        int index= neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            A[index] = pos[i];            
        }
    }
    return A;
}
}

int main(){
    int n =6;
    vector<int> A = {1,2,-4,-5,3,4};
    vect<int> ans = RearrangebySign(A,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

}

*/