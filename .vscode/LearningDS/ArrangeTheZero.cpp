#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int k=0;k<n;k++)
    cin>>arr[k];
    int j=0;
    int i=0;
    while(n>j)
    {
        i++;
        if(arr[j]==0)
        swap(arr[i],arr[j]);
        else
        j++;
    }
    return 0;
    
} 