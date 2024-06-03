# firgelli_ros2

USB control of Actuonix and Firgelli actuators.

## Hardware setup

With a USB cable, connect the Actuonix linear motor control board to a Linux PC.

## udev rules

Add the current Linux user to a group called `dialout`.

Put a file named `50-firgelli.rules` in `/etc/udev/rules.d`. It should contain just one line:

`ATTRS{idVendor}=="04d8", ATTRS{idProduct}=="fc5f", GROUP="dialout", MODE="0666"`

## Dependencies

This work is based on the [StarmanSystems-Actuonix_Linux_tested](https://github.com/lucosmic/StarmanSystems-Actuonix_Linux_tested) repo. In fact, the `setall` script from that repo is still recommended (see below).

The [firgelli_msgs](https://github.com/CanyonLakeRobotics/firgelli_msgs) package is also required.

## Initial LAC settings

To set the initial LAC control values, clone the StarmanSystems package, build it, then run the `setall` script:

```bash
bash ./setall
```

## Usage

Launch with the "rank" of the actuator. If you have two actuators, the ranks would be `1` and `2`. You should also add a namespace for the node if you have multiple actuators.

`ros2 run firgelli_ros2 firgelli_server --ros-args -p rank:=1 -r __ns:=/actuator1`

`ros2 service call /actuator1/position_command firgelli_msgs/srv/PositionCommand position_command:\ 0\`
