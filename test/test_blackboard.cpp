#include <iostream>

#include <era/blackboard/buffer.h>
#include <era/blackboard/observer.h>
#include <era/blackboard/notifier.h>

// ----------------------------------------------------------------------------------------------------

class Bla : public era::blackboard::Notifier<float>
{
public:

    void callback(const float& value)
    {
        std::cout << "callback: " << value << std::endl;
    }
};

// ----------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
    era::blackboard::Buffer b;
    b.initialize<float>(10);

    era::blackboard::Observer<float> observer(&b);

    b.registerNotifier(new Bla);

    for(unsigned int i = 0; i < 100; ++i)
    {
        b.add((float)i / 10);

        if (observer.changed())
            std::cout << observer.latest() << std::endl;
    }

    return 0;
}
