#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <locale.h>
/* 
    发布方实现：
        1.包含头文件；
          ROS中的文本类型要包含头文件---> <std_msgs/String.h>
        2.初始化ROS节点;
        3.创建节点句柄;
        4.创建发布者对象；
        5.编写发布逻辑并发布数据.


*/


int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    // 2.初始化ROS节点;
    ros::init(argc, argv, "publisher_node");
    // 3.创建节点句柄;
    ros::NodeHandle nh;
    // 4.创建发布者对象;
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",10);
    // 5.编写发布逻辑并发布数据.
    //要求以10Hz的频率发布数据，并且文本后添加编号
    //先创建被发布的消息
    std_msgs::String msg;
    // 发布频率
    ros::Rate rate(10);
    //设置编号
    int count = 0;
    //编写循环，循环中发布数据
    while(ros::ok())//节点不死
    {
        count++;

        //msg.data = "hello";
        //实现字符串拼接数字
        std::stringstream ss;
        ss << "hello ---> " << count;
        msg.data = ss.str();
        pub.publish(msg);
        //添加日志;
        ROS_INFO("发布的数据是：%s",ss.str().c_str());
        //休眠，按照发布频率10Hz
        rate.sleep();
        ros::spinOnce(); //官方建议，处理回调函数
    }
    return 0;
}
