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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* lists1 = l1;
        ListNode* lists2 = l2;
        ListNode* dm = new ListNode(-1);
        ListNode* temp = dm;
        while(lists1 && lists2){
            if(lists1->val<=lists2->val){
                temp->next = new ListNode(lists1->val);
                lists1 = lists1->next;
            }
            else{
                temp->next = new ListNode(lists2->val);
                lists2 = lists2->next;
            }
            temp = temp->next;
        }
        while(lists1){
            temp->next = new ListNode(lists1->val);
            lists1 = lists1->next;
            temp = temp->next;
        }
        while(lists2){
            temp->next = new ListNode(lists2->val);
            lists2 = lists2->next;
            temp = temp->next;
        }
        return dm->next;
    }
    ListNode* mergeKListsf(vector<ListNode*>& lists,int l, int r){
        if(l == r) return lists[l];
        int mid = (l+r)/2;
        ListNode *left = mergeKListsf(lists,l,mid);
        ListNode* right = mergeKListsf(lists,mid+1,r);
        return merge(left,right);
    }
   ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;
    return mergeKListsf(lists,0,lists.size()-1);
}
};