class TrieNode {
public:
    TrieNode* child[10];

    TrieNode() {
        for (int i = 0; i < 10; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    void insert(TrieNode* root, string &s) {
        TrieNode* node = root;

        for (char c : s) {
            int idx = c - '0';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }
    }

    int getPrefixLen(TrieNode* root, string &s) {
        TrieNode* node = root;
        int len = 0;

        for (char c : s) {
            int idx = c - '0';

            if (!node->child[idx]) break;

            node = node->child[idx];
            len++;
        }

        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();

        for (int num : arr1) {
            string s = to_string(num);
            insert(root, s);
        }

        int ans = 0;

        for (int num : arr2) {
            string s = to_string(num);
            ans = max(ans, getPrefixLen(root, s));
        }

        return ans;
    }
};