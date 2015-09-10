#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Solution {
public:
    void replaceSpace(char *str, int length) {
        // 统计空格数目
        int spaces = 0;
        char *p = str;
        while (*p != '\0')
            if (*p++ == ' ')
                ++spaces;
        char* oldCur = str + length - 1;
        length += 2 * spaces;
        str = (char*)realloc(str, length);
        char* newCur = str + length  - 1;
        while (oldCur >= str && oldCur < newCur) {
            if (*oldCur == ' ') {
                *newCur-- = '0';
                *newCur-- = '2';
                *newCur-- = '%';
            } else {
                *newCur-- = *oldCur;
            }
            --oldCur;
        }
    }
};

void test(char *str, int len) {
    cout << str << endl;
    Solution s;
    s.replaceSpace(str, len);
    cout << str << endl;
}

int main() {
    char *str = (char*)malloc(sizeof(char)*13);
    *(str+12) = '\0';
    for (int i = 0; i < 12; ++i) 
        *(str + i) = 'a';
    
    *(str + 3) = ' ';
    *(str + 7) = ' ';
    *(str + 11) = ' ';
    test(str, 12);
    return 0;
}
