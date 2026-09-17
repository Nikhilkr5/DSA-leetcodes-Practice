/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //Brute Forcev Approach:
/*
🔎 Brute Force Idea:
Traverse the linked list and store all node values in a vector.
Swap the kth element from the start and the kth element from the end inside the vector.
Traverse the linked list again and overwrite the node values using the updated vector.
Return the head.
This approach:
Time Complexity: O(n)
Space Complexity: O(n) (extra vector used)
*/
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         if(!head) return head;                

//         vector<int> values;
//         ListNode* temp = head;

//         //Step 1: Store values in  vector
//         while(temp){
//             values.push_back(temp->val);
//             temp = temp->next;
//         }

//         int n= values.size();

//         //Step 2:Swap kth from start and kth from end
//         swap(values[k-1], values[n-k]);

//         //Step 3: Write values back to linked list
//         temp = head;
//         int i=0;
//         while(temp){
//             temp->val = values[i++];
//             temp = temp->next;
//         }

//         return head;
//     }
// };


//Better Solution:   Length Calculation First)       //T.C:O(n)  , S.C:O(1)
//                  Length-Based Two Pass

// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         //Edge Case 1: empty list
//         if(head == nullptr) return nullptr;

//         //Step1: find length
//         int len = 0; 
//         ListNode* curr = head;

//         //T.C:O(n) , S.C:O(1)
//         while(curr != nullptr){
//             len++;
//             curr = curr->next;
//         }

//         //Optional Edge Case : if kth from start and kth from end are same node
//         //if (2 * k - 1 == len) return head;


//         //Step2: Find kth node from start (n1)
//         ListNode* n1 = head;
//         int counter = 0;
//         int jumps1 = k -1;

//         while( counter < jumps1){
//             n1 = n1->next;
//             counter++;
//         }

//         //Step3: Find kth node from end (n2)
//         ListNode* n2 = head;
//         counter = 0;
//         int jumps2 = len-k;

//         while(counter < jumps2){
//             n2 = n2->next;
//             counter++;
//         } 

//         //Step4: Swap values         //or: swap(n1->val, n2->val);
//         int temp = n1->val;
//         n1->val = n2->val;
//         n2->val = temp;

//         return head;       
//     }
// };

//Optimal Solution:  One-Pass Approach

//T.C: O(n) , S.C:O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Step 1: Move n1 to kth node from start
        ListNode* n1 = head;
        int startJumps = 0;

        while (startJumps < k - 1) {
            n1 = n1->next;
            startJumps++;
        }

        // Step 2: Use two pointers to find kth from end
        ListNode* nT1 = n1;
        ListNode* n2 = head;

        // Move nT1 to end, move n2 along with it
        while (nT1->next != nullptr) {
            nT1 = nT1->next;
            n2 = n2->next;
        }

        // Step 3: Swap values
        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;

        return head;
    }
};
