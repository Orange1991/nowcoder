#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
            return false;
        stack<int> in;
        int posInPop = 0, posInPush = 0, len = popV.size(), curNum;
        while (posInPop < len) {
            curNum = popV[posInPop];
            if (!in.empty() && in.top() == curNum) {   // 当前元素在栈顶，弹出
                in.pop();
            } else {    // 当前元素不在栈顶
                // 新元素入栈
                while (posInPush < len && pushV[posInPush] != curNum)
                    in.push(pushV[posInPush++]);
                if (posInPush >= len)   // 没有在后续入栈中找到目标元素，说明早已入栈 
                    return false;     
                ++posInPush;
            }
            ++posInPop;
        }
        return true;
    }
};

void test(vector<int> pushV, vector<int> popV) {
    int len = pushV.size();
    if (len <= 0) return;
    cout << "[";
    for (int i = 0; i < len - 1; ++i)
        cout << pushV[i] << ",";
    cout << pushV[len - 1] << "],";
    cout << "[";
    for (int i = 0; i < len - 1; ++i)
        cout << popV[i] << ",";
    cout << popV[len - 1] << "],";
    Solution s;
    if (s.IsPopOrder(pushV, popV))
        cout << "true." << endl;
    else
        cout << "false." << endl;
}

int main() {
    vector<int> pushV;
    vector<int> popV;
    pushV.push_back(1);
    pushV.push_back(2);
    pushV.push_back(3);
    pushV.push_back(4);
    pushV.push_back(5);
    popV.push_back(4);
    popV.push_back(3);
    popV.push_back(5);
    popV.push_back(2);
    popV.push_back(1);

    test(pushV, popV);

    popV.clear();
    popV.push_back(4);
    popV.push_back(3);
    popV.push_back(5);
    popV.push_back(1);
    popV.push_back(2);

    test(pushV, popV);
    
    popV.clear();
    popV.push_back(4);
    popV.push_back(5);
    popV.push_back(3);
    popV.push_back(2);
    popV.push_back(1);

    test(pushV, popV);
    return 0;
}
