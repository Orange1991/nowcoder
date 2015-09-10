#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int value) {
        if (minNums.empty() || minNums.top() >= value)
            minNums.push(value);
        nums.push(value);
    }
    void pop() {
        if (nums.top() == minNums.top())
            minNums.pop();
        nums.pop();
    }
    int top() {
        return nums.top();
    }
    int min() {
        return minNums.top();
    }
private:
    stack<int> nums;
    stack<int> minNums;
};

int main() {
    Solution s;
    s.push(10);
    cout << s.min() << endl;
    s.push(6);
    cout << s.min() << endl;
    s.push(3);
    cout << s.min() << endl;
    s.push(4);
    cout << s.min() << endl;
    s.push(3);
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    s.pop();
    cout << s.min() << endl;
    return 0;
}
