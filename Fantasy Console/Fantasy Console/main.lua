function Load()
    num = 10
    step=1;
    isInit=false
    print("Lua inited!")

end

function Update()
    if num> 100 then step=-1 end
    if num< 10 then step=1 end
    num=num+step
end

function Draw()
    PlaceSprite("Textures/grass03.png",200+num,200,50,50)
    --tilemap draw
    for i=0,8 do
        for u=0,8 do
            PlaceTile("Textures/tile007.png",i,u)
        end
    end
    for i=300,500 do
        for u=100,300 do
            DrawPixel(i,u,5)
        end
    end
    
end