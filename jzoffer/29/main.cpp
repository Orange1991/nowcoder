#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> kMins;
        int len = input.size();
        if (k > len)    // 非法输入
            return kMins; 
        // 构造小顶堆
        int center = len / 2 - 1;
        for (int index = center; index > -1; --index)   // 从中间元素开始调整堆
            heapify(input, len, index);
        // 获取最小的k个元素
        int tmp;
        for (int index = 0; index < k; ++index) {
            tmp = input[0];
            input[0] = input[len - index - 1];
            input[len - index - 1] = tmp;
            kMins.push_back(tmp);
            heapify(input, len - index - 1, 0);
        }
        return kMins;
    }
private:
    void heapify(vector<int>& nums, int len, int index) {
        int center = len / 2 - 1;
        if (index > center)
            return;
        int left = index * 2 + 1, right = index * 2 + 2;
        if (right < len) {
            if (nums[index] <= nums[left] && nums[index] <= nums[right])
                return;
            int bigger = nums[left] <= nums[right] ? left : right;
            int tmp = nums[bigger];
            nums[bigger] = nums[index];
            nums[index] = tmp; 
            heapify(nums, len, bigger);
        } else {
            if (nums[index] <= nums[left])
                return;
            int tmp = nums[left];
            nums[left] = nums[index];
            nums[index] = tmp;
            heapify(nums, len, left);
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(8);
    Solution s;
    vector<int> ans = s.GetLeastNumbers_Solution(nums, 4);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ",";
    cout << endl;
    return 0;
}
