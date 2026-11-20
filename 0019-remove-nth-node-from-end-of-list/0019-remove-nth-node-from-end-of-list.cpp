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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //BETTER APPROACH:

        //if list is empty , return NULL
        // if(head == NULL){
        //     return NULL;
        // }

        // int cnt = 0;
        // ListNode* temp = head;


        // // //Count the number of nodes in the linkedlist
        // while(temp != NULL){
        //     cnt+=1;
        //     temp= temp->next;
        // }
        // // //if n equals the total number of nodes, delete the head
        // if(cnt == n){
        //    ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }

        // // //Calculate the position from start to delete
        // int res = cnt - n;
        // temp = head;

        // while(temp!=NULL){
        //     res--;
        //     if(res==0) break;
        //     temp= temp->next;
        // }

        // ListNode* delNode = temp->next;
        // temp->next = temp->next->next;
        // delete delNode;   //free memory

        // return head;                






        //OPTIMAL APPROACH
        
        //create a dummy node before head to handle edge cases
        // ListNode* dummy = new ListNode(0, head);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        //Initialise slow and fast pointers at  dummy
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        //Move fast pointer N+1 steps ahead to create a gap
        for(int i=0; i<=n;i++){
            fast = fast->next;
        }


        // Move both pointers until fast reaches the end
        while(fast !=NULL){
            slow= slow->next;
            fast = fast->next;            
        }

        // Slow is now at node before target → delete target node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        //Return updates head
        return dummy->next;
    }
};