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
    ListNode* front(ListNode* head) { return head->next; }
    ListNode* anyOtherNode(ListNode* head, int val) {
        ListNode* temp = head;
        while (temp->next && temp->next->val != val) {
            temp = temp->next;
        }
        ListNode* p = temp->next;
        temp->next = p->next;
        p->next = NULL;
        delete p;
        return head;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        map<int, int> freq;
        ListNode* temp = head;
        while (temp) {
            freq[temp->val]++;
            temp = temp->next;
        }
        temp = head;
        while (temp && freq[temp->val] > 1) {
            while (freq[temp->val]--) {
                head = front(head);
            }
            temp = head;
        }
        for (auto it : freq) {
            if (it.second > 1) {
                while (it.second--) {
                    head = anyOtherNode(head, it.first);
                }
            }
        }
        return head;
    }
};