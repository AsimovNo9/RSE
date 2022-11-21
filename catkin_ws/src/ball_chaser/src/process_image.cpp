#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include "sensor_msgs/Image.h"


ros::ServiceClient client;

//Callback Function to Subscriber for Image data

void move_robo_boy(int &state){

    ball_chaser::DriveToTarget srv;

    if(state == 1){
        ROS_INFO_STREAM("Moving the robot to the left");
        srv.request.x =  1.0;
        srv.request.z =  -0.5;
    }
    else if (state == 2){
        ROS_INFO_STREAM("Moving the robot to the right");
        srv.request.x =  1.0;
        srv.request.z =  0.5;
    }
    else{
        ROS_INFO_STREAM("Moving the robot forward");
        srv.request.x =  1.0;
        srv.request.z =  0.0;
    }

    try{
        client.call(srv);
    } catch(std::exception &exc){
        ROS_ERROR("Failed to call service command_bot");
    }
    
}

void see_ball(const sensor_msgs::Image img){
    bool is_white = false;

    int state = 0;


    for(int i = 0; i< img.height; i++){
        for(int j = 0; j < img.step;j++){
            if(img.data[j] == 255){

                //Check if the white pixel is located at the left 
                if((j>0) && j<(img.step/3)){
                    state = 1;
                    break;
                }

                //Check if the white pixel is located at the center
                if(j> (img.step/3) && j<(2*img.step/3)){
                    state = 0;
                    break;
                }

                //Check if the white pixel is located at the right
                if(j> (2*img.step/3) && j<(img.step)){
                    state = 2;
                    break;
                }
            }
        }
        break;
    }

    // Move the robot based off the state
    move_robo_boy(state);
}

int main(int argc, char** argv){
    // ROS initialisation
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Defining the client for the drive bot server
    client = n.serviceClient<ball_chaser::DriveToTarget>("ball_chaser/command_robot");

    // Subscribing to camera images
    ros::Subscriber image_sub = n.subscribe("/camera/rgb/image_raw",10, see_ball);

    //Handling ROS communication events
    ros::spin();

    return 0;
}