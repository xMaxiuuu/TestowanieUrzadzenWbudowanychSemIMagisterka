#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define SIZE_LARGE 5000

// Funkcja sortowania bąbelkowego signed char
void bubbleSort(signed char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                signed char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Weryfikuje czy tablica ułożyła się poprawnie
bool isSorted(signed char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

void runTest(const char* testName, signed char data[], int n, bool czyWypisywac) {
    printf("--- %s ---\n", testName);
    printf("Rozmiar wektora: %d elementow\n", n);
    
    if (czyWypisywac) {
        printf("Wejscie: ");
        if (n == 0) printf("[pusta tablica]");
        for(int i = 0; i < n; i++) printf("%d ", data[i]);
        printf("\n");
    }
    
    // Pomiar czasu
    clock_t start_time = clock();
    bubbleSort(data, n);
    clock_t end_time = clock();
    
    if (czyWypisywac) {
        printf("Wyjscie: ");
        if (n == 0) printf("[pusta tablica]");
        for(int i = 0; i < n; i++) printf("%d ", data[i]);
        printf("\n");
    }
    
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Sprawdzenie poprawności
    if (n == 0 || isSorted(data, n)) {
        printf("Wynik: Algorytm dziala poprawnie\n");
    } else {
        printf("Wynik: Algorytm dziala niepoprawnie\n");
    }
    
    printf("Czas wykonania: %f sekund\n\n", time_spent);
}

int main() {
    printf("\nTESTY LOGICZNE\n");
    printf("=========================================================\n\n");

    signed char test1_small[] = {127, -128};
    runTest("Test wartosci skrajnych (Min/Max)", test1_small, 2, true);

    signed char test2_small[] = {-128, 127, -128, 127, 0};
    runTest("Test duplikatow i przeplotu", test2_small, 5, true);

    signed char test3_small[] = {127, 126, 125, -127, -128};
    runTest("Najgorszy przypadek (odwrotna kolejnosc)", test3_small, 5, true);

    signed char test4_small[] = {-128, -50, 0, 50, 127};
    runTest("Najlepszy przypadek (tablica juz posortowana)", test4_small, 5, true);

    signed char test5_empty[0];
    runTest("Test pustej tablicy", test5_empty, 0, true);

    printf("TESTY WYDAJNOSCIOWE\n");
    printf("=========================================================\n\n");

    signed char test1_large[SIZE_LARGE];
    for(int i = 0; i < SIZE_LARGE; i++) test1_large[i] = (i % 2 == 0) ? 127 : -128;
    runTest("Test wartosci skrajnych (Min/Max)", test1_large, SIZE_LARGE, false);

    signed char test2_large[SIZE_LARGE];
    test2_large[0] = 127; // Zmusza do przesunięcia na sam koniec
    for(int i = 1; i < SIZE_LARGE; i++) test2_large[i] = -128;
    runTest("Test skrajnych duplikatow", test2_large, SIZE_LARGE, false);

    signed char test3_large[SIZE_LARGE];
    for(int i = 0; i < SIZE_LARGE; i++) test3_large[i] = 127 - (i % 256);
    runTest("Najgorszy przypadek (odwrotna kolejnosc)", test3_large, SIZE_LARGE, false);

    signed char test4_large[SIZE_LARGE];
    for(int i = 0; i < SIZE_LARGE; i++) test4_large[i] = -128 + (i % 256);
    runTest("Najlepszy przypadek (tablica juz posortowana)", test4_large, SIZE_LARGE, false);

    signed char test5_large_empty[0];
    runTest("Test pustej tablicy", test5_large_empty, 0, false);

    return 0;
}