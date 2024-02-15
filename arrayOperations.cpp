#include <iostream>
#include <algorithm>
using namespace std;

void display(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearch(int arr[], int size, int val) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // val not found
}

void insertAtBeginning(int *&arr, int &size) {
    int n, val;
    cout << "Enter number of values to add initially: ";
    cin >> n;

    arr = new int[size + n];

    for (int i = size; i < size + n; i++) {
        cout << "Enter initial value" << i << ": ";
        cin >> val;
        arr[i] = val;
    }

    size += n;

    cout << "Array after append: ";
    display(arr, size);
}

void insertValueAtEndForEndIsKnown(int *&arr, int &size) {
    int n, val;
    cout << "Enter number of values to add initially: ";
    cin >> n;

    arr = new int[size + n];

    for (int i = size; i < size + n; i++) {
        cout << "Enter initial value" << i << ": ";
        cin >> val;
        arr[i] = val;
    }

    size += n;

    cout << "Array after append: ";
    display(arr, size);
}

void insertValueAtEndForEndIsUnknown(int *&arr, int &size) {
    int n, val;
    cout << "Enter number of values to add initially: ";
    cin >> n;

    arr = new int[size + n];

    for (int i = size; i < size + n; i++) {
        cout << "Enter initial value" << i << ": ";
        cin >> val;
        arr[i] = val;
    }

    int count = size;
    size += n;

    cout << "Array has " << count << " elements." << endl;
    cout << "Enter value to add: ";
    cin >> val;
    arr[size++] = val;

    cout << "After inserting: " << endl;
    display(arr, size);
}

void insertAtGivenLocation(int *&arr, int &size) {
    int n, val;
    cout << "Enter number of values to add initially: ";
    cin >> n;

    arr = new int[size + n];

    for (int i = size; i < size + n; i++) {
        cout << "Enter initial value" << i << ": ";
        cin >> val;
        arr[i] = val;
    }

    int count = size;
    size += n;

    int pos;
    cout << "Enter position where you want to enter new value: ";
    cin >> pos;

    if (pos >= size) {
        cout << "Invalid position." << endl;
        return;
    }

    if (arr[pos] == -1) {
        cout << "Enter value to add at this position: ";
        cin >> arr[pos];
    } else {
        for (int i = count - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }
        count++;
        cout << "Enter value to add at this position: ";
        cin >> arr[pos];
    }

    cout << "Array after inserting: ";
    display(arr, size);
}

void deletionViaParticularPosition(int *&arr, int &size) {
    int n, val;
    cout << "Enter number of values to add initially: ";
    cin >> n;

    arr = new int[size + n];

    for (int i = size; i < size + n; i++) {
        cout << "Enter initial value" << i << ": ";
        cin >> val;
        arr[i] = val;
    }

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 0 || pos >= size) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    cout << "Array post-deletion: ";
    display(arr, size);
}

int main() {
    int *arr = nullptr;
    int size = 0;
    int choice;
    int index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end (when end size is known)\n";
        cout << "3. Insert at the end (when end size is unknown)\n";
        cout << "4. Insert at a given location\n";
        cout << "5. Delete at a particular position\n";
        cout << "6. Bubble Sort\n";
        cout << "7. Binary Search\n";
        cout << "8. Display Array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertAtBeginning(arr, size);
                break;

            case 2:
                insertValueAtEndForEndIsKnown(arr, size);
                break;

            case 3:
                insertValueAtEndForEndIsUnknown(arr, size);
                break;

            case 4:
                insertAtGivenLocation(arr, size);
                break;

            case 5:
                deletionViaParticularPosition(arr, size);
                break;

            case 6:
                bubbleSort(arr, size);
                cout << "Array after Bubble Sort: ";
                display(arr, size);
                break;

            case 7:
                int key;
                cout << "Enter the element to search: ";
                cin >> key;
                index = binarySearch(arr, size, key);
                if (index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else {
                    cout << "Element not found in the array.\n";
                }
                break;

            case 8:
                display(arr, size);
                break;


            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    delete[] arr; // Don't forget to free the allocated memory
    return 0;
}