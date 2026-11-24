/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //. Brute Force — Use a Set
/*
Keep track of every node we have already visited.
If we reach NULL → no cycle.
If we see the same node again → cycle exists.
*/

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode*> visited;
//         ListNode* temp = head;

//         while(temp!=NULL){
//             if(visited.find(temp) != visited.end()){
//                 return true;
//             }
//             visited.insert(temp);
//             temp = temp->next;
//         }
//         return false;
//     }
// };

/*
Complexity
Time: O(n)
Space: O(n)
*/

//Optimal Solution::Fast & Slow Pointers
/*
Use two pointers:
slow → moves 1 step
fast → moves 2 steps

If there is no cycle:
slow → eventually reaches NULL
If there is a cycle:
slow and fast will eventually meet
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};