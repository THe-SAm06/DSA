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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail = list2;
        ListNode* temp = list2;
        while(temp->next) temp = temp->next;
        tail = temp;

        int len = b-a+1;

        temp = list1;

        a--;

        while(a--){
            temp = temp->next;
        }
        ListNode* nxt = temp->next;
        temp ->next = list2;

        temp = nxt;

        while(len--){
            nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        tail->next = temp;
        return list1;
    }
};