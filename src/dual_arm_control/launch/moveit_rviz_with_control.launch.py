from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_moveit_rviz_launch
from launch_ros.actions import Node
from launch import LaunchDescription

def generate_launch_description():
    # 配置MoveIt
    moveit_config = MoveItConfigsBuilder(
        "dummy2-dual-gripperv2", 
        package_name="dual_arm_control"
    ).to_moveit_configs()
    
    # 生成RViz启动描述
    rviz_launch = generate_moveit_rviz_launch(moveit_config)
    
    # 创建控制节点
    target_planning_node = Node(
        package='dual_arm_control',
        executable='target_planning',
        name='target_planning_node',
        output='screen'
    )
    
    # 合并所有组件
    return LaunchDescription([
        *rviz_launch.entities,
        target_planning_node
    ])
