#ifndef TURTLESIM_KINEMATICS_H
#define TURTLESIM_KINEMATICS_H

#include <ros/ros.h>
#include <turtlesim/Pose.h>

class TurtlesimKinematics
{
    public:
        TurtlesimKinematics();
        void turtle1PoseCallBack(const turtlesim::Pose& pose);
        void turtle2PoseCallBack(const turtlesim::Pose& pose);

    private:
        ros::NodeHandle nh_;
        ros::Subscriber turtle1_pose_sub;
        ros::Subscriber turtle2_pose_sub;
        turtlesim::Pose last_turtle1_pose;
        turtlesim::Pose last_turtle2_pose;
};

#endif