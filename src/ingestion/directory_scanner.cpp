#include "directory_scanner.hpp"
#include <filesystem>

namespace vexora
{
    std::vector<std::string> DirectoryScanner::scan(const std::string& directory)
    {
        std::vector<std::string> files;

        for(const auto& entry: std::filesystem::directory_iterator(directory))
        {
            if(entry.is_regular_file())
            {
                files.push_back(entry.path().string());
            }
        }

        return files;
    }
}