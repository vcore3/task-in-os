#pragma once
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include"data.h"
using namespace std;

void Login(){
    string name,  password;
    cout << "please input root name and password" << endl;
    cin >> name >> password;
    now = muser.next;
    user * head = &muser;
    while(now != NULL){
        if(now -> name == name && now -> password == password){
            cout << "Login successful" << endl;
            cout << "Now you can use follow comandline" << endl;
            cout << "Logout //Logout now user." << endl;
            cout << "Create //Create a file." << endl;
            cout << "Delete //Delete a file." << endl;
            cout << "Open //Open a file." << endl;
            cout << "Close //Close a file." << endl;
            cout << "Read //Read a file." << endl;
            cout << "Write //Write a file." << endl;
            cout << "Dir //List all directory." << endl;
            root = now -> root;
            return ;
        }
        head = now;
        now = now -> next;
    }
    now = (user*)malloc(sizeof(user));
    now -> name = name; now -> password = password; now -> next = NULL;
    now -> front = head;
    now -> root = (files*)malloc(sizeof(files));
    now -> root -> name = "~" ;
    root = now -> root;
    cout<< "user now exist, but system create this for you. " << endl;
    cout << "Now you can use follow comandline" << endl;
    cout << "Logout //Logout now user." << endl;
    cout << "Create //Create a file." << endl;
    cout << "Delete //Delete a file." << endl;
    cout << "Open //Open a file." << endl;
    cout << "Close //Close a file." << endl;
    cout << "Read //Read a file." << endl;
    cout << "Write //Write a file." << endl;
    cout << "Dir //List all directory." << endl;
}

void Fre(files* rot){
    for(int i=0;i<100;++i){
        if(rot->v[i] == 1){Fre(rot->child[i]);rot->v[i] = 0;ad[rot->addr] = 0;};
    }
    free(rot);
}
int Logout(){
    cout<< "please input password" << endl;
    string a;
    cin>>a;
    if(a != now->password){
        cout<<"error password"<<endl;
        return 0;
    }
    Fre(root);
    now->front->next = now->next;
    free(now);
    cout<<"Logout successful"<<endl;
    return 1;
}
files* par(files* hj, string name,int type){
    for(int i=0; i<100; ++i){
        if(hj->v[i] == 1 && hj->child[i]->type == type && hj->child[i]->name == name){
           // if(hj->type == type)return NULL;
            return hj->child[i];
        }
    }
    return NULL;
}

int adr(){
    for(int i=0;i<100;++i){
        if(ad[i] == 0){
            ad[i]=1;
            return i;
        }
    }
    return -1;
}
void Create(string path,int type,string pro){
    int adrr=adr();
    if(adrr == -1){
        cout<<"disk space not enough"<<endl;
        return;
    }
    int last = path.size() - 1;
    int i,j;
    while(path[last] != '/')last--;
    j=2;
    while(j<=last && path[j] !='/')j++;
    files* p = root;string a;
    if(j<=last){
        a=path.substr(2,j-2);
        i=j;
        p=par(root,a,1);
        if(p == NULL){cout<<"error path"<<endl;return;}
    }
    if(j!=last)for(;j<=last;j++){
        if(path[j] == '/'){
            a=path.substr(i+1,j-i-1);
            i=j;
            p=par(p,a,1);
            if(p == NULL){
                cout<<"error path"<<endl;
                return;
            }
        }
    }
    a=path.substr(j);
    for(int i=0;i<100;++i){
       // puts("111");
        if(p->v[i] == 1 && p->child[i]->type == type && p->child[i]->name == a){
            cout<<"This file already exist"<<endl;
            return;
        }
    }
    for(int i=0;i<100;++i){
        //puts("222");
        if(!p->v[i]){
            p->v[i]=1;
           // puts("333");
            p->child[i]=(files*)malloc(sizeof(files));
            //puts("444");
            p->child[i]->addr=adrr;
            //puts("555");
            p->child[i]->protect=pro;
            //puts("666");
            p->child[i]->name=a;
          //  puts("777");
            p->child[i]->type=type;
          //  puts("888");
            p->child[i]->state=0;
         //   puts("999");
            memset(p->child[i]->v,0,sizeof(p->child[i]->v));
           // puts("000");
            cout<<"Create successful"<<endl;
            return;
        }
    }
}

void Delete(string path,int type){
    int last = path.size() - 1;
    int i,j;
    while(path[last] != '/')last--;
    j=2;
    while(j<=last && path[j] !='/')j++;
    files* p = root;string a;
    if(j<=last){
        a=path.substr(2,j-2);
        i=j;
        p=par(root,a,1);
        if(p == NULL){cout<<"File not found"<<endl;return;}
    }
    if(j!=last)for(;j<=last;j++){
        if(path[j] == '/'){
            a=path.substr(i+1,j-i-1);
            i=j;
            p=par(p,a,1);
            if(p == NULL){
                cout<<"File not found"<<endl;
                return;
            }
        }
    }
    if(path[j] == '/')j++;
    a=path.substr(j);
    for(int i=0;i<100;++i){
        if(p->v[i] == 1 && p->child[i]->type == type && p->child[i]->name == a){
          //  p->child[i]->name = NONE;
            Fre(p->child[i]);
            p->v[i]=0;
            p->child[i]=NULL;
            cout<<"Delete successful"<<endl;
            return;
        }
    }
    cout<<"File not found"<<endl;
}

int Open(string path){
    int last = path.size() - 1;
    int i,j;
    while(path[last] != '/')last--;
    j=2;
    while(j<=last && path[j] !='/')j++;
    files* p = root;string a;
    if(j<=last){
        a=path.substr(2,j-2);
        i=j;
        p=par(root,a,2);
        if(p == NULL){//cout<<"Open failed"<<endl;
        return 0;}
    }
    if(j!=last)for(;j<=last;j++){
        if(path[j] == '/'){
            a=path.substr(i+1,j-i-1);
            i=j;
            p=par(p,a,2);
            if(p == NULL){
             //   cout<<"Open failed"<<endl;
                return 0;
            }
        }
    }
    a=path.substr(j);
    for(int i=0;i<100;++i){
        if(p->v[i] == 1 && p->child[i]->type == 2 && p->child[i]->name == a){
            if( p->child[i]->state == 1){
               // cout<<"File already was opened"<<endl;
                return 0;
            }
            p->child[i]->state = 1;
            //cout<<"Open successful"<<endl;
            return 1;
        }
    }
    return 0;
}

int Close(string path){
    int last = path.size() - 1;
    int i,j;
    while(path[last] != '/')last--;
    j=2;
    while(j<=last && path[j] !='/')j++;
    files* p = root;string a;
    if(j<=last){
        a=path.substr(2,j-2);
        i=j;
        p=par(root,a,2);
        if(p == NULL){//cout<<"Close failed"<<endl;
        return 0;}
    }
    if(j!=last)for(;j<=last;j++){
        if(path[j] == '/'){
            a=path.substr(i+1,j-i-1);
            i=j;
            p=par(p,a,2);
            if(p == NULL){
              //  cout<<"Close failed"<<endl;
                return 0;
            }
        }
    }
    a=path.substr(j);
    for(int i=0;i<100;++i){
        if(p->v[i] == 1 && p->child[i]->type == 2 && p->child[i]->name == a){
            if( p->child[i]->state == 0){
                //cout<<"File not was opened"<<endl;
                return 0;
            }
            p->child[i]->state = 0;
           // cout<<"Close successful"<<endl;
            return 1;
        }
    }
    return 0;
}

void Read(string path){
    if(!Close(path)){
        cout<<"Read file"<<endl;
    }
    else{
        Open(path);
    }
    int last = path.size() - 1;
    int i,j;
    while(path[last] != '/')last--;
    j=2;
    while(j<=last && path[j] !='/')j++;
    files* p = root;string a;
    if(j<=last){
        a=path.substr(2,j-2);
        i=j;
        p=par(root,a,2);
        if(p == NULL){cout<<"file error"<<endl;return;}
    }
    if(j!=last)for(;j<=last;j++){
        if(path[j] == '/'){
            a=path.substr(i+1,j-i-1);
            i=j;
            p=par(p,a,2);
            if(p == NULL){
                cout<<"file error"<<endl;
                return;
            }
        }
    }
    a=path.substr(j);
    for(int i=0;i<100;++i){
        if(p->v[i] == 1 && p->child[i]->type == 2 && p->child[i]->name == a){
            if( p->child[i]->state == 0){
                cout<<"file error"<<endl;
                return;
            }
            puts("ok");
            cout<<(p->child[i]->cent)<<endl;
            return;
        }
    }
}

void Write(string path,string way,string dir){
    if(!Close(path)){
        cout<<"Write file"<<endl;
    }
    else{
        Open(path);
    }
    int last = path.size() - 1;
    int i,j;
    while(path[last] != '/')last--;
    j=2;
    while(j<=last && path[j] !='/')j++;
    files* p = root;string a;
    if(j<=last){
        a=path.substr(2,j-2);
        i=j;
        p=par(root,a,2);
        if(p == NULL){cout<<"file error"<<endl;return;}
    }
    if(j!=last)for(;j<=last;j++){
        if(path[j] == '/'){
            a=path.substr(i+1,j-i-1);
            i=j;
            p=par(p,a,2);
            if(p == NULL){
                cout<<"file error"<<endl;
                return;
            }
        }
    }
    a=path.substr(j);
    for(int i=0;i<100;++i){
        if(p->v[i] == 1 && p->child[i]->type == 2 && p->child[i]->name == a){
            if(way == "a"){
                p->child[i]->cent += dir;
            }
            if(dir == "r"){
                p->child[i]->cent = dir;
            }
            cout<<"write success"<<endl;
            return;
        }
    }
}

void Dir(){
    queue<files*> q;
    q.push(root);
    files* t;
    while(!q.empty()){
        t=q.front();q.pop();
        cout<<(t->name)<<" "<<(t->addr)<<" "<<(t->protect)<<" "<<(t->cent.size())<<endl;
        for(int i=0;i<100;++i){
            if(t->v[i] == 1)q.push(t->child[i]);
        }
    }
}
