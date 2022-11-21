#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"

ros::Publisher motor_command_publisher;

bool move_robot(ball_chaser::DriveToTargetRequest& req, ball_chaser::DriveToTargetResponse& res){

    ROS_INFO("DriveToTarget Request Recieved. Commands: -Linear X: %f, Angular z: %f", float(req.x), float(req.z));

    geometry_msgs::Twist commands;

    commands.linear.x = req.x;
    commands.angular.z = req.z;

    motor_command_publisher.publish(commands);

    //Wait for goal to be reached
    ros::Duration(3).sleep();

    res.msg_feedback = "The goal has been reached.";
    ROS_INFO_STREAM(res.msg_feedback);

    return true;

}

int main(int argc, char **argv){
    ros::init(argc, argv, "drive_bot");

    ros::NodeHandle n;

    motor_command_publisher = n.advertise<geometry_msgs::Twist>("cmd_vel", 10);
    
    ros::ServiceServer service = n.advertiseService("ball_chaser/command_robot", move_robot);

    ROS_INFO("Sending coordinates...");

    ros::spin();

    return 0;
}