#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        // 数字转化为字符串
        vector<string> strs;
        char buf[16];
        for (int index = 0, len = numbers.size(); index < len; ++index) {
            sprintf(buf, "%d", numbers[index]);
            strs.push_back(buf);
        }
       
        // 排序
        sort(strs.begin(), strs.end(), cmp);
    
        // 拼接构造最小数字
        string num = "";
        for (int index = 0, len = strs.size(); index < len; ++index) 
            num += strs[index];

        return num;
    }
private:
    static bool cmp(string a, string b) {
        return a + b < b + a;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(32);
    nums.push_back(321);
    Solution s;
    cout << s.PrintMinNumber(nums) << endl;
    return 0;
}
