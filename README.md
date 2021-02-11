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


Simulators | Gazebo | DJI Assistant | jMAVsim 
----------|-----------------|-----------------|-----
ROS version | All | Kinetic (and Melodic with plugins)
*Works on Linux* | Yes | No but OSDK can 
Drones available | Multirotors | All DJI
Sensors | Many (create and modify) | Many 
Obstacles | Yes | None
SITL | Yes | No | Yes
Compatibility | Many | Gazebo | PX4




### Packages useful :

Package | OSDK | dji_m100 suite | Hector quadrotor | SJTU *à essayer* | ROS Quadrotor Simulator | *ArduCopter* 
--------|-----|-----------|-----------|-----------|-----|---
Type | Developement toolkit | Package | Metapackage | Package | Package | Package
Use case | | | | | | | 
ROS version | Kinetic | Kinetic and Melodic | Kinetic and Melodic | Melodic | Indigo (maybe KInetic)
Gazebo version | 7 or more | 7 or 8 | 7 or more | 7 | 7 | 
Cmake version | 2.8.3 or newer | 2.8.3 or newer | 2.8.3 or newer | 3.2.2 | 2.8.3 | 
Drones | All DJI | M100 | [Generic quadrotor](http://wiki.ros.org/hector_quadrotor_description) | Parrot AR Drone | AsTec and others multirotors
Sensors | Camera, GPS, mission, IMU | Camera, GPS, mission | Forward camera, laser, sonar, [many more...](https://github.com/tu-darmstadt-ros-pkg/hector_quadrotor) | Forward/backward camera, laser, sonar, IMU | Camera, sonar
Topics | Odom, attitude, GPS | uav1/... same as before | Odom, attitude, cmd_vel | [Topics related to sensors](https://github.com/edowson/sjtu_drone#read-sensor-data-from-ros-topics) or use RQT GUI 
Navigation | Joysticks | Joysticks | Joysticks, can add keyboard | Joystick, keyboard or waypoints | Xbox joysticks, waypoints, autonomous
Worlds | Empty | Some  (collision etc) | Indoor and Outdoor | Some | Many, indoor and outdoor | 
Physical impact on the drone | | | | Wind | 
GUI | From the assistant | Rviz or rqt_gui | Rviz | rqt_gui or GZcliebnt from Gazebo | Rviz
Compatibility | Install the DJI assistant onto it | Gazebo pluging and a modifiable URDF file, used with the OSDK | Generic modifiable quadrortor URDF file, interface with Gazebo | Many Gazebo plugins | Use mav comm package from PX4, MoveIt! and RotorS 
More | Need the drone | Need the drone. Collision free | [Kinect](https://github.com/kkelchte/hector_quadrotor), multiple plugins, demos | Simulate wind flow, race. May need [Gazebo 9 and Ubuntu 18.04](https://github.com/tahsinkose/sjtu-drone). Fork of [tum_simulator](http://wiki.ros.org/tum_simulator) | Path planning, obstacle avoidance, ~2 and 3D mapping
Links | [Package](https://github.com/dji-sdk/Onboard-SDK/) | See branch ROS_Kinetic_Gazebo | [Package](http://wiki.ros.org/hector_quadrotor), [Tutorial](https://hub.packtpub.com/using-ros-uavs/), [more explanations and posibilities](https://wiki.ros.org/tu-darmstadt-ros-pkg/) | See previous work or [here](https://github.com/tahsinkose/sjtu-drone) | See [here](https://github.com/wilselby/ROS_quadrotor_simulator)

### Flight controller : 

Flight controller | PX4 | Ardupilot 
---|----|-----
ROS version | Melodic | Melodic
Compatibility | Plugin Gazebo 9 | Plugin Gazebo, use [SITL](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html)
More | | DO not need ROS and Gazebo to work properly but compatible, Linux Ubuntu 18.04

