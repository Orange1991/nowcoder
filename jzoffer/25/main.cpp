#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        unordered_map<RandomListNode*, RandomListNode*> nodesMap;
        RandomListNode head(0), *originNode = pHead, *node, *last = &head;
        // 拷贝next结构
        while (originNode) {
            node = new RandomListNode(originNode->label);  // 新建结点
            last->next = node;  // 构造next链接
            last = node;
            nodesMap.insert(make_pair(originNode, node));// 保存结点的映射关系
            originNode = originNode->next;
        }
        // 拷贝random结构
        originNode = pHead;
        node = head.next;
        while (originNode) {
            if (originNode->random != NULL)
                node->random = nodesMap[originNode->random];
            originNode = originNode->next;
            node = node->next;
        }
        return head.next;
    }
};

int main() {
    RandomListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
    n1.random = &n3; n2.random = &n4;
    Solution s;
    RandomListNode* copy = s.Clone(&n1);
    while (copy) {
        cout << copy->label << ",";
        if (copy->random)
            cout << copy->random->label << endl;
        else
            cout << "NULL" << endl;
        copy = copy->next;
    }
    return 0;
}
