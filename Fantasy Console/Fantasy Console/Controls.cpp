#include "Controls.h"
#include <iostream>
#include "raylib.h"

Controls* Controls::instance = nullptr;

//Update Controllers data
 void Controls::UpdateVirtualJoystick()
 {
     vJoystick.buttonLeft = IsKeyDown(KEY_A);
     vJoystick.buttonRight = IsKeyDown(KEY_D);
     vJoystick.buttonUp = IsKeyDown(KEY_W);
     vJoystick.buttonDown = IsKeyDown(KEY_S);
     vJoystick.buttonX = IsKeyDown(KEY_LEFT);
     vJoystick.buttonB = IsKeyDown(KEY_RIGHT);
     vJoystick.buttonY = IsKeyDown(KEY_UP);
     vJoystick.buttonA = IsKeyDown(KEY_DOWN);
 }

 void Controls::UpdateVirtualMouse()
 {
     Vector2 mousePosition = GetMousePosition();
     vMouse.x = mousePosition.x;
     vMouse.y = mousePosition.y;
     vMouse.leftButton = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
     vMouse.rightButton = IsMouseButtonDown(MOUSE_RIGHT_BUTTON);
 }

 Controls::Controls()
 {
     vJoystick = { 0, 0, false, false };
     vMouse = { 0, 0, false, false };
 }

 Controls* Controls::getInstance()
 {
     if (!instance)
     {
         instance = new Controls();
     }
     return instance;
 }
