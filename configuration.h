#pragma once
#include <vector>


class Configuration
{
public:
	struct BlockConfig
	{
		size_t height = 3;
		size_t width = 3;

		bool random_possible_shape = false;
		std::vector<std::vector<std::vector<int>>> possible_shape = {{{false,true,false}, {false,true,false}, {false,true,false}},
																	 {{true, true,false}, {false,true,false}, {false,true,false}},
																	 {{true, false,false}, {true,true,false}, {false,true,false}}};
	};

	struct BoardConfig
	{
		size_t height = 25;
		size_t width = 10;
	};

	struct RenderConfig
	{
		bool flag_write_file = false;
		bool flag_send_net = false;
	};

	enum RemoveLinesLogic
	{
		rllFullLines,
		rllThreeFullLines,
		rllNotRemove,
		rllNinetyPercent
	};

	void initConfiguration()
	{
		//read ini file

		//block_config =
		//board_config =
		//render_config =
		//remove_lines_logic =
	};

	BlockConfig  block_config;
	BoardConfig  board_config;
	RenderConfig render_config;
	RemoveLinesLogic remove_lines_logic = rllFullLines;
};
