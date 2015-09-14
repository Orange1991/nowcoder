#include <iostream>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {

        if (str == "")
            return -1;

        // 初始化
        int hashtable[256];
        for (int i = 0; i < 256; ++i)
            hashtable[i] = 0;

        // 频率统计
        for (int i = 0, len = str.size(); i < len; ++i)
            ++hashtable[str[i]];

        // 找到第一个只出现一次的字符的位置
        for (int i = 0, len = str.size(); i < len; ++i)
            if (hashtable[str[i]] == 1)
                return i;

        // 如果没有则返回-1
        return -1;
    }
};

int main() {
    Solution s;
    cout << "bbcad : " << s.FirstNotRepeatingChar("bbcad") << endl;
    cout << "google: " << s.FirstNotRepeatingChar("google") << endl;
    return 0;
}
