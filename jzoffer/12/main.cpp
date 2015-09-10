#include <iostream>

using namespace std;

class Solution {
public:
    bool illegal;
    double Power(double base, int exponent) {
        illegal = false;    // initiallize
        if (base == 0)      // 0^x
            if (exponent > 0)   // x>0，0^x=0
                return 0.0;   
            else if (exponent == 0)
                return 1.0;     // 0^0=1
            else {              // x<0, illegal calculation
                illegal = true;
                return 0.0; 
            }
        if (exponent < 0)
            return 1 / powerWithPositiveExponent(base, -exponent);
        else
            return powerWithPositiveExponent(base, exponent);
    }
private:
    double powerWithPositiveExponent(double base, int exponent) {
        if (exponent == 0)  // x^0 = 1
            return 1;
        if (exponent == 1)  // x^1 = x
            return base;
        double ans = powerWithPositiveExponent(base, exponent >> 1);
        ans *= ans;
        if (exponent & 0x1)
            ans *= base;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.Power(0.0, 0) << endl;
    cout << s.Power(1.0, 0) << endl;
    cout << s.Power(2.1, -1) << endl;
    return 0;
}
