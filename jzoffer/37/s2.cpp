#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int end = data.size() - 1;
        if (end < 0)        // 数组为空，返回0
            return 0;
        int first = GetFirstK(data, k, 0, end);
        int last = GetLastK(data, k, 0, end);
        if (first != -1)
            return last - first + 1;
        else
            return 0;
    }
private:
    int GetFirstK(vector<int>& data, int k, int start, int end) {
        if (start > end)    // 找不到k
            return -1;  
        int center = (start + end) / 2;
        int midNum = data[center];
        if (midNum == k) {  // 找到一个k
            if ((center > 0 && data[center - 1] != k)   // 判断是否是第一个k
                    || center == 0)
                return center;
            else    // 当前不是第一个k，在前半段中查找第一个k
                return GetFirstK(data, k, start, center - 1);
        } 
        else if (midNum > k)    // 在前半段中查找
            return GetFirstK(data, k, start, center - 1);
        else    // 在后半段中查找
            return GetFirstK(data, k, center + 1, end);
    }
    int GetLastK(vector<int>& data, int k, int start, int end) {
        if (start > end)    // 找不到k
            return -1;  
        int center = (start + end) / 2;
        int midNum = data[center];
        if (midNum == k) {  // 找到一个k
            if ((center < data.size() - 1 && data[center + 1] != k) // 判断是否是最后一个k
                    || center == data.size() - 1)
                return center;
            else    // 当前不是最后一个k，在后半段中查找最后一个k
                return GetLastK(data, k, center + 1, end);
        } 
        else if (midNum > k)    // 在前半段中查找
            return GetLastK(data, k, start, center - 1);
        else    // 在后半段中查找
            return GetLastK(data, k, center + 1, end);
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
