//
//  main.cpp
//  sizeofTest
//
//  Created by xubingZhang on 8/6/16.
//  Copyright © 2016 xubingZhang. All rights reserved.
//

#include <iostream>

using namespace std;

class Base {
public:
    int func(){return 0;};
};

class Base2 {
    
    
public:
    int m_num;
};

class Son:public Base {
    
    
};

class Son1:public Base2 {
    
};

class SonFunc :public Base {
    
    
public:
    int func();
};

int SonFunc::func(){
    return 0;
}

    //struct  由于对齐规则
typedef struct{
    int i;
    short s;
    int i2;
    short s2;
} Struc1;

typedef struct{
    short s;
    short s2;
    int i;
    int i2;
    
} Struc2;

typedef struct{
    short s;
    short s2;
    int i;
    int i2;
    char c;
    
} Struc3;

typedef struct{
   
} Struc4;


int funInt(){
    cout<<"funInt call";
    return 0;
}
char funChar(){
    cout<<"funChar call";
    return '0';
}
double funDouble(){
    cout<<"funDouble call";
    return (double)0.2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
        //int
    cout<<"int size:"<<sizeof(int)<<endl;
    int i = 0;
    cout<<"int i size:"<<sizeof(i)<<endl;
    
        //array
    int intArray[16];
    cout<<"int array size:"<<sizeof(intArray)<<endl;
    cout<<"int array size:"<<sizeof(&intArray)<<endl;//8 ->pointer
    char n[] = "abc";
    cout<<"char array size:"<<sizeof(n)<<endl;
    
        //pointer 指针是用来记录另一个对象的地址，所以指针的内存大小当然就等于计算机内部地址总线的宽度。
    char *pchar = new char[1];
    cout<<"char pointer size:"<<sizeof(pchar)<<endl;
    int *pint = new int[1];
    cout<<"int pointer size:"<<sizeof(pint)<<endl;
    
        //struct
    cout<<"sturct1 size:"<<sizeof(Struc1)<<endl;
    cout<<"sturct2 size:"<<sizeof(Struc2)<<endl;
    cout<<"sturct3 size:"<<sizeof(Struc3)<<endl;
    cout<<"sturct4 size:"<<sizeof(Struc4)<<endl; //1
    
    //class
    cout<<"class Base size:"<<sizeof(Base)<<endl;
    Base bObj;
    cout<<"Object Base size:"<<sizeof(bObj)<<endl;
    cout<<"class Base2 size:"<<sizeof(Base2)<<endl;
    Base2 bObj2;
    cout<<"Object Base2 size:"<<sizeof(bObj2)<<endl;
    
    cout<<"class Son size:"<<sizeof(Son)<<endl;
    cout<<"class Son1 size:"<<sizeof(Son1)<<endl;
    cout<<"class SonFunc size:"<<sizeof(SonFunc)<<endl;
    
        //function sizeof也可对一个函数调用求值，其结果是函数返回值类型的大小，函数并不会被调用
        //但是不可以对返回值类型为空的函数求值。
        //对有参数的函数，在用sizeof时，须写上实参表
//    funInt();
    cout<<"Function funInt size:"<<sizeof(funInt())<<endl;
    cout<<"Function funChar size:"<<sizeof(funChar())<<endl;
    cout<<"Function funDoubleu y size:"<<sizeof(funDouble())<<endl;
    
    return 0;
}
