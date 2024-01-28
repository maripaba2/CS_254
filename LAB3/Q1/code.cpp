#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix_addition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<int>> matrix_subtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<int>> standard_matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = A[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

vector<vector<int>> strassen_matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        vector<vector<int>> result(1, vector<int>(1, 0));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    int mid = n / 2;

    vector<vector<int>> A11(mid, vector<int>(mid, 0));
    vector<vector<int>> A12(mid, vector<int>(mid, 0));
    vector<vector<int>> A21(mid, vector<int>(mid, 0));
    vector<vector<int>> A22(mid, vector<int>(mid, 0));

    vector<vector<int>> B11(mid, vector<int>(mid, 0));
    vector<vector<int>> B12(mid, vector<int>(mid, 0));
    vector<vector<int>> B21(mid, vector<int>(mid, 0));
    vector<vector<int>> B22(mid, vector<int>(mid, 0));

    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    vector<vector<int>> P1 = strassen_matrix_multiply(A11, matrix_subtraction(B12, B22));
    vector<vector<int>> P2 = strassen_matrix_multiply(matrix_addition(A11, A12), B22);
    vector<vector<int>> P3 = strassen_matrix_multiply(matrix_addition(A21, A22), B11);
    vector<vector<int>> P4 = strassen_matrix_multiply(A22, matrix_subtraction(B21, B11));
    vector<vector<int>> P5 = strassen_matrix_multiply(matrix_addition(A11, A22), matrix_addition(B11, B22));
    vector<vector<int>> P6 = strassen_matrix_multiply(matrix_subtraction(A12, A22), matrix_addition(B21, B22));
    vector<vector<int>> P7 = strassen_matrix_multiply(matrix_subtraction(A11, A21), matrix_addition(B11, B12));

    vector<vector<int>> C11 = matrix_subtraction(matrix_addition(matrix_addition(P5, P4), P6), P2);
    vector<vector<int>> C12 = matrix_addition(P1, P2);
    vector<vector<int>> C21 = matrix_addition(P3, P4);
    vector<vector<int>> C22 = matrix_subtraction(matrix_addition(matrix_addition(P5, P1), P3), P7);

    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + mid] = C12[i][j];
            result[i + mid][j] = C21[i][j];
            result[i + mid][j + mid] = C22[i][j];
        }
    }

    return result;
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices
    vector<vector<int>> matrixA = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> matrixB = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    vector<vector<int>> ans=strassen_matrix_multiply(matrixA,matrixB);
    // Time Complexity O(n^2.81)
    print_matrix(ans);
}