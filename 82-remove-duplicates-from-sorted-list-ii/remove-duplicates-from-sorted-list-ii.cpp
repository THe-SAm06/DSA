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
    ListNode* del(ListNode* temp,int val){
        ListNode* nxt;
        while(temp && temp->val == val){
            nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        return temp;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp){
            if(temp->next && temp->next->val == temp->val){
                while(temp && temp->next && temp->next->val == temp->val){
                    int val = temp->val;
                    temp = del(temp,val);
                    if(prev) prev->next = temp;
                    else head = temp;
                }
            }
            else if(temp){
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};