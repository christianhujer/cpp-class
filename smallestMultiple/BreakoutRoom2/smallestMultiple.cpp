#include <iostream>

using namespace std;

bool divisibleByRange(int number) {
    for (int i = 1; i <= 20; i++) {
        if (number % i != 0)
            return false;
    }
    return true;
}

int smallestMultiple() {
    int smallestMultiple = 20;
    while (!divisibleByRange(smallestMultiple)) {
        smallestMultiple++;
    }
    return smallestMultiple;
}

int main() {
    cout << "Smallest multiple of range 1 to 20 is " << smallestMultiple();
    return EXIT_SUCCESS;
}