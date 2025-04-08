# QSF SLS Controller ROS2 Implementation

## Install/Getting Started  
### 1. Install Ubuntu 22.04 and PX4-Autopilot v1.15.4
Install Ubuntu 22.04:
```
wsl --install -d Ubuntu-22.04
```

Open Ubuntu 22.04 shell and check for system update:
```
sudo apt update
sudo apt upgrade
sudo apt install git # for downloading repo
git --version
```
Install PX4-Autopilot v1.15.4:
```
git clone https://github.com/PX4/PX4-Autopilot.git --branch v1.15.4 --recursive
cd ~/PX4-Autopilot
git submodule update
cd ~
bash ./PX4-Autopilot/Tools/setup/ubuntu.sh
cd ~/PX4-Autopilot
pip uninstall empy
pip install empy==3.3.4
make px4_sitl gz_x500
```

Since our SITL is done in gazebo-classic, so do:
```
sudo apt remove gz-garden
sudo apt install aptitude
sudo aptitude install gazebo libgazebo11 libgazebo-dev
make px4_sitl_default gazebo-classic
```

### 2. Install QGroundControl
Setup mirror network in your computer as follows:

This mode allows WSL2 to use the same IP address as the Windows host computer. \\
After this configuration, the QGC on the Windows host machine can directly talk to the WSL simulation without additional settings\\

#### 2.1 Check Windows 11 is newer than 22H2 and update your WSL:
```
wsl --update
```
Then open WSL Settings and set networking mode to mirrored.
   
#### 2.2 In the Windows user folder (C:\Users\$YOUR_USER_NAME), create .wslconfig:
```
[wsl2]
networkingMode=mirrored
dnsTunneling=true
firewall=true
autoProxy=true

[experimental]
# requires dnsTunneling but is also OPTIONAL
bestEffortDnsParsing=true
useWindowsDnsCache=true
```

#### 2.3 Restart WSL 
```
wsl --shutdown
wsl
```

#### 2.4 Check IP address in WSL
```
ifconfig
```

If ifconfig not found, run:
```
audo apt install net-tools
```

Then install QGroundControl on windows: https://docs.px4.io/main/en/dev_setup/dev_env_windows_wsl.html#qgroundcontrol

### 3. Install ROS2 Humble  
Install ROS2 humble
```
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
sudo apt install software-properties-common
sudo add-apt-repository universe
sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
sudo apt update && sudo apt upgrade -y
sudo apt install ros-humble-desktop
sudo apt install ros-dev-tools
source /opt/ros/humble/setup.bash && echo "source /opt/ros/humble/setup.bash" >> .bashrc
```
The above command is from https://docs.px4.io/main/en/ros2/user_guide.html#humble

Some python dependcies might be needed:
```
pip install --user -U empy==3.3.4 pyros-genmsg setuptools
```

Then install gazebo-ros package:
```
sudo apt update
sudo apt install ros-humble-gazebo-ros-pkgs
```

### 4. Install the project
```
cd catkin_ws/src  
git clone https://github.com/ANCL/ECE664_2025.git 
cd ..
catkin build
source devel/setup.bash  # source the workspace
```
### Troubleshooting

- **Authentication Issues**:  
  If you encounter errors during cloning (e.g., password authentication), generate a [GitHub Personal Access Token](https://github.com/settings/tokens) and use it in place of your password when prompted.

- **Build Errors**:  
  If there are errors related to missing headers or dependencies in the `mrotor_controller` folder:
  1. Open and add the following in `package.xml`:
     ```xml
     <exec_depend>controller_msgs</exec_depend>
     ```

  2. Open and edit `CMakeLists.txt`:
     - Add `controller_msgs` in the `find_package()` section:
       ```cmake
       find_package(catkin REQUIRED COMPONENTS controller_msgs)
       ```
     - Add `controller_msgs` to the `catkin_package()` section:
       ```cmake
       catkin_package(CATKIN_DEPENDS controller_msgs)
       ```

  After making these changes, rebuild the workspace:
  ```bash
  cd catkin_ws
  catkin build
  source devel/setup.bash

### 5. Modify parameters
```
code ~/PX4-Autopilot/build/px4_sitl_default/etc/init.d/airframes/4016_holybro_px4vision
```
Find and comment the following:
```
param set-default SYS_USE_IO 0
param set-default MAV_0_CONFIG 101
param set-default MAV_1_CONFIG 102
param set-default SER_TEL1_BAUD 921600
param set-default MPC_Z_TRAJ_P 0.3
param set-default SENS_CM8JL65_CFG 104
param set-default SENS_EN_PMW3901 1
param set-default BAT1_A_PER_V 36.364
param set-default BAT1_V_DIV 18.182
```
Save the changes. Then rebuild PX4
```
cd ~/PX4-Autopilot
make px4_sitl_default
```

### 6. Modify /.bashrc
```
code ~/.bashrc
```  
add following contents:
```
source /opt/ros/noetic/setup.bash
source ~/catkin_ws/devel/setup.bash
source ~/PX4-Autopilot/Tools/setup_gazebo.bash ~/PX4-Autopilot ~/PX4-Autopilot/build/px4_sitl_default

export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:~/PX4-Autopilot
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:~/PX4-Autopilot/Tools/simulation/gazebo-classic/sitl_gazebo-classic
export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:/usr/lib/x86_64-linux-gnu/gazebo-11/plugins
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/catkin_ws/src/ECE664_2025/controller_sitl_gazebo/models
```
## Run SLS SITL
### 1. Launch SITL environment
```
# in a new terminal
roslaunch controller_sitl_gazebo sitl_sls_empty_world.launch
```  
Note: If the vehicle model is not generated propeller in the GUI, try closing the terminal and launch again.
### 2. Run QGroundControl

### 3. Launch SITL controller launch script
```
# in a new terminal
roslaunch mrotor_controller drone1_sls_controller.launch
```
### 4. Open Dynamic Reconfigure GUI
```
# in a new terminal
rosrun rqt_reconfigure rqt_reconfigure
```
* Move sliders to change gains and references
* Check tick-box "mission_enabled" to start set-point and trajectory tracking mission
* Based on PX4Vision vehicle default settings, increase MC_ROLLRATE_D and MC_PITCHRATE_D to 0.004~0.008 for better transient response.
## Plot the Data
Plot the data you obtained using main_ccece25.m file in `MATLAB_Plot` folder by changing the name of the bag file in:
![image](https://github.com/user-attachments/assets/7584aca0-0345-45d9-8889-cc5074fbc41a)
