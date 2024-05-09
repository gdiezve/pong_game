#include "OptionsMenu.hpp"

OptionsMenu::OptionsMenu(float width, float height) {

    if (!font.loadFromFile("res/font.ttf")) {
        cout << "Couldn't find font." << endl;
    }

    optionsMenu[0].setFont(font);
    optionsMenu[0].setFillColor(Color::White);
    optionsMenu[0].setString("1 Player");
    optionsMenu[0].setCharacterSize(70);
    optionsMenu[0].setOrigin(optionsMenu[0].getLocalBounds().width/2.f, optionsMenu[0].getLocalBounds().height/2.f);
    optionsMenu[0].setPosition(width/2.f, height/2.f - 120);

    optionsMenu[1].setFont(font);
    optionsMenu[1].setFillColor(Color::White);
    optionsMenu[1].setString("2 Players");
    optionsMenu[1].setCharacterSize(70);
    optionsMenu[1].setOrigin(optionsMenu[1].getLocalBounds().width/2.f, optionsMenu[1].getLocalBounds().height/2.f);
    optionsMenu[1].setPosition(width/2.f, height/2.f - 20);

    numberPlayers = -1;
}

OptionsMenu::~OptionsMenu() 
{

}

// Draw OptionsMenu
void OptionsMenu::draw(RenderWindow& window) {
    for (int i = 0; i < 2; ++i) {
        window.draw(optionsMenu[i]);
    }
}

// Move up
void OptionsMenu::MoveUp() {
    if (numberPlayers - 1 >= 0) {
        optionsMenu[numberPlayers].setFillColor(Color::White);

        numberPlayers--;
        if (numberPlayers == -1) {
            numberPlayers = 1;
        }

        optionsMenu[numberPlayers].setFillColor(Color(205, 41, 201));
    }
}

// Move down
void OptionsMenu::MoveDown() {
    if (numberPlayers + 1 <= 2) {
        optionsMenu[numberPlayers].setFillColor(Color::White);

        numberPlayers++;
        if (numberPlayers == 2) {
            numberPlayers = 0;
        }

        optionsMenu[numberPlayers].setFillColor(Color(205, 41, 201));
    }
}