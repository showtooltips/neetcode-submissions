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

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode *newHead = head;

        if (head->next != nullptr) {
            newHead = reverseList(head->next);

            // Makes the pointer of the next node point to the
            // current one, inverting the order between these nodes
            head->next->next = head;
        }

        // Clears the current node pointer from pointing to its original
        // next node, because its original next node now points back at the 
        // current node and they would be left pointing at each other without 
        // this line
        head->next = nullptr;
        
        // newHead holds the node at the end of the original list
        // and since it points to the original node address which is being
        // updated in every iteration, inverting the order of the pointers
        // between nodes, it acts as a bookmark in the last node that now is
        // the starting node. It's as if the node's positions never changes 
        // inside the list and at the end of all the recursive calls, we are left
        return newHead;
    }
};
