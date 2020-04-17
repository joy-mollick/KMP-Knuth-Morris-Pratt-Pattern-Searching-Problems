///Time-0.056s

class Solution {
public:
    
    int lps[1000001];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// Fills lps[] for given patttern pat[0..M-1]
/// A two pointer approach
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

    string longestPrefix(string s) {
        computeLPSArray(s);
        int n=s.length();
        int match=lps[n-1];
        string ans=s.substr(0,match);
        return ans;
    }
};
