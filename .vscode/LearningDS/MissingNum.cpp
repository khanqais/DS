// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int flag=0;
//     int largest=4;
//     int missing=0;
//     for(int i=1;i<=largest;i++)
//     {
//         for(int j=0;j<n-1;j++)
//         {
//             if(arr[j]==i)
//             {
//                 flag=1;
//                 break;
//             }

            
//         }
//         if(flag==0)
//         missing=i;
//     }
//     cout<<missing;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int hash[100]={0};
    for(int i=0;i<n;i++)
    hash[arr[i]]++;
    int lar=arr[0];
    for(int j=1;j<n;j++)
    {
        if(arr[j]>lar)
        lar=arr[j];
    }
    
    cout<<"The missing number is:";
    for(int i=1;i<lar+1;i++)
    {
        if(hash[i]==0)
        cout<<i<<" ";
        
    }


    return 0;
}
