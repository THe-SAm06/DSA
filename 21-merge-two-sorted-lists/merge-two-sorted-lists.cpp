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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dm = new ListNode(-1);
        ListNode* temp = dm;
        while(l1 && l2){
            if(l1->val<=l2->val){
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while(l1){
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2){
            temp->next = new ListNode(l2->val);
            l2 = l2->next;
            temp = temp->next;
        }
        return dm->next;
    }
};