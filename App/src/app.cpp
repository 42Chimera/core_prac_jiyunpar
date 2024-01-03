#include "chimera.h"
#include <memory>

class App : public Chimera::Application {
    public:
        App() {};
        ~App() {};
};


std::unique_ptr<Chimera::Application> Chimera::CreateApplication() {
    return std::make_unique<Chimera::Application>();
}