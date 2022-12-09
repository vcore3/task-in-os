
#include<iostream>
#include<string>
#include<cstdio>
#include"cmd.h"
#include"data.h"


int main(){
    Login();
    while(1){
        string c;
        string path,proc;
        string way;
        int type;
        cin>>c;
        if(c == "Logout"){
            if(Logout())break;
        }
        if(c == "Create"){
            cin>>path>>type>>proc;
            Create(path,type,proc);
        }
        if(c == "Delete"){
            cin>>path>>type;
            Delete(path,type);
        }
        if(c == "Open"){
            cin>>path;
            if(Open(path))cout<<"Open successful"<<endl;
            else cout << "Open failed"<<endl;
        }
        if(c == "Close"){
            cin>>path;
            if(Close(path))cout<<"Close successful"<<endl;
            else cout << "Close failed"<<endl;
        }
        if(c == "Read"){
            cin>>path;
            Read(path);
        }
        if(c == "Write"){
            cin>>path>>way>>proc;
            Write(path,way,proc);
        }
        if(c == "Dir"){
           Dir();
        }
    }
    return 0;
}