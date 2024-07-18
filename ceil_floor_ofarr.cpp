#include <iostream>
using namespace std;

void search(int nums[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int x = -1; // Initialize x to -1 to indicate no floor found
    int y = -1; // Initialize y to -1 to indicate no ceiling found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            x = nums[mid];
            y = nums[mid];
            break;
        } else if (nums[mid] < target) {
            x = nums[mid]; // Update floor
            low = mid + 1;
        } else {
            y = nums[mid]; // Update ceiling
            high = mid - 1;
        }
    }

    if (x == -1) {
        cout << "No floor found\n";
    } else {
        cout << "Floor: " << x << "\n";
    }

    if (y == -1) {
        cout << "No ceiling found\n";
    } else {
        cout << "Ceiling: " << y << "\n";
    }
}

int main() {
    int arr[] = {3, 4, 4, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    search(arr, size, 5);
    return 0;
}

