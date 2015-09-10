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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode head(0);
        ListNode *tmp = &head;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                tmp->next = pHead1;
                tmp = tmp->next;
                pHead1 = pHead1->next;
            } else {
                tmp->next = pHead2;
                tmp = tmp->next;
                pHead2 = pHead2->next;
            }
        }

        if (pHead1)
            tmp->next = pHead1;        
        if (pHead2) 
            tmp->next = pHead2;
        
        return head.next;
    }
};

int main() {
    ListNode n1(1), n2(3), n3(5), n4(7), n5(9);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
    ListNode n6(2), n7(4), n8(6), n9(8), n10(10);
    n6.next = &n7; n7.next = &n8; n8.next = &n9; n9.next = &n10;
    Solution s;
    ListNode * tmp = &n1;
    while (tmp) {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
    tmp = &n6;
    while (tmp) {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
    tmp = s.Merge(&n1, &n6);
    while (tmp) {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
    return 0;
}

