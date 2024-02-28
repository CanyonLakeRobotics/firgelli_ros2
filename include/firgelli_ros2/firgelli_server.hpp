#pragma once

#include <rclcpp/rclcpp.hpp>

#include <firgelli_msgs/srv/position_command.hpp>

namespace firgelli_ros2
{

class FirgelliServer
{
public:
  FirgelliServer(std::shared_ptr<rclcpp::Node> node)
  : node_(node)
  , move_to_position_service_(node->create_service<firgelli_msgs::srv::PositionCommand>("position_command", std::bind(&FirgelliServer::moveToPosition, this, std::placeholders::_1, std::placeholders::_2)))
  {
    firgelli_.Open(1 /* rank, assumes just 1 device */);
    firgelli_.Info();
  }

private:
  void moveToPosition(const std::shared_ptr<firgelli_msgs::srv::PositionCommand::Request> request,
                      std::shared_ptr<firgelli_msgs::srv::PositionCommand::Response> /* response */)
  {
    int location = 0x20;
    int value = request->position_command;
    firgelli_.WriteCode(location, value);
  }


  std::shared_ptr<rclcpp::Node> node_;
  Firgelli firgelli_;

  rclcpp::Service<firgelli_msgs::srv::PositionCommand>::SharedPtr move_to_position_service_;
};

}  // namespace firgelli_ros2