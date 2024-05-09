#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class OptionsMenu 
{
    public:
        OptionsMenu(float width, float height);

        void draw(RenderWindow& window);
        void MoveUp();
        void MoveDown();

        int OptionPressed() {
            return numberPlayers;
        }
        ~OptionsMenu();
    
    private:
        int numberPlayers;
        Font font;
        Text optionsMenu[2];
};