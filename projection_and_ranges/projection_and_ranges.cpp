// projection_and_ranges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://www.cppstories.com/2023/projections-examples-ranges/
#include <iostream>

#include "intro.h"
#include "sorting_structures.h"
#include "transform.h"
#include "max_element.h"
#include "custom_algorithm.h"
#include "max_element.h"
#include "custom_algorithm.h"

int main()
{
    intro::member_access::run();
    intro::lambda::run();

    sort::simple::run();
    sort::structure::run();

    transform::run();

    max_element::run();

    custom_algorithm::run();

    std::cin.get();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
