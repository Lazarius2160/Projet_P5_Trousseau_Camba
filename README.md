# Projet_P5_Trousseau_Camba

## Simulation when working on ROS Kinetic 

### Using Gazebo simulator 

Configuration required : 
-	Ubuntu 16.04 (x86/ARM)
-	ROS version : Kinetic 
-	Gazebo 7 or more (to check with gazebo --version)
-	cmake version of at least 2.8.3 (to check with cmake --version)
-	a developping tool to code with C, C++

1. DJI_M100
Need a kinetic ROS version to work with hector_quadrotor.

Installation tutorial: 
..1. Clone this repository with the good branch in your catkin/src folder 

`git clone -b ROS_kinetic_gazebo https://github.com/Lazarius2160/Projet_P5_Trousseau_Camba/`

..2. Give the execution permission to the install file
`chmod +x Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`

..3. Still in your catkin/src folder, launch the install file
`sh Projet_P_Trousseau_Camba/bin/install_kinetic_gazebo_m100.sh`
..4. This should take quite some times due to the catkin_make, when its done try it !
`roslaunch dji_m100_gazebo simulate.launch`
