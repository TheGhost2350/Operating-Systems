#include <iostream>
using namespace std;

int n;

struct Process
{
    int pid;
    int arr_time;
    int burst_time;
    int priority;
    int done;

    Process()
    {
        done = 0;
        pid = 0;
        arr_time = 0;
        burst_time = 0;
        priority = 0;
    }
} *p;

void input()
{
    cout << "Enter the number of processes: ";
    cin >> n;

    p = new Process[n];

    for (int i = 0; i < n; i++)
    {
        cout << "** Process " << i + 1 << " **";
        cout << "\n\t1. PID: ";
        cin >> p[i].pid;
        cout << "\n\t2. ARRIVAL TIME: ";
        cin >> p[i].arr_time;
        cout << "\n\t3. BURST TIME: ";
        cin >> p[i].burst_time;
    }
}

void sort()
{
    Process temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (p[j].arr_time < p[j - 1].arr_time)
            {
                temp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = temp;
            }
        }
    }
}

int find_next_process(int t1)
{
    int first_process = 0, minbt, pindex = -1;

    for (int i = 0; i < n; i++)
    {
        if (p[i].arr_time <= t1 && p[i].done == 0)
        {
            if (first_process == 0)
            {
                first_process = 1;
                minbt = p[i].burst_time;
                pindex = i;
            }
            else if (p[i].burst_time < minbt)
            {
                minbt = p[i].burst_time;
                pindex = i;
            }
        }
    }
    return pindex;
}

void srtf()
{
    int cmplt = 0, pindex = 0;
    cout << "\n\n PID \tSTART TIME \tREMAINING TIME\n\n";
    for (int t = 0; cmplt < n; t++)
    {
        pindex = find_next_process(t);

        if (pindex != -1)
        {
            p[pindex].burst_time--;
            cout << " " << p[pindex].pid << "\t\t" << t << "\t\t" << p[pindex].burst_time << "\n";

            if (p[pindex].burst_time == 0)
            {
                cmplt++;
                p[pindex].done = 1;
            }
        }
    }
}

int main()
{
    input();
    sort();
    srtf();
    return 0;
}

