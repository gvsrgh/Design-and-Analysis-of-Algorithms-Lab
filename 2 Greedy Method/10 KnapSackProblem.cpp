/* A program that demonstrates Knapsack Problem*/
#include <iostream>
#include <vector>
using namespace std;

void sortp(vector<int>& p, vector<int>& w) {
    int n = p.size();
    vector<float> pwRatio(n);
    for (int i = 0; i < n; i++) {
        pwRatio[i] = static_cast<float>(p[i]) / w[i];
    }
    bool swapped;
    for (int i = 1; i < n; i++) {
        swapped = false;
        for (int j = 0; j < n - i; j++) {
            if (pwRatio[j] < pwRatio[j + 1]) {
                swap(pwRatio[j], pwRatio[j + 1]);
                swap(p[j], p[j + 1]);
                swap(w[j], w[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}


float greedyKnapSack(int m, int n, vector<int> p, vector<int> w) {
    sortp(p, w);
    vector<float> x(n);
    float res = 0;
    float u = m;
    int i;
    for (i = 0; i < n; i++)
        if (w[i] > u)
            break;
        else {
            x[i] = 1;
            u = u - w[i];
        }
    if (i < n)
        x[i] = u / w[i];
    for (i = 0;i<n; i++)
        res += p[i] * x[i];
    return res;
}


int main()
{
    int n,m;
    cout<<"Enter the number of objects: ";
    cin>>n;
    cout<<"Enter the bag size: ";
    cin>>m;
    vector<int> p(n);
    vector<int> w(n);
    cout<<"Enter the weights: ";
    for(int i = 0;i<n;i++)
        cin>>w[i];
    cout<<"Enter the profits: ";
    for(int i = 0;i<n;i++)
        cin>>p[i];
    float res = greedyKnapSack(m,n,p,w);
    cout<<"The Most Profit we can get is: "<<res<<endl;
    cout<<endl;
    return 0;
}
