class TreeAncestor {
public:
    vector<vector<int>> upward;
    int rows;
    int cols;

    TreeAncestor(int n, vector<int>& parent) {
        rows = n;
        cols = log2(n) + 1;

        upward.resize(rows, vector<int>(cols, -1));

        for (int node = 0; node < n; node++) {
            upward[node][0] = parent[node];
        }

        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < rows; node++) {

                if (upward[node][j - 1] != -1) {

                    upward[node][j] = upward[ upward[node][j - 1] ][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for (int j = 0; j < cols; j++) {

                if (k & (1 << j)) { // if jth bit is set, then we can take 2^j jump
                    node = upward[node][j];

                    if (node == -1) {
                        return -1;
                    }
                }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */