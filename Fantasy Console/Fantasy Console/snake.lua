-- Параметры игры
local screenWidth = 800
local screenHeight = 450
local tileSize = 20
local gridWidth = screenWidth // tileSize
local gridHeight = screenHeight // tileSize

-- Позиция и направление змейки
local snake = {
    { x = 5, y = 5 },
}
local direction = { x = 1, y = 0 }

-- Позиция еды
local food = { x = 10, y = 5 }

-- Время обновления
local updateTime = 0.1
local timer = 0
local minUpdateTime = 0.05
local maxUpdateTime = 0.5

-- Функция перезапуска игры
local function resetGame()
    snake = { { x = 5, y = 5 } }
    direction = { x = 1, y = 0 }
    food = { x = math.random(0, gridWidth-1), y = math.random(0, gridHeight-1) }
    timer = 0
    updateTime = 0.1 -- Сброс скорости при перезапуске игры
end

-- Инициализация
function Load()
    LoadTexture("Textures/Grass.png")
    LoadTexture("Textures/Scale.png")
end

-- Обновление логики игры
function Update()
    local deltaTime = GetDeltaTime()
    timer = timer + deltaTime
    
    if timer >= updateTime then
        timer = 0

        -- Обновление позиции змейки
        local newHead = {
            x = snake[1].x + direction.x,
            y = snake[1].y + direction.y
        }

        -- Проверка столкновения с границами
        if newHead.x < 0 or newHead.x >= gridWidth or newHead.y < 0 or newHead.y >= gridHeight then
            resetGame()
            return
        end

        -- Проверка столкновения с телом змейки
        for i, segment in ipairs(snake) do
            if newHead.x == segment.x and newHead.y == segment.y then
                resetGame()
                return
            end
        end

        -- Проверка столкновения с едой
        if newHead.x == food.x and newHead.y == food.y then
            -- Увеличение змейки и генерация новой еды
            table.insert(snake, 1, newHead)
            food = { x = math.random(0, gridWidth-1), y = math.random(0, gridHeight-1) }
        else
            -- Перемещение змейки
            table.insert(snake, 1, newHead)
            table.remove(snake)
        end
    end

    -- Получение ввода от виртуального джойстика
    local buttonLeft, buttonRight, buttonUp, buttonDown, buttonX, buttonB, buttonY, buttonA = GetVirtualJoystick()

    -- Обновление направления на основе ввода
    if buttonLeft and direction.x == 0 then
        direction = { x = -1, y = 0 }
    elseif buttonRight and direction.x == 0 then
        direction = { x = 1, y = 0 }
    elseif buttonUp and direction.y == 0 then
        direction = { x = 0, y = -1 }
    elseif buttonDown and direction.y == 0 then
        direction = { x = 0, y = 1 }
    end

    -- Изменение скорости змейки на основе ввода
    if buttonX and updateTime > minUpdateTime then
        updateTime = updateTime - 0.01
    elseif buttonB and updateTime < maxUpdateTime then
        updateTime = updateTime + 0.01
    end
end

-- Отрисовка игры
function Draw()
    -- Отрисовка змейки
    for i, segment in ipairs(snake) do
        DrawTexture(1, segment.x * tileSize, segment.y * tileSize, tileSize, tileSize, 0)
    end

    -- Отрисовка еды
    DrawTexture(0, food.x * tileSize, food.y * tileSize, tileSize, tileSize, 0)
end