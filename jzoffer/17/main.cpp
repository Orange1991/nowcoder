#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL || pRoot1 == NULL) return false;
        if (pRoot1->val == pRoot2->val)
            return isSameTree(pRoot1, pRoot2) 
                    || HasSubtree(pRoot1->left, pRoot2)
                    || HasSubtree(pRoot1->right, pRoot2);
        else
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

    }
private:
    bool isSameTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;
        if (pRoot1->val != pRoot2->val) return false;
        return isSameTree(pRoot1->left, pRoot2->left) && isSameTree(pRoot1->right, pRoot2->right);
    }
};

int main() {
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;
    TreeNode n6(2), n7(4), n8(5);
    n6.left = &n7; n6.right = &n8;
    Solution s;
    if (s.HasSubtree(&n1, &n6))
        cout << "Has." << endl;
    else 
        cout << "Has not." << endl;
    TreeNode n9(6);
    n7.left = &n9;
    if (s.HasSubtree(&n1, &n6))
        cout << "Has." << endl;
    else 
        cout << "Has not." << endl;
    return 0;
}
