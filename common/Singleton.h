#pragma once
#include<map>
#include<memory>
#include<atomic>
#include<thread>
#include<mutex>

namespace myspace {
    class Singleton {
    public:
        static Singleton &GetInstance() {
            static Singleton _instance;
            return _instance;
        }
        void Init();
        void Uninit();
        std::unique_ptr<uint8_t[]> buffer;
        int getCameraWidth();
        void setCamereWidth(int width);

    private:
        std::atomic_bool _isRunning;
        Singleton();
        Singleton(const Singleton &o) = delete;
        int cameraWidth;
    };
}// namespace myspace
