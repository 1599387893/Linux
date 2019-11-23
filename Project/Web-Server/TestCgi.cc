#include<iostream>
#include<string>
#include"Util.hpp"
using namespace std;

//------------------该CGI程序执行简单的运算----------------------

int main()
{
    cerr<<" -----------------------Welcome To CGI----------------"<<endl;

    string param;
    string data1;
    string data2;
    int num1,num2;
    
   // cin>>param;
    //通过环境变量接收
    //通过父进程write
    auto pos = param.find('&');
    data1 = param.substr(0,pos);
    data2 = param.substr(pos);

    num1 = Util::StringToInt(data1);
    num2 = Util::StringToInt(data2);

    cout<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
    cout<<num1<<" - "<<num2<<" = "<<num1-num2<<endl;
    cout<<num1<<" * "<<num2<<" = "<<num1*num2<<endl;
    cout<<num1<<" / "<<num2<<" = "<<num1/num2<<endl;

    cerr<<"data1: "<<data1<<endl;
    cerr<<"data2: "<<data2<<endl;
    cerr<<"num1: "<<num1<<endl;
    cerr<<"num2: "<<num2<<endl;

    return 0;
}
