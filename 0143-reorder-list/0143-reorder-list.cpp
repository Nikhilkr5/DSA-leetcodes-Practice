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



//Brute force Code:  
/*
✅ Brute Force Approach (Using Array of Nodes)
💡 Brute Force Idea:
Linked list ke saare nodes ek array (vector) me store karo
Two pointers use karo:
i = start se
j = end se
Naya order banate hue next pointers reset karo
Last node ka next = nullptr
👉 Ye brute force hai kyunki O(n) extra space use hota hai.
*/
// T.C : O(n), S.C: O(n)

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         //Edge Case:
//         if(head == nullptr || head->next == nullptr) return;

//         //Step 1: store all nodes
//         vector<ListNode*> arr;
//         ListNode* temp = head;

//         while(temp != nullptr){
//             arr.push_back(temp);
//             temp = temp->next;
//         }

//         //Step 2: reorder using two pointers
//         int i=0;
//         int j= arr.size() - 1;

//         while(i<j) {
//             arr[i]->next = arr[j];
//             i++;

//             //Important check to avoid cycle
//             if(i==j) break;

//             arr[j]->next = arr[i];
//             j--;
//         }

//         //Step 3: terminate list
//         arr[i]->next = nullptr;
//     }
// };

/*
⚠️ Very Important Line (Avoid Infinite Loop)
        if (i == j) break;
Without this:
Middle node points to itself
Infinite loop / cycle ban jaata hai
*/





//Optimised Approach: T.C:O(n) , S.C:O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        // Edge case
        if (head == nullptr || head->next == nullptr) return;

        // STEP 1: Find middle (slow & fast pointers)
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;   // break list into two halves

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // STEP 3: Merge two halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {
            //save the next pointers of both halves
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            //now connection build
            first->next = second;
            second->next = t1;
            
            first = t1;
            second = t2;
        }
    }
};



//in coding round or interview do not prefer this  cto bhaiya code for this question althought it is correct but not professional:
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) return;

//         // Step 1: Find middle
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // Step 2: Reverse from slow (middle)
//         ListNode* prev = nullptr;
//         ListNode* curr = slow;

//         while (curr != nullptr) {
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         // Step 3: Merge
//         ListNode* l1 = head;
//         ListNode* l2 = prev;

//         while (l2->next != nullptr) {
//             ListNode* t1 = l1->next;
//             ListNode* t2 = l2->next;

//             l1->next = l2;
//             l2->next = t1;

//             l1 = t1;
//             l2 = t2;
//         }
//     }
// };