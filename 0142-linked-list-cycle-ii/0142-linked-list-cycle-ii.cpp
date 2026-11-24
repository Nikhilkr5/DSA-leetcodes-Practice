/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//Brute Force:: Hash Set
/*
Traverse the linked list and store every visited node.
The first node that we encounter again is the starting node of the cycle.
*/
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> visited;
//         ListNode* temp = head;

//         while(temp != NULL){
//             if(visited.find(temp) != visited.end()){
//                 return temp;
//             }
//             visited.insert(temp);
//             temp = temp->next;
//         }
//         return NULL;
//     }
// };
/*
Complexity
Time: O(n)
Space: O(n)
"I store every visited node in a hash set. When I encounter a node that is already present in the set, that node is the first repeated node, so it is the beginning of the cycle."
*/





//Optimal — Floyd's Cycle Detection ⭐⭐⭐
/*
There are two phases.
Phase 1 — Find whether a cycle exists
Use:
slow → 1 step
fast → 2 steps

If they never meet → no cycle.
If they meet → cycle exists.
Phase 2 — Find the starting node
Once slow and fast meet:
slow = head
Then move both pointers one step at a time.
slow → 1 step
fast → 1 step
The point where they meet again is the starting node of the cycle.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                break;
            }
        }

        //No Cycle
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }

        //Phase 2: find cycle starting point
        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

//Time  = O(n)
// Space = O(1)