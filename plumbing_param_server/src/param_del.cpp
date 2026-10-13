#include <ros/ros.h>
#include <locale>

/*
    参数删除
    实现：
        ros::NodeHandle-------------------------------------------
            deleteParam()
        ros::param------------------------------------------------
            del()
*/

int main(int argc,char **argv)
{
    //设置编码
    setlocale(LC_ALL, "");
    
    ros::init(argc,argv,"param_del");
    ros::NodeHandle nh;

    //删除：NodeHandle
    bool flag1 = nh.deleteParam("radius");
    if(flag1)
    {
        ROS_INFO("删除成功");
    }
    else 
    {
        ROS_WARN("删除失败");
    }
    
    //删除：param
    bool flag2 = ros::param::del("radius_param");
    if(flag2)
    {
        ROS_INFO("删除成功");
    }
    else 
    {
        ROS_WARN("删除失败");
    }

    return 0;
}