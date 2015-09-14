#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int count = 0, start = 0, end = data.size() - 1;
        if (end < 0)        // 数组为空，返回0
            return count;

        // 二分查找，找到一个目标数字
        int center = (start + end) / 2;
        while (start <= end && data[center] != k) {
            if (data[center] > k)
                end = center - 1;
            else 
                start = center + 1;
            center = (start + end) / 2;
        }

        // 如果找到了一个目标数字，则往左右扩展
        if (data[center] == k) {
            count = 1;
            start = center - 1;
            while (start > -1 && data[start--] == k)
                ++count;
            end = center + 1;
            int last = data.size();
            while (end < last && data[end++] == k)
                ++count;
        }

        return count;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);

    cout << "[";
    for (int i = 0, len = nums.size(); i < len - 1; ++i)
        cout << nums[i] << ",";
    cout << nums[nums.size() - 1] << "] : " << endl;
    Solution s;

    cout << -1 << " : " << s.GetNumberOfK(nums, -1) << endl;
    cout << 0 << " : " << s.GetNumberOfK(nums, 0) << endl;
    cout << 1 << " : " << s.GetNumberOfK(nums, 1) << endl;
    cout << 2 << " : " << s.GetNumberOfK(nums, 2) << endl;
    cout << 3 << " : " << s.GetNumberOfK(nums, 3) << endl;
    cout << 4 << " : " << s.GetNumberOfK(nums, 4) << endl;
    cout << 5 << " : " << s.GetNumberOfK(nums, 5) << endl;

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout << "[";
    for (int i = 0, len = nums.size(); i < len - 1; ++i)
        cout << nums[i] << ",";
    cout << nums[nums.size() - 1] << "] : " << endl;
    cout << 3 << " : " << s.GetNumberOfK(nums, 3) << endl;
    return 0;
}
