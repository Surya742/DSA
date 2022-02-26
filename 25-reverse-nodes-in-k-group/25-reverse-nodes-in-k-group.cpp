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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        
        ListNode* dum = new ListNode(0);
        dum->next = head;
        
        ListNode* curr = dum, *nex = dum, *pre = dum;
        int cnt = 0;
        
        while(curr->next != NULL){
            curr = curr->next;
            cnt++;
        }
        
        while(cnt >= k){
            curr = pre->next;
            nex = curr->next;
            for(int i = 1; i < k; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            cnt -= k;
        }
        return dum->next;
    }
};