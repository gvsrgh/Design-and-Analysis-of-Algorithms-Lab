#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(vector<Job>& arr) {
    sort(arr.begin(), arr.end(), comparison);

    int n = arr.size();
    vector<int> result(n);
    vector<bool> slot(n);

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "The maximum profit sequence of jobs is: ";
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    vector<Job> arr(n);
    cout << "Enter the job id, deadline, and profit for each job: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    printJobScheduling(arr);
    return 0;
}
