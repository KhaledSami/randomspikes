class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        for (const auto& c : s) {
            freq[c - 'a']++;
        }
        for (const auto& c : t) {
            freq[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                return ((char) i + 'a');
            }
        }
        return '$';
    }
    
};
