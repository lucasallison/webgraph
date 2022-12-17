#include <iostream>
#include <string>

#include "edge_sort.h"
#include "similarity_sort/sim_sort.h"

const std::string SIM_SORT_ARG = "similarity";
const std::string CONVERT = "convert";

int main(int argc, char **argv)
{

	// TODO improve argument parsing
	if (argc != 4)
	{
		std::cerr << "Three arguments expected but "
				  << argc - 1 << " where given. Program should be called as follows: " << std::endl;

		std::cerr << "main sort_algorithm src_file dst_file" << std::endl;
		return -1;
	}

	const std::string sort_choice(argv[1]);
	Edge_Sort *edge_sorter = nullptr;

	if (sort_choice.compare(SIM_SORT_ARG) == 0)
	{
		edge_sorter = new Sim_Sort();
	}
	else if (sort_choice.compare(CONVERT) == 0)
	{
		edge_sorter = new Edge_Sort();
	}
	else
	{
		// TODO improve
		std::cerr << sort_choice << " sorting has not been implemented. Use: " << SIM_SORT_ARG << std::endl;
		return -1;
	}

	std::string edge_list(argv[2]);
	std::string dest_file(argv[3]);

	if (!edge_sorter->load_graph(edge_list))
	{
		std::cerr << "Failed to read edge list" << std::endl;
		return -1;
	}

	if (sort_choice.compare(CONVERT) == 0)
	{
		edge_sorter->convert_to_txt_graph(dest_file);
	}
	else
	{
		edge_sorter->sort(dest_file);
	}

	delete edge_sorter;

	return 0;
}
