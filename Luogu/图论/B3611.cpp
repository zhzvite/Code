#include<iostream>
int dist[110][110],n;
int main(){
std::cin>>n;
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
std::cin>>dist[i][j];
for(int k=1;k<=n;k++)
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
if(dist[i][k]&dist[k][j])
dist[i][j]=1;
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++)
std::cout<<dist[i][j]<<" ";
std::cout<<std::endl;}
}