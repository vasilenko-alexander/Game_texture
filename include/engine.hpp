#pragma once

#include "engine_export.hpp"
#include "engine_types.hpp"
#include <cstdlib>
#include <string>

namespace ge
{
    class GE_DECLSPEC IEngine
    {
    public:
        virtual ~IEngine();
        /**
         * init_options you can find in engine_constants.hpp
         */
        virtual std::string init_engine(std::string init_options) = 0;
        virtual bool read_event(event& event)                     = 0;
        virtual void uninit_engine()                              = 0;
        virtual void render_triangle(triangle& tr)                = 0;
        virtual void swap_buffers()                               = 0;
        virtual float get_time()                                  = 0;
        virtual triangle transform_triangle(const triangle& trSrc,
                                            const triangle& trDest,
                                            float alpha)   = 0;
        virtual void draw_texture(const std::string& path) = 0;
    };

    IEngine* GE_DECLSPEC getInstance();
    std::istream& GE_DECLSPEC operator>>(std::istream& is, vertex& v);
    std::istream& GE_DECLSPEC operator>>(std::istream& is, triangle& v);
}
