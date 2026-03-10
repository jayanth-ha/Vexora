#pragma once
#include <vector>
#include <string>

namespace vexora
{
    class DirectoryScanner
    {
        public:
            static std::vector<std::string> scan(const std::string& directory);
    };
}