#include <thread>
#include <mutex>
#include <functional>
#include <string>
#include <iostream>
#include <chrono>
#include <cmath>
#include <unistd.h>


#include "hunter_base/hunter_base.hpp"

#define TEST_WITHOUT_SERIAL_HARDWARE

using namespace wescore;

int main(int argc, char **argv)
{
    std::string device_name;
    int32_t baud_rate = 0;

    if (argc == 2)
    {
        device_name = {argv[1]};
        std::cout << "Specified CAN: " << device_name << std::endl;
    }
    else if (argc == 3)
    {
        device_name = {argv[1]};
        baud_rate = std::stol(argv[2]);
        std::cout << "Specified serial: " << device_name << "@" << baud_rate << std::endl;
    }
    else
    {
        std::cout << "Usage: app_hunter_monitor <interface>" << std::endl
                  << "Example 1: ./app_hunter_monitor can1" << std::endl
                  << "Example 2: ./app_hunter_monitor /dev/ttyUSB0 115200" << std::endl;
        return -1;
    }

//hunter这个大致是对两种io的连接,和对接口信息的配置
    HunterBase hunter;
    hunter.Connect(device_name, baud_rate);


    //hunter.SetLightCommand({HunterLightCmd::LightMode::CONST_ON, 0, HunterLightCmd::LightMode::CONST_ON, 0});

    int count = 0;
    while (true)
    {
        hunter.SetMotionCommand(0.5, 0.2);

        if(count == 10)
        {
            // hunter.SetLightCommand({HunterLightCmd::LightMode::LIGHT_MODE_CONST_OFF, 0, HunterLightCmd::LightMode::LIGHT_MODE_CONST_OFF, 0});
            // hunter.DisableLightCmdControl();
        }

        auto state = hunter.GetHunterState();
        std::cout << "-------------------------------" << std::endl;
        std::cout << "control mode: " << static_cast<int>(state.control_mode) << " , base state: " << static_cast<int>(state.base_state) << std::endl;
        std::cout << "battery voltage: " << state.battery_voltage << std::endl;
        std::cout << "velocity (linear, angular): " << state.linear_velocity << ", " << state.angular_velocity << std::endl;
        std::cout << "-------------------------------" << std::endl;

        sleep(1);
        ++count;
    }

    return 0;
}