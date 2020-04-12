/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/
#include <bits/stdc++.h>

using namespace std;

char txt[1000001];
char pat[1000001];
int lps[1000001];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

vector<int>v;
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
            v.push_back(t-p);
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
    int tc;
    scanf("%d",&tc);
    while(tc--){
    scanf("%s",txt);
    scanf("%s",pat);
    v.clear();
    KMPSearch();
    int tot=v.size();
    if(tot!=0)
    printf("%d\n",tot);
    else if(tot==0)
    printf("Not Found");

    if(tot!=0)
    {
        printf("%d",v[0]+1);
        for(int i=1;i<tot;++i) {printf(" %d",v[i]+1);}
    }

    printf("\n");
    }
    return 0;
}
