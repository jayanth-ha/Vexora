#pragma once
#include <string>

namespace vexora
{
    class DocumentLoader
    {
        public:
            static std::string load(const std::string& path);
    };    
}
