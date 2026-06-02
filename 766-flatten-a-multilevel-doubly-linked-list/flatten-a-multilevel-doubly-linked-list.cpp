/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* temp = head;
        while(temp){
            if(temp->child){
                Node* nxt = temp->next;
                temp->next = flatten(temp->child);
                temp->next->prev = temp;
                temp->child = nullptr;
                while(temp->next) temp = temp->next;
                temp->next = nxt;
                if (nxt) nxt->prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};