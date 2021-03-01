# Projet_P5_Trousseau_Camba

## Testing Ardupilot with Gazebo simulator and ROS

### Introduction :
The last group project tried out this solution which worked well. However it did not used Gazebo nor ROS, hence I am going to follow the tutorial they have used for Ardupilot and SITL, then add those for Gazebo and ROS.


The architecture is the following : 
- Ardupilot, as a flight controller,
- ArduCopter, for simulating the drones,
- SITL to simulate the environnement, will try to add Gazebo plugins to do the simulation inside it,
- MAVProxy, a UAV ground station software package for MAVLink based systems,
- MAVROS, a ROS “node” that can convert between ROS topics and MAVLink messages allowing ArduPilot vehicles to communicate with ROS,


**For the moment is not possible to have [SITL + ROS + Gazebo](https://ardupilot.org/dev/docs/ros-gazebo.html) but only SITL + ROS or  SITL + Gazebo with SITL used as a Gazebo plugin. [Here](https://diydrones.com/profiles/blogs/705844-BlogPost-2151758) is a discussion and a shematic of the attempt made.**  
![Ardu+Gazebo+ROS](https://user-images.githubusercontent.com/76939787/109482113-e49e1c80-7a7d-11eb-8096-f7ee1d250e97.png)



### General configuration:
- ROS melodic
- Ubuntu 16.04 at least


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

4. To use Gazebo as an external simulator. I used this **[third tutorial](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html)** which went smoothly and I was able to take off. **_The gazebo part is tricky, especially for simulating everything inside it, it easier to just plot SITL inside gazebo._**

5. ROS MAVRos est un nœud ROS qui permet d’interagir avec ces commandes à travers ROS et donc de créer une interface entre les deux logiciels.  

### Testing : 
1. The tutorial [Setting up SITL on Linux](https://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html#setting-up-sitl-on-linux) was made to configure and launch SITL. Not very precise and complete, I skipped it quickly.  
I also followed some steps of [this testing page](https://ardupilot.org/dev/docs/using-sitl-for-ardupilot-testing.html#using-sitl-for-ardupilot-testing) to see the different possibilites given by SITL (vehicule, start location, simulate OSD and some params to modify) and actions possibles.

2. Then I tried this tutorial to test my SITL simulation [Copter SITL/MAVProxy tutorial](https://ardupilot.org/dev/docs/copter-sitl-mavproxy-tutorial.html) to be sure everything worked fine before trying to add Gazebo and ROS.  
I tested everyting this way, first with SITL with Gazebo:
  - Launch simulation : inside your working space `cd ardupilot/ArduCopter     sim_vehicule.py --map --console` Console is useful to see what is enable or not on the drone and simulator.  
  - To take off: 
    
        mode guided  
        arm throttle  
        takeoff 40
    
I used the guided mode and *armed the motors* which is very important otherwise the drone won't take off, I also had to write my commands on my terminal not in the ArduPilot console.  
  > To guide the drone there are multiple possibilities such as :
  >    - `GUIDED` to move the drone position by positon using a right click on "fly to" and select the altitude,
  >    - `ALTITUDE` to enter the target position manually on the command line,
  >    - or even [loading a mission/creating one by drawing points](https://ardupilot.org/copter/docs/common-planning-a-mission-with-waypoints-and-events.html) and switching to the `AUTO` mode.
  > Beware, [Mission Planner](https://ardupilot.org/planner/index.html#home) is a full-featured ground station application for ArduPilot but available **only** on Windows.
   
  - I guided my drone using "Fly to" with a right click on tge map and couldn't use a joystick with my actual computer. I could also write waypoints on my shell in mode guided.
  - Tested with the wind at 10m/s and 50m/s with 
           
        param set SIM_WIND_DIR 180
        param set SIM_WIND_SPD 10
  - I draw a fence with a right click so the drone wasn't able to fly there, and tried to draw one with the keyboard. 
  - Draw mission : I draw it using the map on SITL, it launches when switching to `mode auto` and use `wp loop` to repeat the mission over and over again.
  - To stop a mission and land at home I used `mode rtl`.  

Now I could test with Gazebo :
  - To launch it just write `gazebo --verbose worlds/iris_arducopter_runway.world` on another shell with the first step of SITL.
  - I repeated the same steps except for the wind part (different way to do this), to set a goal position I had to use the waypoints and not fly to. 
  - Beware, all the steps worked fine except the circle mode (altitude decrease without a crash but the simulation does not respond).  

3. To see if Gazebo worked fine I tried to give it the same commands from [this video](https://youtu.be/n_M5Vs5FBGY).
