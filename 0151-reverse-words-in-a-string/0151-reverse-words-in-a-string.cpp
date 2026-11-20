class Solution {
public:
    string reverseWords(string s) {
        //Brute force approach:
        // vector<string> words;
        // string word = "";

        // for(int i=0;i<s.size();i++){
        //     if(s[i] != ' '){ 
        //         word+=s[i];
        //     } else if(!word.empty()){
        //         words.push_back(word);
        //         word ="";
        //     }
        // }
        // if(!word.empty()){
        //     words.push_back(word);
        // }

        // reverse(words.begin(),words.end());

        // string result ="";
        // for(int i=0;i<words.size();i++){
        //     result += words[i];
        //     if(i<words.size()-1)  result += " ";
        // }   
        // return result;


        //better Approach

        // stringstream ss(s);
        // string token="";
        // string result ="";

        // while(ss >> token){
        //     result = token + " " + result;
        // }
        // return result.substr(0, result.size()-1);


        //Optimal Approach
        //reverse whole string
        reverse(s.begin(), s.end());

        int i=0;
        //hero honge hamare  l and r jo reverse krenge words ko
        int l=0, r=0;
        int n= s.size();

        while(i < n){
            while(i < n && s[i] != ' '){   //i ko agar char dikha to r ko dega and i++ and r++
                s[r++] = s[i++];
                //i++;
                //r++;
            }
            if(l < r){   //l       r
                reverse(s.begin()+l, s.begin()+r);

                s[r]= ' ';
                r++;
                l=r;
            }
            i++; // ye to badhta rhega

        }
        s= s.substr(0,r-1);
        return s;
    }
    
};