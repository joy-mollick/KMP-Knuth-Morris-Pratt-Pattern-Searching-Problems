/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/

/// Very Classical Problem 
/// Time - 0.61348s

#include <bits/stdc++.h>

using namespace std;

///const int mx= 1000020;
string pat;
///char txt[mx];
///char pat[mx];
///int lps[mx];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// KMP pattern Matching O (n+m) time complexity ,where n and m is the length of text and pattern length
/// Here ,we use the logic of longest suffix which is also prefix


/// Fills lps[] for given patttern pat[0..M-1]
/// A two pointer approach
int computeLPSArray()
{
    /// traverser of prefix ,left
    int left = 0;
    int P=(pat).size();
    int lps[P];
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
    return lps[P-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int len;
    int n;
    string base;
    int tc;
    cin>>tc;
    while(tc--){
    cin>>pat;
    int n=pat.length();
    int least_substrng=n-computeLPSArray();
    if(n%(least_substrng)==0) cout<<least_substrng<<endl;
    else cout<<n<<endl;
    }
    return 0;
}
