/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/

/// Think about lps array that , its last element can only cross half of length only ,if the string can be constructed by same substring 
/// Then take the substring length , check it ca divide whole string or not that's it 

/// Time - 0.01s

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

int main()
{
    ///ios::sync_with_stdio(false);
    int tc;
    while(scanf("%s",pat)&&pat[0]!='*')
    {
    computeLPSArray();
    int n=strlen(pat);
    int length_of_substr=n-lps[n-1];
    if(n%(length_of_substr)==0) printf("%d\n",n/(length_of_substr));
    else printf("1\n");
    }
    return 0;
}
