#include <stdio.h>
#include <stdlib.h>

// 함수 헤더 선언.
int **create_matrix(int rows, int cols);
void fill_matrix(int **matrix, int rows, int cols);
void print_matrix(int **matrix, int rows, int cols);
void addition_matrix(int **matrixA, int **matrixB, int **result, int rows, int cols);
void subtraction_matrix(int **matrixA, int **matrixB, int **result, int rows, int cols);
void transpose_matrix(int **matrix, int **result, int rows, int cols);
void multiply_matrix(int **matrixA, int **matrixB, int **result, int rowsA, int colsA, int colsB);
void free_matrix(int **matrix, int rows);

int main()
{
    printf("[----- [Your Name] [Student ID] -----]\n");
    int rowA, colA, rowB, colB; // 행렬 A와 B의 행과 열의 수 입력

    printf("행렬 A의 행의 수과 열의 수를 입력하세요. :");
    scanf("%d %d", &rowA, &colA);
    printf("행렬 B의 행의 수과 열의 수를 입력하세요. :");
    scanf("%d %d", &rowB, &colB);

    // 2차원 구조를 가지는 행렬 생성
    int **matrixA = create_matrix(rowA, colA);
    int **matrixB = create_matrix(rowB, colB);

    // 생성한 행렬을 랜덤한 수로 채우기
    fill_matrix(matrixA, rowA, colA);
    fill_matrix(matrixB, rowB, colB);

    // 행렬 A와 B출력
    printf("행렬 A:\n");
    print_matrix(matrixA, rowA, colA);
    printf("행렬 B:\n");
    print_matrix(matrixB, rowB, colB);

    // 행렬 A + B
    if (rowA == rowB && colA == colB) // 두 행렬의 사이즈가 동일 할 때만 덧셈가능.
    {
        int **resultAdd = create_matrix(rowA, colA);              // A+B를 담을 새로운 행렬 생성
        addition_matrix(matrixA, matrixB, resultAdd, rowA, colA); // A + B 함수실행
        printf("A + B의 결과:\n");
        print_matrix(resultAdd, rowA, colA); // resultadd 출력
        free_matrix(resultAdd, rowA);        // 메모리 해제
    }
    else
    {
        printf("행렬을 연산할 수 없습니다. 사이즈가 다릅니다.\n"); // if 조건 불만족 시 출력
    }

    if (rowA == rowB && colA == colB) // 두 행렬의 사이즈가 동일 할 때만 덧셈가능.
    {
        int **resultSub = create_matrix(rowA, colA);                 // A - B를 담을 새로운 행렬 생성
        subtraction_matrix(matrixA, matrixB, resultSub, rowA, colA); // A - B 함수 실행
        printf("A - B의 결과:\n");
        print_matrix(resultSub, rowA, colA); // resultsub 출력
        free_matrix(resultSub, rowA);        // 메모리 해제
    }
    else
    {
        printf("행렬을 연산할 수 없습니다. 사이즈가 다릅니다.\n"); // if 조건 불만족 시 출력
    }

    // 행렬 A 전치시키는 코드
    int **resultTransposeA = create_matrix(colA, rowA);
    transpose_matrix(matrixA, resultTransposeA, rowA, colA);
    printf("A의 전치행열:\n");
    print_matrix(resultTransposeA, colA, rowA);
    free_matrix(resultTransposeA, colA);

    // 행렬 A 행렬 B 곱셈
    if (colA == rowB)
    {
        int **resultMult = create_matrix(rowA, colB);
        multiply_matrix(matrixA, matrixB, resultMult, rowA, colA, colB);
        printf("A X B의 결과:\n");
        print_matrix(resultMult, rowA, colB);
        free_matrix(resultMult, rowA);
    }
    else
    {
        printf("행렬을 연산할 수 없습니다. 사이즈가 다릅니다.\n");
    }

    // matrixA, matirxB 할당해제.
    free_matrix(matrixA, rowA);
    free_matrix(matrixB, rowB);

    return 0;
}

// 행렬 생성 함수
int **create_matrix(int row, int col) // 행렬의 사이즈는 사전에 입력받은 row, col
{
    int **matrix = (int **)malloc(row * sizeof(int *)); // 2차원 배열을 위한 각 행에 대한 포인터 배열
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(col * sizeof(int)); // 열 생성
    }
    return matrix;
}

// 행렬 원소 채우는 함수
void fill_matrix(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 100; // i * j개의 원소를 각각 순서대로 랜덤한 수 입력
        }
    }
}

// 행렬 출력함수
void print_matrix(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// 행렬 덧셈 연산 함수
void addition_matrix(int **matrixA, int **matrixB, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j]; // 행렬의 특정 행, 열의 원소를 더해서 result라는 행렬에 저장
        }
    }
}

// 행렬 뺄셈 연산 함수
void subtraction_matrix(int **matrixA, int **matrixB, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j]; // 행렬의 특정 행, 열의 원소를 빼서 result라는 행렬에 저장
        }
    }
}

// 행렬 전치 함수
void transpose_matrix(int **matrix, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[j][i] = matrix[i][j]; // y = -x 축 에 맞춰 원소 변경
        }
    }
}

// 행렬 곱셈 함수
void multiply_matrix(int **matrixA, int **matrixB, int **result, int rowA, int colA, int colB)
{
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j]; // 행렬 A의 열 X 행렬 B의 행 연산 후 result에 저장
            }
        }
    }
}

// 메모리 할당 해제
void free_matrix(int **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}