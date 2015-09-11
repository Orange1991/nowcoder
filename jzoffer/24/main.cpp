#include <iostream>
#include <vector>

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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > paths;
        vector<int> path;
        if (root != NULL) 
            FindPathInSubtree(root, expectNumber, path, paths);
        return paths;
    }
private:
    void FindPathInSubtree(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (node->val == sum && node->left == NULL && node->right == NULL) {
            path.push_back(sum);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(node->val);
        if (node->left != NULL)
            FindPathInSubtree(node->left, sum - node->val, path, paths);
        if (node->right != NULL)
            FindPathInSubtree(node->right, sum - node->val, path, paths);
        path.pop_back();
    }
};

int main() {
    TreeNode n1(1), n2(2), n3(3), n4(3), n5(2), n6(0);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n5.right = &n6;
    n3.left = &n5;
    Solution s;
    vector<vector<int> > paths = s.FindPath(&n1, 6);
    for (int i = 0, lenI = paths.size(); i < lenI; ++i) {
        for (int j = 0, lenJ = paths[i].size(); j < lenJ; ++j) {
            cout << paths[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
