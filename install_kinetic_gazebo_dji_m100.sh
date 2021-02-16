#attention au format voir si en .rosinstall ou en .sh???
#ici en .sh

#!/bin/bash

# to execute when in catkin/src folder

sudo apt-get install ros-kinetic-ros-control
sudo apt-get install ros-kinetic-gazebo-ros-control
sudo apt-get install ros-kinetic-unique-identifier
sudo apt-get install ros-kinetic-geographic-info
sudo apt-get install ros-kinetic-laser-geometry
sudo apt-get install ros-kinetic-tf-conversions
sudo apt-get install ros-kinetic-tf2-geometry-msgs
sudo apt-get install ros-kinetic-joy

# to add important git repositories
# the hector quadrotor package and dependancies, mandatory to make the robot flies with dji_m100_controllers_gazebo

git clone -b kinetic-devel https://github.com/tu-darmstadt-ros-pkg/hector_quadrotor
git clone -b catkin https://github.com/tu-darmstadt-ros-pkg/hector_localization
git clone -b kinetic-devel https://github.com/tu-darmstadt-ros-pkg/hector_gazebo
git clone -b kinetic-devel https://github.com/tu-darmstadt-ros-pkg/hector_models
git clone -b catkin https://github.com/tu-darmstadt-ros-pkg/hector_slam

# to control the drone with a keyboard
git clone https://github.com/lharikrishnan1993/hector_keyboard_teleop.git

# the dji_m100 packages 
git clone https://github.com/dji-m100-ros/dji_m100_controllers_gazebo.git
git clone https://github.com/dji-m100-ros/dji_m100_description.git
git clone https://github.com/dji-m100-ros/dji_m100_gazebo.git

cd ..
catkin_make
source devel/setup.bash