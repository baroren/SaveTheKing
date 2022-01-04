#include "MainMenu.h"

MainMenu::MainMenu() {


    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }


    if (!m_helpTex.loadFromFile("Help.png")) {
        // error...
        std::cout << "error loading font";

    }// meed to make it a function




    m_help.setTexture(m_helpTex);
    m_titles.push_back(makeTitle(72, "Save  The  King",680.f,150.f));
    m_titles.push_back(makeTitle(32, "Dungeon  Edition",680.f,210.f));


    m_buttons.push_back(new Button(680, 300, 150, 50, &this->m_font, "New Game",
                                   sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                   sf::Color(70, 20, 20, 200)));
    m_buttons.push_back(new Button(680, 380, 150, 50, &this->m_font, "Help",
                                   sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                   sf::Color(70, 20, 20, 200)));
    m_buttons.push_back(new Button(680, 460, 150, 50, &this->m_font, "Quit",
                                   sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                   sf::Color(70, 20, 20, 200)));

    //m_gameObjects.push_back(new Mage(1000.f, 350.f, 1, 3, 0.17, 10,"W_Red_Idle_SPR.png", false));
    //m_gameObjects.push_back(new Orc(230.f, 300.f, 1, 4, 0.17, 12,true, "skeleton2_v2.png"));
    //m_gameObjects.push_back(new Orc(80.f, 300.f, 1, 4, 0.17, 13,true, "skull.png"));

}


void MainMenu::run(sf::RenderWindow &window) {


    m_help.setOrigin(sf::Vector2f(m_help.getGlobalBounds().width / 2.f, m_help.getGlobalBounds().height / 2.f));
    m_help.setPosition(sf::Vector2f(700.f, 350.f));
    m_help.setScale(1.5, 1.5);


    sf::Clock clock;
    float deltaTime = 0.0f;
    while (window.isOpen()) {


        deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color(34, 20, 26));


        for (int i = 0; i < 2; i++) {
            window.draw(m_titles[i]);
        }
        for (int i = 0; i < 3; i++) {
            window.draw(m_buttons[i]->render());
            window.draw(m_buttons[i]->drawText());

            m_buttons[i]->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

        }

       /* for (int i = 0; i < 2; i++) {
            window.draw(m_titles[i]);
        }*/





        /*  window.draw(m_startGameButton->render());
          window.draw(m_startGameButton->drawText());
          window.draw(m_helpButton->render());
          window.draw(m_helpButton->drawText());
          window.draw(m_quit->render());
          window.draw(m_quit->drawText());*/


        for (int i = 0; i < m_gameObjects.size(); i++) {
            m_gameObjects[i]->updateAndDraw(0, deltaTime, window);
        }


        if (m_buttons[1]->isPressed()) {
            window.draw(m_help);
        } else {
            m_buttons[1]->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

        }
        if (!m_help.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
            && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            m_buttons[1]->quit();
        }
        if (m_buttons[0]->isPressed()) {
            return;
            //    std::cout << "testtest";
        }
         //m_buttons[1]->quit();


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (m_buttons[2]->isPressed() || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        window.display();
    }
}

sf::Text MainMenu::makeTitle(int size, std::string text,float posX, float posY) {
    sf::Text title;
    title.setFont(m_font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(size);
    title.setString(text);
    title.setOrigin(sf::Vector2f(title.getGlobalBounds().width / 2.f,
                                 title.getGlobalBounds().height / 2.f));
    title.setPosition(sf::Vector2f(posX,posY));
    return title;

}