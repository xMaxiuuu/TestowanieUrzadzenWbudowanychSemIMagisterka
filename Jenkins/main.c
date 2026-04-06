#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int numbers[] = {5,3,8,1,2};
    int n = sizeof(numbers)/sizeof(numbers[0]);

    printf("Przed sortowaniem:\n");
    print_array(numbers,n);

    bubble_sort(numbers,n);

    printf("Po sortowaniu:\n");
    print_array(numbers,n);

    return 0;
}