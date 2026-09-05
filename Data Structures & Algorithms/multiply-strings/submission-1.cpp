class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") 
            return "0";

        vector<int> res(num1.length() + num2.length(), 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i1 = 0; i1 < num1.length(); i1++) {
            for (int i2 = 0; i2 < num2.length(); i2++) {
                int digit = (num1[i1] - '0') * (num2[i2] - '0');

                res[i1 + i2] += digit;
            }
        }

        for (int i = 0; i < res.size() - 1; i++) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }

        while (res.back() == 0)
            res.pop_back();

        string res_string;

        for (int i = res.size() - 1; i >= 0; i--)
            res_string += char(res[i] + '0');

        return res_string;
    }
};