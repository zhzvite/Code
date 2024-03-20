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