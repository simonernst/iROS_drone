# iROS_drone

Pour toute question ou problème lié au TP drone (hors séance de TP), merci d'ouvrir une issue sur le repo suivant : https://github.com/simonernst/TP_drone/issues

Pour tout problème de compilation et d'erreurs liées à la simulation, merci de poser d'ouvrir une issue sur ce repo dans l'onglet "Issues"

## Prérequis

- Ubuntu 16.04
- ROS Kinetic + Gazebo 7

Si vous utilisez une autre version de ROS :

ROS MELODIC (**Ubuntu 18**) voir [ici](https://github.com/simonernst/iROS_drone/tree/melodic)

ROS NOETIC (**Ubuntu 20**) voir [ici](https://github.com/simonernst/iROS_drone/tree/noetic)

1. Création d'un workspace
```bash
mkdir -p ~/$VOTRE_WORKSPACE/src
```

2. Depuis votre workspace

```bash
cd ~/$VOTRE_WORKSPACE/src
sudo apt-get install build-essential python-rosdep python-catkin-tools
git clone https://github.com/simonernst/iROS_drone
git clone https://github.com/ros-drivers/joystick_drivers
git clone https://github.com/AutonomyLab/bebop_autonomy.git
cd ..
rosdep update
rosdep install --from-paths src -i -y
catkin build
```

Ne pas oublier de sourcer son workspace après chaque compilation (```source devel/setup.bash```). 

## Utilisation
Deux modes sont disponibles suivant la partie du TP dans laquelle vous serez:

- Lancement mode simulateur
```bash
roslaunch rotors_gazebo mav_velocity_control_with_fake_driver.launch
```
- Lancement mode réel
```bash
roslaunch bebop_driver bebop_node.launch
```
