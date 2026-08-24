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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;

        while(temp){
            st.push(temp);
            temp = temp->next;
        }

        temp = head;
        ListNode* nxt;
        while(temp != st.top()){
            nxt = temp->next;
            temp->next = st.top();
            st.pop();
            if(temp->next->next == nxt) break;
            temp->next->next = nxt;
            temp = nxt;;
        }
        temp->next = nullptr;
    }
};