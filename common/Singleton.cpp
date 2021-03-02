#include"Singleton.h"

namespace myspace
{
    void Singleton::Init()
    {
        this->_isRunning = true;

    }
    void Singleton::Uninit()
    {
        this->_isRunning = false;
    }

    void Singleton::setCamereWidth(int width)
    {
        this->cameraWidth=width;
    }

    int Singleton::getCameraWidth()
    {
        return this->cameraWidth;
    }
    Singleton::Singleton() : _isRunning(false)
    {

    }
} //namespace myspace


