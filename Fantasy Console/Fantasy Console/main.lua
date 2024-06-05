function Load()
    x = 10
    y=10
    deltaTime=0
    v1 = CreateVector2(100, 100)
    v2 = CreateVector2(200, 100)
    v3 = CreateVector2(50, 0)
    isInit=false
    print("Lua inited!")
    InitializeTileMap()
    LoadTexture("Textures/Grass.png")
    LoadTexture("Textures/grass03.png")
    

end

function Update()
 local buttonLeft,buttonRight,buttonUp,buttonDown,buttonX,buttonB,buttonY,buttonA=GetVirtualJoystick()
 deltaTime=GetDeltaTime()
 if buttonRight then x=x+1*deltaTime print(x) end
end

function Draw()
    --DrawTexture(1,x,300,200,200,0);
    --DrawTexture(0,x,0,200,40,40,40,40,40,0,6);
    --DrawTriangle(v1,v2,v3,4)
    SetTile(math.floor(x),0,0)
    SetTile(math.floor(x)-1,0,-1)
    SetTile(0,0,0)
    SetTile(2,0,2)
    SetTile(2,0,2)
    SetTile(0,1,7)
    SetTile(1,1,8)
    SetTile(2,1,9)
    RenderTileMap()
    
end