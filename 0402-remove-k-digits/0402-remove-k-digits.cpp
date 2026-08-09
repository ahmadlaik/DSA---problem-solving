class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        string ans = "";

        for (int i = 0; i < n; i++) {
            char ch = num[i];

            while (!st.empty() && ch < st.top() && k > 0) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        // If k is still remaining, remove from the end
        while (k > 0) {
            st.pop();
            k--;
        }

        // Build answer from stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse because stack gives reverse order
        reverse(ans.begin(), ans.end());

        // Remove leading zeroes
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if (ans.empty())
            return "0";

        return ans;
    }
};