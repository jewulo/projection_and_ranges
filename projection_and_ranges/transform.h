#pragma once

#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>


namespace transform
{
	struct Product {
		std::string name;
		double value{ 0.0 };
	};

	void run(void)
	{
		std::vector<Product> prods{ 7, {"Box ", 1.0} };

		// standard version:
		std::transform(std::begin(prods), std::end(prods), std::begin(prods),
			[v = 0](const Product &p) mutable {
				return Product{ p.name + std::to_string(v++), 1.0};
			}
		);
		for (auto& p : prods) std::cout << p.name << ", ";
		std::cout << '\n';

		// ranges version:
		std::ranges::transform(prods, std::begin(prods),
			[v = 0](const std::string &n) mutable {
				return Product{ n + std::to_string(v++), 1.0 };
			},
			&Product::name);
		for (auto& p : prods) std::cout << p.name << ", ";
		std::cout << '\n';
	}

}