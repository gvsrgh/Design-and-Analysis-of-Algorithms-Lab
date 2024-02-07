/************************************
*A program that finds out the maximum
*and the minimum elements in the
*given array using Brute Force
*Method.
************************************/
#include<iostream>
using namespace std;

void bruteForceMaxMin(int arr[],int n,int &maxi,int &mini)
{
    for(int i = 1;i<n;i++)
    {
        if(arr[i]>maxi)
            maxi = arr[i];
        if(arr[i]<mini)
            mini = arr[i];
    }
}

int main()
{
    int n,maxi,mini;
    cout<<"Enter the Size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array Elements: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    maxi = arr[0];
    mini = arr[0];
    bruteForceMaxMin(arr,n,maxi,mini);
    cout<<"The maximum element in the array is "<<maxi<<endl;
    cout<<"The minimum element in the array is "<<mini<<endl;
    return 0;
}
