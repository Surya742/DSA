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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* res = head;
        int count = 0;
        while(res != NULL){
            count++;
            res = res->next;
        }
        res = head;
        if(res == NULL || res->next == NULL){
                return head;
            }
        for(int i = 0; i < (k%count); i++){
            ListNode* curr = res;
            
            while(curr->next->next != NULL){
                curr = curr->next;
            }
            ListNode* temp = curr->next;
            temp->next = res;
            curr->next = NULL;
            res = temp;
        }
        
        return res;
    }
};