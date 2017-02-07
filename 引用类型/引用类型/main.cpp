//
//  main.cpp
//  引用类型
//
//  Created by mac on 16/3/2.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <iostream>
//using namespace std;

int main(){
    //char name[20];
    //cout<<"Hello!What's your name ?\n";
    //cin>>name;
    //cout<<name<<",Welcome to learn OPP using c++!"<<endl;
    char *name;
    name=new char[10];
    if (!name) {
        std::cout<<"out of memory"<<std::endl;
        return 1;
    }else{
        std::cout<<"input your name!\n";
        std::cin>>name;
        std::cout<<name<<std::endl;
        delete []name;
        return 0;
    }
    return 0;
}