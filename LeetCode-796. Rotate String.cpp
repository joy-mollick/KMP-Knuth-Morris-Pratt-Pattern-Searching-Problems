
/// Very Easy , Rotate string should be found 
/// Time-0.000s

class Solution {
public:
    
string txt;
string pat;
int lps[201];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index
    


/// Fills lps[] for given patttern pat[0..M-1]
/// A two pointer approach
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
    
bool KMPSearch()
{
    int P = (pat).length(); /// pattern's length
    int T = (txt).length(); /// test's length

    computeLPSArray();

    int t = 0; // index for txt[]
    int p = 0; // index for pat[]
    while (t < T) {
        if (pat[p] == txt[t]) {
            p++;
            t++;
        }

        if (p == P) {
           return true;
            p = lps[p - 1]; /// when p equals to its pattern's length then take lps from last character from pattern p-1
        }

        /// mismatch after p characters matches from both pattern and text
        else if (t < T && pat[p] != txt[t]) {
            /// so , take lps from last character (j-1) till which all characters matches with pattern
            if (p != 0)
                p = lps[p - 1];
            else /// when j is equal 0 then only traversing our txt traverser
                t = t + 1;
        }
    }
    return false;
}

    bool rotateString(string A, string B) {
        txt=A+A;
        pat=B;
        int n=A.length();
        int m=B.length();
        if(n!=m) return false;
        if(A==B) return true;
        return KMPSearch();
    }
};
