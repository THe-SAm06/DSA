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
    ListNode* reverse(ListNode* temp){
        ListNode* prev = nullptr;
        ListNode* nxt;
        while(temp){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* temp, int k){
        k--;
        while(k--){
           if(temp) temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevtail = nullptr;
        while(temp){
            ListNode* KthNode = findKthNode(temp,k);
            if(!KthNode){
                if(prevtail) prevtail->next = temp;
                break;
            }
            ListNode* next = KthNode->next;
            KthNode->next = nullptr;
            KthNode = reverse(temp);
            if(temp == head){
                head = KthNode;
            }
            if(prevtail) prevtail->next = KthNode;
            temp->next = next;
            prevtail = temp;
            temp = next;
        }
        return head;
    }
};