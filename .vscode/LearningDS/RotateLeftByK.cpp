// #include <bits/stdc++.h>
// using namespace std;
// void byk(int arr[],int temp[],int k,int n)
// {
//     k=k%n;
//     for(int i=0;i<k;i++)
//     {
//         temp[i]=arr[i];
//     }
//     for(int i=0;i<n-k;i++)
//     {
//          arr[i]=arr[k+i];
//     }
//     for(int i=0;i<k;i++)
//     {
//         arr[n-k+i]=temp[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int k;
//     cin>>k;
//     int temp[100];
//     byk(arr,temp,k,n);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
int n;
void reverses(int arr[],int x,int y)
{
    int temp;
    while(x<y)
    {
        temp=arr[x];
        arr[x]=arr[y];
        arr[y]=temp;
        x++;
        y--;
    }
    return;

}
int main()
{
    
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    reverses(arr,0,k-1);
    reverses(arr,k,n-1);
    reverses(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;


}