#include <iostream>
using namespace std;

int n;

struct Process
{
    int pid, bt, at, done, prior;
    Process()
    {
        pid = 0;
        bt = 0;
        at = 0;
        done = 0;
        prior = 0;
    }
} * p;

void input()
{
    cout << endl << "ENTER NO OF PROCESSES: ";
    cin >> n;
    p = new Process[n];
    for (int i = 0; i < n; i++)
    {
        cout << "PROCESS " << i + 1 << "\t";
        cout << "\n\t1. PID: ";
        cin >> p[i].pid;
        cout << "\n\t2. ARRIVAL TIME: ";
        cin >> p[i].at;
        cout << "\n\t3. ENTER BURST TIME: ";
        cin >> p[i].bt;
        cout << "\n\t4. ENTER PRIORITY: ";
        cin >> p[i].prior;
    }
}

void sort()
{
    Process temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
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

int findNextProcess(int t)
{
    int firstChoice = 0, pIndex = -1, priorValue;

    for (int i = 0; i < n; i++)
    {
        if ((p[i].at <= t) && (p[i].done == 0))
        {
            if (firstChoice == 0)
            {
                firstChoice = 1;
                priorValue = p[i].prior;
                pIndex = i;
            }
            else if (priorValue > p[i].prior)
            {
                priorValue = p[i].prior;
                pIndex = i;
            }
        }
    }
    return pIndex;
}

void priority()
{
    int complete = 0, pIndex = -1, t = 0;
    sort();
    cout << "\n\tPID\tSTARTING TIME\tFINISHING TIME";
    while (complete < n)
    {
        pIndex = findNextProcess(t);
        if (pIndex != -1)
        {
            cout << "\n\t" << p[pIndex].pid << "\t" << t << "\t" << t + p[pIndex].bt;
            t = t + p[pIndex].bt;
            complete++;
            p[pIndex].done = 1;
        }
        else
        {
            t++;
        }
    }
}

int main()
{
    input();
    priority();
    return 0;
}

