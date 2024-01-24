/*A Program that implements binary search using iteration*/
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr,int low,int high,int target)
{
    while(low<=high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            high = mid-1;
        else
            low = mid+1;
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
    if(index < 0 || index >= n)
        cout<<"Element "<<target<<" not found "<<endl;
    else
        cout<<"Element "<<target<<" found at index: "<<index<<endl;
}
