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

/*
Brute Force Solution:
✅ Use extra space to separate odd and even indexed nodes
✅ Then rebuild the list

🟦 🔎 Brute Force Idea:
Traverse the list.
Store odd-indexed values in one vector.
Store even-indexed values in another vector.
Traverse again and overwrite values:
First all odd values
Then all even values
⚠ Important: Indexing is 1-based (head = position 1).

⏱ Complexity:
Time: O(n)
Space: O(n)
*/
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(!head) return head;

//         vector<int> oddVals;
//         vector<int> evenVals;

//         ListNode* temp = head;
//         int position = 1;

//         //Step 1: Separate values
//         while(temp) {
//             if(position % 2 == 1)
//                 oddVals.push_back(temp->val);
//             else 
//                 evenVals.push_back(temp->val);
//             temp = temp->next;
//             position++;        
//         } 

//          // Step 2: Rewrite list (odds first, then evens)
//         temp = head;
//         for(int val: oddVals) {
//             temp->val = val;
//             temp= temp->next;
//         } 
//         for(int val : evenVals){
//             temp->val = val;
//             temp = temp->next;
//         }

//         return head;
//     }
// };

//Optimal Approach:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr1 = head;
        ListNode* curr2 = head->next;

        ListNode* temp1 = curr2;
        
        //  1   2   3   4   5
        //                  c1 c2
        //      t1

        //  c1->next =c2->next
        //  c1 = c1->next
        //  c2->next =c1->next;
        //  c2=c2->next

        // 1->3->5
        // 2->4null;
        //stop because c2 == null
        //c1->t1

        //  1   2   3   4   5   6
        //                  c1  c2  
        //      t1

        //
        //  c1->next =c2->next
        //  c1 = c1->next
        //  c2->next =c1->next;
        //  c2=c2->next

        //  1->3-> 5
        //  2->4-6->null
        //stop in even case when c2->next == null ptr;
        //c1->t1
        while (curr2 != NULL && curr2->next != NULL) {
            // body
            curr1->next = curr2->next;
            curr1 = curr1->next;

            curr2->next = curr1->next;
            curr2 = curr2->next;
        }

        curr1->next = temp1;

        return head;
     
    }
};
/*
Time → O(n)
Space → O(1)
*/