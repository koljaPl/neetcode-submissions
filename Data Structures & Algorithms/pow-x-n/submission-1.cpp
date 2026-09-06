class Solution {
private:
    double helper(double x, long long n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        double res = helper(x * x, n / 2);

        if (n % 2 != 0) {
            return x * res;
        } else {
            return res;
        }
    }
public:
    double myPow(double x, int n) {        
        long long power = n;
        if (power < 0) {
            power = -power;
        }

        double res = helper(x, power);

        if (n >= 0) {
            return res;
        } else {
            return 1 / res;
        }
    }
}; 