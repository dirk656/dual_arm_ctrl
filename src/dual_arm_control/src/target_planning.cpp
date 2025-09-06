#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <memory>

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    
    auto const node = std::make_shared<rclcpp::Node>("target_planning_node", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

    auto const logger = rclcpp::get_logger("start");

    using moveit::planning_interface::MoveGroupInterface;

    auto move_group_interface = MoveGroupInterface(node ,"dummy2_right_arm");

    auto target = []{
        geometry_msgs::msg::Pose msg;
        msg.orientation.w = 0.0;
        msg.position.x = 1.0;
        msg.position.y = 0.0;
        msg.position.z = 0.0;
        return msg;

    }();
    move_group_interface.setPoseTarget(target);

    auto const [success, plan] = [&move_group_interface]{
       moveit::planning_interface::MoveGroupInterface::Plan msg;
        auto const ok = static_cast<bool>(move_group_interface.plan(msg));
        return std::make_pair(ok, msg);
    }();

  // 执行规划
    if(success) {
        move_group_interface.execute(plan);
   }else {
     RCLCPP_ERROR(logger, "规划失败!");
   }
   rclcpp::spin(node);
   rclcpp::shutdown();
   return 0;

   
}
