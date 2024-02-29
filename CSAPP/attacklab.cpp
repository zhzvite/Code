#include<iostream>
using namespace std;
int main(){
    char buf[4];
    //fgets(buf,4,stdin);
    //gets(buf);
    scanf("%4s", buf);
    puts(buf);
}