#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "simple_publisher_cpp");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::String>("chatter", 10);
    ros::Rate rate(10);
    int count = 0;

    //ROS_INFO("Simple Publisher 1");

    while (ros::ok())
    {
        //ROS_INFO("Simple Publisher 2");
        
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello world from C++ " << count;
        msg.data = ss.str();
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
        ++count;
    }
    
    return 0;
}