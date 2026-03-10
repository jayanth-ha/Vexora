#pragma once
#include <vector>
#include <string>
#include <vexora/document_chunk.hpp>

namespace vexora
{
    class TextChunker
    {
        public:
            static std::vector<DocumentChunk> chunk(
                const std::string& text,
                const std::string& source_file,
                size_t chunk_size = 500
            );
    };
}