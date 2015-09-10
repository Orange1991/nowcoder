#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> rtn;
        printNext(rtn, head);
        return rtn;
    }
private:
    void printNext(vector<int>& rtn, struct ListNode* node) {
        if (node == NULL) return;
        printNext(rtn, node->next);
        rtn.push_back(node->val);
    }
};

int main() {
    struct ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Solution s;
    struct ListNode* p = &n1;
    while (p) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
    vector<int> rtn = s.printListFromTailToHead(&n1);
    for (vector<int>::iterator it = rtn.begin(), end = rtn.end(); it != end; ++it) {
        cout << *it << "->";
    }
    cout << "NULL" << endl;
    return 0;
}
