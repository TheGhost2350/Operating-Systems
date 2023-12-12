#include <iostream>
#include <thread>

using namespace std;

void calculateSum(int n, int &result) {
    result = 0;
    for (int i = 1; i <= n; ++i) {
        result += i;
    }
}

int main() {
    int n, sum;
    
    cout << "Enter the value of n: ";
    cin >> n;

    // Declare the thread object
    thread t(calculateSum, n, ref(sum));

    // Wait for the thread to finish its execution
    t.join();

    cout << "The sum of first " << n << " natural numbers is: " << sum << endl;

    return 0;
}

