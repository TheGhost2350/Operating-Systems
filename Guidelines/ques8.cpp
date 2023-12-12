#include<iostream>
using namespace std;

int n;

struct proc
{
        int pid, bt, at, done;
        proc()
        {
                pid=0;
                bt=0;
                at=0;
                done=0;
        }
} *p;

void input()
{
        cout<<"\nEnter the Number of Processes : ";
        cin>>n;

        p= new proc[n];

        for(int i=0; i<n; i++)
        {
                cout<<"\n****Process "<<i+1<<"*****";
                cout<<"\n\t1. Pid : ";
                cin>>p[i].pid;
                cout<<"\n\t2. Arrival Time : ";
                cin>>p[i].at;
                cout<<"\n\t3. Burst Time : ";
                cin>>p[i].bt;
        }
}


void sort_at()
{
        proc temp;
        for(int i=1; i<n; i++)
        {
                for(int j=i; j>0; j--)
	                {
                        if(p[j].at<p[j-1].at)
                        {
                                temp=p[j];
                                p[j]=p[j-1];
                                p[j-1]=temp;
                        }
                }
        }
        for(int i=0; i<n; i++)
        {
                cout<<"\nSorted :\t"<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt;
        }
}

int find_next_process(int t)
{
        int first_choice=0, min_bt, pindex=-1;

        for(int i=0; i<n; i++)
        {
                if((p[i].at<=t)&&(p[i].done==0))
                {
                        if(first_choice==0)
                        {
                                min_bt= p[i].bt;
                                pindex=i;
                                first_choice=1;
                        }
                        else if(min_bt>p[i].bt)
                        {
                                min_bt=p[i].bt;
                                pindex=i;
                        }
                }
        }
        return pindex;
}

void sjf()
{
        int complete=0, pindex=-1, t=0;
        sort_at();
        cout<<"\n\t Pid\tStarting time\tFinishing time";
        while(complete<n)
        {

                pindex= find_next_process(t);
                if(pindex!=-1)
                {
                        cout<<"\n\t "<<p[pindex].pid<<"\t\t"<<t<<"\t\t"<<t+p[pindex].bt;
                        t=t+p[pindex].bt;
                        complete++;
                        p[pindex].done=1;
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
        sjf();
        return 0;
}

