#include "MainMenu.h"

MainMenu::MainMenu() {


  
    m_font = Resources::instance().getFont();
///
    if (!m_music.openFromFile("Shrek.ogg")) {
        // error...
        std::cout << "error loading music";

    }


    m_titles.push_back(makeTitle(72, "Save  The  King",700.f,150.f));
    m_titles.push_back(makeTitle(32, "Dungeon  Edition",700.f,210.f));
    m_menu.createButton("NewGame",700,300);
    m_menu.createButton("Help",700,380);
    m_menu.createButton("Quit",700,460);
    m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(200,200), king,5,true));
    m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(200,900) ,mage,5, true));
    m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(1200,200) ,warrior,5 ,true));
    m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(1200,900) ,thief,5,true));
    m_gameObjects.push_back(make_unique<Mage>(sf::Vector2f(950, 200), fire, 5, true));



}


void MainMenu::run(sf::RenderWindow &window) {

    m_dwarves.push_back(make_unique<Dwarf>(sf::Vector2f(950, 300), dwarf, 3, false, sf::Vector2f(1, 0)));
    m_dwarves.push_back(make_unique<Dwarf>(sf::Vector2f(200, 300), dwarf, 3, false, sf::Vector2f(1, 0)));


    sf::Clock clock;
    float deltaTime = 0.0f;
    while (window.isOpen()) {


        deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color(34, 20, 26));


        for (int i = 0; i < m_titles.size(); i++) {
            window.draw(m_titles[i]);
        }
       m_menu.updateBt(window);
           m_dwarves[0]->move(LEFT,deltaTime);
           m_dwarves[1]->move(RIGHT, deltaTime);

       
      

        for (int i = 0; i < m_gameObjects.size(); i++) {
            m_gameObjects[i]->updateAndDraw(0, deltaTime, window);
        }

        for (int i = 0; i < m_dwarves.size(); i++) {
            m_dwarves[i]->updateAndDraw(0, deltaTime, window);
        }


        sf::Event event;
        if (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (m_menu.handleClick(window.mapPixelToCoords(sf::Mouse::getPosition(window)), window) == 0)
                    {
                        m_dwarves.clear();
                        return;
                    }
                    if(  m_menu.handleClick(window.mapPixelToCoords(sf::Mouse::getPosition(window)),window)==2)
                        window.close();
                    std::cout<<"yeah";


                }
            }
        }
        if(m_menu.helpPressed() )
            window.draw(m_menu.getHelp());


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
void MainMenu::changeText(string text)
{
    m_menu.getButton(0)->changeText(text);
    cout << text;

}
