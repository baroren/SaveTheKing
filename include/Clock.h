#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class Clock{
public:
    Clock(int time =0);
    std::string countDown();
    void reset();
private:
    sf::Clock m_clock;
    int m_time;
    int m_min,m_sec,m_extraTime;
   int deltaTime;
  std:: string m_sTime,st_min,st_sec;
};