// #include<iostream>
// #include<unistd.h>
// #include<signal.h>
// using namespace std;
// void handler(int sig){
//     return ;
// }
// unsigned int snooze(unsigned int secs){
//     unsigned int rc=sleep(secs);
//     printf("Slept for %d of %d secs.\n",secs-rc,secs);
//     return rc;

// }
// int main(int argc,char **argv){
//     if(argc!=2){
//         cout<<"fuc"<<endl;
//         exit(0);
//     }
//     if(!(signal(SIGINT, handler)==SIG_ERR))
//     //unix_error("signal error\n");
//     (void )snooze(stoi(argv[1]));
//     exit(0);
// }
#include"a.h"
int main(){
    mywrite();
}