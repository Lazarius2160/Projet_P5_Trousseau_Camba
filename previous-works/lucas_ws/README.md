## Consignes d'installation
Le fichier associé est un fichier zip qu'il convient de deziper avant de commencer. Pour cela il est recommandé de passer par la commande suivante.
`unzip contribution.zip -d .`
par la suite il faut rentrer dans le répertoire, construire puis sourcer afin de recharger les fichiers des fonctions:

    cd catkin_ws
    catkin_make
    source devel/setup.bash

L'espace de travail est désormais construit. Il faut donc lancer la simulation via le shell avec les commandes suivantes :

    roslaunch sjtu_drone simple.lauch
    rosrun sjtu_drone drone_keyboard

Il faut penser à mettre la simulation en route via le bouton PLAY de l'interface de Gazebo. Enfin il suffit d'appuyer sur n'importe quelle touche pour que le drone effectue le trajet pré-enregistré.
## Modifier le trajet pré-enregistré
le trajet préenregistré se trouve dans le fichier DialogKeyboard.cpp. Pour le modifier il faut effectuer les commandes suivantes :

    cd src
    cd sjtu-drone
    cd src
    gedit DialogKeyBoard.cpp

Le trajet doit être rentré dans la zone délimitée par des commentaires prévus à cet effet.

Le trajet doit commencer par le décollage du drone avec la ligne :

    drone -> rise();
Pour le reste des déplacements il est conseillé d'utiliser uniquement les fonctions moveto(x,y,z) et yaw(x) qui permettent respectivement de se déplacer dans le repère cartésien et de tourner sur lui même. Il faut également coupler ces fontions avec des fonctions sleep(t) afin de donner la durée de l'étape. Voici un exemple possible présent comme trajet pré-enregistré. 

    ls adfdsf

Si l'on change le trajet préenregistré, il est nécessaire de reconstruire l'espace catkin afin que les changements soient pris en compte via la commande :

    catkin build

Enfin il est possible de préenregistrer plusieurs trajets via un SWITCH/CASE. Voici un exemple fournissant le code à rentrer 

    gdfgd
Dans ce cadre la, si l'utilisateur appuie sur la touche 'A' c'est le premier trajet qui est effectué. S'il appuie sur la touche 'B' c'est le second. Cela permet également à l'utilisateur de décomposer un trajet s'il le souhaite. 






  



<!--stackedit_data:
eyJoaXN0b3J5IjpbNjcyMzA5Nzc4XX0=
-->