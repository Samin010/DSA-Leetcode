class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int diff = 0;
        int s = 0, e = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff == 1)
                    s = i;
                if (diff == 2)
                    e = i;
            }
        }
        swap(s1[s], s1[e]);
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
};