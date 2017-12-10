#include "../include/engine.hpp"
#include "../include/engine_constants.hpp"
#include "../include/engine_types.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

int main(int /*argn*/, char* /*args*/ [])
{
    ge::IEngine* gameEngine = ge::getInstance();
    std::string errMsg      = gameEngine->init_engine(ge::everything);

    if (!errMsg.empty())
    {
        std::cerr << errMsg << std::endl;
        return EXIT_FAILURE;
    }

    const std::string text_path = "./textures/texture.png";
    gameEngine->draw_texture(text_path);

    bool run_loop = true;
    ge::event event;
    while (run_loop)
    {
        while (gameEngine->read_event(event))
        {
            if (!event.msg.empty())
            {
                std::cout << event.msg << std::endl;
            }
            if (event.type == ge::events_t::shutdown)
            {
                run_loop = false;
                break;
            }
        }
        const std::string vertexes_path = "./config/texture_coord.txt";

        std::ifstream file(vertexes_path);
        if (!file.is_open())
        {
            std::cerr << "Can't open file with vertexes values" << std::endl;
            continue;
        }

        ge::triangle trLeft;
        ge::triangle trRight;

        file >> trRight >> trLeft;

        gameEngine->render_triangle(trLeft);
        gameEngine->render_triangle(trRight);

        gameEngine->swap_buffers();
    }
    gameEngine->uninit_engine();
    return EXIT_SUCCESS;
}
