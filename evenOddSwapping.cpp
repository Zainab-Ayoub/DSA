#include <iostream>
using namespace std;

int main() {
    int input[5];
    int arr[10] = {0}; // initialize all to zero

    cout << "Enter 5 numbers:\n";
    for (int i = 0; i < 5; ++i) {
        cin >> input[i];
    }

    int *arrPtr = arr + 1; // start from index 1
    int evenIndex = 1;     // odd position in array (1, 3, 5, 7, 9)
    int oddIndex = 2;      // even position in array (2, 4, 6, 8)

    for (int i = 0; i < 5; ++i) {
        if (input[i] % 2 == 0) {
            if (evenIndex < 10) {
                *(arr + evenIndex) = input[i];
                evenIndex += 2;
            }
        } else {
            if (oddIndex < 10) {
                *(arr + oddIndex) = input[i];
                oddIndex += 2;
            }
        }
    }

    cout << "\nFinal array:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "arr[" << i << "] = " << *(arr + i) << endl;
    }

    return 0;
}
