class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if(len1 > len2) return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for(int i = 0; i < len1; ++i) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        
        if(cnt1 == cnt2) return true;
        for(int i = len1; i < len2; ++i) {
            cnt2[s2[i-len1] - 'a']--;
            cnt2[s2[i] - 'a']++;
            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};