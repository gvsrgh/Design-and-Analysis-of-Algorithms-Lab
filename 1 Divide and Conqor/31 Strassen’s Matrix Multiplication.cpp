/* A program to perform Strasens matrix multiplication*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    }
    else {
        int k = n / 2;
        vector<vector<int>> A11(k, vector<int>(k));
        vector<vector<int>> A12(k, vector<int>(k));
        vector<vector<int>> A21(k, vector<int>(k));
        vector<vector<int>> A22(k, vector<int>(k));
        vector<vector<int>> B11(k, vector<int>(k));
        vector<vector<int>> B12(k, vector<int>(k));
        vector<vector<int>> B21(k, vector<int>(k));
        vector<vector<int>> B22(k, vector<int>(k));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + k];
                A21[i][j] = A[i + k][j];
                A22[i][j] = A[i + k][j + k];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + k];
                B21[i][j] = B[i + k][j];
                B22[i][j] = B[i + k][j + k];
            }
        }

        vector<vector<int>> P1 = multiply(A11, subtract(B12, B22));
        vector<vector<int>> P2 = multiply(add(A11, A12), B22);
        vector<vector<int>> P3 = multiply(add(A21, A22), B11);
        vector<vector<int>> P4 = multiply(A22, subtract(B21, B11));
        vector<vector<int>> P5 = multiply(add(A11, A22), add(B11, B22));
        vector<vector<int>> P6 = multiply(subtract(A12, A22), add(B21, B22));
        vector<vector<int>> P7 = multiply(subtract(A11, A21), add(B11, B12));

        vector<vector<int>> C11 = add(subtract(add(P5, P4), P2), P6);
        vector<vector<int>> C12 = add(P1, P2);
        vector<vector<int>> C21 = add(P3, P4);
        vector<vector<int>> C22 = subtract(subtract(add(P5, P1), P3), P7);

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                C[i][j] = C11[i][j];
                C[i][j + k] = C12[i][j];
                C[i + k][j] = C21[i][j];
                C[i + k][j + k] = C22[i][j];
            }
        }
    }
    return C;
}

void print(vector<vector<int>> A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {

    int n;
    cout << "Enter the size of a matrix: ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    cout << "Enter " << n << " x " << n << " matrix elements for A: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter " << n << " x " << n << " matrix elements for B: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = multiply(A, B);
    cout << "Result matrix C: " << endl;
    print(C);
    return 0;
}
