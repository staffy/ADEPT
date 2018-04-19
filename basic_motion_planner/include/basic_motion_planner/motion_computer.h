#ifndef MOTION_COMPUTER_H
#define MOTION_COMPUTER_H

#include <ros/ros.h>

#include <cmath>
#include <queue>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Pose.h>

#include <basic_motion_planner/laserscan_to_pointcloud.h>

class MotionComputer {
private:
    LaserScanToPointCloud laserScanToPointCloud;

    sensor_msgs::LaserScan laser_scan;
    bool acquired_scan;

    std::queue<sensor_msgs::LaserScan> scan_queue;
    std::queue<geometry_msgs::Pose> pose_queue;

    // Subscriber:
    ros::Subscriber scan_sub;
    ros::Subscriber pose_sub;

    void scanCallBack(const sensor_msgs::LaserScan::ConstPtr &scan);
    void poseCallBack(const geometry_msgs::Pose::ConstPtr &pose);

public:
    MotionComputer(ros::NodeHandle &nh);
    bool computeMotion();
};

#endif //MOTION_COMPUTER_H
