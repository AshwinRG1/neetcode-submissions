class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }

        // If we're removing the head
        if (n == size) {
            return head->next;
        }

        current = head;
        ListNode* prev = nullptr;
        while (size != n) {
            prev = current;
            current = current->next;
            size--;
        }
        // Now `current` is the node to remove, `prev` is the one before it

        prev->next = current->next;
        return head;
    }
};