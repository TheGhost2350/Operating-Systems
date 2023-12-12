#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

struct ThreadData
{
    vector<int> *numbers;
    int startIndex;
    int endIndex;
    int sum;
};

void *calculateSum(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->startIndex; i < data->endIndex; ++i)
    {
        data->sum += (*data->numbers)[i];
    }
    return NULL;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    int mid = n / 2;

    pthread_t thread1, thread2;

    ThreadData data1 = {&numbers, 0, mid, 0};

    ThreadData data2 = {&numbers, mid, n, 0};

    pthread_create(&thread1, NULL, calculateSum, &data1);
    pthread_create(&thread2, NULL, calculateSum, &data2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    int totalSum = data1.sum + data2.sum;

    cout << "Sum of the numbers: " << totalSum << endl;

    return 0;
}

