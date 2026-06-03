/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp){
            Node* nd = new Node(temp->val);
            if(temp->next) nd->next = temp->next;
            temp->next = nd;
            temp = temp->next->next;
        }
        Node* dm = new Node(-1);
        Node* curr = dm;
        temp = head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            curr->next = temp->next;
            curr = curr->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dm->next;
    }
};