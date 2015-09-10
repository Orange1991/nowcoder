#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        return construct(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
    }
private:
    struct TreeNode* construct(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie) {
        if (ps > pe) return NULL;
        struct TreeNode* node = new struct TreeNode(pre[ps]);
        if (ps == pe) return node;
        int p = is;
        while (in[p] != pre[ps]) ++p;
        node->left = construct(pre, ps + 1, ps + p - is, in, is, p - 1);
        node->right = construct(pre, ps + p - is + 1, pe, in, p + 1, ie);
        return node;
    }
};

void pre(struct TreeNode* root, vector<int>& rtn) {
    if (root == NULL) return;
    rtn.push_back(root->val);
    pre(root->left, rtn);
    pre(root->right, rtn);
} 

void in(struct TreeNode* root, vector<int>& rtn) {
    if (root == NULL) return;
    in(root->left, rtn);
    rtn.push_back(root->val);
    in(root->right, rtn);
} 

void print(string str, vector<int>& vec) {
    cout << str;
    for (vector<int>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
        cout << *it << "->";
    cout << "NULL" << endl;
}

int main() {
    vector<int> p, i;
    p.push_back(1); i.push_back(5);
    p.push_back(2); i.push_back(4);
    p.push_back(4); i.push_back(6);
    p.push_back(5); i.push_back(7);
    p.push_back(6); i.push_back(2);
    p.push_back(7); i.push_back(1);
    p.push_back(3); i.push_back(8);
    p.push_back(8); i.push_back(11);
    p.push_back(10); i.push_back(10);
    p.push_back(11); i.push_back(12);
    p.push_back(12); i.push_back(3);
    p.push_back(9); i.push_back(9);
    p.push_back(13); i.push_back(14);
    p.push_back(14); i.push_back(13);

    Solution s;
    struct TreeNode* rtn = s.reConstructBinaryTree(p, i);
    vector<int> pr, ir;
    pre(rtn, pr); 
    in(rtn, ir); 
    print("original      pre: ", p);
    print("reConstructed pre: ", pr);
    print("original       in: ", i);
    print("reConstructed  in: ", ir);

    p.clear();
    i.clear();
    pr.clear();
    ir.clear();

    p.push_back(1); i.push_back(4);
    p.push_back(2); i.push_back(7);
    p.push_back(4); i.push_back(2);
    p.push_back(7); i.push_back(1);
    p.push_back(3); i.push_back(5);
    p.push_back(5); i.push_back(3);
    p.push_back(6); i.push_back(8);
    p.push_back(8); i.push_back(6);
    
    rtn = s.reConstructBinaryTree(p, i);
    pre(rtn, pr); 
    in(rtn, ir); 
    print("original      pre: ", p);
    print("reConstructed pre: ", pr);
    print("original       in: ", i);
    print("reConstructed  in: ", ir);
    
    return 0;
}

