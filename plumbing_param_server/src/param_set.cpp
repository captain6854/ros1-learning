#include <ros/ros.h>
#include <locale>

/*
    实现对参数的新增与修改
    需求：首先设置机器人的共享参数，类型、半径（0.15m）
         再修改半径（0.2m）
    实现：
        （两套API）
        ros::NodeHandle nh;
            setParm(键,值)
        ros::param
             set(键,值)
    修改：只需要再次调用setParam()或set()函数，存在就覆盖，不存在就新增。
*/

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    //初始化ROS节点
    ros::init(argc,argv,"set_param");
    //创建ROS节点句柄
    ros::NodeHandle nh;
    //参数增----------------------
    //方案1：nh
    nh.setParam("type","xiaoHuang");
    nh.setParam("radius",0.15);
    //方案2：ros::param
    ros::param::set("type_param","xiaoBai");
    ros::param::set("radius_param",0.15);
    //参数改(实际上就是对原来参数的覆盖)----------------------
    //方案1：nh
    nh.setParam("radius",0.2);
    //方案2：ros::param
    ros::param::set("radius_param",0.2);
    return 0;
}