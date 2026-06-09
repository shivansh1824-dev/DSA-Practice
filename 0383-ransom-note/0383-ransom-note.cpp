class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        for(char ch : magazine) {
            freq[ch - 'a']++;
        }

        for(char ch : ransomNote) {
            freq[ch - 'a']--;

            if(freq[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};