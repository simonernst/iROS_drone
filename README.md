# iROS_drone

Pour toute question ou problème lié au TP drone (hors séance de TP), merci d'ouvrir une issue sur le repo suivant : https://github.com/simonernst/TP_drone/issues

Pour tout problème de compilation et d'erreurs liées à la simulation, merci de poser d'ouvrir une issue sur ce repo dans l'onglet "Issues"

## Prérequis

- Ubuntu 16.04
- ROS Kinetic + Gazebo 7

Si autre version de ROS, 
MELODIC (**Ubuntu 18**) voir [ici](https://github.com/simonernst/iROS_drone/tree/melodic)

NOETIC (**Ubuntu 20**) voir [ici](https://github.com/simonernst/iROS_drone/tree/noetic)

## Prise en main et installation

1. Créez votre workspace (cf Tuto ROS si besoin)
2. Depuis votre workspace

```bash
sudo apt-get install build-essential python-rosdep python-catkin-tools
cd $Votre_Workspace/src
git clone https://github.com/simonernst/iROS_drone
git clone https://github.com/ros-drivers/joystick_drivers
git clone https://github.com/AutonomyLab/bebop_autonomy.git
cd ..
rosdep update
rosdep install --from-paths src -i
catkin build
```

Ne pas oublier de sourcer son workspace après chaque compilation (```source devel/setup.bash```). Je vous recommande de l'écrire dans votre .bashrc

## Utilisation


Lancement mode simulateur
```bash
roslaunch rotors_gazebo mav_velocity_control_with_fake_driver.launch
```
Lancement mode réel
```bash
roslaunch bebop_driver bebop_node.launch
```

## Debug
