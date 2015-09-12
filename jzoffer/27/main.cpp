#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if (str.size() == 0)
            return ans;
        vector<bool> used(9, false);
        // 对str重排序
        vector<char> chars;
        for (int i = 0, len = str.size(); i < len; ++i)
            chars.push_back(str[i]);
        sort(chars.begin(), chars.end());
        str = "";
        for (int i = 0, len = chars.size(); i < len; ++i)
            str += chars[i];
        // 构造字符排列
        Permutation(str, used, 1, str.size(), "", ans);
        return ans;
    }
private:
    void Permutation(string& str, vector<bool>& used, int no, int len, string prefix, vector<string>& ans) {
        if (no > len && find(ans.begin(), ans.end(), prefix) == ans.end()) {
            ans.push_back(prefix);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (used[i])
                continue;
            used[i] = true;
            Permutation(str, used, no + 1, len, prefix + str[i], ans);
            used[i] = false;
        }
    }
};

int main() {
    Solution s;
    vector<string> ans = s.Permutation("abca");
    for (int i = 0, len = ans.size(); i < len; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
