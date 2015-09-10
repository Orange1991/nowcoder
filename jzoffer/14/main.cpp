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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *fast = pListHead, *slow = pListHead;
        while (fast && k > 0) {
            fast = fast->next;
            --k;
        }
        if (k > 0) {
            return NULL;
        } else {
            while (fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
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
    for (int i = 0; i < 7; ++i) {
        tmp = s.FindKthToTail(&n1, i);
        if (tmp != NULL)
            cout << i << ": " << tmp->val << endl;
        else
            cout << i << ": NULL" << endl;
    }
    return 0;
}
