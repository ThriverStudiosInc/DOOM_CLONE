#pragma once

#include <slog/slog.h>

#include <string>
#include <algorithm>

namespace Common {

    inline SLogger g_Logger;

    inline SLogger* GetLogger()
    {
        if(!g_Logger.name)
            slogLoggerSetName(&g_Logger, "DoomClone");

        return &g_Logger;
    }

    inline std::string toLowerCase(std::string str)
    {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }
}