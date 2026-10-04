#include <ros/ros.h>

int main(int argc, char **argv)
{
    //解决乱码
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "hello_vscode");
    ros::NodeHandle nh;

    ROS_INFO("Hello from VSCode!哈哈");

    ros::spin();
    return 0;
}