#pragma once

struct html_disabled
{
    template<typename T>
    static void close( T * p )
    {
        p->remove_attribute("disabled");
    }
};

