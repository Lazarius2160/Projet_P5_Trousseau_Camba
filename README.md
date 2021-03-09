# Projet_P5_Trousseau_Camba

## What we did :
In this branch you'll see the two solutions we choose working on ROS Melodic : 
- using ArduPilot, a flight controller, with SITL as a native simulator, where we tried to add ROS and/or Gazebo,
- and hector quadrotor metapackage with Gazebo and ROS.  
<br>

These two solutions were intrinsically different as their architectures are different : **_one is a ROS metapackage which navigates thanks to ROS nodes and the other a flight controller which flies thanks to the MAVLink protocol._**

You will find explanations, tutorial and testing on "Test_ardupilot.md" and "Test_hector_quadrotor.md".  
In the launch file, a .launch file for the simulation for hector and a .md for the commands to install Ardupilot and everything needed for this solution.

