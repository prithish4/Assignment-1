#include <iostream>

using namespace std;

// Function to find the median of two sorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    // If the first array is empty, find the median in the second array
    if (size1 == 0) {
        if (size2 % 2 == 1) {
            return arr2[size2 / 2];  // Return middle element
        } else {
            return (arr2[size2 / 2 - 1] + arr2[size2 / 2]) / 2.0;  // Return average of middle elements
        }
    }

    // If the second array is empty, find the median in the first array
    if (size2 == 0) {
        if (size1 % 2 == 1) {
            return arr1[size1 / 2];  // Return middle element
        } else {
            return (arr1[size1 / 2 - 1] + arr1[size1 / 2]) / 2.0;  // Return average of middle elements
        }
    }

    int totalSize = size1 + size2;
    int mergedIndex = 0;
    int median1 = 0, median2 = 0;
    int i = 0, j = 0;

    // Merge elements from two sorted arrays until we reach the middle of the combined array
    for (mergedIndex = 0; mergedIndex <= totalSize / 2; mergedIndex++) {
        // Store the previous median value before updating it
        median1 = median2;

        // Check if we have more elements in arr1 and either arr2 is empty 
        // or the current element in arr1 is less than or equal to the current element in arr2
        if (i < size1 && (j >= size2 || arr1[i] <= arr2[j])) {
            // Take the next element from arr1 and move to the next index
            median2 = arr1[i++];
        } else {
            // Otherwise, take the next element from arr2 and move to the next index
            median2 = arr2[j++];
        }
    }

    // If the total number of elements is odd, return the single middle element
    if (totalSize % 2 == 1) {
        return median2;
    } 
    // If the total number of elements is even, return the average of the two middle elements
    else {
        return (median1 + median2) / 2.0;
    }

}


int main() {
    // You can use cout statements, but ensure that you submit after commenting them out, as the autograder will otherwise mistake it for your actual output
    // Everything else in the main function remains unchanged
    
    int size1;
    // cout << "Enter the size of the array1: ";
    cin >> size1;

    int arr[size1];
    // cout << "Enter " << size1 << " elements:" << endl;
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    // cout << "The array elements are: ";
    // for (int i = 0; i < size1; ++i) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int size2;
    // cout << "Enter the size of the array2: ";
    cin >> size2;

    int arr1[size2];
    // cout << "Enter " << size2 << " elements:" << endl;
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }

    // cout << "The array elements are: ";
    // for (int i = 0; i < size2; ++i) {
    //     cout << arr1[i] << " ";
    // }
    // cout << endl;
    
    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl; // do not comment this out
    
    return 0;
}
