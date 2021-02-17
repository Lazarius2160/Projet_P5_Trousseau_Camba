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
1. To get Ardupilot, SITL and Arducopter I followed **[this first tutorial](https://ardupilot.org/dev/docs/building-setup-linux.html#building-setup-linux).**\
It also installs [gitk](https://git-scm.com/docs/gitk/) a repository browser, and [git-gui](https://git-scm.com/docs/git-gui) a GUI interface for Git. These are basics Git helpers but are not mandatory.
> Note : 
> To build Arducopter after making the log-out log-in I used `./waf configure --board sitl` to configure a software in the loop simulator, and `./waf copter` to get all multirotors needed.
> To update the submodule I had to do a `git config --global url."https://".insteadOf git://` first.
2. The next tutorial I followed was **[Setting up SITL on Linux](https://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html#setting-up-sitl-on-linux)** it was made to configure and launch SITL.
> I had to give the whole path to lauch sim_vehicule.py like `./Tools/autotest/sim_vehicule.py -v ArduCopter` because with the file *install-prereqs-ubuntu.sh*, the `Tools/autotest directory` hasn't been added to the PATH.
** A VOIR SI MET PAS QUE DANS TUTO**


It also let us updates [MavProxy](https://ardupilot.org/mavproxy/index.html#home), which a "UAV ground station software package for MAVLink based systems". **!! MAVProxy permet de donner des commandes au drone dans la simulation. Par exemple on peut armer les moteurs, les désarmer, donner une mission au drone et plus généralement gérer le drone et la simulation. MAVRos est un nœud ROS qui permet d’interagir avec ces commandes à travers ROS et donc de créer une interface entre les deux logiciels.!!**

3. Trying to use Gazebo as an external simulator. I used this [third tutorial](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html). 

4. ROS

### Testing : 
1. The tutorial **[Setting up SITL on Linux](https://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html#setting-up-sitl-on-linux)** was made to configure and launch SITL. **QU'EST CE QUE J'AI PU FAIRE**
