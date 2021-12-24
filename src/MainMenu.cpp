#include "MainMenu.h"

MainMenu::MainMenu()
{


    if (!m_font.loadFromFile("arcadeClassic.ttf"))
    {
        // error...
        std::cout<<"error loading font";

    }
    if (!m_skelTex.loadFromFile("skeleton2_v2.png"))
    {
        // error...
        std::cout<<"error loading font";

    }

    if (!m_helpTex.loadFromFile("Help.png"))
    {
        // error...
        std::cout<<"error loading font";

    }// meed to make it a function


    m_skeleton.setTexture(m_skelTex);
    m_help.setTexture(m_helpTex);
    makeTitle(m_title,72,"Save  The  King");
    makeTitle(m_second_title,32,"dungeon  Edition");
    this->m_startGameButton=new Button(680,300,150,50,&this->m_font,"New Game",
                                       sf::Color(70,70,70,200),sf::Color(70,3,150,200),
                                       sf::Color(70,20,20,200));
    this->m_helpButton=new Button(680,380,150,50,&this->m_font,"Help",
                                       sf::Color(70,70,70,200),sf::Color(70,3,150,200),
                                       sf::Color(70,20,20,200));
    this->m_quit=new Button(680,460,150,50,&this->m_font,"Quit",
                                  sf::Color(70,70,70,200),sf::Color(70,3,150,200),
                                  sf::Color(70,20,20,200));

}

void MainMenu::run()
{
    sf::RenderWindow window(sf::VideoMode(1400, 700), "Save The king Dungen edition");
    sf::CircleShape shape;

    m_title.setPosition(sf::Vector2f(680.f,150.f));
    m_second_title.setPosition(sf::Vector2f(680.f,210.f));//change into not hard coded
    m_skeleton.setPosition(sf::Vector2f(200.f,200.f));

    m_skeleton.setScale(10.f,10.f);
    m_help.setOrigin(sf::Vector2f(m_help.getGlobalBounds().width/2.f,m_help.getGlobalBounds().height/2.f));
    m_help.setPosition(sf::Vector2f(700.f,350.f));
    m_help.setScale(1.5,1.5);
    // auto bounds = m_title_sprite.getLocalBounds();

    //m_title_sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );
 // m_title_sprite.setPosition(sf::Vector2f(680.f,200.f));

    while (window.isOpen())
    {
        m_startGameButton->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

        m_helpButton->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
        m_quit->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(34,20,26));

        window.draw(m_title);
        window.draw(m_second_title);
        window.draw(m_startGameButton->render());
        window.draw(m_startGameButton->drawText());
        window.draw(m_helpButton->render());
        window.draw(m_helpButton->drawText());
        window.draw(m_quit->render());
        window.draw(m_quit->drawText());

        window.draw(m_skeleton);
        if(m_helpButton->isPressed())
        {
            window.draw(m_help);
        }else
        {
            m_helpButton->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

        }
        if(!m_help.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
           && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_helpButton->quit();
        }
        m_startGameButton->quit();
        if(m_quit->isPressed())
        {
            window.close();
        }


        window.display();
    }
}

void MainMenu::makeTitle(sf::Text& title,int size ,std::string text)
{
    title.setFont(m_font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(size);
    title.setString(text);
    title.setOrigin(sf::Vector2f(title.getGlobalBounds().width/2.f,
                                   title.getGlobalBounds().height/2.f));

}