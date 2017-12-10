#pragma once

#include "engine_export.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace ge
{
    enum class keys
    {
        nobutton,
        up,
        down,
        left,
        right,
        pause,
        select,
        button1,
        button2
    };

    enum class events_t
    {
        noevent,
        pressed,
        released,
        shutdown
    };

    struct event
    {
        std::string msg;
        events_t type = events_t::noevent;
        keys key      = keys::nobutton;
    };

    struct GE_DECLSPEC vertex
    {
        float x = 0.f;
        float y = 0.f;
    };

    struct GE_DECLSPEC triangle
    {
        std::vector<vertex> v = { vertex(), vertex(), vertex() };
    };

    struct GE_DECLSPEC texture
    {
        std::vector<vertex> coord      = { vertex(), vertex(), vertex() };
        std::vector<vertex> norm_coord = { vertex(), vertex(), vertex() };
    };
}
