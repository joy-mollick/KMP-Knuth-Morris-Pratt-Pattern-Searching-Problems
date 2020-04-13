/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/

/// Time -  0.283s
/// Same problem in spoj , with peinting the palindrome see explanation and logic of code 

#include <bits/stdc++.h>

using namespace std;

int ans;

const int mx= 1000001;
string pat;
int lps[2*mx];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// KMP pattern Matching O (n+m) time complexity ,where n and m is the length of text and pattern length
/// Here ,we use the logic of longest suffix which is also prefix


/// Fills lps[] for given patttern pat[0..M-1]
/// A two pointer approach
void computeLPSArray()
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
}

int main()
{
    ///ios::sync_with_stdio(false);
    int caso=1;
    int n;
    int tc;
    cin>>tc;
    string rev_pat;
    while(tc--)
    {
    cin>>pat;
    n=pat.length();
    rev_pat=pat;
    reverse(rev_pat.begin(),rev_pat.end());
    pat=rev_pat+"$"+pat;
    int tot=pat.length();
    computeLPSArray();
    int longest_match=lps[tot-1];
    int should_be_add=n-longest_match;
    printf("Case %d: %d\n",caso,n+should_be_add);
    caso++;
    }
    return 0;
}
