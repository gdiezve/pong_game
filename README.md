# Pong Game

This repository contains a customized version of the iconic Pong game, developed using C++ and SFML library. The following video shows how the game looks like.

https://github.com/gdiezve/pong_game/assets/49267946/a34ec0cc-177c-467a-8ec8-1461b864c868

## How to play

In order to be able to play the game, you can download the source code into your local machine and execute the file called *pong*.

Once you start the game, through the main menu you should be able to choose the number of players:
* If *1 Player* is selected, the right pad of the game will be controled by an AI, and the left one can be controled using the key arrows (**up** and **down** arrows of your keyboard).
* When *2 Players* option is selected, the right pad can be moved using the keys **W** to go **up** and **S** to move it **down**.

When the ball goes out of boundaries (right or left of the screen) will appear again at the middle of the screen, restarting the game; the score will be updated for the winner player of the set.

## Troubleshooting

If you have any problems executing the game, you can compile it by yourself; it will be necessary to have installed SFML in your computer (check the SFML installation guide here).

Once you have SFML installed in your system, try to execute the following commands from the project's main directory:

````
$ g++ -c PlayGame.cpp
$ g++ -c MainMenu.cpp
$ g++ -c OptionsMenu.cpp
$ g++ main.cpp -o pong MainMenu.o PlayGame.o OptionsMenu.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
````

This will generate again the executable file and you should be able to play the game by executing it from console:

````
$ ./pong
````
