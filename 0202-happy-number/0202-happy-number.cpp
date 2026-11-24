class Solution {
public:

    ///Brute/Better approach:
    // int sumOfSquaresOfDigits(int n) {
    //     int sum = 0;
    //     while (n > 0) {
    //         int dig = n % 10;
    //         sum += dig * dig;
    //         n /= 10;
    //     }
    //     return sum;
    // }

    // bool isHappy(int n) {
    //     unordered_set<int> seen;

    //     while (n != 1) {
    //         if (seen.count(n)) {
    //             return false;  // cycle detected
    //         }
    //         seen.insert(n);
    //         n = sumOfSquaresOfDigits(n);
    //     }
    //     return true;
    // }


    //Optimal Approach

    int sumofSquaresOfDigits(int n){
        int sum = 0;
        while(n > 0){
            int dig = n % 10;
            sum += dig * dig;
            n= n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(fast != 1){
            slow = sumofSquaresOfDigits(slow);
            fast = sumofSquaresOfDigits(sumofSquaresOfDigits(fast));

            if(fast == 1){
                return true;                
            }
            if(slow == fast) {
                return false;
            }            
        }
        return true;       
    }
};