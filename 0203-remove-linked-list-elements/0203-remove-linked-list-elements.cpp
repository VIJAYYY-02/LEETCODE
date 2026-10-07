class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       //phele check hjead
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Now rest of the list 
        ListNode* p = head;
        while (p != nullptr && p->next != nullptr) {
            if (p->next->val == val) {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
