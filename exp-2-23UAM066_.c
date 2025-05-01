#include <stdio.h>

void merge(int arr[], int indices[], int temp[], int count[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int tempIndices[right - left + 1];
    int rightCounter = 0; // Number of elements taken from right side
	int m;

    while (i <= mid && j <= right) {
        if (arr[indices[i]] <= arr[indices[j]]) {
            count[indices[i]] += rightCounter; // Count how many elements from right are smaller
            tempIndices[k - left] = indices[i];
            temp[k] = arr[indices[i]];
            i++;
        } else {
            rightCounter++; // This element from right is smaller than remaining left elements
            tempIndices[k - left] = indices[j];
            temp[k] = arr[indices[j]];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        count[indices[i]] += rightCounter;
        tempIndices[k - left] = indices[i];
        temp[k] = arr[indices[i]];
        i++;
        k++;
    }

    while (j <= right) {
        tempIndices[k - left] = indices[j];
        temp[k] = arr[indices[j]];
        j++;
        k++;
    }

    for (m = left; m <= right; m++) {
        arr[m] = temp[m];
        indices[m] = tempIndices[m - left];
    }
}

void mergeSort(int arr[], int indices[], int temp[], int count[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, indices, temp, count, left, mid);
        mergeSort(arr, indices, temp, count, mid + 1, right);
        merge(arr, indices, temp, count, left, mid, right);
    }
}

int main() {
    int arr[50];
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    
    printf("Enter array elements: ");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int indices[size], temp[size], count[size];
    
    for (i = 0; i < size; i++) {
        indices[i] = i;  // Track original indices
        count[i] = 0;    // Initialize count array
    }

    mergeSort(arr, indices, temp, count, 0, size - 1);

    printf("\nResult array (count of smaller elements after self): ");
    for (i = 0; i < size; i++) {
        printf("%d ", count[i]);
    }
    
    return 0;
}

