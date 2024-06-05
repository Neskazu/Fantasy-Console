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

