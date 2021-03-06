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
        unordered_map<Node*, Node*> ump;
        Node* curr = head;
        while (curr != NULL) {
            Node* copy = new Node(curr->val);
            ump[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while (curr != NULL) {
            ump[curr]->next = ump[curr->next];
            ump[curr]->random = ump[curr->random];
            curr = curr->next;
        }
        return ump[head];
    }
};
