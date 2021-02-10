# Projet_P5_Trousseau_Camba

## Introduction

The goal of this 4-weeks project is to make a state of the art of the simulator avaible on the drone market now and try out some solution. 

For this project, the *Software In the Loop* method must be priviledge as it "characterizes a numerical simulation of the operation of the software of an embedded system during which the entire environment, including the hardware part of the embedded system, is simulated." from [wikidictionnary](https://fr.wiktionary.org/wiki/software-in-the-loop), because it normally has to be done prior to the HIL.\
The focus will be on simulators ROS friendly. Mostly using Melodic, as well as Kinetic if needed.


The previous project worked with : 
- RotorS, in ROS Kinetic with various Drones on Gazebo,
- BebopS, a fork of RotorS which works with Parrot 2 only on Gazebo,
- TUM simulator, only with A.R. Drone 2, use Gazebo as the simulator on ROS Melodic,
- SJTU drone, fork of TUM Simulator on Melodic, Parrot ARDrone,
- ArduPilot and SITL simulator, no need of ROS nor Gazebo but compatible, very handy and widespread.



### Comparison of exiting simulator :


Simulators | Gazebo | ?? | DJI Assistant | jMAVsim | 
----------|--------|------------|-----------------|------|---
ROS version | All | ?? | Kinetic (and Melodic with plugins)
*Works on Linux* | Yes | | No but OSDK can 
Drones available | Multirotors | ?? | All DJI
Sensors | Many (create and modify) | ?? | Many 
Obstacles | Yes | ?? | None
SITL | Yes | ?? | No | Yes
Compatibility | Many | | Gazebo | PX4




### Packages and tools to interact with the drone :

Package | OSDK | dji_m100 suite | Hector quadrotor | SJTU *à essayer* | ROS Quadrotor Simulator | PX4 | Ardupilot
--------|-----|-----------|-----------|-----------|-----|----|-----
ROS version | Kinetic | Kinetic and Melodic | Kinetic and Melodic | Melodic | Indigo (maybe KInetic)
Gazebo version | 7 or more | 7 or 8 | 7 or more | 7 | 7 | 
Cmake version | 2.8.3 or newer | 2.8.3 or newer | 2.8.3 or newer | 3.2.2 | 2.8.3 | 
Drones | All DJI | M100 | [Generic quadrotor](http://wiki.ros.org/hector_quadrotor_description) | Parrot AR Drone | ??
Sensors | Camera, GPS, mission, IMU | Camera, GPS, mission | Forward camera, laser, sonar, [many more...](https://github.com/tu-darmstadt-ros-pkg/hector_quadrotor) | Forward/backward camera, laser, sonar, IMU | Camera, sonar
Topics | Odom, attitude, GPS | uav1/... same as before | Odom, attitude, cmd_vel | [Topics related to sensors](https://github.com/edowson/sjtu_drone#read-sensor-data-from-ros-topics) or use RQT GUI 
Navigation | Joysticks | Joysticks | Joysticks, can add keyboard | Joystick, keyboard or waypoints | Xbox joysticks, waypoints, autonomous
Worlds | Empty | Some  (collision etc) | Indoor and Outdoor | Some | Many, indoor and outdoor | 
GUI | From the assistant | Rviz or RQT | Rviz | RViz or GZcliebnt from Gazebo | Rviz
Compatibility | ? | With hector | ? | ? | With PX4, MoveIt!
More | Need the drone | Need the drone. Collision free | [Kinect](https://github.com/kkelchte/hector_quadrotor) | Simulate wind flow, race | Path planning, obstacle avoidance
Links | [Package](https://github.com/dji-sdk/Onboard-SDK/) | See branch ROS_Kinetic_Gazebo | [Package](http://wiki.ros.org/hector_quadrotor), [Tutorial](https://hub.packtpub.com/using-ros-uavs/) | See previous work or [here](https://github.com/tahsinkose/sjtu-drone) | See [here](https://github.com/wilselby/ROS_quadrotor_simulator)




