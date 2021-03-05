#This file will  launch a simulation with ArduPIlot SITL and Gazebo :

#!/bin/bash

cd ~/Pkg_Projet/ardupilot_ws/ardupilot/ArduCopter

sim_vehicle.py -f gazebo-iris --console --map &
gazebo --verbose worlds/iris_arducopter_runway.world &
