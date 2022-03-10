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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        if(head->val == head->next->val && head->next->next == NULL) return NULL;
        if(head->next->next == NULL) return head;
        
        ListNode* curr = head;
        ListNode* newHead = head;
        while(curr != NULL && curr->next != NULL && curr->val == curr->next->val){
        while(curr != NULL && curr->next != NULL && curr->val == curr->next->val){
            curr = curr->next;
        }
        if(curr != head){
            newHead = curr->next;
        }
        if(newHead == NULL) return NULL;
        curr = newHead;
         }
        int temp=INT_MAX;
        while(curr != NULL && curr->next != NULL && curr->next->next != NULL){
            
            if(curr->next->val == curr->next->next->val){
                ListNode* temp1 = curr->next;
                ListNode* temp2 = curr->next->next;
                temp = curr->next->val;
                curr->next = curr->next->next->next;
                
                delete(temp2);
                delete(temp1);
            }else{
                if(curr->next->val == temp){
                    ListNode* tempdel = curr->next;
                    curr->next = curr->next->next;
                    delete(tempdel);
                    // curr = curr->next;
                    
                }else{
                    curr = curr->next;
                } 
            }
        }
        if(curr->next){
            if(curr->next->val == temp){
                    ListNode* tempdel = curr->next;
                    curr->next = curr->next->next;
                    delete(tempdel);
                }
        }
        
        return newHead;
    }
};