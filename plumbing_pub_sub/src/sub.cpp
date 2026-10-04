#include <ros/ros.h>
#include <std_msgs/String.h>
#include <locale.h>
/*
    订阅方实现：
        1.包含头文件;
            （传递消息的载体）ROS中的文本类型要包含头文件 ---> std_msgs/String.h
        2.初始化ROS节点；
        3.创建节点句柄；
        4.创建订阅者对象；
        5.处理订阅到的数据。
        6.spin()函数
*/

void doMsg(const std_msgs::String::ConstPtr &msg)
{
    //通过msg这个参数获取并操作订阅到的数据
    ROS_INFO("订阅到的数据是：%s",msg->data.c_str());
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    // 2.初始化ROS节点；
    ros::init(argc, argv, "subscriber_node");
    // 3.创建节点句柄；
    ros::NodeHandle nh;
    // 4.创建订阅者对象；
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter",10,doMsg);
    // 5.处理订阅到的数据。

    ros::spin(); //循环回调函数，处理订阅到的数据

    return 0;
}