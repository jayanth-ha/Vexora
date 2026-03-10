#pragma once
#include <string>
#include <iostream>
#include <cstdint>

namespace vexora
{
    struct DocumentChunk
    {
        uint64_t id;
        std::string text;
        std::string source_file;
        uint32_t chunk_index;
    };
}