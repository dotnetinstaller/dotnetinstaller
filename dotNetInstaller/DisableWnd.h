#pragma once

struct close_enable
{
    template<typename T>
    static void close( T * p )
    {
        p->EnableWindow(TRUE);
    }
};

