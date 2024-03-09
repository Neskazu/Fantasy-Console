function Load()
    num = 10
    step=1;
    print("Lua inited!")
end

function Update()
    if num> 100 then step=-1 end
    if num< 10 then step=1 end
    num=num+step
end

function Draw()
    DrawCircle(400, 225, num, 1)
    DrawCircle(1, 1, 140, 2)
end