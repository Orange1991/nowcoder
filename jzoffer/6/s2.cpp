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

        int index1 = 0, index2 = len - 1, mid = index1;
        while (rotateArray[index1] >= rotateArray[index2]) {
            if (index2 - index1 == 1) {
                return rotateArray[index2];
            }
            mid = (index1 + index2) / 2;
            if (rotateArray[index1] == rotateArray[index2] 
                    && rotateArray[index1] == rotateArray[mid]) {
                return normalSearch(rotateArray, index1, index2);
            }
            if (rotateArray[mid] >= rotateArray[index1])
                index1 = mid;
            else if (rotateArray[mid] <= rotateArray[index2])
                index2 = mid;
        }
        return rotateArray[mid];
    }
private:
    int normalSearch(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        int cur = start + 1;
        while (cur <= end) {
            if (nums[cur] >= nums[cur - 1]) ++cur;
            else break;
        }
        if (cur > end) --cur;
        return nums[cur];
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

    nums1.clear();
    nums1.push_back(1);
    nums1.push_back(0);
    nums1.push_back(1);
    nums1.push_back(1);
    nums1.push_back(1);
    test(nums1);
    return 0;
}
