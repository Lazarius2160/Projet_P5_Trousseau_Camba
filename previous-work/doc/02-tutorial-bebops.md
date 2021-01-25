# BebopS – Test navigation

@date 30/06/2020

## Installation

Installation sans problème en suivant le tutoriel pour Ubuntu 18,04 with ROS Melodic and Gazebo 9 [[lien]](https://github.com/gsilano/BebopS)

## Lancement 

Launch file: *task2_world.launch*

J’ai dû relancer la simulation plusieurs fois avant que Gazebo ne se lance mais je pense qu’il s’agit surtout là d’un problème de performances de mon ordinateur plus que d’un problème au sein du simulateur.

La simulation fonctionne de la manière suivante :

- On entre dans le fichier waypoint.txt les coordonnées du point que le drone doit atteindre. Les coordonnées sont entrées sous le format suivant : t, x, y, z, r avec t la durée en s qu’a  le drone pour atteindre le point, les coordonnées du point et l’angle du drone quand il arrive au point.
- On lance la simulation avec roslaunch task2_world.launch
- Pour activer ou désactiver le filtre des points des passages qui permet de lisser la trajectoire on peut changer le paramètre waypoint_filter dans la commande.
Remarques concernant la simulation: 
- Pas très ergonomique, on ne peut pas donner un point de passage dans Gazebo directement et il faut alors rentrer le point dans le fichier waypoint.txt puis relancer la simulation.
- Il faudrait vérifier si on peut éviter les obstacles
- Les durées entre les différents points doivent donner le temps au drone de se déplacer d’un point à l’autre sans quoi il ne fera que se rapprocher puis changera d’objectif avant d’être arrivé à sa destination. Cette notion de durée ne devrait pas être à mon humble avis pour permettre au drone de se déplacer d’objectif en objectif complètement.
- A vérifier également : peut-on publier un message sur un topic qui donnerait des coordonnées à atteindre ? Ce serait plus simple qu’en passant par ce fichier waypoint.txt
