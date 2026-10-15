#include <ros/ros.h>
#include "plumbing_head/hello.h"
#include <locale.h>

namespace hello_ns
{
    void MyHello::run()
    {
        ROS_INFO("hello world--run函数执行...");
    }
}

int main(int argc,char **argv)
{
    //设置编码
    setlocale(LC_ALL, "");
    ros::init(argc,argv,"hello_head");
    //代码调用
    hello_ns::MyHello myhello;
    myhello.run();

    return 0;
}
