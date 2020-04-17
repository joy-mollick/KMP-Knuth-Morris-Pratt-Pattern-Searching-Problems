class Solution {
public:
    
    int lps[10001];
    void computeLPSArray(string pat)
{
    /// traverser of prefix ,left
    int left = 0;
    int P=(pat).length();
    lps[0] = 0; /// lps[0] is always 0

    int right = 1;
    while (right < P) {
        if (pat[right] == pat[left]) {
            left++;
            lps[right] = left;/// take longest suffix length which is also prefix
            right++;
        }
        else /// (pat[right] != pat[left])
        {
            if (left != 0) {
                left = lps[left - 1];
            }
            else /// if (len == 0) ,then start from again start ,because there is no common suffix and prefix till right index
            {
                lps[right] = 0;
                right++;
            }
        }
    }
}
    bool repeatedSubstringPattern(string s) {
        
        computeLPSArray(s);
        int n=s.length();
        int sbstrng_lngth=n-lps[n-1];
        ///cout<<sbstrng_lngth<<endl;
        if(n%(sbstrng_lngth)==0&&(n!=sbstrng_lngth)) return true;
        else return false;
    }
};
