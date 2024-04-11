#include <stdio.h>
#include <stdlib.h>

// �Լ� ��� ����.
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
    int rowA, colA, rowB, colB; // ��� A�� B�� ��� ���� �� �Է�

    printf("��� A�� ���� ���� ���� ���� �Է��ϼ���. :");
    scanf("%d %d", &rowA, &colA);
    printf("��� B�� ���� ���� ���� ���� �Է��ϼ���. :");
    scanf("%d %d", &rowB, &colB);

    // 2���� ������ ������ ��� ����
    int **matrixA = create_matrix(rowA, colA);
    int **matrixB = create_matrix(rowB, colB);

    // ������ ����� ������ ���� ä���
    fill_matrix(matrixA, rowA, colA);
    fill_matrix(matrixB, rowB, colB);

    // ��� A�� B���
    printf("��� A:\n");
    print_matrix(matrixA, rowA, colA);
    printf("��� B:\n");
    print_matrix(matrixB, rowB, colB);

    // ��� A + B
    if (rowA == rowB && colA == colB) // �� ����� ����� ���� �� ���� ��������.
    {
        int **resultAdd = create_matrix(rowA, colA);              // A+B�� ���� ���ο� ��� ����
        addition_matrix(matrixA, matrixB, resultAdd, rowA, colA); // A + B �Լ�����
        printf("A + B�� ���:\n");
        print_matrix(resultAdd, rowA, colA); // resultadd ���
        free_matrix(resultAdd, rowA);        // �޸� ����
    }
    else
    {
        printf("����� ������ �� �����ϴ�. ����� �ٸ��ϴ�.\n"); // if ���� �Ҹ��� �� ���
    }

    if (rowA == rowB && colA == colB) // �� ����� ����� ���� �� ���� ��������.
    {
        int **resultSub = create_matrix(rowA, colA);                 // A - B�� ���� ���ο� ��� ����
        subtraction_matrix(matrixA, matrixB, resultSub, rowA, colA); // A - B �Լ� ����
        printf("A - B�� ���:\n");
        print_matrix(resultSub, rowA, colA); // resultsub ���
        free_matrix(resultSub, rowA);        // �޸� ����
    }
    else
    {
        printf("����� ������ �� �����ϴ�. ����� �ٸ��ϴ�.\n"); // if ���� �Ҹ��� �� ���
    }

    // ��� A ��ġ��Ű�� �ڵ�
    int **resultTransposeA = create_matrix(colA, rowA);
    transpose_matrix(matrixA, resultTransposeA, rowA, colA);
    printf("A�� ��ġ�࿭:\n");
    print_matrix(resultTransposeA, colA, rowA);
    free_matrix(resultTransposeA, colA);

    // ��� A ��� B ����
    if (colA == rowB)
    {
        int **resultMult = create_matrix(rowA, colB);
        multiply_matrix(matrixA, matrixB, resultMult, rowA, colA, colB);
        printf("A X B�� ���:\n");
        print_matrix(resultMult, rowA, colB);
        free_matrix(resultMult, rowA);
    }
    else
    {
        printf("����� ������ �� �����ϴ�. ����� �ٸ��ϴ�.\n");
    }

    // matrixA, matirxB �Ҵ�����.
    free_matrix(matrixA, rowA);
    free_matrix(matrixB, rowB);

    return 0;
}

// ��� ���� �Լ�
int **create_matrix(int row, int col) // ����� ������� ������ �Է¹��� row, col
{
    int **matrix = (int **)malloc(row * sizeof(int *)); // 2���� �迭�� ���� �� �࿡ ���� ������ �迭
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(col * sizeof(int)); // �� ����
    }
    return matrix;
}

// ��� ���� ä��� �Լ�
void fill_matrix(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 100; // i * j���� ���Ҹ� ���� ������� ������ �� �Է�
        }
    }
}

// ��� ����Լ�
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

// ��� ���� ���� �Լ�
void addition_matrix(int **matrixA, int **matrixB, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j]; // ����� Ư�� ��, ���� ���Ҹ� ���ؼ� result��� ��Ŀ� ����
        }
    }
}

// ��� ���� ���� �Լ�
void subtraction_matrix(int **matrixA, int **matrixB, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j]; // ����� Ư�� ��, ���� ���Ҹ� ���� result��� ��Ŀ� ����
        }
    }
}

// ��� ��ġ �Լ�
void transpose_matrix(int **matrix, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[j][i] = matrix[i][j]; // y = -x �� �� ���� ���� ����
        }
    }
}

// ��� ���� �Լ�
void multiply_matrix(int **matrixA, int **matrixB, int **result, int rowA, int colA, int colB)
{
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j]; // ��� A�� �� X ��� B�� �� ���� �� result�� ����
            }
        }
    }
}

// �޸� �Ҵ� ����
void free_matrix(int **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}