#include <iostream>
using namespace std;

class Process
{
public:
    int pid;
    int bt;
    int at;
    int pr;
    int flag;
} *proc;

int n;

void sortOnArrival();
void input()
{
    cout << "Enter the number of processes: ";
    cin >> n;
    proc = new Process[n];
    cout << "Enter the process information in the following order" << "\n";
    cout << "PID" << "\t" << "Arrival Time" << "\t" << "Burst Time" << "\t" << "Priority Number" << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << "\n";
        cin >> proc[i].pid >> proc[i].at >> proc[i].bt >> proc[i].pr;
        proc[i].flag = 0;
    }
}

int findNextProcess(int t)
{
    int pindex = -1;
    int firstChoice = 0;
    int priorValue;
    for (int i = 0; i < n; i++)
    {
        if (proc[i].at <= t && proc[i].flag == 0)
        {
            if (firstChoice == 0)
            {
                firstChoice = 1;
                priorValue = proc[i].pr;
                pindex = i;
            }
            else if (priorValue > proc[i].pr)
            {
                priorValue = proc[i].pr;
                pindex = i;
            }
        }
    }
    return pindex;
}

int preemptivePriority()
{
    int complete = 0;
    int pindex = 0;
    sortOnArrival();
    cout << "PID" << "\t" << "Starting Time" << "\t" << "Finishing Time" << "\n";
    for (int t = 0; complete < n; t++)
    {
        pindex = findNextProcess(t);
        if (pindex != -1)
        {
            cout << proc[pindex].pid << "\t\t" << t << "\t\t" << (t + 1) << "\n";
            proc[pindex].bt--;
            if (proc[pindex].bt == 0)
            {
                complete++;
                proc[pindex].flag = 1;
            }
        }
    }
    return 0;
}

void sortOnArrival()
{
    Process temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (proc[j].at < proc[j - 1].at)
            {
                temp = proc[j];
                proc[j] = proc[j - 1];
                proc[j - 1] = temp;
            }
        }
    }
}

int main()
{
    input();
    preemptivePriority();
    return 0;
}

