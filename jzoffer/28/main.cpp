#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int candidate, times = 0, len = numbers.size();
        for (int index = 0; index < len; ++index)
            if (times == 0) {
                candidate = numbers[index];
                times = 1;
            } 
            else if (candidate == numbers[index])
                ++times;
            else
                --times;
        // 验证候选值
        times = 0;
        for (int index = 0; index < len; ++index)
            if (numbers[index] == candidate)
                ++times;
        
        return times > len / 2 ? candidate : 0;
    }
};

void test(vector<int> nums) {
    int len = nums.size();
    if (len == 0)
        return;
    cout << "[";
    for (int i = 0; i < len - 1; ++i)
        cout << nums[i] << ",";
    cout << nums[len - 1] << "] : ";
    Solution s;
    cout << s.MoreThanHalfNum_Solution(nums) << endl;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(2);
    test(nums);
    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(3);
    test(nums);
    return 0;
}
