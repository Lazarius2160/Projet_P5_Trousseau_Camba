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


## Comparison of exiting simulator :


Simulators | Gazebo | ?? | DJI Assistant
----------|--------|------------|-----------------
ROS version | All | ?? | Kinetic (and Melodic with plugins)
Drones available | Multirotors | ?? | All DJI
Sensors | Many (create and modify) | ?? | Many 
Obstacles | Yes | ?? | None
SITL | Yes | ?? | No


### Packages and tools to interact with the drone :

Package | OSDK | dji_m100 suite | Hector quadrotor | SJTU *à essayer* | ROS Quadrotor Simulator
--------|-----|-----------|-----------|-----------|-----
ROS version | Kinetic | Kinetic and Melodic | Kinetic and Melodic | 
Gazebo version | 7 or more | 7 or more | 7 or more |
Drones | All DJI | M100 | [Generic quadrotor](http://wiki.ros.org/hector_quadrotor_description) |
*Sensors* | Camera, GPS, mission | Camera, GPS, mission | ??? |
Topics | Odom, attitude, IMU, GPS | uav1/... same as before | ?? |
Navigation | Joysticks | Joysticks | Joysticks, can add keyboard |
Worlds | Empty | Many (collision etc) | Indoor and Outdoor |
More | Need the drone | Need the drone.\ Collision free | ?? |




