# firgelli_ros2

## Hardware setup

With a USB cable, connect the Actuonix linear motor control board to a Linux PC.

## udev rules

Add the current Linux user to a group called `dialout`.

Put a file named `50-firgelli.rules` in `/etc/udev/rules.d`. It should contain just one line:

`ATTRS{idVendor}=="04d8", ATTRS{idProduct}=="fc5f", GROUP="dialout", MODE="0666"`

## Initial LAC settings

To set the initial LAC control values, clone the StarmanSystems package, build it, then run the `setall` script:

```bash
bash ./setall
```

## Usage

`ros2 run firgelli_ros2 firgelli_server`

`ros2 service call /position_command firgelli_msgs/srv/PositionCommand position_command:\ 0\`
