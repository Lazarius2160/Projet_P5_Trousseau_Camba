# Projet_P5_Trousseau_Camba


## Simulation when working on ROS Kinetic for DJI 
   
   FOR THE TWO SOLUTIONS HERE, NEED TO HAVE THE REAL DRONE TO BE PLUGED TO, SO THE SIMULATION CAN WORK PROPERLY.\
   Because it works as an *HIL Hardware In The Loop* : "HIL testing is a technique where real signals from a controller are connected to a test system that simulates reality, tricking the controller into thinking it is in the assembled product." from [ni.com](https://www.ni.com/fr-fr/innovations/white-papers/17/what-is-hardware-in-the-loop-.html#section-1136066798).
   
   For this project the *Software In the Loop* method must be priviledge as it "characterizes a numerical simulation of the operation of the software of an embedded system during which the entire environment, including the hardware part of the embedded system, is simulated." from [wikidictionnary](https://fr.wiktionary.org/wiki/software-in-the-loop), because it normally has to be done prior to the HIL.\
   Hence, when using OSDK to develop the application (solution 2), developers need to purchase a drone and an onboard computer.


### General configuration : 

Configuration required : 
-	Ubuntu 16.04 (x86/ARM)
-	ROS version : Kinetic 
-	Cmake version of at least 2.8.3 (to check use `cmake --version`)
-  Install C, C++ Compiler and Development Tools by installing build-essential


#### DJI Drones (M100, M210, ..., M600) with the DJI assistant OSDK
1. General informations

   Onboard Software Development Kit for those who want to develop only software and rapidly prototype, it simulates the sensors on the robot which flies on an empty world.\
   No need to have the company onboard computer, instead one can use a thrid party computer as explained [here](https://developer.dji.com/onboard-sdk/documentation/purchaseguide/hardware.html#onboard-computer). \
   Simulator integrated to the assistant or possible to contect it with Gazebo for more functionnalities. \
   Use a RQT GUI by itself, may be used with Rviz (see below on the next section). \
   However, having a ready-made SDK also restricts the developer from many aspects, mostly by the assumptions made by product owner while configuring it.
   
2. Sensors emulated

   Camera, odometry, altitude, inertia unit IMU, joint state. Navigate with GPS. Can control through joysticks, keyboard.

3. How it works 

   Simulate the drone in the DJI assistant 2, visualize the informations and camera with an RQT GUI.\
   The drone would then be piloted through the UAV provided with the drone. \

4. Installation tutorial

Make sure to have the configuration needed and follow [official tutorial](https://developer.dji.com/onboard-sdk/documentation/quickstart/development-environment.html#configure-ros-development-environment) or look at the [package on ROS.org](http://wiki.ros.org/dji_sdk) and follow the [tutorial](http://wiki.ros.org/dji_sdk/Tutorials/Getting%20Started).
      
5. Testing 

   Impossible to do without the drone.


### To get more capacites, it is possible to use the Gazebo simulator 

Configuration required :\
Same as before plus :
-	Gazebo 7 or more (to check use `gazebo --version`)


#### DJI_M100 GitHUb version
1. General informations

   The DJI M100 is a quadrotor drone which needs a kinetic ROS version to work with hector_quadrotor. However the simulation can be done on Melodic (just need to add a pluging to hector).\   
   Able to work in collision free mode, can be piloted (joystick or keyboard) or given a nav goal on Rviz. Hence,it needs Rviz to work with dji_m100_description.
\      
   Customisable : some worlds already integrated (collision sphere, search and rescue...).\      
   Some features already included : Landing, take-off, send goal.\      
   Switching to ROS Melodic is possible if a plugin to convert hector_quadrotor is used.\      
   Launch file as examples for the Gazebo simulation.
   
2. Sensors emulated

   Camera, odometry, altitude, inertia unit IMU, joint state. Navigate with GPS.

3. How it works 

   Simulate the drone in Gazebo and visualize informations through Rviz.\
   The DJI_m100_controller class represents the DJI M100 hardware in Gazebo for the gazebo_ros_control plugin using SITL.\
   The drone would then be piloted through a logitech_gamepad.launch or xbox_controller.launch for the Xbox gamepads controllers. To controll it with the keyboard     need to launch :
   `python hector_keyboard_teleop/src/hector_keyboard_teleop.py` 
   And move it with : w - Forward, a - Left, s - Reverse, d - Right, z - Climb up, c - Climb down, . - Stop

4. Installation tutorial

   1. Clone this repository with the good branch in your catkin/src folder 
     `git clone -b ROS_kinetic_gazebo https://github.com/Lazarius2160/Projet_P5_Trousseau_Camba/`

   2. Give the execution permission to the install file
      `chmod +x Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`

   3. Still in your catkin/src folder, launch the install file
      `sh Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`

   4. This should take quite some times due to the catkin_make, when its done try it
      `roslaunch dji_m100_gazebo simulate.launch`
      
5. Testing 

   To test if the hector quadrotor works fine, try `roslaunch hector_quadrotor_demo outdoor_flight_gazebo.launch`, somertimes, it needs to have the motor enable manually `rosservice call /enable_motors "enable: true` 
   
   
