#include <iostream>

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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) return pHead;
        ListNode *last = pHead, *cur = pHead->next, *next;
        last->next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
};

int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
    Solution s;
    ListNode * tmp = &n1;
    while (tmp) {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
    tmp = s.ReverseList(&n1);
    while (tmp) {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
    return 0;
}

