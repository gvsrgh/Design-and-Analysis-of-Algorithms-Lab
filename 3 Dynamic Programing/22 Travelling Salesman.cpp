#include<iostream>
#include<vector>
#include<functional> // for std::function
#include<limits>
using namespace std;

#define MAX 9999

int TSP(int n, vector<vector<int>>& distan) {
    int completed_visit = (1 << n) - 1;
    vector<vector<int>> DP(1 << n, vector<int>(n, -1));
   
    if(n == 0)
        return 0;

    function<int(int, int)> dfs = [&](int mark, int position) {
        if(mark == completed_visit)
            return distan[position][0];
       
        if(DP[mark][position] != -1)
            return DP[mark][position];

        int answer = numeric_limits<int>::max();
        for(int city = 0; city < n; city++) {
            if((mark & (1 << city)) == 0) {
                int newAnswer = distan[position][city] + dfs(mark | (1 << city), city);
                answer = min(answer, newAnswer);
            }
        }
        return DP[mark][position] = answer;
    };

    return dfs(1, 0);
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
   
    vector<vector<int>> distan(n, vector<int>(n, 0));
   
    cout << "Choose input mode:\n";
    cout << "1. Row-wise\n";
    cout << "2. Column-wise\n";
    int mode;
    cin >> mode;

    if(mode == 1) {
        cout << "Enter the distance matrix row-wise:\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> distan[i][j];
            }
        }
    } else if(mode == 2) {
        cout << "Enter the distance matrix column-wise:\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> distan[j][i];
            }
        }
    } else {
        cout << "Invalid mode selected. Exiting...\n";
        return 1;
    }
   
    cout << "Minimum Distance Travelled -> " << TSP(n, distan) << endl;
    return 0;
}
