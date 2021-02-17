# Projet_P5_Trousseau_Camba

## Testing Ardupilot with Gazebo simulator on ROS

### Introduction :
The last group project tried out this solution which worked well. However it did not used Gazebo nor ROS, hence I am going to follow the tutorial they have used for Ardupilot and SITL, then add those for Gazebo and ROS.


The architecture is the following : 
- Ardupilot, as a flight controller,
- MAVROS, a ROS “node” that can convert between ROS topics and MAVLink messages allowing ArduPilot vehicles to communicate with ROS,
- ArduCopter, for simulating the drones,
- SITL to simulate the environnement, will try to add Gazebo plugins to do the simulation in it,
- MAVRos, MAVLink extendable communication node for ROS with proxy for Ground Control Station.
**METTRE UNE IMAGE**



### General configuration:
- ROS melodic
- Ubuntu 16.04 at least


### Installation :
To get Ardupilot, SITL and Arducopter I followed [this tutorial](https://ardupilot.org/dev/docs/building-setup-linux.html#building-setup-linux).\
It also installs [gitk](https://git-scm.com/docs/gitk/) a repository browser, and [git-gui](https://git-scm.com/docs/git-gui) a GUI interface for Git. These are basics Git helpers but are not mandatory.
To build Arducopter after making the log-out log-in I used `./waf configure --board sitl` to configure a software in the loop simulator, and `./waf copter` to get all multirotor types.


Note :
To do the submodule update I had to do a `git config --global url."https://".insteadOf git://` first.
