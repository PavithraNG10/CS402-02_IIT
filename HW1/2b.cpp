#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to multiply two matrices of integers using row-major order
vector<vector<int>> multiplyIntegerMatricesRowMajor(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();    // Number of rows in matrix A
    int n = A[0].size(); // Number of columns in matrix A
    int p = B[0].size(); // Number of columns in matrix B

    vector<vector<int>> result(m, vector<int>(p, 0)); // Initialize the result matrix

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < p; j++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to multiply two matrices of doubles using row-major order
vector<vector<double>> multiplyDoubleMatricesRowMajor(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int m = A.size();    // Number of rows in matrix A
    int n = A[0].size(); // Number of columns in matrix A
    int p = B[0].size(); // Number of columns in matrix B

    vector<vector<double>> result(m, vector<double>(p, 0.0)); // Initialize the result matrix

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < p; j++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    // Define the dimensions of the matrices
    int m = 100; // Number of rows
    int n = 200; // Number of columns for matrices A and B
    int p = 150; // Number of columns for matrix B

    // Generate random matrices with integers between 1 and 10
    vector<vector<int>> matrixA(m, vector<int>(n));
    vector<vector<int>> matrixB(n, vector<int>(p));

    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrixA[i][j] = rand() % 10 + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            matrixB[i][j] = rand() % 10 + 1;
        }
    }

    // Measure the execution time for integer matrices (row-major order)
    clock_t start_time_int_row = clock(); // Start the timer for integer matrices (row-major)
    vector<vector<int>> result_int_row = multiplyIntegerMatricesRowMajor(matrixA, matrixB);
    clock_t end_time_int_row = clock(); // Stop the timer for integer matrices (row-major)
    double elapsed_time_int_row = double(end_time_int_row - start_time_int_row) / CLOCKS_PER_SEC;
    cout << "Integer matrix multiplication (row-major) took " << elapsed_time_int_row << " seconds." << endl;

    // Generate random matrices with double values between 1 and 10
    vector<vector<double>> matrixADouble(m, vector<double>(n));
    vector<vector<double>> matrixBDouble(n, vector<double>(p));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrixADouble[i][j] = (rand() % 1000) / 100.0 + 1.0; // Generate random double values between 1 and 10
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            matrixBDouble[i][j] = (rand() % 1000) / 100.0 + 1.0; // Generate random double values between 1 and 10
        }
    }

    // Measure the execution time for double matrices (row-major order)
    clock_t start_time_double_row = clock(); // Start the timer for double matrices (row-major)
    vector<vector<double>> result_double_row = multiplyDoubleMatricesRowMajor(matrixADouble, matrixBDouble);
    clock_t end_time_double_row = clock(); // Stop the timer for double matrices (row-major)
    double elapsed_time_double_row = double(end_time_double_row - start_time_double_row) / CLOCKS_PER_SEC;
    cout << "Double matrix multiplication (row-major) took " << elapsed_time_double_row << " seconds." << endl;

    return 0;
}
