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
//Optimised Approach:  //T.C:O(n)  S.C: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Edge case 1: empty list
        if (head == nullptr) return nullptr;

        ListNode* nodeA = head;

        //T:O(n) , S.C: O(1)
        while(nodeA != nullptr){
            ListNode* nodeB = nodeA->next;
            int val = nodeA->val;

            //Skip all duplicates of current value
            while(nodeB != nullptr && nodeB->val == val) {
                nodeB = nodeB->next;
            }
            nodeA->next = nodeB;
            nodeA = nodeB;
        }
        return head;
    }
};


//Brute Force Approach(Using Extra Array)
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         //Edge Case
//         if(head == nullptr) return nullptr;

//         //Step1: store unique values
//         vector<int> vals;
//         ListNode* temp = head;
//         while(temp != nullptr){
//             if(vals.empty() || vals.back()!= temp->val){
//                 vals.push_back(temp->val);
//             }
//             temp = temp->next;
//         }

//         //Step 2: rebuild libnkedlist from unique values
//         ListNode* newHead = new ListNode(vals[0]);
//         ListNode* curr = newHead;

//         for(int i=1;i<vals.size();i++){
//             curr->next = new ListNode(vals[i]);
//             curr = curr->next;
//         }
//         return newHead;
//     }
// };

//T.C : O(n)
//S.C : O(n)