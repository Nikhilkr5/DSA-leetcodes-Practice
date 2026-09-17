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
 //don't prefer this brute force  code:Sirf val reverse ho raha hai
    //Nodes ka order same hi rehta hai
    //Pointers touch bhi nahi hote
    //👉 Internally list reverse nahi hui
 //Brute force Approach :using an array .T.c:O(n), S.C= O(n)
 //Array of values – value replacement)
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         //Step 1: store values
//         vector<int> vals;
//         ListNode* temp = head;

//         while(temp!= nullptr){
//             vals.push_back(temp->val);
//             temp = temp->next;
//         }

//         //Step2:write values back in reverse
//         temp = head;
//         int i= vals.size()-1;

//         while(temp!=nullptr){
//             temp->val = vals[i];
//             i--;
//             temp=temp->next;
//         }
//         return head;
//     }
// };

//Brute Force Approach:(Nodes ko array me daal ke reverse karna)
//Code-1 (Array of nodes – pointer reversal later)
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         //Base Case
//         if(head == nullptr || head->next == nullptr){
//             return head;
//         }

//         //Step 1: Find length of linkedList
//         int len =0;
//         ListNode* l = head;
//         while(l != nullptr){
//             len++;
//             l = l->next;
//         }

//         //Step 2: Store nodes in array
//         vector<ListNode*> arr(len);
//         l = head;
//         int i=0;
//         while(l != nullptr){
//             arr[i] = l;
//             i++;
//             l = l->next;
//         }

//         //Step 3: Reverse the array
//         int start = 0, end = len-1;
//         while(start < end){
//             swap(arr[start], arr[end]);
//             start++;
//             end--;
//         }

//         //Step 4: Rebuild linkedlist using reversed array
//         for(int k=0; k<len -1; k++){
//             arr[k]->next = arr[k+1];
//         }
//         arr[len-1] ->next = nullptr;

//         //New head
//         return arr[0];
//     }
// };



//Optimised Approach: T.C: O(n)  , O(1)(no extra memory)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Base Case
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* nextNode = curr->next;   //store next
            curr->next = prev;                 //reverse link
            prev = curr;                       //move prev
            curr = nextNode;                   //move curr
        }

        return prev;    //new head
    }
};