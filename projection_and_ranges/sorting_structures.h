#pragma once

#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

namespace sort
{
	namespace simple
	{
		/*
		* Let’s start with something simple like sorting;
		* we can expand the example from the Standard:
		*/
		void run()
		{
			std::pair<int, std::string_view> pairs[] = {
				{2, "foo"}, {1, "bar"}, {0, "baz"}
			};

			// member access:
			std::ranges::sort(pairs, std::ranges::less{},
				&std::pair<int, std::string_view>::first);

			// a lambda
			std::ranges::sort(pairs, std::ranges::less{},
				[](auto const& p) { return p.first; });
		}
	}
	/*
	* Lets try sorting structures
	*/
	namespace structure
	{
		struct Box {
			std::string name;
			double w = 0.0;
			double h = 0.0;
			double d = 0.0;

			constexpr double volume() const { return w * h * d; }
		};

		void print(std::string_view intro, const std::vector<Box>& container)
		{
			std::cout << intro << '\n';
			for (const auto& elem : container)
				std::cout << std::format("{}, volume {}\n", elem.name, elem.volume());

			std::cout << '\n';
		}

		void run()
		{
			std::cout << " **** sorting_structures **** \n";
			const std::vector<Box> container{
				{"large cubic", 10, 10, 10}, {"large cubic", 3, 3, 3},
				{"large long", 10, 2, 2}, {"small", 3, 2, 2}
			};

			print(" * initial *", container); 

			// the ranges version:
			auto copy = container;
			std::ranges::sort(copy, {}, &Box::name);
			print("* after sorting by name *", copy);

			std::ranges::sort(copy, {}, &Box::volume);
			print("* after sorting by volume *", copy);
		}
	}

}