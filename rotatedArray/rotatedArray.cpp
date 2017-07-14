#include <iostream>

using namespace std;

int findMin(int arr[], int start, int end) {
    int mid = (end - start) / 2 + start;

    cout << "Start: " << start << endl;
    cout << "Mid: " << mid << endl;
    cout << "End: " << end << endl;

    if (end - start == 0) {
        return arr[start];
    }

    if (arr[mid] > arr[end]) {
        return findMin(arr, mid+1, end);
    } else {
        return findMin(arr, start, mid);
    }
}

int main () {
    int array [4] = {6,2,4,5};
    cout << "Answer: " << findMin ( array, 0, 3) << endl;
    return 0;
}
