#include "MainMenu.h"

MainMenu::MainMenu() {


    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }





    //m_help.setTexture(m_helpTex);
    m_titles.push_back(makeTitle(72, "Save  The  King",700.f,150.f));
    m_titles.push_back(makeTitle(32, "Dungeon  Edition",700.f,210.f));

    m_menu.createButton("NewGame",700,300);
    m_menu.createButton("Help",700,380);
    m_menu.createButton("Quit",700,460);
    m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(100,200), 1, 3, 0.17, 5, "Dwarf.png", true));
   m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(900,300), 2, 4, 0.17, 5, "King.png", false));
    m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(100,400) ,1, 3, 0.17, 5, "Mage.png", true));

}


void MainMenu::run(sf::RenderWindow &window) {


    sf::Clock clock;
    float deltaTime = 0.0f;
    while (window.isOpen()) {


        deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color(34, 20, 26));


        for (int i = 0; i < 2; i++) {
            window.draw(m_titles[i]);
        }
       m_menu.updateBt(window);

        /* for (int i = 0; i < 2; i++) {
             window.draw(m_titles[i]);
         }*/




        // printHelp(window,m_menu.getButton(1));
        /*  window.draw(m_startGameButton->render());
          window.draw(m_startGameButton->drawText());
          window.draw(m_helpButton->render());
          window.draw(m_helpButton->drawText());
          window.draw(m_quit->render());
          window.draw(m_quit->drawText());*/


        for (int i = 0; i < m_gameObjects.size(); i++) {
            m_gameObjects[i]->updateAndDraw(0, deltaTime, window);
        }



        /*     if (m_buttons[0]->isPressed()) {
                 return;
                 //    std::cout << "testtest";
             }
              //m_buttons[1]->quit();
              */

       // window.draw(m_menu.getHelp());
        sf::Event event;
        if (window.pollEvent(event)) {
        //    m_menu.getButton(1)->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                  if(  m_menu.handleClick(window.mapPixelToCoords(sf::Mouse::getPosition(window)),window)==0)
                      return;
                    if(  m_menu.handleClick(window.mapPixelToCoords(sf::Mouse::getPosition(window)),window)==2)
                        window.close();
                    std::cout<<"yeah";


                }
            }
        }
        if(m_menu.helpPressed() )
            window.draw(m_menu.getHelp());


        /*if (m_buttons[2]->isPressed() || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
         */

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
/*void MainMenu::printHelp(sf::RenderWindow & window,Button *button)
{
    if (button->isPressed()) {
        window.draw(m_menu.get);
    } else {
        //  m_buttons[1]->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

    }
    if (!m_help.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
        && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        button->quit();
    }
}*/