# Testing Ardupilot with Gazebo simulator and/or ROS

## Introduction :
The last group project tried out this solution which worked well (Ardupilot + SITL). However they did not used Gazebo nor ROS, hence I am going to follow the tutorial they have used for Ardupilot and SITL, then add those for Gazebo and ROS.  
<br>
**But beware, for the moment is not possible to have [SITL + ROS + Gazebo](https://ardupilot.org/dev/docs/ros-gazebo.html) but only SITL + ROS or  SITL + Gazebo with SITL used with a Gazebo plugin. [Here](https://diydrones.com/profiles/blogs/705844-BlogPost-2151758) is a discussion and a shematic of the attempt made to use them 3 together on ROS Indigo :**  
![ROS+Gazebo+SITL](https://user-images.githubusercontent.com/76939787/109482113-e49e1c80-7a7d-11eb-8096-f7ee1d250e97.png)  
<br>
Indeed, the Gazebo part uses a pure Gazebo plugin so there is no need of ROS however it is [still possible to use ROS with normal gazebo-ros packages](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html#plugin-installation).
<br>

### Architecture :
The architecture is the following : 
- ArduCopter from ArduPilot, as a flight controller and for simulating the drones,
- SITL to simulate the environnement, native firmware simulator + FDM program provided by ArduPilot,
- MAVProxy, a UAV ground station software package for MAVLink based systems, talks to ArduPilot using the MAVLink protocol,
- If using : 
  - ROS : use MAVROS, a ROS “node” that can convert between ROS topics and MAVLink messages allowing ArduPilot vehicles to communicate with ROS,
  - Gazebo : a Gazebo Plugin.  


Here is a schema of the controller and SITL (Flight Gear is optionnal and works for planes, hence I did not use it), one will use sim_vehicule.py to launch everything in short : 
<br>
![ArdupilotSoftwareintheLoopSITL](https://user-images.githubusercontent.com/76939787/109513125-1080c880-7aa5-11eb-8512-ee62ae74b854.jpeg)  
<br>



### General configuration :
- ROS melodic
- Ubuntu 16.04 at least  


## Ardupilot and SITL : 


### Installation :
1. To get Ardupilot, SITL and Arducopter I followed **[this first tutorial](https://ardupilot.org/dev/docs/building-setup-linux.html#building-setup-linux).**\
It also installs [gitk](https://git-scm.com/docs/gitk/) a repository browser, and [git-gui](https://git-scm.com/docs/git-gui) a GUI interface for Git. These are basics Git helpers but are not mandatory.  
> To build Arducopter after making the log-out log-in I used `./waf configure --board sitl` to configure a software in the loop simulator, and `./waf copter` to get all multirotors needed.
> To update the submodule I had to do a `git config --global url."https://".insteadOf git://` first.

2. The next tutorial I followed was **[Setting up SITL on Linux](https://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html#setting-up-sitl-on-linux)** it was made to configure and launch SITL.
> May had to give the whole path to lauch sim_vehicule.py like `./Tools/autotest/sim_vehicule.py -v ArduCopter` because with the file *install-prereqs-ubuntu.sh*, the `Tools/autotest directory` hasn't been added to the PATH.
** A VOIR SI MET PAS QUE DANS TUTO**

3. It also let us updates [MavProxy](https://ardupilot.org/mavproxy/index.html#home), which a "UAV ground station software package for MAVLink based systems". First I installed it using [this website](https://ardupilot.org/mavproxy/docs/getting_started/download_and_installation.html#linux) and to get everything up to date.
> MAVProxy allows to give commands to the UAV in the simulation. For example, to arm the engines, disarm them, give the UAV a mission and more generally manage the UAV and the simulation.


### Testing : 
1. The tutorial [Setting up SITL on Linux](https://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html#setting-up-sitl-on-linux) was made to configure and launch SITL. Not very precise and complete, I skipped it quickly.  
I also followed some steps of [this testing page](https://ardupilot.org/dev/docs/using-sitl-for-ardupilot-testing.html#using-sitl-for-ardupilot-testing) to see the different possibilites given by SITL (vehicule, start location, simulate OSD and some params to modify) and actions possibles.

2. Then I tried this tutorial to test my SITL simulation [Copter SITL/MAVProxy tutorial](https://ardupilot.org/dev/docs/copter-sitl-mavproxy-tutorial.html) to be sure everything worked fine before trying to add Gazebo and ROS.  
<br>
I tested everyting this way, first with SITL without Gazebo:  
  - Launch simulation : go inside your working space and do `cd ardupilot/ArduCopter`, now launch `sim_vehicule.py --map --console`. Console is useful to see what is enable or not on the drone and simulator.  
  - Take off: 
    
        mode guided  
        arm throttle  
        takeoff 40
    
I used the guided mode and *armed the motors* which is very important otherwise the drone won't take off (wait until "pre armed good"), I also had to write my commands on my terminal not in the ArduPilot console.  
  > To guide the drone there are multiple possibilities such as :
  >    - `GUIDED` to move the drone position by positon using a right click on "fly to" and select the altitude,
  >    - `ALTITUDE` to enter the target position manually on the command line,
  >    - or even [loading a mission/creating one by drawing points](https://ardupilot.org/copter/docs/common-planning-a-mission-with-waypoints-and-events.html) and switching to the `AUTO` mode.
  > Beware, [Mission Planner](https://ardupilot.org/planner/index.html#home) is a full-featured ground station application for ArduPilot but available **only** on Windows.


 *I guided my drone using "Fly to" with a right click on tge map and couldn't use a joystick with my actual computer. I could also write waypoints on my shell in Guided Mode.*  
  - Wind : Tested with the wind at 10m/s and 50m/s with 
           
        param set SIM_WIND_DIR 180
        param set SIM_WIND_SPD 10
        
  - Fence : I draw a fence with a right click so the drone wasn't able to fly there, one have to enable it with `param set fence_enable 1` when on Guided Mode.
  - Draw mission : I draw it using the map on SITL, it starts when switching to `mode auto` and use `wp loop` to repeat the mission over and over again.
  - Stop a mission : To stop a mission and land at home I used `mode rtl`.  


## Using Gazebo as an external simulator :
When the first part worked fine I tried to add Gazebo to my simulation. 

### Installation :
To use Gazebo as an external simulator. I used this **[third tutorial](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html)** which went smoothly and I was able to take off.  

### Testing : 
Now that I could test with Gazebo I had to :
  - To launch it change the sim_vehicule in the first shell (ctrl+C and type this command) `sim_vehicle.py -f gazebo-iris --console --map`, open another shell and type `cd` then `gazebo --verbose worlds/iris_arducopter_runway.world`.
  - I select the drone on Gazebo and clicked on *follow* to better see where it was going.
  - Then I repeated the same steps except for the wind part (different way to do this), in Gazebo the RTL made it return to the last landing position.
  - Beware, all the steps worked fine except the circle mode (altitude decrease without a crash but the simulation does not respond).   
I also tried to give it the same commands from [this video](https://youtu.be/n_M5Vs5FBGY), it went ok.  


## Interfacing Ardupilot and SITL with ROS :
When I thought I was done with Gazebo I went back to the part without Gazebo and tried to interfaced ROS with my autopilot.

### Installation :
I started by initializing a proper catkin workspace [like so](http://wiki.ros.org/catkin/Tutorials/create_a_workspace) and then followed [this tutorial](https://ardupilot.org/dev/docs/ros-install.html#installing-mavros) to get a proper MAVRos (mandatory to use ROS).  
> I had to do an `apt-get update` prior to everything and use `sudo` to install the install_geographiclib_datasets.sh  
Then follow [this tutorial ROS with SITL](https://ardupilot.org/dev/docs/ros-sitl.html) and it was done!  

### Testing : 
I launched 3 things as said in the previous tutorial : 
- Shell 1 : `sim_vehicle.py -v ArduCopter --console --map` to launch a copter session and see what would happen,
- Shell 2 : `roslaunch apm.launch` to initiate the MAVRos connextion to SITL,
- Shell 3 : `rqt` the GUI interface for using ROS easily.  

Thanks to the GUI I could try different things when the drone was flying:
- Topic monitor : in `plugins/topics/topic monitor` one can see the values of the topics created by MAVRos,
-Service caller : in `plugins/services/services caller` it is possible to change the value of a service to interact with the drone without using the shell. For example writing GUIDED in custom_mode on `/mavros/set_mode` to switch the mode, one biggest problem is on `/mavros/cmd/arming` because on the ground the motors are armed for only 15secs (hard to take off using rqt),
- TF Tree : I created a tf tree using `vizualisation/tf tree`, however the tree is separated in 3 which is certainly a problem a could not solve and has been discussed [here](https://github.com/mavlink/mavros/issues/1388) : ![tf-_ardupilot](https://user-images.githubusercontent.com/76939787/109682794-09c68400-7b7f-11eb-8f76-12aced899b05.png)
- ROSGraph : see the photo on the repo, with `vizualisation/node graph`, this shows the interaction with SITL is done without ROS otherwise a node would have appeared (while there is only MAVRos which makes the links),
- RViz : I had trouble using RViz as the "add by topics" was giving me not working displays (path, initial pose, odometry, ...) only "Pose" would work.

## To go further : 
As said before having ROS+Gazebo+SITL is not possible for now so I wasn't able to test it. Trying it would close a loop and make an even powerful tool.  
<br>
Some people use [ROS and Hector SLAM to do non GPS Navigation](https://ardupilot.org/dev/docs/ros-slam.html), using a lidar simulated on Gazebo instead of lidar harware is possible and explained [here](https://discuss.ardupilot.org/t/arducopter-sitl-gazebo-ros-slam-simultaneous-localisation-and-mapping/63022/1).

## To conclude : 


