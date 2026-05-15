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
        if(head==nullptr)return nullptr;
        unordered_map<Node*,Node*> m1;

        Node* curr = head;

        while(curr){
            m1[curr]= new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr){
            m1[curr]->next = m1[curr->next];
            m1[curr]->random = m1[curr->random];
            curr= curr->next;
        }

        return m1[head];
    }
};
