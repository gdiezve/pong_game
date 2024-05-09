#include <SFML/Graphics.hpp>
#include "MainMenu.hpp" 
#include "PlayGame.hpp"
#include "OptionsMenu.hpp"

using namespace sf;

int main() {
    RenderWindow Menu(VideoMode(800, 600), "Main Menu");
    MainMenu mainMenu(Menu.getSize().x, Menu.getSize().y);
    int numPlayers = 1;

    while (Menu.isOpen()) {
        Event event;
        while (Menu.pollEvent(event)) {
            if (event.type == Event::Closed) {
                Menu.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return) {
                    RenderWindow Options(VideoMode(800,600), "Options Menu");
                    OptionsMenu optionsMenu(Options.getSize().x, Options.getSize().y);

                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) 
                    {
                        Options.close();
                        PlayGame(numPlayers);
                    }
                    if (x == 1) 
                    {
                        while (Options.isOpen()) {
                            Event aevent;
                            while (Options.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    Options.close();
                                }
                                if (aevent.type == Event:: KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        Options.close();
                                    }
                                    if (aevent.key.code == Keyboard::Up) {
                                        optionsMenu.MoveUp();
                                        break;
                                    }
                                    if (aevent.key.code == Keyboard::Down) {
                                        optionsMenu.MoveDown();
                                        break;
                                    }
                                    if (aevent.key.code == Keyboard::Return) {
                                        numPlayers = optionsMenu.OptionPressed() + 1;
                                        Options.close();
                                    }
                                }
                            }
                            Options.clear();
                            optionsMenu.draw(Options);
                            Options.display();
                        }
                    }
                    if (x == 2) {
                        Menu.close();
                    }
                    break;
                } 
            }
        }
        Menu.clear();
        mainMenu.draw(Menu);
        Menu.display();
    }
}