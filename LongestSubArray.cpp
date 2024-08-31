#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k,n;
    cin>>k>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int maxlen=0;
    map<long long,int>presummap;
    long long presum=0;
    for(int i=0;i<n;i++)
    {
       presum=presum+arr[i];
       if(presum==k)
       {
          maxlen=max(maxlen,i+1);
       }
       long long rem=presum-k;
       if(presummap.find(rem)!=presummap.end())
       {int len=i-presummap[rem];
       maxlen=max(maxlen,len);
       }    
       if(presummap.find(presum)==presummap.end())
       presummap[presum]=i;

    }
cout<<maxlen;
    
    
    return 0;
}