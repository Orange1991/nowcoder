#include <iostream>
#include <queue>

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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> nodes;
        if (root == NULL) return nodes;
    
        // 层序遍历
        queue<TreeNode*> nodesInLevel;
        nodesInLevel.push(root);
        TreeNode* node;
        while (!nodesInLevel.empty()) {
            node = nodesInLevel.front();
            nodesInLevel.pop();
            nodes.push_back(node->val);
            if (node->left != NULL)
                nodesInLevel.push(node->left);
            if (node->right != NULL)
                nodesInLevel.push(node->right);
        }
        return nodes;
    }
};

int main() {
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.right = &n4; n3.left = &n5;
    Solution s;
    vector<int> nodes = s.PrintFromTopToBottom(&n1);
    for (int i = 0, len = nodes.size(); i < len; ++i)
        cout << nodes[i] << ",";
    cout << endl;
    return 0;
}
