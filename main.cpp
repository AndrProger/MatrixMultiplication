#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int **createRandomMatrix(int n) {
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = getRandomNumber(1, 10);
        }
    }
    return matrix;
}

int **createNullMatrix(int n) {
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

int **multiplyMatricesFirts(int **matrix1, int **matrix2, int n) {
    int **result = createNullMatrix(n);
    for (int j = 1; j < n; j++)
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];

    return result;
}

int **multiplyMatricesSecond(int **matrix1, int **matrix2, int n) {
    int **result = createNullMatrix(n);
    for (int i = 1; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];

    return result;
}

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printTest(int n, double timeFirst, double timeSecond) {
    cout << "------------------------------------------------------------------------" <<endl;
    cout << "Size: "<< n<<" First time: "<<timeFirst <<" Second time: "<<timeSecond <<endl;
    cout << "------------------------------------------------------------------------" <<endl<<endl;
}


void test(int n) {
    int **matrix1 = createRandomMatrix(n);
    int **matrix2 = createRandomMatrix(n);

    auto start = std::chrono::high_resolution_clock::now();
    int **resultFirst=multiplyMatricesFirts(matrix1, matrix2, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationFirst = end - start;
    double secondsFirst = durationFirst.count();

    start = std::chrono::high_resolution_clock::now();
    int **resultSecond=multiplyMatricesSecond(matrix1, matrix2, n);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSecond = end - start;
    double secondsSecond = durationSecond.count();

    printTest(n,secondsFirst,secondsSecond);
    for (int i = 0; i < n; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] resultFirst[i];
        delete[] resultSecond[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultFirst;
    delete[] resultSecond;

    return;
}

int main() {
    srand(time(nullptr));


//    test(2);
    for(int n=10;n<=100000;n=n+10){
        test(n);
    }
    return 0;
}
