#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height)
{
    if (!font.loadFromFile("res/font.ttf")) {
        cout << "Couldn't find font." << endl;
    }

    // Play button
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setOrigin(mainMenu[0].getLocalBounds().width/2.f, mainMenu[0].getLocalBounds().height/2.f);
    mainMenu[0].setPosition(width/2.f, height/2.f - 120);

    // Options button
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Options");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setOrigin(mainMenu[1].getLocalBounds().width/2.f, mainMenu[1].getLocalBounds().height/2.f);
    mainMenu[1].setPosition(width/2.f, height/2.f - 20);

    // Exit Button 
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Exit");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setOrigin(mainMenu[2].getLocalBounds().width/2.f, mainMenu[2].getLocalBounds().height/2.f);
    mainMenu[2].setPosition(width/2.f, height/2.f + 80);

    MainMenuSelected = -1;
}

MainMenu::~MainMenu() 
{

}

// Draw MainMenu
void MainMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_main_menu; ++i) {
        window.draw(mainMenu[i]);
    }
}

// Move up
void MainMenu::MoveUp() {
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected--;
        if (MainMenuSelected == -1) {
            MainMenuSelected = 1;
        }

        mainMenu[MainMenuSelected].setFillColor(Color(205, 41, 201));
    }
}

// Move down
void MainMenu::MoveDown() {
    if (MainMenuSelected + 1 <= Max_main_menu) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected++;
        if (MainMenuSelected == 3) {
            MainMenuSelected = 0;
        }

        mainMenu[MainMenuSelected].setFillColor(Color(205, 41, 201));
    }
}