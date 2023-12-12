#include<iostream>
using namespace std;

int n;

class Process
{
public:
    int pid;
    int bt;
    int at;
    int priority;
    int rt;
    int done;

    Process()
    {
        pid = 0;
        bt = at = priority = rt = done = 0;
    }
} * p;

int findNextProcess(int t);

void input()
{
    cout << "Enter the number of processes: ";
    cin >> n;
    p = new Process[n];
    cout << "\n\nEnter the details of the processes:";
    for (int i = 0; i < n; i++)
    {
        cout << "\n Process " << i + 1 << " ";
        cout << "\n\t1. PID: ";
        cin >> p[i].pid;
        cout << "\n\t2. Arrival time: ";
        cin >> p[i].at;
        cout << "\n\t3. Burst time: ";
        cin >> p[i].bt;
    }
}

void sort()
{
    Process temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (p[j].at < p[j - 1].at)
            {
                temp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = temp;
            }
        }
    }
}

void roundRobin()
{
    int pIndex = -1, timeSlice, complete = 0;
    cout << "Enter time slice: ";
    cin >> timeSlice;
    cout << "PID\tTIME\tBURST TIME\n";
    for (int t = 0; complete < n;)
    {
        pIndex = findNextProcess(t);
        if (pIndex != -1)
        {
            if (p[pIndex].bt <= timeSlice)
            {
                cout << p[pIndex].pid << "\t" << t << "\t" << p[pIndex].bt << "\n";
                t = t + p[pIndex].bt;
                p[pIndex].done = 1;
                complete++;
                p[pIndex].bt = 0;
            }
            else
            {
                cout << p[pIndex].pid << "\t" << t << "\t" << timeSlice << "\n";
                t = t + timeSlice;
                p[pIndex].bt = p[pIndex].bt - timeSlice;
            }
        }
        else
            t++;
    }
}

int findNextProcess(int t)
{
    static int i = -1;
    int pIndex = -1;
    i++;
    if (i == n)
        i = 0;
    int startedAt = i;
    do
    {
        if (p[i].at <= t && p[i].done == 0)
        {
            pIndex = i;
            return pIndex;
        }
        else if (p[i].done == 1)
        {
            i++;
            if (i == n)
                i = 0;
        }
        else
        {
            i = 0;
        }
    } while (i != startedAt);
    return pIndex;
}

int main()
{
    input();
    sort();
    roundRobin();
    return 0;
}

