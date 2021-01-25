# Évaluation Lucas.



## Résumé des échanges tous au long du stage:


Début du stage, du fait d'un historique avec Lucas et l'équipe enseignant en robotique, il lui est fortement déconseillé de travailler sur le sujet.

Des échanges en début de stage pour l'aider à configurer un environnement de travail (19/06).

Je témoigne le 19/07 de mes doutes sur l'implication de Lucas dans le projet. En réponses, mes doutes seraient infondés, mais je n'ai pas beaucoup plus d'éléments concrets sur des réalisations (une promesse d'un rapport qui ne viendra pas). Lucas choisit de se focaliser sur du code C++/ROS qui permet de prendre la main sur le drone.

En rendu, j'ai une première version du rapport le 01/09, mais toujours aucune contribution via le dépôt git mis en place pour partager les avancés.


## Rapport dans sa version 1:

**Esthétique:**

- Sobre et très aéré lui permettant d'atteindre un honorable 21 pages.
- Aucune figure ou illustration.


**Résumé:** 

- Une liste de ce qu'il y avait à faire dans le projet.

**Intro**

- Contexte OK.
- Coquille rendant une phrase illisible (sur les 5 phrases que compte l'intro). Une intro se doit d'être impeccable au moins sur la forme.
- À minima un plan de comment est structuré le rapport est attendu en intro.

**Contexte**

- Présentation du contexte de stage lié à la pandémie.
- "L'IMT Lille Douai ayant vu mes efforts et mon implication dans la recherche de stage" : non le fait que l'école te propose la réalisation d'un projet en échange d'un stage ne prouve pas cette affirmation. C'est une voie de secours proposé à tous les étudiants n'ayant pas trouvé de stage. Est-ce que tu as d'autres éléments qui permettent de valider l'affirmation celons laquelle l'école à reconnue tes efforts ?
- 1er parti de la Section de contexte COVID qui aurait davantage ça place dans une section sur les acquis du stage.
- 2de partie de contexte sur le déroulement chronologique du stage.
- Section illisible pour toute personne non familière de Linux et ROS. Une présentation de ces technologies (+ Gazebo) dans une perspective Drone en guise de contexte aurait été inintéressante (en plus de permettre aux lecteurs de valider qu'en effet le stagiaire s'est formé sur ces technos. Dans l'état on ne peut que croire l'auteur sur parole.) 


## A - État de l'art.

- De nouveau un rendu trop chronologique... on attend d'un état de l'art un plan du type:
	+ présentation du problème auquel doit répondre la solution.
	+ Présentation du protocole de test et des critères d'évaluation.
	+ Liste des solutions investiguée (peut être inversé avec protocole/critères).
	+ Comparaison croisée des solutions par rapport aux critères (avec des tableaux c'est idéal).
- L'état de l'art n'est pas plus riche que la lecture des documentations des différentes solutions, et encore il est difficile de voir comment s'articulent ces solutions (par exemple: SJTU et un fork de TUM tous deux basé sur Gazebo...). 


## B - Retour d'expérience sur SJTU.

Section qui fait l'état d'un bug débugger (Expérimentation qui tourne cours, pas d’intégration dans ROS et donc pas de compilation du code) et de conclusion hâtive sur la qualité de SJTU. 
Je n'ai pas compris pourquoi via teleop_twist "les déplacements paraissent plus réalistes et adaptés.

## C - Supervision.

Présentation des noeuds/topic ??? Confusion entre ces deux termes recouvrant pourtant des objectés très différent dans ROS.
À minima un schéma ici permettrait de mieux se rendre compte de l'architecture d'éployé par SJTU.


## Acquis sur le projet.

Cette section manque dans le rapport. Je n'ai aucun élément par exemple sûr comment s'est répartie le travail avec ton binôme.


## Ce qui ressort des actions menées.

- Installation d'un environnement de travail
- S'est formé Linux/ROS 
- À regarder beaucoup de vidéo YouTube
- Contrôle à la manette ROS
- Participation à l'état de l'art ? (aucune contribution à l'état de l'art sur gitlab)
	+ Mon analyse de l'état de l'art réalisé: des essais d'installations de solution jusqu'à en trouver une qui marche pas trop mal out-of-the-box.
- Installation et expérimentation sur SJTU car il est le plus facile à utiliser.
- Mais une intégration qui tourne court, dû à des difficultés techniques. Dommage que ces difficultés n'ai pas initié un échange avec moi alors que je t'ai fait part de mon étonnement que tu n'as pas de difficulté particulière dans mon mail de mi-juillet.
- Exécution des commandes permettant de visualiser les noeuds en cours d'exécutions et les topics associés (30 minutes)

Je n'ai aucun élément code. Il faudrait à minima: 

1. l'archive de ton travail accompagné d'un Readme me permettant de l'installer et de l'expérimenter.
2. Un document de type tutoriel qui explique pas-à-pas ce que je dois mettre dans mon code C++ pour avoir un Noeud *moveto* fonctionnant pour un drone dans l'environnement de simulation que tu proposes.
3. La réécriture du rapport.


