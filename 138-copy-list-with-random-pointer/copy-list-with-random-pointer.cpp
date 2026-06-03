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
        unordered_map<Node*,Node*> mp;
        Node* temp = head;
        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        Node* dm = new Node(-1);
        Node* curr = dm;
        temp = head;
        while(temp){
            curr->next = mp[temp];
            curr = curr->next;
            curr->random = mp[temp->random];
            temp = temp->next;
        }
        return dm->next;
    }
};