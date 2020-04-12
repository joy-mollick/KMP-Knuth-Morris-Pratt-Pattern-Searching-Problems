/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/

/// Time - 0.08s 

#include <bits/stdc++.h>

using namespace std;

const int mx= 1000020;
char txt[mx];
char pat[mx];
int lps[mx];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// KMP pattern Matching O (n+m) time complexity ,where n and m is the length of text and pattern length
/// Here ,we use the logic of longest suffix which is also prefix


/// Fills lps[] for given patttern pat[0..M-1]
/// A two pointer approach
void computeLPSArray()
{
    /// traverser of prefix ,left
    int left = 0;
    int P=strlen(pat);
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
    int P = strlen(pat); /// pattern's length
    int T = strlen(txt); /// test's length

    computeLPSArray();

    int t = 0; // index for txt[]
    int p = 0; // index for pat[]
    while (t < T) {
        if (pat[p] == txt[t]) {
            p++;
            t++;
        }

        if (p == P) {
            /// pattern started from t - p index, because p give u total matches - so t-p give u starting matching point
           printf("%d\n",t-p);
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
}

int main()
{
    ///ios::sync_with_stdio(false);
    int caso=1;
    int n;
    while(scanf("%d %s %s",&n,pat,txt)!=EOF)
    {
    KMPSearch();
    printf("\n");
    }
    return 0;
}
