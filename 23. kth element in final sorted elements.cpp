/*Kth position in sorted array*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,temp;
    cout<<"Enter the size of the first array: ";
    cin>>m;
    vector<int> arr1(m);
    cout<<"Enter the elements of the first array: ";
    for(int i =0;i<m;i++)
        cin>>arr1[i];
    cout<<"Enter the size of the second array: ";
    cin>>n;
    vector<int> arr2(n);
    cout<<"Enter the elements of the second array: ";
    for(int i=0;i<n;i++)
        cin>>arr2[i];
    int k;
    cout<<"Enter the kth value: ";
    cin>>k;
    vector<int> crr(n+m);
    merge(arr1.begin(),arr1.end(),arr2.begin(),arr2.end(),crr.begin());
    sort(crr.begin(),crr.end());
    cout<<crr[k-1]<<endl;
    return 0;
}
