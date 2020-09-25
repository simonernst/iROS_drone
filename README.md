# iROS_drone

## Description

** TODO


## Installation

In a catkin workspace :

Ubuntu 16.04
```bash
git clone https://github.com/simonernst/iROS_drone
```
Ubuntu 18.04
```bash
git clone -b ubuntu18 https://github.com/simonernst/iROS_drone
```





## Utilisation


Lancement mode simulateur
```bash
roslaunch 
```
Lancement mode réel
```bash

```

## Debug



## TODO

### Dev
 - add gazebo models + directement intégré au pkg
 - add rotor_ws
 - add bebop_autonomy
 - add special launch file
 - values in range (fake_driver.cpp)
 - asservissement position
 - land/takeoff/stop -> position controller
 
 ### Admin
 - Rendu TP ?
 - Notation ?
 - Vidéo ?
 
 
 ### Sujet TP
 sujet TP (reprendre ancien + ajouter dev)
 Word -> PDF // Github wiki
 
 #### Partie 1 : Simulation
  - Prise en main de ROS (topic / rviz / rqt / dynamic reconfigure) -> demander des preuves
  - Développement interface manette
  - Mode Surveillance / Loisir -> Service
  
  
  
 #### Partie 2 : Réel
  - Test sur drone réel
  - Ajout de nouvelles commandes (Flips G/D F/B)
  
  Idées
  - commande en navigation
  - GPS
  - ROS actions
  - rosbag
  - Section bonnes pratiques et bon à savoir
  - Multidrones
  - Reconnaissance de personnes via drone (genre détection -> centrage -> prise d'une photo via snapshot)
      -> ecoute topic sur reconnaissance personne + prise d'une photo via un service (extension mode surveillance)

 
 
