#include <iostream>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n < 1) return 0;    // 非法输入
        if (n < 10) return 1;   // 10以下的数字仅有1
        int count = 0, offset = 0;
        long long num = n, rest, nums = 1;
        while (num >= 10) { // 处理数字，获取除去最高位的其他位
            ++offset;   // 低位的位数
            num /= 10;  // num去掉低位，最终只留下最低位
            nums *= 10; // 低位共能构成多少个数字
        }

        // 统计低10^offset+1以下的数字中低offset位中的1，例如2345中000-999的个数
        // 每个数字都由offset位构成，所以共有offset*nums个位
        // 这些位中0-9出现的次数是相同的，因此其中有1/10个位是数字1
        // 另外，在上述处理结束后num为最高位数字，其低offset位出现了num次，
        // 例如，2345中000-999出现了2次，即0000-0999和1000-1999
        // 因此，10^offset+1以下的数字中低offset位中1的个数应该为num * offset * nums / 10;
        count += num * offset * nums / 10;

        rest = n - num * nums;

        // 统计第n位中1的个数
        if (num > 1)    // 如果最高位大于1，则低n-1位可以构成的所有数字前面都可以加一个1
            count += nums;  // 所以第n位有nums个1
        else    // 如果最高位等于1，则仅有rest个数字前面可以加1
            count += rest + 1;

        // 统计10^offset+1以上的数字中低offset位中1的个数
        count += NumberOf1Between1AndN_Solution(rest);
        
        return count;
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 101; ++i) {
        cout << i << " : " << s.NumberOf1Between1AndN_Solution(i) << endl;
    }
    cout << 345 << " : " << s.NumberOf1Between1AndN_Solution(345) << endl;
    cout << 2345 << " : " << s.NumberOf1Between1AndN_Solution(2345) << endl;
    cout << 824883294 << " : " << s.NumberOf1Between1AndN_Solution(824883294) << endl;
    return 0;
}

