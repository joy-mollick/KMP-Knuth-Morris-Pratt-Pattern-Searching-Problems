#include <bits/stdc++.h>

using namespace std;

/// Super Classical Problem 
/// Very Very Nice Problem ,You have cut off all the consecutive substring which matches for previous end substring and take care if a substring already contains in another substring 
/// Time - 0.170s

const int mx=300001;
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
bool KMPSearch()
{
    int P = (pat).length(); /// pattern's length
    int T = (txt).length(); /// test's length

    int t = 0; // index for txt[]
    int p = 0; // index for pat[]
    while (t < T) {
        if (pat[p] == txt[t]) {
            p++;
            t++;
        }

        if (p == P) {
            return true;
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
    return false;
}
// ab + bc +cd
int solve(string s1,string s2,string s3)
{
    /// s1 + s2 + s3
    /// first think some possibilities that s1 contains whole s1 or s2
    /// s1 contains whole s2 , but some s3
    /// s1 contains whole s3 , but some s2
    /// s1 contains whole s2 and s3
    /// s1 contains some s2 and some s3
    /// Here ,we will cover all possibilities
   int mx_match_between_s1_s2=0;
   int k;
   string s1_s2=s1;
   txt=s1;
   pat=s2;
   computeLPSArray();
   if(KMPSearch())/// s1 contains whole s2
   {
       mx_match_between_s1_s2=s2.length();/// because whole s2 match in s1
   }
   else
   {
       /// It is for checking how many longest suffix of s1 which is prefix of s2 so that we can concatenate s1+s2 with minimum length
       pat=s2+s1;
       computeLPSArray();
       k=pat.length();/// It will help us to find that kind of longest suffix of s1
       mx_match_between_s1_s2=lps[k-1];
       while(mx_match_between_s1_s2>(s1.length()))
       {
           k=lps[k-1];
           mx_match_between_s1_s2=k;
       }
   }
   if(mx_match_between_s1_s2==0) s1_s2+=s2;/// when there is no match with s2 , so take whole string
   else
   {
       for(int j=mx_match_between_s1_s2;j<s2.length();j++) {s1_s2+=s2[j];}/// take the rest characters of s2 which are not matched with suffix of s1
   }

   /// So , now half done of the task has been done so now we have to deal with taking s3

   string s1_s2_s3=s1_s2;
   int mx_match_between_s1_s2_s3=0;///It will hold max matching between s3 and our previous preprocessed string s1_s2
   txt=s1_s2;
   pat=s3;
   computeLPSArray();
   if(KMPSearch())
   {
       mx_match_between_s1_s2_s3=s3.length();
   }
   else
   {
       pat=s3+s1_s2;
       computeLPSArray();
       k=pat.length();
       mx_match_between_s1_s2_s3=lps[k-1];
       while(mx_match_between_s1_s2_s3>(s1_s2.length()))
       {
           k=lps[k-1];
           mx_match_between_s1_s2_s3=k;
       }
   }
   if(mx_match_between_s1_s2_s3==0) s1_s2_s3+=s3;
   else
   {
       for(int j=mx_match_between_s1_s2_s3;j<s3.length();j++) s1_s2_s3+=s3[j];
   }
   int tot_length=s1.length()+s2.length()+s3.length();
   int res_strng_length=s1_s2_s3.length();
   ///cout<<s1_s2_s3<<endl;, this is our resultant string 
   return (res_strng_length);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,n,m,len;
    string s1,s2,s3;
    while(cin>>s1>>s2>>s3)
    {
        /// s1,s2,s3
         int ans=solve(s1,s2,s3);
        /// s2,s1,s3
          ans=min(ans,solve(s2,s1,s3));
        /// s2,s3,s1
          ans=min(ans,solve(s2,s3,s1));
        /// s1,s3,s2
          ans=min(ans,solve(s1,s3,s2));
        /// s3,s1,s2
          ans=min(ans,solve(s3,s1,s2));
        /// s3,s2,s1
          ans=min(ans,solve(s3,s2,s1));

          cout<<ans<<endl;
    }
    return 0;
}
