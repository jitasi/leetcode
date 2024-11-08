class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {""};
        if (n == 1)
            return {"()"};

        vector<string> ret;
        for (int i = 0; i < (n + 1) / 2; i++) {
            const vector<string>& sub_1 = generateParenthesis(i);
            const vector<string>& sub_2 = generateParenthesis(n - i - 1);
            for (int j = 0; j < sub_1.size(); j++) {
                for (int k = 0; k < sub_2.size(); k++) {
                    ret.push_back("(" + sub_1[j] + ")" + sub_2[k]);
                    if (i != n - i - 1) {
                        ret.push_back("(" + sub_2[k] + ")" + sub_1[j]);
                    }
                }
            }
        }
        return ret;
    }
};