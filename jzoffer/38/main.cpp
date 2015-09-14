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
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == NULL)
            return 0;
        return bigger(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
private:
    int bigger(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    TreeNode n1(1), n2(2), n3(3);
    n1.left = &n2;
    n2.right = &n3;
    Solution s;
    cout << s.TreeDepth(&n1) << endl;
}
