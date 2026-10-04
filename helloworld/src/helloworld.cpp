//1.包含ROS的头文件
#include <ros/ros.h>
//2.编写main函数
int main(int argc,char* argv[])
{
        //3.初始化ROS节点
        ros::init(argc,argv,"hello_node");
        //4.创建ROS节点句柄
        ros::NodeHandle n;
        //5.输出日志
        ROS_INFO("hello world!");
        return 0;
}
 
