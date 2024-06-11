-- Game params
local screenWidth = 768
local screenHeight = 768
local tileSize = 16
local gridWidth = screenWidth // tileSize
local gridHeight = screenHeight // tileSize
local score=0
-- Snake postions
local snake = {
    { x = 5, y = 5 },
}
local direction = { x = 1, y = 0 }

-- Food pos
local food = { x = 10, y = 5 }

-- Update time
local updateTime = 0.1
local updateTimeChange=0.0001
local timer = 0
local minUpdateTime = 0.05
local maxUpdateTime = 0.5

local function DrawSquare()
    for x=0,gridWidth-1 do
        SetTile(x,0,10,0)
        SetTile(x,gridHeight-1,10,0)
    end 
    for y = 1, gridHeight - 2 do
        SetTile(0, y, 10, 0)
        SetTile(gridWidth - 1, y, 10, 0) 
    end
end
-- Reset params to default values
local function resetGame()
    snake = { { x = 5, y = 5 } }
    direction = { x = 1, y = 0 }
    food = { x = math.random(0, gridWidth-1), y = math.random(0, gridHeight-1) }
    timer = 0
    updateTime = 0.1 
    score=0
end

-- Init
function Load()
    LoadTexture("Textures/Grass.png")
    LoadTexture("Textures/Scale.png")
    InitializeTileMap()
end

-- Update every frame
function Update()
    local deltaTime = GetDeltaTime()
    timer = timer + deltaTime
    
    if timer >= updateTime then
        timer = 0
        if updateTime>minUpdateTime then
            updateTime=updateTime-updateTimeChange
        end
        -- Update snake pos
        local newHead = {
            x = snake[1].x + direction.x,
            y = snake[1].y + direction.y
        }

        -- Check collisions with grid
        if newHead.x < 0 or newHead.x >= gridWidth-1 or newHead.y < 0 or newHead.y >= gridHeight-1 then
            resetGame()
            return
        end

        -- check collisions with snake
        for i, segment in ipairs(snake) do
            if newHead.x == segment.x and newHead.y == segment.y then
                resetGame()
                return
            end
        end

        -- check collisions with food
        if newHead.x == food.x and newHead.y == food.y then
            -- Увеличение змейки и генерация новой еды
            table.insert(snake, 1, newHead)
            food = { x = math.random(1, gridWidth-2), y = math.random(1, gridHeight-2) }
            score=score+1
        else
            -- Move snake
            table.insert(snake, 1, newHead)
            table.remove(snake)
        end
    end

    -- Get joystick inputs
    local buttonLeft, buttonRight, buttonUp, buttonDown, buttonX, buttonB, buttonY, buttonA = GetVirtualJoystick()

    -- Update direction based on input
    if buttonLeft and direction.x == 0 then
        direction = { x = -1, y = 0 }
    elseif buttonRight and direction.x == 0 then
        direction = { x = 1, y = 0 }
    elseif buttonUp and direction.y == 0 then
        direction = { x = 0, y = -1 }
    elseif buttonDown and direction.y == 0 then
        direction = { x = 0, y = 1 }
    end

end

-- Draw The game 
function Draw()
    DrawSquare()
    -- Draws snake
    for i, segment in ipairs(snake) do
        DrawTexture(1, segment.x * tileSize, segment.y * tileSize, tileSize, tileSize, 0)
    end
    -- Draw food
    DrawTexture(0, 3*tileSize, 1*tileSize, food.x * tileSize, food.y * tileSize, tileSize, tileSize, tileSize, tileSize, 0, 7)
    DrawText("Score: "..score,screenWidth/2,0,20,1)
    RenderTileMap()
    
end