#include <cstdio>

#include "firgelli_ros2/firgelli.h"
#include "firgelli_ros2/firgelli_server.hpp"

namespace firgelli_ros2
{
}  // namespace firgelli_ros2

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("firgelli_server");

  firgelli_ros2::FirgelliServer firgelli_server(node);

  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  executor.spin();

  printf("Shutting down\n");
  rclcpp::shutdown();
  return 0;
}
