/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/

/// Time - 0.109s

#include <bits/stdc++.h>

using namespace std;

const int mx= 250001;
string pat;
string txt;
bool found;
int ans;
vector<int>v;
int lps[mx];
/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

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
   /// return lps;
}

void KMPSearch()
{
    int P = (pat).length(); /// pattern's length
    int T = (txt).length(); /// test's length

    computeLPSArray(); /// It is the heart of kmp search , longest prefix array which is also suffix till ith index


    int t = 0; // index for txt[]
    int p = 0; // index for pat[]
    while (t < T) {
        if (pat[p] == txt[t]) {
            p++;
            t++;
        }

        if (p == P) {
             v.push_back(t - p);
             found=true; /// pattern started from t - p index, because p give u total matches - so t-p give u starting matching point
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
    int tc;
    cin>>tc;
    cin>>pat;
    cin>>txt;
    found=false;
    txt=txt+txt;
    KMPSearch();
    if(found) cout<<(v[0])<<endl;/// found
    else cout<<"-1"<<endl;/// not found

    return 0;
}
