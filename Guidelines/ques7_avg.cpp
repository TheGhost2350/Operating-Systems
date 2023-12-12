#include<iostream>
using namespace std;

int n;

struct Process
{
    int pid;
    int arr_time;
    int burst_time;
    int priority;
    int done;
    int start_time;
    int finish_time;

    Process()
    {
        done = 0;
        pid = 0;
        arr_time = 0;
        burst_time = 0;
        priority = 0;
        start_time = 0;
        finish_time = 0;
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
        cout << "\n\t1. PID:  ";
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

void fcfs()
{
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    int current_time = p[0].arr_time;
    cout << "\n\n PID \tSTART TIME \tFINISH TIME \tWAITING TIME \tTURNAROUND TIME\n\n";
    for (int i = 0; i < n; i++)
    {
        p[i].start_time = current_time;
        p[i].finish_time = current_time + p[i].burst_time;
        cout << "  " << p[i].pid << "\t\t" << p[i].start_time << "\t\t" << p[i].finish_time << "\t\t";

        // Calculate waiting time and turnaround time
        int waiting_time = p[i].start_time - p[i].arr_time;
        int turnaround_time = p[i].finish_time - p[i].arr_time;

        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;

        cout << waiting_time << "\t\t" << turnaround_time << "\n";

        current_time = p[i].finish_time;
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = static_cast<float>(total_waiting_time) / n;
    float avg_turnaround_time = static_cast<float>(total_turnaround_time) / n;

    cout << "\nAverage Waiting Time: " << avg_waiting_time;
    cout << "\nAverage Turnaround Time: " << avg_turnaround_time;
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

int main()
{
    input();
    sort();
    fcfs();
    return 0;
}

