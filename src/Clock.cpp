#include "Clock.h"

Clock::Clock(int time)
{
    addedTime=0;
    m_subTime=0; //temps
    if(time>60) {
        m_extraTime=0;
        deltaTime=time%60;
        m_min = time / 60;
        m_sec = time % 60;
//        std::cout<<"ctor"<<m_sec<<deltaTime<<std::endl;
    }
    else if(time<60)
    {
        deltaTime=time;
        m_sec=time;
        m_min=0;

    }
    else {
        m_min=1;
        m_sec = 0;
    }

//  std::  cout <<m_sec;

}

std::string Clock::countDown() {
    m_time=(int )(m_clock.getElapsedTime().asSeconds());
    if(m_min==0&&m_sec==0)
    {

        std::cout<<"Game over";
        return "Game Over";

    }
//    std::cout <<" time"<<m_time<<":"<<m_sec<<"delta:"<<deltaTime<<std::endl;
   if ((int)(m_time)%60<60 && ((m_time%60-m_extraTime+m_sec)!=deltaTime ))
   {
     // std::cout<<"time : "<<m_time<<"::"<<m_sec<<std::endl;

       m_sec--;
   }else if((int)(m_time%60)>=deltaTime)
   {
       m_clock.restart().asSeconds();
       m_time=(int )(m_clock.getElapsedTime().asSeconds());
       m_extraTime=(m_time%60);
       deltaTime=59;
       m_sec=59;
//        std::cout <<"test "<<m_min <<deltaTime<<std::endl;
       m_min--;
   }

   if(m_min<10)
        st_min='0'+std::to_string(m_min);
   else
       st_min=std::to_string(m_min);

    if(m_sec<10)
        st_sec='0'+std::to_string(m_sec);
    else
    st_sec=std::to_string(m_sec);

    m_sTime=st_min+':'+st_sec;
  // std::cout << m_min<<":"<<m_sec<<std::endl;
   return m_sTime;
}
void Clock :: addTime()
{
    if(addedTime<1) {
        std::cout<<"clock add time"<<addedTime<<std::endl;

        m_time += 10;
        m_sec += 10;
        deltaTime+=10;
        if (m_sec > 59) {
            m_min++;
            deltaTime = m_sec = m_sec % 60;
            m_time = m_time % 60;
        }
    }
    addedTime++;

}
void Clock:: subTime()
{
    if(m_subTime<1) {
        std::cout<<"clock sub time"<<addedTime<<std::endl;

        m_time -= 10;
        m_sec -= 10;
        deltaTime-=10;
        if (m_sec < 0) {
            m_min--;
            deltaTime = m_sec = 60+m_sec % 60;
            m_time = 60+m_time % 60;
        }
    }
    m_subTime++;
}
void Clock:: reset() {

  m_clock.restart().asSeconds();

}