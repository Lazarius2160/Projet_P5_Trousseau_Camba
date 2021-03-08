# Simulation when working on ROS Kinetic for DJI 
   
> Beware : If using DJI assistant or flight simulator, one needs to have the hardware plugged in (as the software is protected under some licences), whether the full UAV for the assistant, or just a controller for the flight simulator.  
<br>

Theses solutions works as an *HIL Hardware In The Loop* : "HIL testing is a technique where real signals from a controller are connected to a test system that simulates reality, tricking the controller into thinking it is in the assembled product." from [ni.com](https://www.ni.com/fr-fr/innovations/white-papers/17/what-is-hardware-in-the-loop-.html#section-1136066798).  
<br>

## General configuration : 

Configuration required : 
-	Ubuntu 16.04 (x86/ARM) at least (recommended for ROS kinetic)
-	ROS version : Kinetic 
-	Cmake version of at least 2.8.3 (to check use `cmake --version`)
-  Install C, C++ Compiler and Development Tools by installing build-essential


For the hardware part :
![dji](https://user-images.githubusercontent.com/76939787/109983703-5c30ad80-7d03-11eb-9a23-420aecdacf67.png)


## DJI assistant OSDK :

### General informations :
The Onboard Software Development Kit is for those who want to develop only softwares and rapidly prototype, it simulates the sensors on the robot which flies on an empty world.  
Indeed a simulator is integrated to the assistant or it is possible to connect the assistant with Gazebo for more functionnalities (see below).  
No need to have the company onboard computer, instead one can use a thrid party computer as explained [here](https://developer.dji.com/onboard-sdk/documentation/purchaseguide/hardware.html#onboard-computer).  
Is uses a native RQT GUI, may be used with Rviz (see below on the next section).  
> However, having a ready-made SDK also restricts the developer from many aspects, mostly by the assumptions made by product owner while configuring it.
   
### Drones which can be used :
All DJI Drones from M100, M210, ..., until M600 as well as others from different categories (Mavik etc).

### Sensors emulated :
Camera, odometry, altitude, inertia unit IMU, joint state. Navigate with GPS. Can be controlled with joysticks or keyboard.

### How it works :
Simulates the drone in the DJI assistant 2, visualize the informations and camera with an GUI.  
The drone is controlled with the controller provided with the drone.  

### Installation tutorial :
Make sure to have the configuration needed and follow [official tutorial](https://developer.dji.com/onboard-sdk/documentation/quickstart/development-environment.html#configure-ros-development-environment) or look at the [package on ROS.org](http://wiki.ros.org/dji_sdk) and follow the [tutorial](http://wiki.ros.org/dji_sdk/Tutorials/Getting%20Started).

### Testing :

Impossible to do without the drone.


**To get more capacites, it is possible to use the Gazebo simulator**  
<br>

## DJI_M100 GitHUb version adding Gazebo

### General configuration :
Configuration required :
Same as before plus :
-	Gazebo 7 or more (to check use `gazebo --version`)


#### General informations :
The DJI M100 is a quadrotor drone which needs a kinetic ROS version to work with hector_quadrotor. However the simulation can be done on Melodic (just need to add a pluging to hector).  
It can work in collision free mode, be piloted (joystick or keyboard) or given a nav goal on Rviz. Hence,it needs Rviz to work with dji_m100_description.  
<br>
Customisable : some worlds are already integrated (collision sphere, search and rescue...).  
Some features are already included : Landing, take-off, send goal.  
Launch file as examples for the Gazebo simulation are already implemented.
   
### Sensors emulated :
Camera, odometry, altitude, inertia unit IMU, joint state. Navigate with GPS and more. The advantage of havn=ing Gazebo is that a wide range of sensors is available.

### How it works :
Simulate the drone in Gazebo and visualize informations through Rviz.  
The DJI_m100_controller class represents the DJI M100 hardware in Gazebo for the gazebo_ros_control plugin using SITL.  
The drone would be piloted through a logitech_gamepad.launch or xbox_controller.launch for the Xbox gamepads controllers. To controll it with the keyboard need to launch :
   `python hector_keyboard_teleop/src/hector_keyboard_teleop.py` 
And move it with : w - Forward, a - Left, s - Reverse, d - Right, z - Climb up, c - Climb down, . - Stop

### Installation tutorial :

   1. Clone this repository with the good branch in your catkin/src folder 
     `git clone -b ROS_kinetic_gazebo https://github.com/Lazarius2160/Projet_P5_Trousseau_Camba/`

   2. Give the execution permission to the install file
      `chmod +x Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`

   3. Still in your catkin/src folder, launch the install file
      `sh Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`

   4. This should take quite some times due to the catkin_make, when its done try it
      `roslaunch dji_m100_gazebo simulate.launch`
      
### Testing :
To test if the hector quadrotor works fine using Gazebo and DJI assistant, try `roslaunch hector_quadrotor_demo outdoor_flight_gazebo.launch`, somertimes, it needs to have the motor enable manually `rosservice call /enable_motors "enable: true` .  
> The drone needs to be plugged in !

## To conclude :
This solution is pretty easy to use and rather user-friendly, however the software cannot be changed for experimentations hence this solution is not flexible enough for such a project. But may be usefull for training and experimenting the first drone fly.
