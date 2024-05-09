#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

// Source for radial gradient: https://github.com/SFML/SFML/wiki/Source:-Radial-Gradient-Shader

void PlayGame(int numPlayers) {
    RenderWindow window(VideoMode(800, 600), "Pong Game");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Font font;
    if (!font.loadFromFile("res/font.ttf")) {
        cout << "Could not load font." << endl;
    }

    Text score;
    score.setFont(font);
    score.setCharacterSize(30);
    score.setFillColor(Color(248, 183, 246));

    FloatRect text_center = score.getLocalBounds();
    score.setOrigin(text_center.width/2, text_center.height/2); // NOT WORKING 
    score.setPosition(window.getSize().x/2.f, 10);
    score.setString("0 - 0");

    // Background
    Texture background_texture;
    if (!background_texture.loadFromFile("res/background.jpeg")) {
        cout << "Cannot load background file" << endl; 
    }

    RectangleShape background;
    background.setSize(Vector2f(window.getSize()));
    background.setPosition(0, 0);
    background.setTexture(&background_texture);

    // Pad1
    Texture pad_texture;
    if (!pad_texture.loadFromFile("res/pad.png")) {
        cout << "Cannot load pad file" << endl; 
    }
    pad_texture.setSmooth(true);

    Sprite pad1;
    pad1.setTexture(pad_texture);
    pad1.setPosition(Vector2f(window.getSize().x - 780, window.getSize().y/2.f));

    // Pad2
    Sprite pad2;
    pad2.setTexture(pad_texture);
    pad2.setPosition(Vector2f(window.getSize().x - 20 - pad2.getLocalBounds().width, window.getSize().y/2.f));
    // pad2.setOrigin(pad2.getLocalBounds().width / 2.f, pad2.getLocalBounds().height / 2.f);

    // Ball
    Texture ball_texture;
    if (!ball_texture.loadFromFile("res/ball.png")) {
        cout << "Cannot load ball file" << endl;
    }
    ball_texture.setSmooth(true);

    Sprite ball;
    ball.setTexture(ball_texture);
    ball.setPosition(Vector2f(window.getSize()) / 2.f);
    ball.setOrigin(ball.getLocalBounds().width/2.f, ball.getLocalBounds().height/2.f);

    // Sound
    SoundBuffer hit_buffer;
    if (!(hit_buffer.loadFromFile("res/hit.wav"))) {
        cout << "Cannot load hit.wav file" << endl;  
    }

    Sound hit;
    hit.setBuffer(hit_buffer);

    // States
    bool up = false;
    bool down = false;
    bool w_key = false;
    bool s_key = false;

    // Variables
    int yVelocityPad1 = 0;
    int xVelocityBall = -4;
    int yVelocityBall = -4;
    int yVelocityPad2 = 0;
    int pad1Score = 0;
    int pad2Score = 0;

    Event event;

    cout << "Game started" << endl;
    while (window.isOpen()) {
        // Process events
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    up = true;
                }

                if (event.key.code == Keyboard::Down) {
                    down = true;
                }
                if (event.key.code == Keyboard::W) {
                    w_key = true;
                }

                if (event.key.code == Keyboard::S) {
                    s_key = true;
                }
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    up = false;
                }

                if (event.key.code == Keyboard::Down) {
                    down = false;
                }

                if (event.key.code == Keyboard::W) {
                    w_key = false;
                }

                if (event.key.code == Keyboard::S) {
                    s_key = false;
                }
            }
        }

        //Movement logic for pad1
        if (up) {
            yVelocityPad1 = -5;
        }
        if (down) {
            yVelocityPad1 = 5;
        }
        if (up && down) {
            yVelocityPad1 = 0;
        }
        if (!up && !down) {
            yVelocityPad1 = 0;
        }
        
        pad1.move(0, yVelocityPad1);

        // Out of bounds check for pad1
        if (pad1.getPosition().y < 0) {
            pad1.setPosition(Vector2f(window.getSize().x - 780, 0));
        }
        if (pad1.getPosition().y > (window.getSize().y - pad1.getLocalBounds().height)) {
            pad1.setPosition(Vector2f(window.getSize().x - 780, window.getSize().y - pad1.getLocalBounds().height)); 
        }
        if (ball.getGlobalBounds().intersects(pad1.getGlobalBounds())) {
            xVelocityBall = -xVelocityBall;
            hit.play();
        }

        if (numPlayers == 1) {
            // Movement Pad2 (AI)
            if (ball.getPosition().y < pad2.getPosition().y) {
            yVelocityPad2 = -4;
            }
            if (ball.getPosition().y > pad2.getPosition().y) {
            yVelocityPad2 = 4;
            }
        } else if (numPlayers == 2) {
            // Movement Pad2 (Real Player)
            if (w_key) {
            yVelocityPad2 = -5;
            }
            if (s_key) {
                yVelocityPad2 = 5;
            }
            if (w_key && s_key) {
                yVelocityPad2 = 0;
            }
            if (!w_key && !s_key) {
                yVelocityPad2 = 0;
            }
        }

        pad2.move(0, yVelocityPad2);

        // Out of bounds check for pad2
        if (pad2.getPosition().y < 0) {
            pad2.setPosition(Vector2f(window.getSize().x - 20 - pad2.getLocalBounds().width, 0));
        }
        if (pad2.getPosition().y > (window.getSize().y - pad2.getLocalBounds().height)) {
            pad2.setPosition(Vector2f(window.getSize().x - 20 - pad2.getLocalBounds().width, window.getSize().y - pad2.getLocalBounds().height)); 
        } 
        if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds())) {
            xVelocityBall = -xVelocityBall;
            hit.play();
        }

        // Movement logic for ball
        ball.move(xVelocityBall, yVelocityBall);

        // Out of bounds check for ball
        if (ball.getPosition().y < 20) {
            yVelocityBall = -yVelocityBall;
        }
        if (ball.getPosition().y > (window.getSize().y - ball.getLocalBounds().height - 20)) {
            yVelocityBall = -yVelocityBall;
        }
        if (ball.getPosition().x < -ball.getScale().x) {
            pad2Score++;
            ball.setPosition(Vector2f(window.getSize()) / 2.f);
        }
        if (ball.getPosition().x > window.getSize().x) {
            pad1Score++;
            ball.setPosition(Vector2f(window.getSize()) / 2.f);
        }

        window.clear();

        // Drawing
        window.draw(background);
        window.draw(pad1);
        window.draw(pad2);
		window.draw(ball);

        // Score
        stringstream text;
        text << pad1Score << " - " << pad2Score;
        score.setString(text.str());
        window.draw(score);

        window.display();
    }
}