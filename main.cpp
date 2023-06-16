#include <iostream>
#include <SFML/Graphics.hpp>

// Define a struct for positions
struct Position {
    int x;
    int y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

float calculateDistance(sf::Vector2f p1, sf::Vector2f p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(3005, 1790), "Game Press Esc. to Exit", sf::Style::Default);
    std::srand(static_cast<unsigned int>(time(nullptr)));


    //Rectangles Properties
    sf::RectangleShape rect1;
    rect1.setSize(sf::Vector2f(100, 100));
    rect1.setOutlineThickness(5);
    rect1.setOutlineColor(sf::Color::Black);


    //Obstacles Properties
    sf::RectangleShape obstacle;
    obstacle.setSize(sf::Vector2f(100, 100));
    obstacle.setOutlineThickness(5);
    obstacle.setFillColor(sf::Color::Black);
    obstacle.setOutlineColor(sf::Color::Black);

    int x = 2;
    int y = 6;
    int i = 0;

    int obstaclesX[900] = { 0 };
    int obstaclesY[900] = { 0 };
    int obstacleArrayIndex = 0;

    int noObstaclesX[900] = { 0 };
    int noObstaclesY[900] = { 0 };
    int noObstacleArrayIndex = 0;


    // darwing of rectangles starts
    while (i < 17)
    {
        for (int row = 0; row < 30; row++)
        {


            int obstacleChance = rand() % 4;

            if (obstacleChance == 0)
            {
                obstaclesX[obstacleArrayIndex] = x;
                obstaclesY[obstacleArrayIndex] = y;
                obstacle.setPosition(sf::Vector2f(x, y));
                window.draw(obstacle);
                obstacleArrayIndex++;
            }
            else
            {
                noObstaclesX[noObstacleArrayIndex] = x;
                noObstaclesY[noObstacleArrayIndex] = y;
                rect1.setPosition(sf::Vector2f(x, y));
                window.draw(rect1);
                noObstacleArrayIndex++;
            }

            x = x + 100;
        }
        y = y + 105;
        x = 2;
        i++;
    }   //drawing ends



    //player pic properties and load
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png"))
    {
        std::cout << "Player.png not found";
    }

    sf::Sprite playerTextureSprite;
    playerTextureSprite.setTexture(playerTexture);
    playerTextureSprite.setPosition(sf::Vector2f(2, 6));

    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("enemy.png"))
    {
        std::cout << "enemy.png not found";
    }


    //player pic properties and load
    sf::Sprite enemyTextureSprite;
    enemyTextureSprite.setTexture(enemyTexture);


    // Generate random position for the enemy within the window
    int randomIndex = std::rand() % noObstacleArrayIndex;
    int enemyX = noObstaclesX[randomIndex];
    int enemyY = noObstaclesY[randomIndex];
    enemyTextureSprite.setPosition(sf::Vector2f(enemyX, enemyY));

    // Movement variables for player
    sf::Vector2f playerPosition = playerTextureSprite.getPosition();        //get player position
    bool isPlayerMoving = false;

    // Movement variables for enemy
    Position enemyPosition(enemyX / 100, enemyY / 105);
    Position targetPosition = enemyPosition;
    float speed = 5.5f; // Adjust this value to control enemy speed   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))  // check for events
        {
            if (event.type == sf::Event::Closed)           //window will close if close is clicked
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)          // taking input for palyer movements
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    int targetIndex = -1;
                    int targetY = playerTextureSprite.getPosition().y - 105;
                    for (int i = 0; i < noObstacleArrayIndex; i++)
                    {
                        if (noObstaclesY[i] == targetY && noObstaclesX[i] == playerTextureSprite.getPosition().x)
                        {
                            targetIndex = i;
                            break;
                        }
                    }
                    if (targetIndex != -1) // Allow movement if found in noObstaclesY array
                    {
                        playerPosition.y -= 105;
                        isPlayerMoving = true;

                    }
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    int targetIndex = -1;
                    int targetY = playerTextureSprite.getPosition().y + 105;
                    for (int i = 0; i < noObstacleArrayIndex; i++)
                    {
                        if (noObstaclesY[i] == targetY && noObstaclesX[i] == playerTextureSprite.getPosition().x)
                        {
                            targetIndex = i;
                            break;
                        }
                    }
                    if (targetIndex != -1) // Allow movement found in noObstaclesY array
                    {
                        playerPosition.y += 105;
                        isPlayerMoving = true;

                    }
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    int targetIndex = -1;
                    int targetX = playerTextureSprite.getPosition().x - 100;
                    for (int i = 0; i < noObstacleArrayIndex; i++)
                    {
                        if (noObstaclesX[i] == targetX && noObstaclesY[i] == playerTextureSprite.getPosition().y)
                        {
                            targetIndex = i;
                            break;
                        }
                    }
                    if (targetIndex != -1)
                    {
                        playerPosition.x -= 100;
                        isPlayerMoving = true;

                    }
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    int targetIndex = -1;
                    int targetX = playerTextureSprite.getPosition().x + 100;
                    for (int i = 0; i < noObstacleArrayIndex; i++)
                    {
                        if (noObstaclesX[i] == targetX && noObstaclesY[i] == playerTextureSprite.getPosition().y)
                        {
                            targetIndex = i;
                            break;
                        }
                    }
                    if (targetIndex != -1)
                    {
                        playerPosition.x += 100;
                        isPlayerMoving = true;

                    }
                }
            }

        }

        // Update player position
        playerTextureSprite.setPosition(playerPosition);

        // Update enemy position
        if (isPlayerMoving) {
            sf::Vector2f enemyCurrentPosition = enemyTextureSprite.getPosition();
            float distanceToPlayer = calculateDistance(enemyCurrentPosition, playerPosition);

            if (distanceToPlayer > 5) //distanceToPlayer is length of vecter calculted by pathagorus theorem
            {
                if (distanceToPlayer < 7)
                {
                    window.close();
                }
                // Calculate the direction towards the player
                sf::Vector2f direction = playerPosition - enemyCurrentPosition;

                float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

                // Normalize the direction
                direction /= length;

                // Calculate the new enemy position based on speed
                enemyCurrentPosition += direction*speed;

                // Update the enemy sprite position
                enemyTextureSprite.setPosition(enemyCurrentPosition);
            }
        }

        window.clear();
        for (int i = 0; i < obstacleArrayIndex; i++)
        {
            obstacle.setPosition(sf::Vector2f(obstaclesX[i], obstaclesY[i]));
            window.draw(obstacle);
        }
        for (int i = 0; i < noObstacleArrayIndex; i++)
        {
            rect1.setPosition(sf::Vector2f(noObstaclesX[i], noObstaclesY[i]));
            window.draw(rect1);
        }
        window.draw(playerTextureSprite);
        window.draw(enemyTextureSprite);
        window.display();
    }

    std::cout << "U lose";

    return 0;
}
