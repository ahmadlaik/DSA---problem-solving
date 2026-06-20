class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        // Left -> Right pass
        for (int i = 1; i < restrictions.size(); i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                    (restrictions[i][0] - restrictions[i - 1][0])
            );
        }

        // Right -> Left pass
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                    (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

        long long ans = 0;

        // Maximum peak between adjacent restrictions
        for (int i = 1; i < restrictions.size(); i++) {
            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long dist = x2 - x1;

            ans = max(ans, (h1 + h2 + dist) / 2);
        }

        // Buildings after the last restriction
        long long lastPos = restrictions.back()[0];
        long long lastHeight = restrictions.back()[1];

        ans = max(ans, lastHeight + (n - lastPos));

        return (int)ans;
    }
};