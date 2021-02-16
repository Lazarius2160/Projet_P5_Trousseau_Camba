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



### Comparison of exiting simulator :

Simulators | Gazebo | DJI Assistant | jMAVsim | New Paparazzi Simulator
----------|----------|----------|----------|----------
Type | Simulator 3D | Software with embedded simulator | Simulator 3D | Simulator 3D
ROS version | All | Kinetic (and Melodic with plugins) | Melodic | [Under developpement](https://wiki.paparazziuav.org/wiki/Pprzros)
*Works on Linux* | Yes | No but OSDK can | Yes | Yes
Drones available | Multirotors (1 to 8)| All DJI | Quadrotors | Rotorcrafts
Sensors | Many (create and modify) | Many | No incorporation of sensors | Depending on the vizualisation mode
Obstacles | Yes | None | No
SITL | Yes | No | Yes | Yes
Compatibility | Many | Gazebo | Use MAVLink protocol, Java3D library, works with PX4 | With all the Paparazzi suite and others tools
Multi-vehicle simulation | Yes but can only simulate a single type of vehicle at a time  | No | Recommended if you need to support a lot of quadcopters, and the simulation only needs to be approximate| [Possible but need some troubleshooting](https://wiki.paparazziuav.org/wiki/NPS#Simulating_Multiple_Aircraft)
Links | [Official website](http://gazebosim.org/) | [Link to download the assistant](https://www.dji.com/fr/downloads/softwares/assistant-dji-2-for-matrice), | [With SITL](https://bresch.gitbooks.io/devguide/content/en/simulation/jmavsim.html), and [more](https://docs.px4.io/master/en/simulation/jmavsim.html) | [Wiki](https://wiki.paparazziuav.org/wiki/NPS) | 

\
Added to the simulator, ROS packages are here to complete the simulation according to our needs.


### Packages useful :

Package | OSDK | dji_m100 suite | Hector quadrotor | *SJTU* | *ROS Quadrotor Simulator* | *BebopS* 
--------|--------|----------|-----------|-----------|--------|--------
Type | Developement toolkit | Package | Metapackage | Package | Package | Package, forked from RotorS
ROS version | Kinetic | Kinetic and Melodic | Kinetic and Melodic | Melodic | Indigo (maybe Kinetic) | Kinetic and Melodic
Simulator | Gazebo 7 or more | Gazebo 7 or 8 |Gazebo 7 or more | Gazebo 7 | Gazebo 7 | Gazebo 7 or more
Cmake version | 2.8.3 or newer | 2.8.3 or newer | 2.8.3 or newer | 3.2.2 | 2.8.3 | 2.3.8
Drones | All DJI | DJI M100 only | [Generic quadrotor](http://wiki.ros.org/hector_quadrotor_description) | Parrot AR Drone | AsTec and others multirotors | Parot Bebop 2
Sensors | Camera, GPS, mission, IMU | Camera, GPS, mission | Forward camera, laser, sonar, [many more...](https://github.com/tu-darmstadt-ros-pkg/hector_quadrotor) | Forward/backward camera, laser, sonar, IMU | Camera, sonar | IMU, camera, laser 1D 
Topics | Odom, attitude, GPS | uav1/... same as before | Odom, attitude, cmd_vel | [Topics related to sensors](https://github.com/edowson/sjtu_drone#read-sensor-data-from-ros-topics) or use RQT GUI | 
Navigation | Joysticks | Joysticks | Joysticks, can add keyboard | Joystick, keyboard or waypoints | Xbox joysticks, waypoints, autonomous | Waypoints in a text file
Worlds | Empty | Some  (collision etc) | Complex, indoor and Outdoor | Some | Many, indoor and outdoor | Some, outside
Physical impact on the drone | None | None | | Wind | Wind | Wind
GUI | From the assistant | Rviz or rqt_gui | Rviz | rqt_gui or GZcliebnt from Gazebo | Rviz | Rviz 
Compatibility | Install the DJI assistant onto it | Gazebo pluging and a modifiable URDF file, used with the OSDK | Generic modifiable quadrortor URDF file, interface with Gazebo, cannot support MAVLinks and hardware platforms like Pixhawk. Can be interfaced with [MoveIt!](https://github.com/tahsinkose/hector-moveit) | Many Gazebo plugins | Use mav comm package from PX4, MoveIt! and RotorS | Modifiable URDF files, 
More | Need the drone | Need the drone. Collision free | [Kinect](https://github.com/kkelchte/hector_quadrotor), multiple plugins, demos, flight dynamics | Simulate a race. May need [Gazebo 9 and Ubuntu 18.04](https://github.com/tahsinkose/sjtu-drone). Fork of [tum_simulator](http://wiki.ros.org/tum_simulator) | Path planning, obstacle avoidance, ~2 and 3D mapping | Choose your own FDM backends
Links | [Package](https://github.com/dji-sdk/Onboard-SDK/) | See branch ROS_Kinetic_Gazebo | [Package](http://wiki.ros.org/hector_quadrotor), [tutorial](https://hub.packtpub.com/using-ros-uavs/), [more explanations and possibilities](https://wiki.ros.org/tu-darmstadt-ros-pkg/) | See previous work or [here](https://github.com/tahsinkose/sjtu-drone) | See [here](https://github.com/wilselby/ROS_quadrotor_simulator) | [Tutorial](https://github.com/gsilano/BebopS)


### Flight controller : 

Flight controller | PX4 | Ardupilot | Paparazzi | 
-----|-----|-----|-----
ROS version | Melodic | Melodic | Under developpement
Simulator | Gazebo, jMAVsim | SITL, Gazebo | [Gazebo](https://wiki.paparazziuav.org/wiki/Gazebo) or its own simulator [New Paparazzi Simulator](https://wiki.paparazziuav.org/wiki/NPS) using JSBSim (FDM)
Compatibility | Plugin Gazebo 9 | Plugin Gazebo, use [SITL](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html) and [MavProxy](https://ardupilot.org/mavproxy/index.html#home) | Gazebo, JBSim, FlightGear
Drones | Multirotors | Wide range, can use package ArduCopter, [multirotors ready to use here](https://ardupilot.org/copter/docs/common-rtf.html#common-rtf) | Multirotors (choice limited by hardware) | Rotorcrafts
Multi-vehicle simulation |[Possible with Gazebo, FlightGear and JMAVSim](https://docs.px4.io/master/en/simulation/multi-vehicle-simulation.html)  | [Tools in development](https://publications.waset.org/10010266/development-of-tools-for-multi-vehicles-simulation-with-robot-operating-system-and-ardupilot) |[Possible](https://wiki.paparazziuav.org/wiki/Simulation#Multiple_UAV_Simulation)
Navigation | GPS (waypoints and position hold), stereo vision | GPS, mission planner, follow me and click on the simulation (with SITL) | GPS (waypoints and position hold), stereo vision
Communication | MAV Link | MAV Link | MAV Link 
More | Flight stack and autopilot | DO not need ROS and Gazebo to work properly but compatible, use Linux Ubuntu 18.04 | Automated take off and landing 
Links | [Official github](https://github.com/PX4/PX4-Autopilot) | [Wiki](https://ardupilot.org/copter/index.html) |[Wiki](https://wiki.paparazziuav.org/wiki/Main_Page)

### More projects : 
Name | Paparazzi Project | DJI assistant 
----|----|----
Type | A completer voir fiche package | Recopier les données du dessus et les enlevées de packages

### To summarize : 
The project group found out that *Gazebo* was the best simulator they could use regarding its ROS compatibility, sensors emulated and modifiability/compatibility.\
The former group project tried out :
- BebopsS, worked well but needed to change the waypoints directly onto the waypoints.txt
- SJTU_drone, no issues noted
- ArduPilot and SITL, the most advanced tutorial with the most capacities, but did not try with Gazebo.\
**A compléter après la réunion de Mardi**

