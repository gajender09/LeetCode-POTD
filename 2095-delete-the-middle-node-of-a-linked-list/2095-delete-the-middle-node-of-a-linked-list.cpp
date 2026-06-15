class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return NULL;

        int count = 0;

        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = new ListNode(-1);
        prev->next = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            prev = prev->next;
        }

        if (count % 2 == 0) {
            ListNode* mid = slow->next;
            ListNode* nextNode = mid->next;
            mid->next = NULL;
            slow->next = nextNode;
            delete (mid);
        } 
        else {
            ListNode* mid = slow;
            ListNode* nextNode = mid->next;
            mid->next = NULL;
            prev->next = nextNode;
            delete (mid);
        }

        return head;
    }
};