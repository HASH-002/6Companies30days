class Solution {
   public:
    int solve(Node *r) {
        if (!r)
            return 0;

        int left = solve(r->left);
        int right = solve(r->right);
        int old_data = r->data;
        r->data = left + right;
        return old_data + left + right;
    }
    void toSumTree(Node *node) {
        solve(node);
    }
};