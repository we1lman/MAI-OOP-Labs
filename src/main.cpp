#include "four.cpp"
#include <iostream>

int main()
{
    try {
        Four num1{1, 2, 3};
        Four num2("321");

        std::cout << "num1: " << num1 << std::endl;
        std::cout << "num2: " << num2 << std::endl;

        Four sum = num1 + num2;
        std::cout << "num1 + num2: " << sum << std::endl;

        Four diff = num2 - num1;
        std::cout << "num2 - num1: " << diff << std::endl;

        std::cout << "num1 == num2: " << (num1 == num2) << std::endl;
        std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
        std::cout << "num2 > num1: " << (num2 > num1) << std::endl;

        Four copy = num1;
        std::cout << "copy of num1: " << copy << std::endl;

        Four moved = std::move(num2);
        std::cout << "moved num2: " << moved << std::endl;
        std::cout << "num2 после перемещения: " << num2 << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
