## Setting up the environnement:
This installing tutorial is a resume of what I did in the *Test_ardupilot.md* so it concatenate 3 tutorials in one. It is separated in 3, the first part is mandatory and the 2 and 3 can be done separatly or not done at all.  
For more explanations go to my [Test_ardupilot.md](https://github.com/Lazarius2160/Projet_P5_Trousseau_Camba/blob/c012ee46ff7e42417c4a2f1eb568f7f3feef7bba/Test_ardupilot.md) or see the original tutorials linked below.


### Ardupilot + SITL :
First I followed [this tuto](https://ardupilot.org/dev/docs/building-setup-linux.html#building-setup-linux).  
Open a shell on your terminal and write :

    sudo apt-get update
    sudo apt-get install git
    sudo apt-get install gitk git-gui

Then navigate to the directory where you would like the clone to be stored

    git clone https://github.com/your-github-userid/ardupilot
    cd ardupilot
    git submodule update --init --recursive
    Tools/environment_install/install-prereqs-ubuntu.sh -y
    . ~/.profile 
    
To make this path permanent one must log out and in of its session. And clean out some build artifacts :

    ./waf clean

Then I installed MavProxy using [this tuto](https://ardupilot.org/mavproxy/docs/getting_started/download_and_installation.html#linux) :

    sudo apt-get install python3-dev python3-opencv python3-wxgtk4.0 python3-pip python3-matplotlib python3-lxml python3-pygame
    pip3 install PyYAML mavproxy --user
    echo "export PATH=$PATH:$HOME/.local/bin" >> ~/.bashrc

Then restart the system.  
<br>
In case MavProxy is not up to date I used :

    pip install --upgrade pymavlink MAVProxy --user
  
### Adding Gazebo :
Once you have installed your gazebo version go to your working directory and type :

    git clone https://github.com/khancyr/ardupilot_gazebo
    cd ardupilot_gazebo
    mkdir build
    cd build
    cmake ..
    make -j4
    sudo make install
    
See the whole tuto [here](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html).

### Adding ROS :
Install MavROS :

    sudo apt-get install ros-melodic-mavros ros-melodic-mavros-extras
    wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh
    chmod a+x install_geographiclib_datasets.sh
    ./install_geographiclib_datasets.sh
    sudo apt-get install ros-melodic-rqt ros-melodic-rqt-common-plugins ros-melodic-rqt-robot-plugins
    
Then set up a proper catkin workspace :

    mkdir -p ardupilot_ws/src
    cd ardupilot_ws
    catkin init
    cd src
    mkdir launch
    cd launch
    roscp mavros apm.launch apm.launch
    gedit apm.launch
    
 Change the first line to : `<arg name="fcu_url" default="udp://127.0.0.1:14551@14555" />`.  
 
 See the whole tuto [here](https://ardupilot.org/dev/docs/ros-install.html#installing-mavros).

## Testing the world:
### Start SITL simulator :  
Shell:
 
    cd ardupilot/ArduCopter
    sim_vehicle.py -w

Wait until everything is loaded, kill it and type :
    
    sim_vehicle.py --console --map

### Add *Gazebo* :
Shell 1: 
    
    sim_vehicle.py -f gazebo-iris --console --map
    
Shell 2:
    
    cd
    gazebo --verbose worlds/iris_arducopter_runway.world
    
### Use ROS :
Shell 1: 

    sim_vehicle.py -v ArduCopter --console --map
    
Shell 2: 
     
    roslaunch apm.launch 
    
Shell 3: 

    rqt the GUI interface for using ROS easily.


The result of those testing are written in my [Test_ardupilot.md](https://github.com/Lazarius2160/Projet_P5_Trousseau_Camba/blob/c012ee46ff7e42417c4a2f1eb568f7f3feef7bba/Test_ardupilot.md).










