/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/

/// Time - 0.342s
/// Very Good Question 

#include <bits/stdc++.h>

using namespace std;

const int mx= 1000001;
string pat;
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


int main()
{
    ///ios::sync_with_stdio(false);
    int caso=1;
    int n;
    string base;
    cin>>pat;
    n=pat.length();
    computeLPSArray();
    int ans=0;
    /// for the example like substring is in the beginning not overlapping middle
    int start_pos;
    for(int i=0;i<n-1;i++)
    {
        if(lps[i]==lps[n-1])/// That means it is found also in the middle because lps hold long suffix till i which is also a suffix of the string
        {
            ans=max(ans,lps[i]);
        }
    }
    /// Second possible whole suffix can be also prefix ,there is no other string into that string like abcabcabc where lps[n-1] will be 6 which will be not found for any lps[i] in the middle 
    if(ans==0)
    {
            int pos=lps[lps[n-1]-1];
            if(pos==0) ans=0;
            else
            {
                start_pos=lps[n-1];
                ans=pos;
            }

    }
    if(ans)
    {
        start_pos=n-ans;
        int length=ans;
        cout<<(pat.substr(start_pos,length))<<endl;
    }
    else
    {
        cout<<"Just a legend"<<endl;
    }
    return 0;
}
