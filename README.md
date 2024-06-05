# Fantasy-Console

Fantasy-Console is a Lua-powered game engine that allows you to create and render 2D tile-based games. This project includes various APIs to manage tiles, textures, input, and physics, providing a comprehensive toolset for game development.

## Features

- **Tile Management:** Load, set, and render tiles on a grid.
- **Texture Management:** Load and draw textures with ease.
- **Input Handling:** Get virtual joystick and mouse input.
- **Physics Engine:** Check collisions between rectangles, circles, and points.
- **Quality of Life Utilities:** Create vectors, draw geometric shapes, and more.

## API Reference
### Tiles
#### InitializeTileMap(Required)
Initializes the tile map, setting all tile values to a default state.
```sh
InitializeTileMap()
```
#### SetTile
Sets a tile at the specified coordinates with given tileindex and textureindex
```sh
SetTile(x, y, tileIndex, textureIndex)
```
- 'x' (int): The x-coordinate of the tile.
- 'y' (int): The y-coordinate of the tile.
- 'tileIndex' (int): The index value for the tile.
- 'textureindex' (int): The index of texture for the tile(from LoadTexture).(optional)
#### RendereTileMap
Every call Renders the entire tile map on the screen.
```sh
RenderTileMap()
```
### Textures
#### LoadTexture
Loads a texture from Resources folder.
```sh
LoadTexture("Resources/texture.png")
```
#### DrawTexture
Draws a texture on the screen at the specified coordinates and dimensions.
```sh
DrawTexture(id, x, y, srcWidth, srcHeight, rotation)
DrawTexture(id, srcX, srcY, dstX, dstY, srcWidth, srcHeight, dstWidth, dstHeight, rotation, colorId)
```
### Input
#### GetVirtualJoystick
Retrieves the virtual joystick buttons state.
```sh
  local buttonLeft, buttonRight, buttonUp, buttonDown, buttonX, buttonB, buttonY, buttonA = GetVirtualJoystick()
```
#### GetVirtualMouse
Retrieves the state of the virtual mouse.
```sh
local Mouse.x, Mouse.y, buttonLeft, buttonRight = GetVirtualMouse()
```
#### GetDeltaTime
Gets the time elapsed since the last frame.
```sh
local deltaTime = GetDeltaTime()
```

# Fantasy-Console
## Tiles
### InitializeTileMap
### SetTile
### RenderTileMap
## Textures
### LoadTexture
### DrawTexture
### Input
##GetVirtualJoystick
##GetVirtualMouse
##GetDeltaTime
##Physic
### CheckCollisionRecs
### CheckCollisionCircles
### CheckCollisionPointRec
## QOL 
### CreateVector2
Vector2:Get
Vector2:Set
### DrawTriangle

