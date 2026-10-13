#include <ros/ros.h>
#include <locale>

/*
    参数查询
        ros::NodeHandle-------------------------------------------
            Param(键,默认值)
                存在，返回对应结果，否则返回默认值
            
            getParm(键,存储结果的变量)
                存在，返回true，并将结果存储在变量中
                不存在，返回false，且不为变量设值

            getParamCached(键,存储结果的变量)--提高变量获取效率
                存在，返回true,并将值赋值给变量
                不存在，返回false,且不为变量设值

            getParamNames(std::vector<std::string>)
                获取所有的键，并存储在参数vector中
            
            hasParam(键)
                是否包含某个键，存在返回true, 否则返回false
            
            searchParam(被搜索的键，存储搜索结果的变量)
                搜索键
                
        ros::param------------------------------------------------
            与ros::NodeHandle的getParam()函数类似
        
*/


int main(int argc, char **argv)
{
    //设置编码
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"get_param");
    //创建ROS节点句柄
    ros::NodeHandle nh;

    //ros::NodeHandle-----------------------------------------
    //1.param
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius );
    //2.getParm
    double radius2 = 0.0;
    // bool result = nh.getParam("radiusXXX",radius2);
    //3.getParamCached 与 getParam()类似，只是提高变量获取效率，避免重复查询，但一般测试下看不出来效果
    bool result = nh.getParamCached("radius",radius2);
    if(result)
    {
        ROS_INFO("获取到的半径是：%.2f",radius2);
    }
    else
    {
        ROS_WARN("被查询的参数不存在");
    }
    //4.getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names)
    {
        ROS_INFO("遍历到的元素：%s",name.c_str());
    }
    //5.hasParam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("XXX");
    ROS_INFO("radius是否存在:%d,XXX是否存在:%d",flag1,flag2);
    //6.searchParam
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索到的键：%s",key.c_str());
    return 0;
}