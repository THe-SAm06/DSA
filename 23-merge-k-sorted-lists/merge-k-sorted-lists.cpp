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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dm = new ListNode(-1);
        ListNode* temp = dm;
        int count =0;
        for(int i=0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp){
                count++;
                temp = temp->next;
            }
        }
        for(int i=0;i<count;i++){
            int mn = INT_MAX;
            int idx;
            for(int j = 0;j<lists.size();j++){
                if(lists[j] && (lists[j]->val)<=mn){
                    mn = lists[j]->val;
                    idx = j;
                }
            }
            temp->next = new ListNode(mn);
            lists[idx] = lists[idx]->next;
            temp = temp->next;
        }
        return dm->next;
    }
};