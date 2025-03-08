#pragma once

#include <slog/slog.h>

namespace Common {

    inline SLogger g_Logger;

    inline SLogger* GetLogger()
    {
        if(!g_Logger.name)
            slogLoggerSetName(&g_Logger, "DoomClone");

        return &g_Logger;
    }
}