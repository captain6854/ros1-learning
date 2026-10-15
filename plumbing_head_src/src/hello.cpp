#include <ros/ros.h>
#include "plumbing_head_src/hello.h"

namespace hello_ns
{
    void MyHello::run()
    {
        ROS_INFO("hello world--源文件中的run函数执行...");
    }
}