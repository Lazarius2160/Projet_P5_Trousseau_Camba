## SJTU Drone

@date: 01/07/2020

## Installation

Installé sans problèmes en suivant https://github.com/tahsinkose/sjtu-drone 

Lancement de la simulation

Launch file: *simple.launch*

Remarques concernant la simulation:

- Pas de navigation par points de passage a priori mais il existe une fonction moveTo dans le code source. Il faut tester son fonctionnement avec le topic posCtrl et CmdVel pour voir comment ceux-ci interagissent et si il est possible de donner un objectif au drone
- Possibilité de contrôler le drone avec un clavier. Il y a une interface propre au simulateur en utilisant rosrun sjtu_drone drone_keyboard
- La possibilité de contrôler le drone permettrait de tester les capteurs du drone pour faire du mapping par exemple

Tutoriel suivi

https://www.youtube.com/watch?v=l6hVfVK_YWw 

Tutoriel réalisé par The Construct pour simuler un drone à l’aide de SJTU_Drone.
Dans ce tutoriel il est expliqué les bases des différents plugins impliqués dans la simulation. Il est particulièrement intéressant si nous avons besoin plus tard de configurer le drone ou de modifier le modèle par exemple.
