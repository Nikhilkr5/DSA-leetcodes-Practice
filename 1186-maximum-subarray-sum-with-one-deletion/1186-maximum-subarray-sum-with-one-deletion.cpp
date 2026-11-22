class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n= arr.size();
        int nodelete = arr[0];
        int onedelete = INT_MIN;   //non sensical Illogical  // or O
        int res = arr[0];

        for(int i=1;i<n;i++){
            int prevNodelete = nodelete;
            int prevOnedelete = onedelete;

            nodelete = max(prevNodelete +arr[i], arr[i]);
            if (prevOnedelete != INT_MIN)
                onedelete = max(prevOnedelete + arr[i], prevNodelete);
            else
                onedelete = prevNodelete;

            

            res = max(res, max(onedelete, nodelete));
        }
        return res;
        
    }
};

/*
“Either I extend a path where deletion was already used, or I delete the current element and take previous no-deletion sum.”

*/


/*
🔥 Code:
if (prevOnedelete != INT_MIN)
    onedelete = max(prevOnedelete + arr[i], prevNodelete);
else
    onedelete = prevNodelete;
🧠 Short Meaning (seedha dimaag me daalo)
✅ IF part:
prevOnedelete != INT_MIN

👉 Deletion already use ho chuka hai

➡️ Ab 2 choice:

prevOnedelete + arr[i] → purana path continue karo
prevNodelete → naya path lo aur current element delete karo

👉 best pick karo

❌ ELSE part:
prevOnedelete == INT_MIN

👉 Abhi tak deletion use nahi hua

➡️ Sirf ek hi option:

current element delete karo
onedelete = prevNodelete;
🎯 Ek line me pura logic

“Agar deletion pehle ho chuka hai → continue ya new delete choose karo
Agar nahi hua → abhi current element delete karo”

Bas 🔥 itna hi yaad rakhna hai.


*/

/*
✅ Time Complexity
You loop through the array once:
for (int i = 1; i < n; i++)
Inside the loop → only constant time operations (max, additions, assignments).
So:
Time Complexity = O(N)
Where N = arr.size()

✅ Space Complexity
You are only using:
nodelete
onedelete
prevNodelete
prevOnedelete
res
All are just variables.
No extra arrays.
So:
Space Complexity = O(1)
Constant space.

🎯 Final Answer (Exam Style)

Time Complexity: O(N)

Space Complexity: O(1)
*/



/*
🔥 Line-by-line SHORT EXPLANATION
🟢 Initialization
int nodelete = arr[0];

👉 normal subarray (no deletion)

int onedelete = INT_MIN;

👉 abhi tak deletion use nahi hua (invalid state)

int res = arr[0];

👉 final answer track karega

🔁 Loop start
for(int i = 1; i < n; i++)
🔹 Step 1: previous values save
int prevNodelete = nodelete;
int prevOnedelete = onedelete;

👉 kyunki update karte waqt purani values chahiye

🔥 Step 2: nodelete (easy)
nodelete = max(prevNodelete + arr[i], arr[i]);

👉 2 choice:

extend karo
ya naya start karo

👉 pure Kadane

🔥 Step 3: onedelete (MAIN PART)
✅ IF: deletion pehle ho chuka hai
if (prevOnedelete != INT_MIN)

👉 2 choice:

onedelete = max(prevOnedelete + arr[i], prevNodelete);
extend old deleted path
ya current element delete karo
❌ ELSE: abhi tak deletion nahi hua
else
    onedelete = prevNodelete;

👉 matlab:

“abhi current element delete kar raha hoon (first time)”

🔥 Step 4: answer update
res = max(res, max(nodelete, onedelete));

👉 best pick karo:

bina delete
ya ek delete ke saath
🎯 Final Return
return res;
🧠 FULL LOGIC IN 5 LINES (REVISION)
nodelete → normal Kadane
onedelete → ek deletion allowed
agar deletion ho chuka → extend ya current delete
agar nahi hua → current delete
har step pe max answer update
💥 Ultimate one-liner

“Har index pe decide karte hain: extend karna hai, restart karna hai, ya ek element delete karke best banana hai.”


*/