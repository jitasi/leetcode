class Solution {
public:
    string multiply(string num1, string num2) {
        const int num1_len = num1.length();
        const int num2_len = num2.length();
        vector<int> num1_vec(num1_len);
        for (int i = 0; i < num1_len; i++)
            num1_vec[num1_len - i - 1] = num1[i] - '0';

        vector<int> ret_vec(num1_len + num2_len, 0);
        for (int i = 0; i < num2_len; i++) {
            const int cur_digit_place = num2_len - i - 1;
            const int cur_digit = num2[i] - '0';
            for (int j = 0; j < num1_len; j++) {
                ret_vec[cur_digit_place + j] += cur_digit * num1_vec[j];
            }
        }
        int carry = 0;
        for (int i = 0; i < num1_len + num2_len; i++) {
            carry += ret_vec[i];
            ret_vec[i] = carry % 10;
            carry = carry / 10;
        }

        string ret;
        bool leading_zeros = true;
        for (int i = num1_len + num2_len - 1; i >= 0; i--) {
            if (ret_vec[i] == 0 && leading_zeros)
                continue;
            if (ret_vec[i] != 0 && leading_zeros)
                leading_zeros = false;
            ret += '0' + ret_vec[i];
        }

        if (ret.empty())
            ret = "0";
        return ret;
    }
};