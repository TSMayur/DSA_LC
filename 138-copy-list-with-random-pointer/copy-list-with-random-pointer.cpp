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
        unordered_map<Node*, Node*> o;
        o[nullptr] = nullptr;

        Node* cur = head;
        while (cur != nullptr) {
            if (o.find(cur) == o.end()) {
                o[cur] = new Node(0);
            }
            o[cur]->val = cur->val;
            if (o.find(cur->next) == o.end()) {
                o[cur->next] = new Node(0);
            }
            o[cur]->next = o[cur->next];
            if (o.find(cur->random) == o.end()) {
                o[cur->random] = new Node(0);
            }
            o[cur]->random = o[cur->random];
            cur = cur->next;
        }
        return o[head];
    }
};