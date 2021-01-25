# Simulation de drone – Packages intéressants

@date 29/06/2020

## RotorS

[sur github](https://github.com/ethz-asl/rotors_simulator) - [wiki](https://github.com/ethz-asl/rotors_simulator/wiki)


ROS version: **Indigo** et **Kinetic**

- Capteurs simulés: centrale à inertie, odométrie, Visual-inertial sensor, caméras
- Interface avec un joystick et clavier
- Exemples de launch files 
- Plusieurs modèles de drone: AscTec HummingBird, Pelican, FireFly mais peut aussi être utilisé avec d’autres modèles
- Plusieurs mondes pour la simulation
- Possibilité de simuler du vent

## BebopS

https://github.com/gsilano/BebopS 

https://github.com/gsilano/BebopS/wiki 

ROS version: **Melodic**

Fork de RotorS

- Capteurs simulés: centrale à inertie, odométrie, caméras, laser 1D
- Exemples de launch files 
- Un seul modèle de drone: Parrot Bebop 2
- Possibilité de simuler du vent
- Pas de possibilité de contrôler le drone manuellement pour l’instant. 
- Navigation par point de passage dans un fichier texte

## TUM Simulator

http://wiki.ros.org/tum_simulator 

https://github.com/surajmahangade/tum_simulator_melodic 

ROS version: **Indigo** mais porté sur **Melodic** par un autre contributeur

- Capteurs simulés: centrale à inertie, altitude, caméras
- Contrôle par joystick et clavier
- Navigation avec un package supplémentaire (https://github.com/tum-vision/tum_ardrone)

## SJTU Drone

https://github.com/tahsinkose/sjtu-drone 

ROS Version: **Melodic**

Fork de TUM Simulator

- Capteurs simulés: caméras, sonar, laser, altitude
- Exemples de launch files
- Contrôle par joystick ou clavier
- Navigation par points de passage possible dans gazebo directement (Lucas teste cette option à l’heure actuelle)
- Possibilité de simuler le vent
- Un modèle de drone : Parrot ARDrone
  
## Conclusion

Les deux packages qui retiennent notre attention et que nous allons tester cette semaine sont donc BebopS et SJTU Drone. Nous allons notamment essayer de mettre en place la navigation avec des points de passage. D’autres packages existent mais ont l’air moins démocratisés et complets que ces deux-là a priori comme ceux-ci :

https://github.com/larics/mmuav_gazebo 

https://github.com/NishanthARao/ROS-Quadcopter-Simulation 


D’autres ont l’air plutôt intéressants mais sont sur d’autres versions de ROS:

https://github.com/wilselby/ROS_quadrotor_simulator (fork de RotorS sur Indigo qui a l’air particulièrement complet avec mapping 2D et 3D et navigation)
