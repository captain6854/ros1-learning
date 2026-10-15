#include <ros/ros.h>
#include "plumbing_head_src/hello.h"
#include <locale.h>

int main(int argc,char **argv)
{
    //设置编码
    setlocale(LC_ALL, "");
    ros::init(argc,argv,"use_hello");
    //代码调用
    hello_ns::MyHello myhello;
    myhello.run();
    
    return 0;
}