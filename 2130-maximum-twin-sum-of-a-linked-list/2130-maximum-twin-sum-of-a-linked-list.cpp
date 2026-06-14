class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        secondHalf = reverseList(secondHalf);

        ListNode* firstHalf = head;

        int maxSum = 0;

        while (secondHalf != nullptr) {

            maxSum = max(maxSum, firstHalf->val + secondHalf->val);

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxSum;
    }
};