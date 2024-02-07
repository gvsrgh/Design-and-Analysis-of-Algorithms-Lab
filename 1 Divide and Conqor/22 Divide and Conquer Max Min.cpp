/************************************
*A program that finds out the maximum
*and the minimum elements in the
*given array using Divide and conqor
*Method.
************************************/
#include<iostream>
using namespace std;

void divideAndConquerMaxMin(int arr[], int i, int j, int &maxi, int &mini) {
    int mid, maxi1, mini1;
    if (i == j)
        maxi = arr[i], mini = arr[i];
    else if (i == (j - 1))
        if (arr[i] < arr[j])
            maxi = arr[j], mini = arr[i];
        else
            maxi = arr[i], mini = arr[j];
    else {
        mid = (i + j) / 2;
        divideAndConquerMaxMin(arr, i, mid, maxi, mini);
        divideAndConquerMaxMin(arr, mid + 1, j, maxi1, mini1);
        if (maxi1 > maxi)
            maxi = maxi1;
        if (mini1 < mini)
            mini = mini1;
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
    divideAndConquerMaxMin(arr, 0, n - 1, maxi, mini);
    cout<<"The maximum element in the array is "<<maxi<<endl;
    cout<<"The minimum element in the array is "<<mini<<endl;
    return 0;
}
