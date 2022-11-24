#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include "sensor_msgs/Image.h"

int state = 0;
ros::ServiceClient client;

//Callback Function to Subscriber for Image data

void drive_robot(float lin_x, float ang_z){

    ball_chaser::DriveToTarget srv;

    srv.request.x =  lin_x;
    srv.request.z =  ang_z;

    try{
        client.call(srv);
    } catch(std::exception &exc){
        ROS_ERROR("Failed to call service command_bot");
    }
    
}

void process_image_callback(const sensor_msgs::Image img){
    int white_pixel = 255;
    int position;
    float x, z = 0;

    for(int i = 0; i < img.height*img.step; i++){
        if(img.data[i] == 255){
            position = (int)(i/img.height);
            ROS_INFO_STREAM("Found white ball");
            break;
        }
    }

    if(position<=(img.step/3)){
        x = 0.5;
        z = -0.5;
    }
    if(position>(img.step/3) && (position<=2*img.step/3)){
        x = 0.5;
        z = -0.5;
    }
    if((position>(2*img.step/3)) && (position <= img.step)){
        x = 0.5;
        z = -0.5;
    }

    // Move the robot based off the state
    drive_robot(x, z);
}

int main(int argc, char** argv){
    // ROS initialisation
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Defining the client for the drive bot server
    client = n.serviceClient<ball_chaser::DriveToTarget>("ball_chaser/command_robot");

    // Subscribing to camera images
    ros::Subscriber image_sub = n.subscribe("/camera/rgb/image_raw",10, process_image_callback);

    //Handling ROS communication events
    ros::spin();

    return 0;
}
