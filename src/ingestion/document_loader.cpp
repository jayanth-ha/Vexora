#include "document_loader.hpp"
#include <fstream>
#include <sstream>

namespace vexora
{
    std::string DocumentLoader::load(const std::string& path)
    {
        std::ifstream file(path);
        
        std::stringstream buffer;
        buffer << file.rdbuf();

        return buffer.str();
    }
}