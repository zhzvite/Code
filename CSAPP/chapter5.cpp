#include<iostream>
using namespace std;
int a[3][3]={1,2,3,4,5};
int main(){
    int *p=a[0];
    
    cout << *(p + 3);
    
}
