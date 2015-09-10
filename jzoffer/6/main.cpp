#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if (len == 0) return 0;
        if (len == 1 || rotateArray[0] < rotateArray[len - 1])
            return rotateArray[0];
        int cur;
        for (cur = 1; cur < len; ++cur) {
            if (rotateArray[cur] < rotateArray[cur - 1])
                break;
        }
        return rotateArray[cur];
    }
};

void test(vector<int> nums) {
    int len = nums.size();
    if (len == 0) return;
    cout << "[";
    for (int i = 0; i < len - 1; ++i)
        cout << nums[i] << ",";
    cout << nums[len - 1] << "] : ";
    Solution s;
    cout << s.minNumberInRotateArray(nums) << endl;
}

int main() {
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(5);
    test(nums1);
    nums1.clear();

    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(1);
    test(nums1);

    return 0;
}
