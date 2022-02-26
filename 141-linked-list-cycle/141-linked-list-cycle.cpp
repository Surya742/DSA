/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode *curr = head;
//         int it = 100000;
//         if(curr == NULL) return false;
//         while(curr->next != NULL && it != 0){
//             curr = curr->next;
//             it--;
//         }
//         if(it != 0){
//             return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};