// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved

// Created by Aidan Lalonde-Novales
// Created on 2022-06-09
// This program rounds a number based on user input, using reference

#include <iostream>
#include <string>
#include <cmath>


void RoundNum(float &num, int roundTo) {
    // rounds the users number to their desired decimal place

    int roundUnit;
    roundUnit = pow(10, roundTo);

    // https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/
    num = (static_cast<float>(static_cast<int>(num * roundUnit + 0.5))
        / roundUnit);
}


int main() {
    // Takes user input, passes it to round function,
    // then outputs the rounded number

    std::string numString;
    std::string decimalString;
    float num;
    int decimal;

    std::cout <<
    "This program rounds a number based on user input.\n"
    << std::endl;

    // input
    std::cout << "Enter the number you want to round: ";
    std::cin >> numString;
    std::cout << "Enter decimal places to round to: ";
    std::cin >> decimalString;

    // process and output
    try {
        num = std::stof(numString);
        decimal = std::stoi(decimalString);
        if (decimal >= 0) {
            RoundNum(num, decimal);
            std::cout << "\nThe rounded number is " << num <<
            "." << std::endl;
        } else {
            std::cout <<
            "\nThe decimal places to round to cannot be negative."
            << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout <<
        "\nThat cannot be rounded. "
        "Please ensure you are entering valid numbers."
        << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
