class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        int halfLen = (len + 1) / 2;

        string lh1 = n.substr(0, halfLen);
        string lh2 = to_string(stoll(lh1) + 1);
        string lh3 = to_string(stoll(lh1) - 1);

        auto makePalindrome = [&](string left) {
            string right = left;
            reverse(right.begin(), right.end());

            if (len & 1)
                right = right.substr(1);

            return stoll(left + right);
        };

        vector<long long> candidates;

        candidates.push_back(makePalindrome(lh1));

        if (!lh2.empty())
            candidates.push_back(makePalindrome(lh2));

        if (!lh3.empty() && lh3 != "-1")
            candidates.push_back(makePalindrome(lh3));

        long long p10 = 1;
        for (int i = 0; i < len; i++)
            p10 *= 10;

        candidates.push_back(p10 + 1);           
        candidates.push_back(p10 / 10 - 1);   

        long long ans = -1;
        long long bestDiff = LLONG_MAX;

        for (long long x : candidates) {
            if (x == num)
                continue;

            long long curDiff = llabs(num - x);

            if (curDiff < bestDiff ||
                (curDiff == bestDiff && x < ans)) {
                bestDiff = curDiff;
                ans = x;
            }
        }

        return to_string(ans);
    }
};