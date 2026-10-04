#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Float64.h>

#include <algorithm>
#include <limits>

namespace my_robot {

class ObstacleWatcher {
 public:
  ObstacleWatcher() : nh_(), pnh_("~") {
    pnh_.param("threshold", threshold_, 0.5);          // 读 ~threshold 参数
    sub_ = nh_.subscribe("scan", 10, &ObstacleWatcher::onScan, this);
    pub_ = nh_.advertise<std_msgs::Float64>("min_range", 10);
    timer_ = nh_.createTimer(ros::Duration(1.0), &ObstacleWatcher::onTimer, this);
  }

 private:
  void onScan(const sensor_msgs::LaserScan::ConstPtr& msg) {
    if (msg->ranges.empty()) return;
    last_min_ = *std::minmax_element(msg->ranges.begin(), msg->ranges.end()).first;
  }

  void onTimer(const ros::TimerEvent&) {
    std_msgs::Float64 out;
    out.data = last_min_;
    pub_.publish(out);
    if (last_min_ < threshold_) {
      ROS_WARN_STREAM("obstacle at " << last_min_ << " m");
    }
  }

  ros::NodeHandle nh_, pnh_;
  ros::Subscriber sub_;
  ros::Publisher pub_;
  ros::Timer timer_;
  double threshold_{0.5};
  double last_min_{std::numeric_limits<double>::infinity()};
};

}  // namespace my_robot

int main(int argc, char** argv) {
  ros::init(argc, argv, "obstacle_watcher");   // 必须在任何 NodeHandle 之前
  my_robot::ObstacleWatcher node;
  ros::spin();
  return 0;
}
