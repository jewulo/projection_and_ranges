#pragma once

#include <iostream>
#include <map>
#include <ranges>
#include <vector>

namespace custom_algorithm
{
	namespace alg1
	{
		void PrintEx(const std::ranges::range auto& container, auto proj)
		{
			for (std::size_t i = 0; auto && elem : container)
				std::cout << std::invoke(proj, elem)
				<< (++i == container.size() ? "\n" : ",");

		}
	}

	namespace alg2
	{
		template <typename Proj = std::identity>
		void PrintEx(const std::ranges::range auto& container, Proj proj = {})
		{
			for (std::size_t i = 0; auto && elem : container)
				std::cout << std::invoke(proj, elem)
				<< (++i == container.size() ? "\n" : ",");
		}
	}

	void run(void)
	{
		std::vector<std::pair<int, char>> pairs{ {0, 'A'}, {1, 'B'}, {2, 'C'} };
		alg1::PrintEx(pairs, &std::pair<int, char>::first);
		alg1::PrintEx(pairs, &std::pair<int, char>::second);
		alg2::PrintEx(pairs, &std::pair<int, char>::first);
		alg2::PrintEx(pairs, &std::pair<int, char>::second);

		std::vector numbers { 1,2,3,4,5 };
		// alg1::PrintEx(numbers);	// DOES NOT COMPILE
		alg2::PrintEx(numbers);	// default proj
		alg1::PrintEx(numbers, [](auto& v) { return v * v; });
		alg2::PrintEx(numbers, [](auto& v) { return v * v; });

		std::map<std::string, int> words{ {"Hello", 1},{"World", 2} };
		alg1::PrintEx(words, [](auto& keyVal) { return keyVal.first; });
		alg1::PrintEx(words, &std::map<std::string, int>::value_type::second);
		alg2::PrintEx(words, [](auto& keyVal) { return keyVal.first; });
		alg2::PrintEx(words, &std::map<std::string, int>::value_type::second);
	}
}
