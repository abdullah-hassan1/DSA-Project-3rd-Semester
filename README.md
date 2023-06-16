# DSA-Project-3rd-Semester


-> DSA Project With GUI by SFML Library

->The Projrct use vector concept of physics to catch the player

-> Setup The SFML Library And Run The Code 

https://github.com/abdullah-hassan1/DSA-Project-3rd-Semester/assets/106105359/5674af47-bffc-473b-8ad6-fe754e3db81e

# Description

- The provided code is a C++ program that uses the SFML (Simple and Fast Multimedia Library) library to create a simple game. Let's go through the code and explain each part:

- The code includes two libraries: iostream for input/output operations and SFML/Graphics.hpp for graphics and window management.

- The code defines a struct called Position to represent a position with x and y coordinates.

- The code includes a function calculateDistance that calculates the distance between two points using the Euclidean distance formula.

- The main function is the entry point of the program.

- It creates an SFML RenderWindow object named window with a size of 3005x1790 pixels and a title "Game Press Esc. to Exit".

- Two RectangleShape objects are created: rect1 and obstacle. These rectangles will be used to draw the game elements on the window.

- Several variables are initialized, such as x, y, and i, which will be used in the drawing loop.

- Arrays obstaclesX and obstaclesY are initialized to store the x and y coordinates of obstacles. Similarly, arrays noObstaclesX and noObstaclesY store the coordinates of non-obstacle elements.

- The code enters a drawing loop that iterates 17 times. Each iteration represents a row of rectangles.

- Inside the loop, there is another loop that iterates 30 times, representing the columns of rectangles.

- In each iteration of the inner loop, a random number obstacleChance is generated. If obstacleChance is 0, an obstacle is drawn at the current position (x, y). Otherwise, a non-obstacle element is drawn.

- The x-coordinate is incremented by 100 in each iteration to move to the next column.

- After each row is drawn, the y-coordinate is incremented by 105, and the x-coordinate is reset to 2.

- After the drawing loop, the code loads player and enemy textures from image files using sf::Texture and displays an error message if the files are not found.

- sf::Sprite objects playerTextureSprite and enemyTextureSprite are created and associated with the loaded textures. The player sprite is positioned at the starting position (2, 6), and the enemy sprite is positioned randomly on a non-obstacle element.

- Variables playerPosition and isPlayerMoving are initialized to keep track of the player's position and movement state.

- A while loop starts for handling SFML events and updating the game state.

- The loop checks for various events, such as window close or keypress events.

- If the close event is triggered, the window is closed.

- If a keypress event occurs, the code checks the pressed key. If it's an arrow key, the player's position is updated based on the direction, but only if the target position is not an obstacle. The noObstaclesX and noObstaclesY arrays are checked to determine if the target position is valid.

- The player and enemy positions are updated accordingly.

- The code then checks if the player is moving. If so, it calculates the distance between the enemy and the player. If the distance is less than 7, the window is closed. Otherwise, the code calculates the direction from the enemy to the player, normalizes it, and updates the enemy's position based on the speed.

- The window is cleared, and all game elements are redrawn in their updated positions.

- The window is displayed, and the loop continues until the window is closed.

- Finally, after the window is closed, the code prints "U lose" to the console.

- In summary, the code creates a window and draws a grid of rectangles representing obstacles and non-obstacles. It allows the player to move using arrow keys while an enemy chases the player. If the enemy reaches the player, the game ends.
