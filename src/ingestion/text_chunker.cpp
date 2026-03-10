#include "text_chunker.hpp"

namespace vexora
{
    std::vector<DocumentChunk> TextChunker::chunk(
        const std::string& text,
        const std::string& source_file,
        size_t chunk_size)
    {
        std::vector<DocumentChunk> chunks;

        size_t start = 0;
        uint32_t index = 0;

        while(start < text.size())
        {
            std::string chunk_text = text.substr(start, chunk_size);
            
            DocumentChunk chunk;
            chunk.id = chunks.size();
            chunk.text = chunk_text;
            chunk.source_file =source_file;
            chunk.chunk_index = index++;

            chunks.push_back(chunk);

            start += chunk_size;
        }

        return chunks;
    }
}