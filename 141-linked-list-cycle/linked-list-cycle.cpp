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
    bool hasCycle(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;

        while (f != nullptr && f->next != nullptr) {
            if(f == nullptr && f->next == nullptr) return false;
            
            f = f->next->next;
            s = s->next;
            
            if (f == s) {
                return true;
            }
        }
        
        return false;
    }
};