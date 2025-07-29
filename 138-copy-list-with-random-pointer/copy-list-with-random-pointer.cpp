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
        if(head==NULL) return NULL; //Edge case

        // Step1 : Create copy nodes in bw original nodes
        Node* temp = head;
        while(temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }

        //Step 2: Connect random pointers of copy nodes
        temp = head;
        while(temp) {
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        //Step 3: Disconnect the copied nodes from bw the original nodes
        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp) {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};