#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; 

   int arr[n]; 
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = arr[0]; 
    int secondlarg=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            secondlarg=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondlarg && arr[i]<largest)
        secondlarg=arr[i];
    }

    

    
    cout << "The largest number is: " << largest << endl;
    cout << "The 2nd largest number is: " << secondlarg << endl;

    return 0;
}