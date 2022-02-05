// Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// problem Link: https://leetcode.com/problems/merge-k-sorted-lists/

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
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l1 = NULL;
        if(lists.size() == 0){
            return l1;
        }
        
        if(lists.size() == 1 && lists[0] == NULL){
            return lists[0];
        }
        
        l1 = lists[0];
        
        for(int i = 1; i < lists.size(); i++){
            ListNode* l2 = lists[i];
            l1 = mergeTwoLists(l1,l2);
        }
        return l1;
    }
};