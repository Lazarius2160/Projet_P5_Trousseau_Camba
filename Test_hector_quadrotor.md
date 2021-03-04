
# Testing ROS hector_quadrotor package with Gazebo simulator (have been tested with TheConstruct)

## Introduction :
Hector is a collection of ROS stacks (a stack is a collection of packages that provides a
functionality).
These stacks supply several tools to simulate or to interact with robots (SLAM, location
or modelling...)
In this collection, the hector quadrotor stack is able to moderate (with the physical parameters) a 3D quadrotor model in Gazebo and to have a 3D reconstruction of the world with
a SLAM tool.

### General configuration:
- ROS melodic
- Ubuntu 16.04 at least  


## hector package : 


### Installation :
1. To get hector_quadrator packages that work on melodic, I used this tutorial **[hector tutorial](https://github.com/basavarajnavalgund/hector-quadrotor).**

Considering that you already have created your ROS workspace, clone the following packages in the "src" folder :
> git clone -b kinetic-devel https://github.com/tu-darmstadt-ros-pkg/hector_quadrotor

> git clone -b catkin https://github.com/tu-darmstadt-ros-pkg/hector_localization

> git clone -b kinetic-devel https://github.com/tu-darmstadt-ros-pkg/hector_gazebo

> git clone -b kinetic-devel https://github.com/tu-darmstadt-ros-pkg/hector_models

> git clone -b catkin https://github.com/tu-darmstadt-ros-pkg/hector_slam

2. These are others packages that are required, in particular in order to use a controller : 
> sudo apt-get install ros-melodic-geographic-info

> sudo apt-get install ros-melodic-ros-control

> sudo apt-get install ros-melodic-gazebo-ros-control

> sudo apt-get install ros-melodic-joy

> sudo apt-get install ros-melodic-teleop-twist-keyboard


3. Then go back to your workspace to compile. As I used TheConstruct, I compiled with :  
> catkin_make

And source the workspace :

> source devel/setup.bash 

### ROS architecture :

Here is a schema that helps to understand how to control the drone within the simulation. For simulation only you just need the ROS block (using hector packages and gazebo). 
The connection to ArduCopter through MAVlink showed here were used to link it with a real drone as well.
<br>
![ros_node_simulation_hector](https://user-images.githubusercontent.com/47387835/109682712-91f45b80-7b76-11eb-8c2b-fbd4d721ede6.PNG)
<br>

The control would be done through a script (the Simulation blue block) that would publish inside the /cmd_vel topic (control the speed of the drone) and subscribe to the /poseupdate one to get the new position.


### Testing : 

1. To start the demo with an already defined map and the slam functionalities use : 
> roslaunch hector_quadrotor_demo indoor_slam_gazebo.launch

or
> roslaunch hector_quadrotor_demo outdoor_flight_gazebo.launch

2. Before beeing able to control the drone you need to enable the motors :
> rosservice call /enable_motors "enable: true"

3. You can start to control the drone with your keyboard using :
> rosrun teleop_twist_keyboard teleop_twist_keyboard.py

Here is the rqt graph after having started the demo : 
![rosgraph_hector_quadrotor](https://user-images.githubusercontent.com/47387835/109857762-ef5dda80-7c52-11eb-8ede-f93b0a7233c5.png)