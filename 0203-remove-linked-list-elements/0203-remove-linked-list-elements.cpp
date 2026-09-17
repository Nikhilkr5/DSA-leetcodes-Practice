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
✅ Brute Force Approach (Using extra array of nodes)
💡 Idea (simple words)
Linked list traverse karo
Jo nodes ka val != given val hai, unko ek array me store karo
Array se linked list dobara build karo
Jo val == given val hai, wo automatically remove ho jaate hain
Ye brute force hai kyunki:
Extra space use ho raha hai (array)
*/

/*
🧠 Brute Force Logic Steps
vector<ListNode*> arr banao
Har node check karo
Agar node->val != val → array me daalo
Agar array empty hai → return nullptr
Warna array ke nodes ko wapas next pointers se jodo
Last node ka next = nullptr
arr[0] ko new head bana ke return karo
*/

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         //Step1: Store nodes that should NOT be removed
//         vector<ListNode*> arr;
//         ListNode* temp = head;

//         while(temp != nullptr){
//             if(temp->val != val){
//                 arr.push_back(temp);
//             }
//             temp = temp->next;
//         }

//         //Step 2: if no nodes left, return empty list
//         if(arr.size()==0) {
//             return nullptr;
//         }

//         //Step 3: rebuild linkedlisr
//         for(int i=0;i<arr.size()-1;i++){
//             arr[i]->next = arr[i+1];
//         }

//         //Step 4: last node points to null
//         arr.back()->next = nullptr;

//         //Step 5: return new head
//         return arr[0];        
//     }
// };


    //Optimised Approach:

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //Dummy node to handle deletion of head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        //prev and curr pointers
        ListNode* prev = dummy;
        ListNode* curr = head;

        //Traverse the list
        while(curr != nullptr){
            if(curr->val == val){
                //Remove curr
                prev->next = curr->next;
                curr = curr->next;
            } else {
                //Move both pointers
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

