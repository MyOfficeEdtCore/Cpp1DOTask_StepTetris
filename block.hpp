#pragma once
#include <array>

static constexpr size_t BlockHeight = 3;
static constexpr size_t BlockWidth = 3; 
using BlockLine = std::array<bool, BlockWidth>;
using BlockField = std::array<BlockLine, BlockHeight>;
using BlockPosition = std::pair<int, int>;

static constexpr BlockField possibleShape[] {
    BlockField{BlockLine{false,true,false}, BlockLine{false,true,false}, BlockLine{false,true,false}},
    BlockField{BlockLine{true, true,false}, BlockLine{false,true,false}, BlockLine{false,true,false}},
    BlockField{BlockLine{true, false,false}, BlockLine{true,true,false}, BlockLine{false,true,false}}
};

struct Block {
    BlockField field {};
    BlockPosition upperLeft {};
};

bool operator!=(const Block& l, const Block& r) {
    return l.field != r.field || l.upperLeft != r.upperLeft;
}


