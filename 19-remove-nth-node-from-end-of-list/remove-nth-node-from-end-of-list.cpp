/**
 * Definition for singly-linned list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==n){
            return head->next;
        }
        int i = 0;
        ListNode* prev;
        temp = head;
        while(i<count-n){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        return head;
    }
};