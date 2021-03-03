# Projet_P5_Trousseau_Camba

## Introduction


The goal of this 4-weeks project is to make a state of the art of the simulator avaible on the drone market now and try out some solution. 


For this project, the *Software In the Loop* method must be priviledge as it "characterizes a numerical simulation of the operation of the software of an embedded system during which the entire environment, including the hardware part of the embedded system, is simulated." from [wikidictionnary](https://fr.wiktionary.org/wiki/software-in-the-loop), because it normally has to be done prior to the HIL.\
The focus will be on simulators ROS friendly. Mostly using Melodic, as well as Kinetic if needed.


The previous project found solutions with : 
- RotorS, in ROS Kinetic with various Drones on Gazebo,
- BebopS, a fork of RotorS which works with Parrot 2 only on Gazebo,
- TUM simulator, only with A.R. Drone 2, use Gazebo as the simulator on ROS Melodic,
- SJTU drone, fork of TUM Simulator on Melodic, Parrot ARDrone,
- ArduPilot and SITL simulator, no need of ROS nor Gazebo but compatible, very handy and widespread.

We have looked for the more widespread simulators that could be used along with ROS.

  
## Comparison :  


### Comparison of exiting simulator :

Simulators | Gazebo | DJI Assistant | jMAVsim | New Paparazzi Simulator
----------|----------|----------|----------|----------
Type | Simulator 3D | Software with embedded simulator | Simulator 3D | Simulator 3D
ROS version | All | Kinetic (and Melodic with plugins) | Melodic | [Under developpement](https://wiki.paparazziuav.org/wiki/Pprzros)
Works on Linux | Yes | DJI's simulation supports only Windows/Mac, need to add the dji_m100 package below on the OSDK to make it run on Linux | Yes | Yes
Drones available | Multirotors (1 to 8)| All DJI | Quadrotors | Rotorcrafts
Sensors | Many (create and modify) | Many | No incorporation of sensors | Depending on the vizualisation mode
Obstacles | Yes | None | No
SITL | Yes | No | Yes | Yes
Compatibility | Many | Gazebo | Use MAVLink protocol, Java3D library, works with PX4 | With all the Paparazzi suite and others tools
Multi-vehicle simulation | Yes but can only simulate a single type of vehicle at a time  | No | Recommended if you need to support a lot of quadcopters, and the simulation only needs to be approximate| [Possible but need some troubleshooting](https://wiki.paparazziuav.org/wiki/NPS#Simulating_Multiple_Aircraft)
Links | [Official website](http://gazebosim.org/) | [Link to download the assistant](https://www.dji.com/fr/downloads/softwares/assistant-dji-2-for-matrice), only empty world available by itself | [With SITL](https://bresch.gitbooks.io/devguide/content/en/simulation/jmavsim.html), and [more](https://docs.px4.io/master/en/simulation/jmavsim.html) | [Wiki](https://wiki.paparazziuav.org/wiki/NPS) | 


\
Added to the simulator, ROS packages are here to complete the simulation according to our needs.



### Packages useful :

Package | dji_m100 suite | Hector quadrotor | *SJTU* | *ROS Quadrotor Simulator* | *BebopS* 
--------|----------|-----------|-----------|--------|--------
Type | Package | Metapackage | Package | Package | Package, forked from RotorS
ROS version | Kinetic and Melodic | Kinetic and Melodic | Melodic | Indigo (maybe Kinetic) | Kinetic and Melodic
Simulator | Gazebo 7 or 8 |Gazebo 7 or more | Gazebo 7 | Gazebo 7 | Gazebo 7 or more
Cmake version | 2.8.3 or newer | 2.8.3 or newer | 3.2.2 | 2.8.3 | 2.3.8
Drones | DJI M100 only | [Generic quadrotor](http://wiki.ros.org/hector_quadrotor_description) | Parrot AR Drone | AsTec and others multirotors | Parot Bebop 2
Sensors | Camera, GPS, mission | Forward camera, laser, sonar, [many more...](https://github.com/tu-darmstadt-ros-pkg/hector_quadrotor) | Forward/backward camera, laser, sonar, IMU | Camera, sonar | IMU, camera, laser 1D 
Topics | uav1/... same as before | Odom, attitude, cmd_vel | [Topics related to sensors](https://github.com/edowson/sjtu_drone#read-sensor-data-from-ros-topics) or use RQT GUI | 
Navigation | Joysticks | Joysticks, can add keyboard | Joystick, keyboard or waypoints | Xbox joysticks, waypoints, autonomous | Waypoints in a text file
Worlds | Some  (collision etc) | Complex, indoor and Outdoor | Some | Many, indoor and outdoor | Some, outside
Physical impact on the drone | None | Wind | Wind | Wind | Wind
GUI | Rviz or rqt_gui | Rviz | rqt_gui or GZcliebnt from Gazebo | Rviz | Rviz 
Compatibility | Gazebo pluging and a modifiable URDF file, used with the OSDK | Generic modifiable quadrortor URDF file, interface with Gazebo, cannot support MAVLinks and hardware platforms like Pixhawk. Can be interfaced with [MoveIt!](https://github.com/tahsinkose/hector-moveit) | Many Gazebo plugins | Use mav comm package from PX4, MoveIt! and RotorS | Modifiable URDF files, 
More | Need the drone. Collision free | [Kinect](https://github.com/kkelchte/hector_quadrotor), multiple plugins, demos, flight dynamics | Simulate a race. May need [Gazebo 9 and Ubuntu 18.04](https://github.com/tahsinkose/sjtu-drone). Fork of [tum_simulator](http://wiki.ros.org/tum_simulator) | Path planning, obstacle avoidance, ~2 and 3D mapping | Choose your own FDM backends
Links | See branch ROS_Kinetic_Gazebo | [Package](http://wiki.ros.org/hector_quadrotor), [tutorial](https://hub.packtpub.com/using-ros-uavs/), [more explanations and possibilities](https://wiki.ros.org/tu-darmstadt-ros-pkg/) | See previous work or [here](https://github.com/tahsinkose/sjtu-drone) | See [here](https://github.com/wilselby/ROS_quadrotor_simulator) | [Tutorial](https://github.com/gsilano/BebopS)

If we want to use more advanced flight fonctionalities, flight controllers can also be used. They need a more complicated Data structure with often several softwares that have to be interfaced together.

### Flight controller : 

Flight controller | PX4 | Ardupilot | Paparazzi | 
-----|-----|-----|-----
ROS version | Melodic | Melodic | Under developpement
Simulator | Gazebo, jMAVsim | SITL, Gazebo | [Gazebo](https://wiki.paparazziuav.org/wiki/Gazebo) or its own simulator [New Paparazzi Simulator](https://wiki.paparazziuav.org/wiki/NPS) using JSBSim (FDM)
Compatibility | Plugin Gazebo 9 | Plugin Gazebo, use [SITL](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html) and [MavProxy](https://ardupilot.org/mavproxy/index.html#home), however ROS with SITL in Gazebo is [under creation](https://ardupilot.org/dev/docs/ros-gazebo.html) | Gazebo, JBSim, FlightGear
Drones | Multirotors | Wide range, can use package ArduCopter, [multirotors ready to use here](https://ardupilot.org/copter/docs/common-rtf.html#common-rtf) | Multirotors (choice limited by hardware) | Rotorcrafts
Multi-vehicle simulation |[Possible with Gazebo, FlightGear and JMAVSim](https://docs.px4.io/master/en/simulation/multi-vehicle-simulation.html)  | [Tools in development](https://publications.waset.org/10010266/development-of-tools-for-multi-vehicles-simulation-with-robot-operating-system-and-ardupilot) |[Possible](https://wiki.paparazziuav.org/wiki/Simulation#Multiple_UAV_Simulation)
Navigation | GPS (waypoints and position hold), stereo vision | GPS, mission planner, follow me and click on the simulation (with SITL) | GPS (waypoints and position hold), stereo vision
Communication | MAV Link | MAV Link or [MAVRos](http://wiki.ros.org/mavros) (see note 2) | MAV Link 
More | Flight stack and autopilot | DO not need ROS and Gazebo to work properly but compatible (see note 1), use Linux Ubuntu 18.04 | Automated take off and landing 
Links | [Official github](https://github.com/PX4/PX4-Autopilot) | [Wiki](https://ardupilot.org/copter/index.html) |[Wiki](https://wiki.paparazziuav.org/wiki/Main_Page)


 
Notes :
1. "We will be using a standard version of ArduPilot but a custom plugin for Gazebo, until the gazebo plugin gets merged into Gazebo-master. This plugin can be used with or without ROS integration." 
2. "MAVROS is a ROS “node” that can convert between ROS topics and MAVLink messages allowing ArduPilot vehicles to communicate with ROS."

### More projects : 
Name | OSDK for DJI | Paparazzi Project
-------|-------|-------
Type | Development toolkit for developing applications, which could run on the onboard computer. Needs to be used with the DJI assistant.
ROS version | Kinetic, Cmake 2.8.3 or newer
Simulator | Got is own with the DJI assistant, compatible with Gazebo 7 or more through dji_m100 package
Drones | All DJI 
Sensors | Camera, GPS, mission, IMU
Navigation | With the assistant, use joysticks 
Physical impact on the drone | None
GUI | From the assistant 
More | Need the drone, runs on Linux and ROS 
Links | [Package](https://github.com/dji-sdk/Onboard-SDK/)

### To summarize : 
The project group found out that *Gazebo* was the best simulator they could use regarding its ROS compatibility, sensors emulated and modifiability/compatibility as it uses plugins to accept custom inputs, output custom data, and perform custom control in simulation.\
The former group project tried out :
- BebopsS, worked well but needed to change the waypoints directly onto the waypoints.txt
- SJTU_drone, no issues noted
- ArduPilot and SITL, the most advanced tutorial with the most capacities, but did not try with Gazebo.\

## Conclusion : 

## How to use this repo : 

There are two branch that have been created depending on which ROS version is used (Kinetic or Melodic).

-In the kinetic branch there are the explanation about the DJI assistant test along with the installation file.

-In the melodic branch there are one markdown file for each method we tried : hector_quadrotor package and ArduPilot

