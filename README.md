# ROS Packages for Hunter Mobile Base

## Packages

* hunter_bringup: launch and configuration files to start ROS nodes 
* hunter_base: a ROS wrapper around Hunter SDK to monitor and control the robot
* hunter_msgs: scout related message definitions
* (hunter_robot: meta package for the Hunter robot ROS packages)

## Basic Usage

1. Install dependent ROS packages

    ```
    $ sudo apt install ros-melodic-controller-manager
    $ sudo apt install ros-melodic-teleop-twist-keyboard
    ```

    Change ros-melodic-* in the command to ros-kinetic-* if you're using ROS Kinetic.

2. Clone the packages into your catkin workspace and compile

    (the following instructions assume your catkin workspace is at: ~/catkin_ws/src)

    ```
    $ cd ~/catkin_ws/src
    $ git clone https://github.com/CosCJ/hunter_ros.git
    $ cd ..
    $ catkin_make
    ```
3. Scout communication mode
    
    ３．1. Can port communication
    
    Two scripts inside the "~/catkin_ws/src/hunter_base/src/hunter_sdk/scripts" folder are provided for easy setup. 
    
    * If you're using can for the first time
             
          $ cd ~/catkin_ws/src/hunter_base/src/hunter_sdk/scripts
          $ ./setup_can2usb.bash
          
    * If you have used can communication normally
    
      (bring up the device each time you unplug and re-plug the adapter)
          
          $ cd ~/catkin_ws/src/hunter_base/src/hunter_sdk/scripts
          $ ./bringup_can2usb.bash
          
3. Launch ROS nodes
 
* Start the base node 

    ```
    $ roslaunch hunter_bringup hunter_minimal.launch
    ```
* Start the keyboard tele-op node

    ```
    $ roslaunch hunter_bringup hunter_teleop_keyboard.launch
    ```
