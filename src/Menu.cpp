#include "Menu.h"
Menu::Menu(){
    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }


    if (!m_helpTex.loadFromFile("Help.png")) {
        // error...
        std::cout << "error loading font";

    }// meed to make it a function
    m_music=true;
    m_help.setTexture(m_helpTex);
    m_help.setOrigin(sf::Vector2f(m_help.getGlobalBounds().width / 2.f, m_help.getGlobalBounds().height / 2.f));
    m_help.setPosition(sf::Vector2f(700.f, 450.f));
    m_help.setScale(1.5, 1.5);
    m_helpPressed =false;
    /* m_buttons.push_back(new Button(700, 300, 150, 50, &this->m_font, "New Game",
                                    sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                    sf::Color(70, 20, 20, 200)));
     m_buttons.push_back(new Button(700, 380, 150, 50, &this->m_font, "Help",
                                    sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                    sf::Color(70, 20, 20, 200)));
     m_buttons.push_back(new Button(700, 460, 150, 50, &this->m_font, "Quit",
                                    sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                    sf::Color(70, 20, 20, 200)));*/
}

void Menu::createButton(string name,int x,int y)
{
    m_buttons.push_back(new Button(x, y, 150, 50, &this->m_font, name,
                                   sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                   sf::Color(70, 20, 20, 200)));
}

Button* Menu:: getButton(int i)
{
    return m_buttons[i];
}
sf::Sprite Menu::getHelp()
{
    return m_help;
}
int Menu::handleClick(sf::Vector2f mousePos,sf::RenderWindow& window)
{
   /* for(int i=0;i>m_buttons.size();i++)
    {
        switch (i) {
            case 0:*/
for(int i=0; i<m_buttons.size();i++)
{
    if(i!=1)
        if(checkBt(i, mousePos, window)) {
            std::cout << i<<std::endl;
            return i;
        }
    if(i==1)
    {
        std::cout<<"Help";
        if(!  helpBt(1, mousePos,window))
            if(!m_help.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                std::cout<<"out of bounce "<<std::endl;
                m_helpPressed = false;
                }
            }

}
    return -1;

}
bool Menu:: checkBt(int i, sf::Vector2f mousePos, sf::RenderWindow& window)
{
    if(m_buttons[i]->isPressed(mousePos))
    {

        return true;
    }
    return false;
}

bool Menu:: helpBt(int i,sf::Vector2f mousePos,sf::RenderWindow& window)
{
    if(m_buttons[i]->isPressed(mousePos))
    {
        m_helpPressed=true;
      //  window.draw(m_help);
       std:: cout<<"help"<<std::endl;
       return true;
    }
    return false;
}

bool Menu ::helpPressed(){
    return m_helpPressed;
};
void Menu ::setHelp(bool help)
{
    m_helpPressed=help;
}
void Menu:: updateBt(sf::RenderWindow& window)
{
    for (int i = 0; i < m_buttons.size(); i++) {
        window.draw(m_buttons[i]->render());
        window.draw(m_buttons[i]->drawText());
        m_buttons[i]->update(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

    }
}
void Menu::changeText(string text)
{
    m_buttons[3]->changeText(text);
}