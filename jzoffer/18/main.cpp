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
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        vector<TreeNode*> last, cur, nextLast, nextCur;
        TreeNode *p, *s;
        last.push_back(pRoot);
        cur.push_back(pRoot->right);
        cur.push_back(pRoot->left);
        while (last.size() > 0) {
            for (int i = 0, len = last.size(); i < len; ++i) {
                p = last[i];
                s = cur[2 * i];
                p->left = s;
                if (s) { 
                    nextLast.push_back(s);
                    nextCur.push_back(s->right);
                    nextCur.push_back(s->left);
                }
                s = cur[2 * i + 1];
                p->right = s;
                if (s) { 
                    nextLast.push_back(s);
                    nextCur.push_back(s->right);
                    nextCur.push_back(s->left);
                }
            }
            last.clear();
            last.insert(last.begin(), nextLast.begin(), nextLast.end());
            nextLast.clear();
            cur.clear();
            cur.insert(cur.begin(), nextCur.begin(), nextCur.end());
            nextCur.clear();
        }
    }
};

void print(TreeNode* root) {
    if (root == NULL)
        return;
    
    cout << root->val << "->";
    print(root->left);
    print(root->right);
}

int main() {
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;
    Solution s;
    print(&n1);
    cout << endl;
    s.Mirror(&n1);
    print(&n1);
    cout << endl;
    return 0;
}
