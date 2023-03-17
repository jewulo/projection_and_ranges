#pragma once

#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <string_view>

namespace intro
{
	// member access:
	namespace member_access
	{
		void run()
		{
			std::cout << " **** intro member_access **** \n";

			std::pair<int, std::string_view> pairs[] = {
				{2, "foo"}, {1, "bar"}, {0, "baz"}
			};

			// member access:
			std::ranges::sort(pairs, std::ranges::less{},
				&std::pair<int, std::string_view>::first);

			std::cout << "[ ";
			for (auto items : pairs)
				std::cout << std::format("[{}, {}] ", items.first, items.second);
			std::cout << "]\n";

			std::cout << "\n";
		}
	}

	// lambda:
	namespace lambda
	{
		void run()
		{
			std::cout << " **** intro lambda **** \n";
			std::pair<int, std::string_view> pairs[] = {
				{2, "foo"}, {1, "bar"}, {0, "baz"}
			};

			// lambda:
			std::ranges::sort(pairs, std::ranges::less{},
				[](auto const& p) { return p.first; });

			std::cout << "[ ";
			for (auto items : pairs)
				std::cout << std::format("[{}, {}] ", items.first, items.second);
			std::cout << "]\n";

			std::cout << "\n";
		}
	}
}
