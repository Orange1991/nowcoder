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
        int height = 0;
        return IsBalanceTree(pRoot, height);
    }
private:
    bool IsBalanceTree(TreeNode* pRoot, int& height) {
        if (pRoot == NULL)  // 空树是平衡二叉树
            return true;

        int leftSubTreeHeight = 0, rightSubTreeHeight = 0;
        // 验证左子树是否是平衡二叉树
        if (!IsBalanceTree(pRoot->left, leftSubTreeHeight))
            return false;
        // 验证右子树是否是平衡二叉树
        if (!IsBalanceTree(pRoot->right, rightSubTreeHeight))
            return false;

        // 验证左右子树的深度是否符合条件
        int diff = leftSubTreeHeight - rightSubTreeHeight;
        if (diff < 0) 
            diff = -diff;
        if (diff > 1) 
            return false;

        // 为当前子树的深度赋值
        height = leftSubTreeHeight > rightSubTreeHeight
                ? leftSubTreeHeight + 1
                : rightSubTreeHeight + 1;
        return true;
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
