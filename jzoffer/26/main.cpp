#include <iostream>
#include <stack>

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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        stack<TreeNode*> nodes;
        TreeNode head(0), beforeHead(0);  // 便于统一处理
        head.right = pRootOfTree;
        TreeNode *last = &beforeHead, *node;
        nodes.push(&head);
        // 中序遍历的过程，构建双链表
        while (!nodes.empty()) {
            node = nodes.top(); // 取得下一个结点
            nodes.pop();        
            last->right = node; // 构建双链表的后指针
            node->left = last;  // 构建双链表的前指针
            last = node;        // 更新最后一个结点指针
            node = node->right; // 添加后续结点到栈中
            while (node) {
                nodes.push(node);
                node = node->left;
            }
        }
        last->right = NULL;     // 链表结尾指向NULL
        if (head.right != NULL) // 链表首结点指向NULL
            head.right->left = NULL;
        return head.right;
    }
};

int main() {
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9), n10(10);
    n2.left = &n1;
    n3.left = &n2; n3.right = &n4; 
    n5.left = &n3; n5.right = &n7;
    n7.left = &n6; n7.right = &n8;
    n8.right = &n9;
    n10.left = &n5; 
    Solution s;
    TreeNode *node = s.Convert(&n10), *last = node;
    while (node) {
        cout << node->val << "->";
        last = node;
        node = node->right;
    }
    cout << "NULL" << endl;
    while (last) {
        cout << last->val << "->";
        last = last->left;
    }
    cout << "NULL" << endl;
    return 0;
}
