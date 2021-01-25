# Ardupilot & SITL (Software In The Loop)

@date 04/07/2020

Après être tombé sur les quelques limites des deux solutions précédentes, nous avons cherché s’il existe un simulateur qui possédait expressément un système de navigation. Nous avons alors découvert Ardupilot qui est un autopilote et qui peut être utilisé en simulation avec SITL. Le package ArduCopter permet quant à lui de simuler un drone. Ces solutions ne nécessitent ni ROS ni Gazebo pour fonctionner mais sont compatibles avec ces outils. 

Avantages de cette solution :

- Compatible avec ROS [[lien]](https://ardupilot.org/dev/docs/ros.html)
- Compatible avec Gazebo [[lien]](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html)
- Navigation automatique (ArduPilot étant par essence un pilote automatique)
- Documentation précise et complète en ligne.
- Permet de simuler plusieurs types de drones (du simple hélicoptère à des drones à 3,4,6 ou 8 rotors) – De nombreuses configurations de drone sont téléchargeables également. [[lien]](https://ardupilot.org/dev/docs/pre-built-binaries.html)

Linux version : Ubuntu 18.04 (et donc ROS Melodic)

## Installation

Simple et guidée en suivant [ce tutoriel](https://ardupilot.org/dev/docs/building-setup-linux.html#building-setup-linux)

Permet de télécharger et installer ArduPilot, ArduCopter et SITL.

## Tutoriels suivis

Mise en place de la simulation avec SITL
[[lien]](https://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html)

Premier lancement de la simulation en utilisant SITL comme simulateur. La première mission est relativement simple à réaliser. Donner un objectif au drone se fait en un clic droit et en choisissant Fly to, puis à donner l’altitude désirée. Il faut penser à armer les moteurs avant le lancement.

Comprendre MAVProxy
[[lien]](https://ardupilot.org/mavproxy/index.html#home)

MAVProxy permet de donner des commandes au drone dans la simulation. Par exemple on peut armer les moteurs, les désarmer, donner une mission au drone et plus généralement gérer le drone et la simulation.
MAVRos est un nœud ROS qui permet d’interagir avec ces commandes à travers ROS et donc de créer une interface entre les deux logiciels.

## La suite

Il faut maintenant essayer de mettre en place Gazebo comme simulateur et interfacer ArduPilot avec ROS.

## Gazebo

[Tutoriel suivi](https://ardupilot.org/dev/docs/using-gazebo-simulator-with-sitl.html#using-gazebo-simulator-with-sitl)

Première tentative ratée, la simulation se lance mais le drone n’apparaît pas. J’ai sûrement un problème d’installation ou de configuration.