
#include <stdio.h>

#define MAX_SIZE 100

// Function prototypes
void createArray(int arr[], int *n);
void displayArray(int arr[], int n);
void bubbleSort(int arr[], int n);
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int low, int high, int key);

int main() {
    int arr[MAX_SIZE], n = 0, choice, key, result;

    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Sort Array (Bubble Sort)\n");
        printf("4. Search using Linear Search\n");
        printf("5. Search using Binary Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Creating the array
                printf("Enter the number of elements (max %d): ", MAX_SIZE);
                scanf("%d", &n);
                if (n <= MAX_SIZE && n > 0) {
                    createArray(arr, n); // Passing array and its size
                } else {
                    printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
                }
                break;

            case 2:
                // Displaying the array
                displayArray(arr, n);
                break;

            case 3:
                // Sorting the array using Bubble Sort
                bubbleSort(arr, n);
                printf("Array sorted using Bubble Sort.\n");
                break;

            case 4:
                // Linear search for an element
                printf("Enter the element to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, n, key);
                if (result != -1)
                    printf("Element found at position %d (1-based index).\n", result + 1);
                else
                    printf("Element not found in the array.\n");
                break;

            case 5:
                // Binary search for an element
                printf("Enter the element to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, 0, n - 1, key);
                if (result != -1)
                    printf("Element found at position %d (1-based index).\n", result + 1);
                else
                    printf("Element not found in the array.\n");
                break;

            case 6:
                return 0; // Exit the program

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to create an array
void createArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

// Function to display the array
void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Linear Search Algorithm
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // Return the index where the key is found
    }
    return -1; // Key not found
}

// Binary Search Algorithm
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid; // Return the index where the key is found
        else if (arr[mid] < key)
            low = mid + 1; // Narrow search to the right half
        else
            high = mid - 1; // Narrow search to the left half
    }
    return -1; // Key not found
}
