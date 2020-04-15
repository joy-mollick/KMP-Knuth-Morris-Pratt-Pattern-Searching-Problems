#include <bits/stdc++.h>

using namespace std;

/// Very Nice Problem ,You have cut off all the consecutive substring which matches for previous end substring
/// Time - 0.000s

const int mx=101;
string pat;
string txt;
int mx_match_lngth;
int lps[mx];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// KMP pattern Matching O (n+m) time complexity ,where n and m is the length of text and pattern length
/// Here ,we use the logic of longest suffix which is also prefix


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
/// Prints occurrences of pattern in given text
void KMPSearch()
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
            mx_match_lngth=P;///Full length matches of current string
            return;
            p = lps[p - 1]; /// when p equals to its pattern's length then take lps from last character from pattern p-1
        }

        if(t==T)
        {
            mx_match_lngth=p;/// How much characters from start have been matched with the last 
            return;
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
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,n,m,len;
    cin>>tc;
    while(tc--)
    {
     cin>>n>>m;
     txt="";
     int ans=0;
     while(m--)
     {
         mx_match_lngth=0;
         cin>>pat;
         len=pat.length();
         KMPSearch();
         ans=ans+(len-mx_match_lngth);
         txt=pat;
     }
     cout<<ans<<endl;
    }
    return 0;
}
