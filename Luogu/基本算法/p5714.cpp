#include<iostream>
using namespace std;
double m,h;
int main(){
    cin>>m>>h;
    double dd;
    dd=m/(h*h);
    if(dd<18.5)cout<<"Underweight";
    else if(dd<24)cout<<"Normal";
    else {
        cout<<dd<<endl<<"Overweight";
    }
}