#pragma once

#include <array>
#include <map>
#include <string>


namespace max_element
{	
	const std::map <std::string, std::array<double, 5>> productToOrders {
		{ std::string{"apples"}, {100.0, 200.0, 50.5, 30.0, 10.0}},
		{ std::string{"bananas"}, {80.0, 10.0, 100.0, 120.0, 70.0}},
		{ std::string{"carrots"}, {130.0, 75.0, 25.0, 64.5, 128.0}},
		{ std::string{"tomatoes"}, {70.0, 100.0, 170.0, 80.0, 90.0}}
	};

	namespace v1
	{
		// original max_length
		template <typename T>
		std::size_t MaxKeyLength(const std::map<std::string, T>& m)
		{
			if (m.empty())
				return 0;

			auto res = std::ranges::max_element(std::views::keys(m),
				[](const auto& a, const auto& b) {
					return a.length() < b.length();
				});
			return (*res).length();
		}
	}

	namespace v2
	{
		// max_length using projection
		template <typename T>
		std::size_t MaxKeyLength(const std::map<std::string, T>& m)
		{
			if (m.empty())
				return 0;

			auto res = std::ranges::max_element(std::views::keys(m),
				std::less{}, &std::string::length // <<
			);
			return (*res).length();
		}
	}

	void run(void)
	{
		std::cout << v1::MaxKeyLength(productToOrders) << '\n';
		std::cout << v2::MaxKeyLength(productToOrders) << '\n';
		std::cout << '\n';
	}
}

