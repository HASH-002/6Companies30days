/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
   public:
    Node* quadBuilder(vector<vector<int>>& a, int x, int y, int len) {
        if (len == 1)
            return new Node(a[x][y] == 1, true);

        len /= 2;

        Node* tl = quadBuilder(a, x, y, len);
        Node* tr = quadBuilder(a, x, y + len, len);
        Node* bl = quadBuilder(a, x + len, y, len);
        Node* br = quadBuilder(a, x + len, y + len, len);

        if ((tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) &&
            ((tl->val && tr->val && bl->val && br->val) ||
             !(tl->val || tr->val || bl->val || br->val))) {
            return new Node(val, true);
        }

        return new Node(true, false, tl, tr, bl, br);
    }
    Node* construct(vector<vector<int>>& a) {
        return quadBuilder(a, 0, 0, a.size());
    }
};