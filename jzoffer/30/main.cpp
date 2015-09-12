#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        if (len == 0)
            return 0;
        int max = array[0], sum = max;
        for (int index = 1; index < len; ++index) {
            sum += array[index];
            if (sum > max)
                max = sum;
            if (sum <= 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(-3);
    nums.push_back(-2);
    nums.push_back(7);
    nums.push_back(-15);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    cout << s.FindGreatestSumOfSubArray(nums) << endl;
}
