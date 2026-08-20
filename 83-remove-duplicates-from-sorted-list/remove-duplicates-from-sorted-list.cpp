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
    ListNode* del(ListNode *temp){
        ListNode* delnode = temp->next;
        ListNode* nxt = nullptr;
        if(temp->next){
            nxt = temp->next->next;
        }
        temp->next = nxt;
        delete delnode;
        return temp;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        while(temp->next){
            if(temp->val == temp->next->val){
                temp = del(temp);
                if(!temp) break;
            }
            else temp = temp->next;
        }
        return head;
    }
};