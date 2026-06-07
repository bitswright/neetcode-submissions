class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256] = {0};
        for(char ch: t) {
            freq[ch]++;
        }
        int l = 0, r = 0;
        int count = 0;
        int sLen = s.length(), tLen = t.length();
        int minStart = -1, minLen = INT_MAX;
        while(r < sLen) {
            freq[s[r]]--;
            if(freq[s[r]] >= 0) {
                count++;
            }
            while(count == tLen) {
                if(r-l+1 < minLen) {
                    minStart = l;
                    minLen = r-l+1;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        return minStart == -1 ? "" : s.substr(minStart, minLen);
    }
};
