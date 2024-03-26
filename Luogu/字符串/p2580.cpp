/*map用法
 #include<iostream>
#include<map>
#include<string>
using namespace std;
int n;

map<string,int >mp;
map<string,int> mp2;
int main(){
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        mp[s]++;
    }
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(!mp[s])cout<<"WRONG";
        if(mp[s]&&!mp2[s])cout<<"OK";
        if(mp[s]&&mp2[s])cout<<"REPEAT";
                mp2[s]++;
        cout<<endl;
    }
}
*/
//trie板子

#include<iostream>
using namespace std;
const int N=1e6+1e6;
int son[N][26],cnt[N],idx;
int sonn[N][26],cntt[N];
char s[N];
int n;
void insert(char str[],int son[N][26],int cnt[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
int  find(char str[],int son[N][26],int cnt[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])return 0;
        p=son[p][u];
    }
    return cnt[p];

}
int main(){
cin>>n;
while(n--){
    cin>>s;
    insert(s,son,cnt);
}
cin>>n;
while(n--){
    cin>>s;
if(!find(s,son,cnt))cout<<"WRONG";
else if(find(s,son,cnt)&&!find(s,sonn,cntt)){
    cout<<"OK";
}
else {
    cout<<"REPEAT";
}
cout<<endl;
insert(s,sonn,cntt);

}
}
