#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip> // For setting precision with double matrices

using namespace std;

// Function to multiply two matrices of integers
vector<vector<int>> multiplyIntegerMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();    // Number of rows in matrix A
    int n = A[0].size(); // Number of columns in matrix A
    int p = B[0].size(); // Number of columns in matrix B

    vector<vector<int>> result(m, vector<int>(p, 0)); // Initialize the result matrix

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to multiply two matrices of doubles
vector<vector<double>> multiplyDoubleMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int m = A.size();    // Number of rows in matrix A
    int n = A[0].size(); // Number of columns in matrix A
    int p = B[0].size(); // Number of columns in matrix B

    vector<vector<double>> result(m, vector<double>(p, 0.0)); // Initialize the result matrix

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
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

    // Measure the execution time for integer matrices
    clock_t start_time_int = clock(); // Start the timer for integer matrices

    vector<vector<int>> result_int = multiplyIntegerMatrices(matrixA, matrixB);

    clock_t end_time_int = clock(); // Stop the timer for integer matrices

    double elapsed_time_int = double(end_time_int - start_time_int) / CLOCKS_PER_SEC;

    cout << "\nInteger matrix multiplication took " << elapsed_time_int << " seconds." << endl;

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

    // Measure the execution time for double matrices
    clock_t start_time_double = clock(); // Start the timer for double matrices

    vector<vector<double>> result_double = multiplyDoubleMatrices(matrixADouble, matrixBDouble);

    clock_t end_time_double = clock(); // Stop the timer for double matrices

    double elapsed_time_double = double(end_time_double - start_time_double) / CLOCKS_PER_SEC;

    cout << "\nDouble matrix multiplication took " << elapsed_time_double << " seconds." << endl;

    return 0;
}
