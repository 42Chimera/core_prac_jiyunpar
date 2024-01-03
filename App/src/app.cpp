#include "chimera.h"

class App : public Chimera::Application {
    public:
        App() {};
        ~App() {};
};

int main(void) {
    App *app = new App();
    app->Run();
    delete app;
    return 0;
}