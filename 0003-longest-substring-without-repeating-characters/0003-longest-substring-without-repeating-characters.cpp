class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        int l = 0;

        vector<int> freq(128, 0);

        for (int r = 0; r < n; r++) {

            freq[s[r]]++;

            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};