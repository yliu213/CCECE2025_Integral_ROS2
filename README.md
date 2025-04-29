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
cd ~
sudo apt remove gz-garden
sudo apt install aptitude
sudo aptitude install gazebo libgazebo11 libgazebo-dev
cd ~/PX4-Autopilot
make px4_sitl_default gazebo-classic
```

Install Cyclone DDS:
```
cd ~
sudo apt install ros-humble-rmw-cyclonedds-cpp
source /opt/ros/humble/setup.bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp 
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
cd
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

### 4. Install Micro XRCE-DDS Agent & Client
Follow the guide at: https://docs.px4.io/main/en/ros2/user_guide.html#humble

### 5. Install the project
Here, assume you don't have a workspace
```
mkdir -p ros2_ws/src
cd ros2_ws/src  
git clone https://github.com/yliu213/CCECE2025_Integral_ROS2.git --recursive
cd ..
colcon build
source install/setup.bash  # source the workspace
```

### 6. Modify empty.world
```
code ~/PX4-Autopilot/Tools/simulation/gazebo-classic/sitl_gazebo-classic/worlds/empty.world
```
Add the following inside <world> block:
```
<plugin name="gazebo_ros_state" filename="libgazebo_ros_state.so">
      <ros>
        <namespace>/gazebo</namespace>
      </ros>
      <update_rate>250</update_rate>
</plugin>
```

### 7. Modify /.bashrc
```
cd
code ~/.bashrc
```  
add following contents in the end, replace <user> by your user name:
```
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/home/<user>/ros2_ws/src/setup/models
export GAZEBO_PLUGIN_PATH=~/PX4-Autopilot/build/px4_sitl_default/build_gazebo-classic:$GAZEBO_PLUGIN_PATH:
export IGN_GAZEBO_RESOURCE_PATH=$IGN_GAZEBO_RESOURCE_PATH:/home/<user>/ros2_ws/src/setup/models
```

## Run SLS SITL
### 1. Launch SITL environment
In a new terminal:
```
ros2 launch double_sls_qsf init.launch.py
```  
And click the start icon in gazebo
### 2. Run QGroundControl

### 3. Launch SITL controller launch script
In a new terminal:
```
ros2 launch double_sls_qsf ctrnode.launch.py
```
### 4. Open Dynamic Reconfigure GUI
In a new terminal:
```
ros2 run rqt_reconfigure rqt_reconfigure
```
* Move sliders to change gains and references
* Check tick-box "mission_enabled" to start set-point and trajectory tracking mission
* Based on PX4Vision vehicle default settings, you may want to decrease MC_ROLLRATE_D and MC_PITCHRATE_D and increase their K and I gains for better response.
