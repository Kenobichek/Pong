# Pong

Beginning of the game:
To start the game, go to the folder with the game and open the pong.exe file, also in this folder are the libraries to run the application, 
if suddenly the library you need is not found, you can find it on the site https://ru.dll-files.com/

Default settings:
You can change game settings in the configuration.json file.

Game functionality:
In order to start the game, you need to press the space bar. If the ball is out of bounds, 
it returns to the center of the map and in order for it to start moving, you need to press the spacebar again.
The user navigates using the up and down arrows.

Code implementation:
1. The code is written in C++.
2. The code uses OOP, each entity has its own class, there are also classes which responsible for handling game process.
   Inheritance is used: the bot and user class are inherited from the player.
   Using polymorphism: the vector stores pointers to players, both users and bots are added to this vector.
   Using encapsulation: the internal state of which classes are hidden from the outside world.
3. There is the use of a vector, a queue (in the bot class, to store the position where it needs to move), 
   the use of an unordered map in the control class. Lambdas where used for event handling.
4. Connected libraries SDL_ttf and SDL_image.
5. Using the observer pattern in the control class. When event happens, 
   all the listeners subscribed to this event are called.0
