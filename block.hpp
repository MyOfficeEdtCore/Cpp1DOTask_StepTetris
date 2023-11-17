#pragma once
#include <vector>

class Block {
public:
	const size_t BlockHeight;
	const size_t BlockWidth;

	using BlockLine = std::vector<int>;
	using BlockField = std::vector<BlockLine>;
	using BlockPosition = std::pair<int, int>;   //I would prefer structure

	BlockField field;
	BlockPosition upperLeft {};

	std::vector<std::vector<std::vector<int>>> possibleShape;

	explicit Block(const Configuration::BlockConfig &block_config)
	: BlockHeight(block_config.height)
	, BlockWidth(block_config.width)
	{
		field.resize(BlockHeight);
		for (auto i = 0; i < BlockHeight; i++)
		{
			field[i].resize(BlockWidth);
		}

		if (!block_config.random_possible_shape)
			possibleShape = block_config.possible_shape;
		else
		{
			//create random
		}
	}
};

bool operator!=(const Block& l, const Block& r)
{
	return l.field != r.field || l.upperLeft != r.upperLeft;
}


