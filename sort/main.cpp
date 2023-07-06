

#include <iostream>

void bubble_sort(double arr[], int n, int& comparisons, int& swaps) {
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void selection_sort(double arr[], int n, int& comparisons, int& swaps) {
    int min_idx;

    for (int i = 0; i < n - 1; ++i) {
        min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
            swaps++;
        }
    }
}

int main() {
    double arr[] = {5.3, 2.1, 8.7, 1.5, 6.4, 9.0, 3.2};
    int n = sizeof(arr) / sizeof(arr[0]);
    double arr_copy[n];
    std::copy(arr, arr + n, arr_copy);

    int bubble_comparisons = 0;
    int bubble_swaps = 0;
    bubble_sort(arr, n, bubble_comparisons, bubble_swaps);

    int selection_comparisons = 0;
    int selection_swaps = 0;
    selection_sort(arr_copy, n, selection_comparisons, selection_swaps);

    std::cout << "Bubble Sort:\n";
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nComparisons: " << bubble_comparisons << "\nSwaps: " << bubble_swaps << std::endl;

    std::cout << "\nSelection Sort:\n";
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr_copy[i] << " ";
    }
    std::cout << "\nComparisons: " << selection_comparisons << "\nSwaps: " << selection_swaps << std::endl;

    return 0;
}
