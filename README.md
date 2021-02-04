# Projet_P5_Trousseau_Camba

## Simulation when working on ROS Kinetic 

### Using Gazebo simulator 

Configuration required : 
-	Ubuntu 16.04 (x86/ARM)
-	ROS version : Kinetic 
-	Gazebo 7 or more (to check use `gazebo --version`)
-	cmake version of at least 2.8.3 (to check use `cmake --version`)
-	a developping tool to code with C, C++
- Need Rviz

#### DJI_M100
1. General informations:

   The DJI M100 is a quadrotor drone which needs a kinetic ROS version to work with hector_quadrotor. However the simulation can be done on Melodic (just need to add a pluging to hector).
   Able to work in collision free mode, can be piloted or given a nav goal on rviz.
   Customisable : some worlds already integrated (collision sphere, search and rescue...).
   SWitching to ROS Melodic is possible if a plugin to convert hector_quadrotor is used.

2. How it works :

   Simulate the drone in Gazebo and visualize informations through Rviz.
   The DJI_m100_controller class represents the DJI M100 hardware in Gazebo for the gazebo_ros_control plugin during SITL.
   The drone would then be piloted through a logitech_gamepad.launch or xbox_controller.launch for the Xbox gamepads controllers. To controll it with the keyboard     need to launch :
   `python hector_keyboard_teleop/src/hector_keyboard_teleop.py` 
   And move it with : w - Forward, a - Left, s - Reverse, d - Right, z - Climb up, c - Climb down, . - Stop

3. Installation tutorial: 

   1. Clone this repository with the good branch in your catkin/src folder 
     `git clone -b ROS_kinetic_gazebo https://github.com/Lazarius2160/Projet_P5_Trousseau_Camba/`

   2. Give the execution permission to the install file
      `chmod +x Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`

   3. Still in your catkin/src folder, launch the install file
      `sh Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`

   4. This should take quite some times due to the catkin_make, when its done try it
      `roslaunch dji_m100_gazebo simulate.launch`
