class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* current = head;

        while (current != NULL && current->next != NULL) {
            
            if (current->val == current->next->val) {
                // Skip the duplicate node
                current->next = current->next->next;
            }
            else {
                // Move to the next node
                current = current->next;
            }
        }

        return head;
    }
};