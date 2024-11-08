class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ch_idx(255, -1);

        int longest_len = 0;
        int cur_len = 0;
        for (int i = 0; i < s.length(); i++) {
            const int ch = s[i];
            if (ch_idx[ch] == -1 || (ch_idx[ch] < i - cur_len)) {
                cur_len++;
            } else {
                if (cur_len > longest_len)
                    longest_len = cur_len;
                cur_len = i - ch_idx[ch];
            }
            ch_idx[ch] = i;
        }

        if (cur_len > longest_len)
            longest_len = cur_len;
        return longest_len;
    }
};