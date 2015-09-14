#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL)
            return true;

        int lHegiht = Height(pRoot->left),
            rHeight = Height(pRoot->right);

        int diff = lHegiht - rHeight;
        if (diff < 0) diff = -diff;
        if (diff > 1)
            return false;

        return IsBalanced_Solution(pRoot->left)
            && IsBalanced_Solution(pRoot->right);
    }
private:
    int Height(TreeNode* pRoot) {
        if (pRoot == NULL)
            return 0;
        int lHeight = Height(pRoot->left);
        int rHeight = Height(pRoot->right);
        return (lHeight > rHeight ? lHeight : rHeight) + 1;
    }
};

int main() {
    TreeNode n1(1), n2(2), n3(3);
    n1.left = &n2;
    n1.right = &n3;
    Solution s;

    if (s.IsBalanced_Solution(&n1))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    TreeNode n4(4), n5(5);
    n2.left = &n4;
    if (s.IsBalanced_Solution(&n2))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    if (s.IsBalanced_Solution(&n1))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    n4.right = &n5;
    if (s.IsBalanced_Solution(&n2))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    if (s.IsBalanced_Solution(&n1))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
}
