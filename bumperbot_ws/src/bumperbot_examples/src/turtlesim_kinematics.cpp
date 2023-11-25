#include "bumperbot_examples/turtlesim_kinematics.h"

TurtlesimKinematics::TurtlesimKinematics()
{
    turtle1_pose_sub = nh_.subscribe("/turtle1/pose", 1000, &TurtlesimKinematics::turtle1PoseCallBack, this);
    turtle2_pose_sub = nh_.subscribe("/turtle2/pose", 1000, &TurtlesimKinematics::turtle2PoseCallBack, this);
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

    float theta_rad = last_turtle2_pose.theta - last_turtle1_pose.theta;   
    float theta_deg = 180 * theta_rad / 3.14; 

    ROS_INFO_STREAM("------------------------------------\n" <<
                    "Translation Vector turtle1 -> turtle2 \n" <<
                    "Tx: " << Tx << "\n" <<
                    "Ty: " << Ty << "\n" <<
                    "Rotation Matrix turtle1 -> turtle2 \n" << 
                    "theta (rad): " << theta_rad << "\n" <<
                    "theta (deg): " << theta_deg << "\n" <<
                    "|R11   R12|:  |" << std::cos(theta_rad) << "\t" << -std::sin(theta_rad) << "|\n" <<
                    "|R21   R22|   |" << std::sin(theta_rad) << "\t\t" << std::cos(theta_rad) << "|\n");
}