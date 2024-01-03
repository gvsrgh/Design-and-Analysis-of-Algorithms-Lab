/*A Program that implements binary search using recurssion*/
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr,int low,int high,int target)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==target)
            return mid;
        else if(target<arr[mid])
            return binarySearch(arr,low,mid-1,target);
        else
            return binarySearch(arr,mid+1,high,target);
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element to be searched: ";
    cin>>target;
    int index=-1;
    index = binarySearch(arr,0,n-1,target);
    if(index == -1)
        cout<<"Element "<<target<<" not found "<<endl;
    else
        cout<<"Element "<<target<<" found at index: "<<index<<endl;
}
