class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // traverse lists and push first node of every list into pq
        for (auto node : lists) {

            if (node != NULL) {
                pq.push({node->val, node});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {

            auto [value, node] = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next != NULL) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};