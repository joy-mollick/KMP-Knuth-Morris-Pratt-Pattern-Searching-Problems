#include <bits/stdc++.h>

using namespace std;

/// Time -0.000s
/// Nice problem , like extend to palindrome spoj problem 

const int mx= 200002;
string pat;
string rev_pat;
///char txt[mx];
///char pat[mx];
int lps[mx];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// KMP pattern Matching O (n+m) time complexity ,where n and m is the length of text and pattern length
/// Here ,we use the logic of longest suffix which is also prefix


/// Fills lps[] for given patttern pat[0..M-1]
/// A two pointer approach
int computeLPSArray()
{
    /// traverser of prefix ,left
    int left = 0;
    int P=(pat).size();
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
    int caso=1;
    int n;
    string base;
    int tc;
    cin>>tc;
    while(tc--)
    {
    cin>>pat;
    base=pat;
    rev_pat=pat;
    reverse(rev_pat.begin(),rev_pat.end());
    string will_be_add="";
    if(rev_pat==pat)
    {
        int mx_match_wth=computeLPSArray();
        for(int i=mx_match_wth;i<pat.length();i++)
        will_be_add+=pat[i];
    }
    else{
    pat=rev_pat+"$"+pat;/// we will find longest suffix of oroginal string which is also prefix of reverse string so this is our new pattern
    int mx_match_wth_reverse=computeLPSArray();
    will_be_add="";
    for(int i=mx_match_wth_reverse;i<base.length();i++) will_be_add+=rev_pat[i];/// add the characters from reverse string after matching character with original suffix
    }
    cout<<base<<" "<<will_be_add<<endl;
    }
    return 0;
}
