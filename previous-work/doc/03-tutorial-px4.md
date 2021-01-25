# PX4

@date 20/07/2020

PX4 est un logiciel très similaire à ArduPilot qui remplit les mêmes objectifs à savoir la navigation. Pour simuler le drone on utilise également SITL et Gazebo. L'avantage de PX4 est qu'il est développé en collaboration avec les équipes de ROS et les deux outils sont donc compatibles plus facilement.

Avantages de cette solution :

- Compatible avec [ROS](https://dev.px4.io/v1.9.0/en/ros/)
- Compatible avec [Gazebo](https://dev.px4.io/v1.9.0/en/simulation/ros_interface.html)
- Navigation automatique (PX4 étant par essence un pilote automatique)
- Documentation précise et complète en ligne.
- Permet de simuler plusieurs types de drones - [Modèles disponibles avec Gazebo](https://dev.px4.io/v1.9.0/en/simulation/gazebo.html)

Linux version : Ubuntu 18.04 (et donc ROS Melodic)

## Installation

Simple et guidée en suivant [ce tutoriel](https://dev.px4.io/v1.9.0/en/simulation/ros_interface.html)

Permet de télécharger et installer ROS, PX4, SITL, Gazebo à l'aide d'un script.
Pour lancer la simulation j'ai pu avoir besoin de télécharger des modules de Python comme numpy.

## Tutoriels suivis

[Installation de SITL, ROS et Gazebo](https://dev.px4.io/v1.9.0/en/simulation/ros_interface.html)

Avant tout il faut commencer par cloner [Firmware](https://github.com/PX4/Firmware)

    cd
    git clone https://github.com/PX4/Firmware.git

Pour lancer une simulation sans ROS il suffit de suivre les instructions ci-dessous qui permettent d'avoir une simulation sous gazebo avec le quadrotor par défaut

    cd Firmware
    make px4_sitl gazebo
    
Pour une simulation utilisant ROS, suivre ces instructions

    cd <Firmware_clone>
    DONT_RUN=1 make px4_sitl_default gazebo
    source ~/catkin_ws/devel/setup.bash    # (optional)
    source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo
    roslaunch px4 mavros_posix_sitl.launch
    
Pour lancer la simulation j'ai pu avoir besoin de télécharger des modules de Python comme numpy. 
J'ai aussi installé gstream pour pouvoir build correctement après avoir lu [ceci](https://answers.ros.org/question/349159/mavros-px4-error-failed-to-import-packaging/)

    sudo apt-get install libgstreamer-plugins-base1.0-dev
    
## Lancement d'une mission (simple décollage)

Cloner notre repo suivant [ce tuto](https://gvipers.imt-lille-douai.fr/thibaut.felten/projet-ros/blob/master/README.md)

Enfin il faut suivre la même procédure que ci-dessus avant de lancer notre launch file:

    cd <Firmware_clone>
    DONT_RUN=1 make px4_sitl_default gazebo
    source ~/catkin_ws/devel/setup.bash    # (optional)
    source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo
    roslaunch px4 test.launch

Cela donne le rqt_graph suivant

![rqt_graph](doc/rosgraph-px4-test-launch-file.png)

Le drone Iris utilisé en simulation dans gazebo

![gazebo_screenshot](doc/images/Capture_d_écran_de_2020-07-20_16-50-10.png)

## Vol manuel avec un joystick

Pour utiliser un joystick dans la simulation, le plus simple est de télécharger QGroundControl [ici](http://qgroundcontrol.com/)

On peut alors lancer une simulation avec Gazebo par exemple:
    cd Firmware
    make px4_sitl gazebo_typhoon_h480
    
On lance QGroundControl et on configure le joystick en utilisant [ce tutoriel](https://docs.qgroundcontrol.com/master/en/SetupView/Joystick.html)

Il suffit alors d'armer le drone (on peut par exemple assigner un bouton à cette fonction) et de décoller en utilisant les joysticks de la manette (gauche pour l'altitude et droit pour l'inclinaison du drone)

A noter que selon la manette utilisée il peut y avoir des étapes de configuration supplémentaires (par exemple avec une manette PS4 sans fil)

## Changer de map ou de drone / Utiliser un debugger

Pour pouvoir changer de drone ou de map utilisée lors de la simulation, il suffit de customiser cette ligne:

    make px4_sitl [VIEWER_MODEL_DEBUGGER]
    
Viewer représente le simulateur, gazebo ou jmavsim par exemple.

Model représente le modèle de drone à utiliser.
Il existe de nombreux modèles de drone et autres engins disponibles en simulation, ceux compatibles avec Gazebo sont [ici](https://dev.px4.io/v1.9.0/en/simulation/gazebo.html#running-the-simulation)

On peut également utiliser un debugger, les options sont mutliples : ide, gdb, lldb... [Voir ici](https://dev.px4.io/v1.9.0/en/debug/simulation_debugging.html)

Enfin on peut rajouter un dernier argument World qui représente la map à utiliser, les différentes cartes pré-installées sont [ici](https://dev.px4.io/master/en/simulation/gazebo_worlds.html)

Pour avoir une liste exhaustive des possibilités offertes par l'outil:

    make px4_sitl list_vmd_make_targets
    
A noter que tous les champs ne sont pas nécessaires, on remplacera les champs inutilisés par _
Par exemple pour utiliser le drone par défaut (quadrotor iris) sur la carte sonoma_raceway on lancera:

    make px4_sitl gazebo___sonoma_raceway
    
Le premier lancement d'une nouvelle carte peut être un peu plus long car il faudra télécharger la carte.

## Accéder aux données des capteurs

MAVLink fonctionne sur un modèle similaire à ROS avec des publisher et subscriber.
Ainsi on peut accéder aux données des topics avec la commande listener.

Exemple: On lance une simulation, puis depuis la console utilisée pour lancer la simulation on utilise la commande listener pour accéder aux données des 5 derniers messages de l'acceleromètre:

    make px4_sitl gazebo___sonoma_raceway
    listener sensor_accel 5
    
Pour obtenir la liste des topics en cours on utilise la commande ci-dessous dans la console où on a lancé la simulation. Cela permet d'avoir une liste des capteurs présents sur le drone également.

    sensors status

## Accéder aux données des capteurs via ROS

Lors d'une simulation utilisant ROS, on peut accéder aux données des capteurs à l'aide de la commande rostopic echo.

La liste des topics liés au drone et notamment les données des capteurs se retrouve en utilisant simplement rostopic list et en s'intéressant aux lignes commençant par /mavros

    rostopic list | grep /mavros
    
On peut ainsi accéder aux données de la centrale à inertie par exemple avec la commande ci-dessous pour récupérer les accélérations ou l'orientation du drone.

    rostopic echo /mavros/imu/data
    
## Navigation et missions

Pour réaliser une mission, on peut utiliser QGroundControl afin de la planifier facilement.

On commence par lancer QGroundControl. 
On lance ensuite une simulation, par exemple

    make px4_sitl gazebo___sonoma_raceway
    
La simulation se lance, la carte affichée sur QGroundControl se met à jour et on peut alors préparer la mission.
Pour aller au plus simple et simplement donner un point de destination au drone, on clique sur takeoff dans le coin haut gauche de l'écran. On confirme à l'aide d'un slider en bas de l'écran. Cela va armer le drone et le faire décoller.
Ensuite, on peut cliquer sur la carte et choisir Go to location pour donner un point de destination au drone. Il faut à chaque fois confirmer avec le slider.

On peut également programmer une mission complète à l'aide du menu mission disponible via le bouton représentant uen trajectoire entre A et B. On a cette fois encore la carte, on peut ensuite donner au drone l'ordre de décoller,puis on désigne les points à visiter en ajoutant des waypoints. On peut aussi proposer de retourner au point de décollage. On upload la mission et on peut retourner au menu fly pour la lancer.