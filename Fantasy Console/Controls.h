#pragma once
struct VirtualJoystick 
{
    bool buttonLeft;
    bool buttonRight;
    bool buttonUp;
    bool buttonDown;
    bool buttonX;
    bool buttonB;
    bool buttonY;
    bool buttonA;
};
struct VirtualMouse 
{
    float x;
    float y;
    bool leftButton;
    bool rightButton;
};
class Controls 
{
private:
    static Controls* instance;
public:
    VirtualJoystick vJoystick;
    VirtualMouse vMouse;
    void UpdateVirtualJoystick();
    void UpdateVirtualMouse();
    Controls();
    ~Controls();
    static Controls* getInstance();
};