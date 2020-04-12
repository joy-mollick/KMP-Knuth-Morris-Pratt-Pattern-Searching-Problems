/*
See Tushar Roy's Two Tutorial Videos of  KMP Pattern Search explanation
Use implementation from geeksforgeeks for KMP Pattern Search .
*/

/// Time 0.03s

/// It's nothing but construction of lps array 

#include <bits/stdc++.h>

using namespace std;

char pat[1000001];
int lps[1000001];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

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
    scanf("%d",&tc);
    int caso=1;
    int n;
    while(tc--)
    {
    scanf("%d",&n);
    scanf("%s",pat);
    computeLPSArray();
    printf("Test case #%d\n",caso);
    for(int i=1;i<n;i++){
    int prefix_length=i+1;
    int length_of_substr=prefix_length-lps[i];
    if(prefix_length%(length_of_substr)==0 && prefix_length!=length_of_substr ) printf("%d %d\n",prefix_length,prefix_length/(length_of_substr));///when prefix_length==length_of_substr then k will be 1 , so ignore it 
    }
    printf("\n");
    caso++;
    }
    return 0;
}
