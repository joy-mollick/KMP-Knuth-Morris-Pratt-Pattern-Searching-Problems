#include <bits/stdc++.h>

using namespace std;

/// Interesting problem 
///Time - 0.000s
/// Just Read the problem and extract the real string which occurs ,then normal printing till 8th charcter 

const int mx=2001;
string pat;
string txt;
int mx_match_lngth;
int lps[mx];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// KMP pattern Matching O (n+m) time complexity ,where n and m is the length of text and pattern length
/// Here ,we use the logic of longest suffix which is also prefix



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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,n,m,len;
    cin>>tc;
    while(tc--)
    {
       cin>>pat;
       computeLPSArray();
       int n=pat.length();
       int exact_length_of_period;
       int extra_step_length;
       for(int i=n-1;i>=0;i--)
       {
           if(lps[i] && ((i+1)%lps[i]==0)&&((i+1)/lps[i]==2))
           {
               exact_length_of_period=lps[i];
               extra_step_length=n-i-1;
               break;
           }
       }
       int cont=0;
       int start=(extra_step_length);
       string ashol=pat.substr(start,exact_length_of_period);///This is our real string which will periodically occur
       for(int i=0;cont<8;i++,cont++)
       {
           cout<<ashol[i%exact_length_of_period];
       }
       cout<<"...";
       cout<<endl;
    }
    return 0;
}
