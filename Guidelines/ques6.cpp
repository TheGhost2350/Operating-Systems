#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main()
{

        char buff[50];
        int n;
        int fd1=open("source.txt",O_RDONLY);
        int fd2=open("target.txt",O_WRONLY||O_CREAT);
        if(fd1<0)
        cout<<"\n source file not opened sucessfully";
        if(fd2<0)
        cout<<"\n target file not opened successfuly";
        while((n=read(fd1,buff,50))>0)
        {
                write(fd2,buff,n);
        }
        write(fd2,"\0",1);
        if(n<0)
                cout<<"file could not read the content";
        close(fd1);
        close(fd2);
        fd2=open("target.txt",O_RDONLY);
        cout<<"\n file 1 has been copied to file 2 and its contents are \n";
        while((n=read(fd2,buff,49))>0)
        {
                buff[49]='\0';
                cout<<buff;
        }

        return 0;
}

