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
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
    
        // 统计两个单链表中结点的个数
        ListNode *p1 = pHead1, *p2 = pHead2;
        int num1 = 0, num2 = 0;
        while (p1 != NULL) {
            ++num1;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            ++num2;
            p2 = p2->next;
        }

        // 移动较长的链表
        p1 = pHead1;
        p2 = pHead2;
        if (num1 > num2) {
            while (num1 > num2) {
                p1 = p1->next;
                --num1;
            }
        } else if (num2 > num1) {
            while (num2 > num1) {
                p2 = p2->next;
                --num2;
            }
        }

        // 寻找第一个相同的结点
        while (p1 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};

int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n1.next = &n2;
    n2.next = &n3;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n1;
    n7.next = &n1;
    Solution s;
    ListNode *ans = s.FindFirstCommonNode(&n4, &n7);
    if (ans != NULL)
        cout << ans->val << endl;
    else
        cout << "NULL" << endl;
    return 0;
}
