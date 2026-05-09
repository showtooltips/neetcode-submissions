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
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        }
        ListNode *curr = new ListNode(head->val, head->next);
        ListNode *prev = nullptr;

        while (1) {
            curr->next = prev;
            prev = curr;
            if (head->next == nullptr) break;
            head = head->next;
            curr = new ListNode(head->val);
        }
        return prev;
    }
};
