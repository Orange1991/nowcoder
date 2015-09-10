#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> copy(array.begin(), array.end());
        array.clear();
        for (vector<int>::iterator it = copy.begin(), end = copy.end(); it != end; ++it)
            if ((*it) & 0x1 == 1)
                array.push_back(*it);
        for (vector<int>::iterator it = copy.begin(), end = copy.end(); it != end; ++it)
            if (!((*it) & 0x1))
                array.push_back(*it);
    }
};

void test(vector<int> vec) {
    int len = vec.size();
    if (len == 0) return;
    cout << "[";
    for (int i = 0 ; i < len - 1; ++i)
        cout << vec[i] << ",";
    cout << vec[len - 1] << "],";
    cout << " [";
    Solution s;
    s.reOrderArray(vec);
    for (int i = 0 ; i < len - 1; ++i)
        cout << vec[i] << ",";
    cout << vec[len - 1] << "]" << endl;
}

int main() {
    vector<int> vec;
    for (int i =0; i < 10; ++i)
        vec.push_back(i);
    test(vec);
    return 0;
}
