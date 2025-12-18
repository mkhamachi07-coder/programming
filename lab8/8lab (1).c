#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Для INT_MAX
//Вывод матрицы 
void print_matrix(int **matrix, int rows, int cols, const char *name) {
    printf("Матрица %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// Освобождение памяти
void free_matrix(int **matrix, int rows) {
    if (matrix == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
// Возвращает массив [min_row, min_col, min_value]
int *find_min_element(int **A, int N, int M) {
    // Динамически выделяем память для результата: [row, col, value]
    int *result = (int *)malloc(3 * sizeof(int));
    if (result == NULL) {
        perror("Ошибка выделения памяти для find_min_element");
        exit(EXIT_FAILURE);
    }
    // Инициализация
    result[0] = -1; // min_row
    result[1] = -1; // min_col
    result[2] = INT_MAX; // min_value (наибольшее возможное целое)

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] < result[2]) {
                result[2] = A[i][j];
                result[0] = i;
                result[1] = j;
            }
        }
    }
    return result;
}

// Формирование новой матрицы B
int **form_matrix_B(int **A, int N, int M, int min_row, int min_col, int *new_N, int *new_M) {
    // Новые размеры матрицы B
    *new_N = N - 1;
    *new_M = M - 1;

    // Динамическое выделение памяти для новой матрицы B
    int **B = (int **)malloc((*new_N) * sizeof(int *));
    if (B == NULL) {
        perror("Ошибка выделения памяти для строк матрицы B");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < *new_N; i++) {
        B[i] = (int *)malloc((*new_M) * sizeof(int));
        if (B[i] == NULL) {
            perror("Ошибка выделения памяти для столбцов матрицы B");
            // Освобождаем уже выделенные строки
            for (int k = 0; k < i; k++) free(B[k]);
            free(B);
            exit(EXIT_FAILURE);
        }
    }

    // Заполнение матрицы B
    int dest_row = 0;
    for (int src_row = 0; src_row < N; src_row++) {
        // Пропускаем строку с минимальным элементом
        if (src_row == min_row) continue;

        int dest_col = 0;
        for (int src_col = 0; src_col < M; src_col++) {
            // Пропускаем столбец с минимальным элементом
            if (src_col == min_col) continue;

            B[dest_row][dest_col] = A[src_row][src_col];
            dest_col++;
        }
        dest_row++;
    }

    return B;
}

//Подсчет нулей
int count_zeros(int **matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

//Обмен первой и последней строки
void swap_first_last_rows(int **matrix, int N, int M) {
    if (N < 2) {
        // Нечего менять, если меньше двух строк
        return; 
    }
    
    // Используем временный указатель на строку для обмена
    // Нет необходимости копировать данные поэлементно
    int *temp_row_ptr = matrix[0];
    matrix[0] = matrix[N - 1];
    matrix[N - 1] = temp_row_ptr;
    
    printf("Первая и последняя строки поменяны местами.\n");
}


// =======================================================
// --- MAIN ---
// =======================================================
int main() {
    // Задаем размерность исходной матрицы A
    const int N = 4; // Строки
    const int M = 5; // Столбцы
 
    int initial_data[4][5] = {
        {5, 2, 8, 1, 9},
        {4, 7, 0, 6, 3},
        {10, 15, 3, 2, 0},
        {12, 1, 1, 0, 11}
    };

    // 1. Динамическое выделение памяти для исходной матрицы A
    int **A = (int **)malloc(N * sizeof(int *));
    if (A == NULL) {
        perror("Ошибка выделения памяти для строк матрицы A");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(M * sizeof(int));
        if (A[i] == NULL) {
            perror("Ошибка выделения памяти для столбцов матрицы A");
            // Освобождаем уже выделенные строки перед выходом
            for (int k = 0; k < i; k++) free(A[k]);
            free(A);
            return EXIT_FAILURE;
        }
        // Копирование данных из статического массива initial_data в динамическую матрицу A
        for (int j = 0; j < M; j++) {
            A[i][j] = initial_data[i][j];
        }
    }

    print_matrix(A, N, M, "A (Исходная)");

    // 2. Нахождение минимального элемента
    int *min_info = find_min_element(A, N, M);
    int min_row = min_info[0];
    int min_col = min_info[1];
    int min_val = min_info[2];

    printf("--- Шаг 1: Поиск минимального элемента ---\n");
    printf("Минимальный элемент: %d (Строка: %d, Столбец: %d)\n", 
           min_val, min_row + 1, min_col + 1);

    // Переменные для размеров новой матрицы B
    int N_B, M_B;

    // 3. Формирование матрицы B
    printf("\n--- Шаг 2: Формирование матрицы B ---\n");
    int **B = form_matrix_B(A, N, M, min_row, min_col, &N_B, &M_B);
    
    print_matrix(B, N_B, M_B, "B (После вычеркивания)");

    // 4. Определение количества нулей в матрице B
    printf("--- Шаг 3: Подсчет нулей ---\n");
    int zeros_count = count_zeros(B, N_B, M_B);
    printf("Количество нулей в матрице B: **%d**\n", zeros_count);

    // 5. Поменять местами первую и последнюю строки
    printf("\n--- Шаг 4: Обмен строк ---\n");
    swap_first_last_rows(B, N_B, M_B);
    
    print_matrix(B, N_B, M_B, "B (Финальная, после обмена строк)");

    free(min_info); 
    free_matrix(A, N);
    free_matrix(B, N_B);

    return 0;
}