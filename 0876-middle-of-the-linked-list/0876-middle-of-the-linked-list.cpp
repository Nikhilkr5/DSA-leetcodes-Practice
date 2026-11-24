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


//Brute Force Approach:: Store Nodes in Vector

//Traverse the linked list and store every node in a vector.
//Then the middle node is at: n / 2
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {

//         vector<ListNode*> nodes;
//         ListNode* temp = head;

//         while (temp != NULL) {
//             nodes.push_back(temp);
//             temp = temp->next;
//         }

//         return nodes[nodes.size() / 2];
//     }
// };
//Complexity::
//Time:: O(n)
//S.C:: O(n)



// //Better Approach:: Find length first
/*
Idea
Do two traversals:
First traversal: Count the number of nodes.
Second traversal: Move n/2 steps from the head.
*/
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         int n =0;
//         ListNode* temp = head;

//         //count nodes
//         while(temp != NULL){
//             n++;
//             temp=temp->next;
//         }

//         //Go to middle
//         temp = head;

//         for(int i=0;i<n/2;i++){
//             temp= temp->next;
//         }
//         return temp;
//     }
// };

//T.C:: O(n)
//S.C:: O(1)


// //Optimal Approach:  Slow and Fast Pointers ⭐
/*
Maintain two pointers
slow->moves 1 step
fast -> moves 2 steps
When fast reaches the end, slow will be at the middle.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

/*
Complexity:
Time: O(n)
Space: O(1)
*/