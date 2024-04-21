function Load()
    num = 10
    step=1;
    isInit=false
    print("Lua inited!")
    LoadTileSet("Textures/Grass.png")
end

function Update()
    if num> 100 then step=-1 end
    if num< 10 then step=1 end
    num=num+step
end

function Draw()
    SetTile(0,0,0)
    SetTile(1,0,1)
    SetTile(2,0,2)
    SetTile(0,1,7)
    SetTile(1,1,8)
    SetTile(2,1,9)
    RenderTileMap()
    
end