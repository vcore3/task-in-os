#pragma once
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

struct files {
    string name;
    int type;
    int state;
    int addr;
    string protect;
    string cent;
    files* child[100];
    int v[100];
};

struct user {
    string name, password;
    files * root;
    user * front;
    user * next = NULL;
};


user muser;

files * root;
user * now;

int ad[100];