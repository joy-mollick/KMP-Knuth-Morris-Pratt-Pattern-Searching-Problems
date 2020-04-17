/// Very Classical like as extend to palindrome ,spoj problem 
/// Time - 0.060s


class Solution {
public:
    int lps[2000001];
    string pat;
    void computeLPSArray()
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

    string shortestPalindrome(string s) {
        if(s.size()==0) return "";
        int n=s.size()+s.size()+1;
        string rev=s;
        reverse(rev.begin(),rev.end());
        pat=s+"$"+rev;
        computeLPSArray();
        cout<<n<<endl;
        int mx_match=lps[n-1];
        string first_part="";
        ///cout<<mx_match<<endl;
        for(int i=mx_match;i<(s.size());i++) {first_part+=s[i];}
        reverse(first_part.begin(),first_part.end());
        ///cout<<first_part<<endl;
        string ans=first_part+s;
        return ans;
    }
};
