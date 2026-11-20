class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n= text.size();
        unordered_map<char,int> have;
        for(int i=0;i<n;i++){
            have[text[i]]++;
        }
        unordered_map<char,int> need;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1; 

        int res = INT_MAX;

        for(auto i: need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            int times = fhave/fneed;
            res = min(res, times);
        }
        return res;        
    }
};
/*
⏱ Complexity:
Let n = length of text.
Time:
Build have → O(n)
Loop over need (5 characters) → O(1)

👉 O(n)

Space:
have stores at most 26 letters → O(1)
need stores 5 letters → O(1)
👉 Overall Space = O(1)

🧠 Important Observation:
Your approach is correct logically:
max balloons = minimum (have[c] / need[c])
That is exactly how you solve this type of frequency division problem.
*/