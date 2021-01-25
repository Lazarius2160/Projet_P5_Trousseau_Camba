# projet-ros

Projet de fin d'année M1 (simulation drone)

## Prérequis

[ROS Melodic](https://wiki.ros.org/melodic/Installation) installé sur la machine (Ubuntu 18.04).

Avec des compléments:
```bash
sudo apt install ros-melodic-geographic-msgs ros-melodic-mavlink libgeographic-dev geographiclib-tools geographiclib-doc
```

Avoir un niveau intermédiaire en [ROS](https://wiki.ros.org/) (i.e. maitriser à minima le *'Beginner Level'* des [tutoriaux](https://wiki.ros.org/ROS/Tutorials).

## Installation

Ouvrir un terminal puis cloner le projet dans le repertoire *src* de *catkin*.

```bash
cd catkin_ws/src
git clone https://gvipers.imt-lille-douai.fr/thibaut.felten/projet-ros
```

ou avec *ssh*:

```bash
cd catkin_ws/src
git clone ssh://git@gvipers.imt-lille-douai.fr:2222/thibaut.felten/projet-ros.git
```
cd 

Le répertoire est cloné, il faut maintenant pull le submdodule contenant MAVRos

```bash
cd projet-ros
git submodule init
git submodule update
```
    
On peut maintenant build:

```bash
cd ~/catkin_ws
catkin build
```
**ET POUR LANCER UN PREMIER QUELQUE CHOSE ?**

Suivre le tutoriel d'installation de [PX4](https://gvipers.imt-lille-douai.fr/thibaut.felten/projet-ros/blob/master/doc/03-tutorial-px4.md#tutoriels-suivis)

## Organisation du repertoire

Par dossier :

- doc : Recherche de solutions 01 - Solutions envisagées 02 - Solution retenue 03
- mavros : Sous-module utilisé pour interfacer la solution PX4 avec ROS
- offboard_control : package pour tester la navigation avec ros
- launch et node : à supprimer