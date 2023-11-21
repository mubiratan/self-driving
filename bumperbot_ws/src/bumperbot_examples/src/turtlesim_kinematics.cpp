#include "bumperbot_examples/turtlesim_kinematics.h"

TurtlesimKinematics::TurtlesimKinematics()
{
    turtle1_pose_sub = nh_.subscribe("/turtle1/pose", 1000, &TurtlesimKinematics::turtle1PoseCallBack, this);
    turtle2_pose_sub = nh_.subscribe("/turtle2/pose", 1000, &TurtlesimKinematics::turtle1PoseCallBack, this);
}

void TurtlesimKinematics::turtle1PoseCallBack(const turtlesim::Pose& pose)
{
    last_turtle1_pose = pose;
}

void TurtlesimKinematics::turtle2PoseCallBack(const turtlesim::Pose& pose)
{
    last_turtle2_pose = pose;

    float Tx = last_turtle2_pose.x - last_turtle1_pose.x;
    float Ty = last_turtle2_pose.y - last_turtle1_pose.y;

    ROS_INFO_STREAM("------------------------------\n" <<
                    "Translation Vector turtle1 > turtle2 \n" <<
                    "Tx: " << Tx << "\n" <<
                    "Ty: " << Ty << "\n");
}