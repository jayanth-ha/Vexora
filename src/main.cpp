#include <spdlog/spdlog.h>
#include "ingestion/directory_scanner.hpp"
#include "ingestion/document_loader.hpp"
#include "ingestion/text_chunker.hpp"

int main()
{
    auto files = vexora::DirectoryScanner::scan("../docs");

    for(const auto& file : files)
    {
        auto text = vexora::DocumentLoader::load(file);

        auto chunks = vexora::TextChunker::chunk(text, file);

        spdlog::info("Loaded {} chunks from {}", chunks.size(), file);
    }

    return 0;
}