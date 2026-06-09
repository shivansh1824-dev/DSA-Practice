class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.size() > s.size()) {
            return ans;
        }

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char ch : p) {
            pFreq[ch - 'a']++;
        }

        int k = p.size();

        for (int i = 0; i < k; i++) {
            windowFreq[s[i] - 'a']++;
        }

        if (windowFreq == pFreq) {
            ans.push_back(0);
        }

        for (int i = k; i < s.size(); i++) {

            windowFreq[s[i] - 'a']++;

            windowFreq[s[i - k] - 'a']--;

            if (windowFreq == pFreq) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};