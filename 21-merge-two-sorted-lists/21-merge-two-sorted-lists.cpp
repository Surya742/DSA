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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        if(l1->val <= l2->val){
            head = tail = l1;
            l1 = l1->next;
        }else{
            head = tail = l2;
            l2 = l2->next;
        }
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        
        if(l1 == NULL){
            tail->next = l2;
            
        }else{
            tail->next = l1;
        }
        
        return head;
//         if(l1 == NULL && l2 == NULL){
//             return l1;
//         }else if(l1 == NULL){
//             return l2;
//         }else if(l2 == NULL){
//             return l1;
//         }
        
//         ListNode* res;
//         ListNode* curr1 = l1;
//         ListNode* curr2 = l2;
//         ListNode* resCurr;
        
//         if(l1->val <= l2->val){
//             ListNode* temp = new ListNode(curr1->val);
//             res = temp;
//             resCurr = res;
//             curr1 = curr1->next;
//         }else{
//             ListNode* temp = new ListNode(curr2->val);
//             res = temp;
//             resCurr = res;
//             curr2 = curr2->next;
//         }
        
//         while(curr1 != NULL && curr2 != NULL){
//             if(curr1->val <= curr2->val){
//                 ListNode* temp = new ListNode(curr1->val);
//                 resCurr->next = temp;
//                 resCurr = resCurr->next;
//                 // res = insertEnd(res,curr1->val);
//                 curr1 = curr1->next;
//             }else{
//                 ListNode* temp = new ListNode(curr2->val);
//                 resCurr->next = temp;
//                 resCurr = resCurr->next;
//                 // res = insertEnd(res, curr2->val);
//                 curr2 = curr2->next;
//             }
//         }
        
//         while(curr1 != NULL){
//             ListNode* temp = new ListNode(curr1->val);
//                 resCurr->next = temp;
//                 resCurr = resCurr->next;
//                 // res = insertEnd(res,curr1->val);
//                 curr1 = curr1->next;
//         }
        
//         while(curr2 != NULL){
//             ListNode* temp = new ListNode(curr2->val);
//                 resCurr->next = temp;
//                 resCurr = resCurr->next;
//                 // res = insertEnd(res, curr2->val);
//                 curr2 = curr2->next;
//         }
        
//         return res;
    }
};