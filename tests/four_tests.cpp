#include <gtest/gtest.h>
#include <stdexcept>
#include "../src/four.cpp"  // Убедитесь, что путь к файлу корректен

// Тест конструктора по умолчанию
TEST(FourTest, DefaultConstructor)
{
    Four numberDefault;

    ASSERT_EQ(numberDefault.getSize(), 0);                 // Проверяем, что размер равен 0
    ASSERT_EQ(numberDefault.getData(), nullptr);           // Проверяем, что данные равны nullptr
}

// Тест конструктора с некорректной цифрой
TEST(FourTest, IncorrectDigitConstructor)
{
    EXPECT_THROW(Four number(1, '4'), std::invalid_argument); // '4' недопустима в 4-ой системе
    EXPECT_THROW(Four number(1, 'a'), std::invalid_argument); // 'a' недопустима
}

// Тест конструктора с некорректной длиной
TEST(FourTest, IncorrectLengthConstructor)
{
    EXPECT_THROW(Four number(0, '0'), std::invalid_argument); // Длина 0 недопустима
}

// Тест конструктора с инициализацией списка
TEST(FourTest, InitListConstructor)
{
    Four expected("333"); // Представляет число 333 в 4-ой системе

    Four number{3, 3, 3};

    ASSERT_TRUE(number == expected);
}

// Тест конструктора с инициализацией списка с некорректными цифрами
TEST(FourTest, IncorrectDigitInitListConstructor)
{
    EXPECT_THROW(Four({'4'}), std::invalid_argument);                       // '4' недопустима
    EXPECT_THROW(Four({'1', '2', '4', '0'}), std::invalid_argument);        // '4' недопустима
    EXPECT_THROW(Four({'1', '4', '3', '0', '2'}), std::invalid_argument);   // '4' недопустима
}

// Тест конструктора из строки
TEST(FourTest, StringConstructor)
{
    Four expected{3, 2, 2}; // Представляет число 223 в 4-ой системе

    Four number("223");

    ASSERT_TRUE(number == expected) << "Ожидалось, что число '223' будет равно {3, 2, 2}, но получили: " << number;
}


// Тест конструктора из строки с некорректными цифрами
TEST(FourTest, IncorrectDigitStringConstructor)
{
    EXPECT_THROW(Four("4"), std::invalid_argument);        // '4' недопустима
    EXPECT_THROW(Four("12340"), std::invalid_argument);    // '4' недопустима
    EXPECT_THROW(Four("14302"), std::invalid_argument);    // '4' недопустима
}

// Тест копирующего конструктора
TEST(FourTest, CopyConstructor)
{
    Four number1("1233"); // Представляет число 1233 в 4-ой системе

    Four number2{number1};

    ASSERT_TRUE(number1 == number2);
}

// Тест конструктора перемещения
TEST(FourTest, MoveConstructor)
{
    Four numberOriginal("1231"); // Представляет число 1231 в 4-ой системе
    Four expected{numberOriginal};

    Four number{std::move(numberOriginal)};

    ASSERT_TRUE(number == expected);
    ASSERT_EQ(numberOriginal.getSize(), 0); // После перемещения размер должен быть 0
    ASSERT_EQ(numberOriginal.getData(), nullptr); // После перемещения данные должны быть nullptr
}

// Тест оператора присваивания
TEST(FourTest, AssignmentOperator)
{
    Four number2("3223"); // Представляет число 3223 в 4-ой системе

    Four number1;
    number1 = number2;

    ASSERT_TRUE(number1 == number2);
}

// Тест на оператор "==": проверка равенства одинаковых чисел
TEST(FourTest, Equality_SameNumbers)
{
    Four number1({2, 3});   // Представляет число 32 в 4-ой системе (развернуто: 23)
    Four number2({2, 3});   // Представляет число 32 в 4-ой системе

    ASSERT_TRUE(number1 == number2) << "Ожидалось, что числа равны.";
}

// Тест на оператор "==": проверка неравенства разных чисел
TEST(FourTest, Equality_DifferentNumbers)
{
    Four number1({2, 3});   // 32 в 4-ой системе
    Four number3({2, 1});   // 12 в 4-ой системе

    ASSERT_FALSE(number1 == number3) << "Ожидалось, что числа не равны.";
}

// Тест на оператор "<": проверка, что число не меньше самого себя
TEST(FourTest, LessThan_SameNumbers)
{
    Four number1({2, 3});   // 32 в 4-ой системе
    Four number2({2, 3});   // 32 в 4-ой системе

    ASSERT_FALSE(number1 < number2) << "Ожидалось, что число не меньше самого себя.";
}

// Тест на оператор "<": проверка, что большее число не меньше меньшего
TEST(FourTest, LessThan_GreaterNumber)
{
    Four number1({2, 3});   // 32 в 4-ой системе
    Four number3({2, 1});   // 12 в 4-ой системе

    ASSERT_FALSE(number1 < number3) << "Ожидалось, что большее число не меньше меньшего.";
}

// Тест на оператор "<": проверка, что меньшее число меньше большего
TEST(FourTest, LessThan_LessNumber)
{
    Four number3({2, 1});   // 12 в 4-ой системе
    Four number1({2, 3});   // 32 в 4-ой системе

    ASSERT_TRUE(number3 < number1) << "Ожидалось, что меньшее число меньше большего.";
}

// Тест на оператор ">": проверка, что число не больше самого себя
TEST(FourTest, GreaterThan_SameNumbers)
{
    Four number1({2, 3});   // 32 в 4-ой системе
    Four number2({2, 3});   // 32 в 4-ой системе

    ASSERT_FALSE(number1 > number2) << "Ожидалось, что число не больше самого себя.";
}

// Тест на оператор ">": проверка, что большее число больше меньшего
TEST(FourTest, GreaterThan_GreaterNumber)
{
    Four number1({2, 3});   // 32 в 4-ой системе
    Four number3({2, 1});   // 12 в 4-ой системе

    ASSERT_TRUE(number1 > number3) << "Ожидалось, что большее число больше меньшего.";
}

// Тест на оператор ">": проверка, что меньшее число не больше большего
TEST(FourTest, GreaterThan_LessNumber)
{
    Four number3({2, 1});   // 12 в 4-ой системе
    Four number1({2, 3});   // 32 в 4-ой системе

    ASSERT_FALSE(number3 > number1) << "Ожидалось, что меньшее число не больше большего.";
}

// Тест добавления нуля
TEST(FourTest, AddZero)
{
    Four number1("1233");       // 1233 в 4-ой системе
    Four number1Copy{number1};  // Копия number1
    Four numberZero;            // 0

    number1 += numberZero;

    ASSERT_TRUE(number1 == number1Copy); // Число не должно измениться
}

// Тест сложения
TEST(FourTest, Add)
{
    Four number1("1023"); // 1023 в 4-ой системе (развернуто: 3201)
    Four number2("31");   // 31 в 4-ой системе (развернуто: 13)

    // Рассчитаем сумму:
    // 1023 (base 4) = 1*4^3 + 0*4^2 + 2*4^1 + 3*4^0 = 64 + 0 + 8 + 3 = 75
    // 31 (base 4) = 3*4^1 + 1*4^0 = 12 + 1 = 13
    // Сумма = 75 + 13 = 88
    // 88 в base 4:
    // 88 ÷ 4 = 22, остаток 0
    // 22 ÷ 4 = 5, остаток 2
    // 5 ÷ 4 = 1, остаток 1
    // 1 ÷ 4 = 0, остаток 1
    // Итого: 1120

    Four expected("1120"); // 1120 в 4-ой системе

    number1 += number2;

    ASSERT_TRUE(number1 == expected);
}

// Тест сложения с переносом, приводящим к увеличению длины числа
TEST(FourTest, AddExtend)
{
    Four number1("3333"); // 3333 в 4-ой системе = 3*4^3 + 3*4^2 + 3*4^1 + 3*4^0 = 192 + 48 + 12 + 3 = 255
    Four number2("1");    // 1 в 4-ой системе = 1

    // Сумма = 255 + 1 = 256
    // 256 в base 4:
    // 256 ÷ 4 = 64, остаток 0
    // 64 ÷ 4 = 16, остаток 0
    // 16 ÷ 4 = 4, остаток 0
    // 4 ÷ 4 = 1, остаток 0
    // 1 ÷ 4 = 0, остаток 1
    // Итого: 10000

    Four expected("10000"); // 10000 в 4-ой системе

    number1 += number2;

    ASSERT_TRUE(number1 == expected);
}

// Тест вычитания нуля
TEST(FourTest, SubZero)
{
    Four number1("1233");       // 1233 в 4-ой системе
    Four number1Copy{number1};  // Копия number1
    Four numberZero;            // 0

    number1 -= numberZero;

    ASSERT_TRUE(number1 == number1Copy); // Число не должно измениться
}

// Тест вычитания
TEST(FourTest, Sub)
{
    // Исходные числа:
    // number1 = "1033" (base 4) = 1*4^3 + 0*4^2 + 3*4^1 + 3*4^0 = 64 + 0 + 12 + 3 = 79
    // number2 = "31" (base 4)  = 3*4^1 + 1*4^0 = 12 + 1 = 13
    // Разница = 79 - 13 = 66
    // 66 в base 4 = 1002

    Four number1("1033");         // 1033 в 4-ой системе
    Four number2("31");           // 31 в 4-ой системе
    Four expected("1002");        // 1002 в 4-ой системе

    number1 -= number2;

    ASSERT_TRUE(number1 == expected);
}

// Тест вычитания, приводящего к ошибке (недостаточно для вычитания)
TEST(FourTest, SubstructionError)
{
    // Исправленные числа без недопустимых цифр:
    // number1 = "0233" (base 4) = 0*4^3 + 2*4^2 + 3*4^1 + 3*4^0 = 0 + 32 + 12 + 3 = 47
    // number2 = "12333" (base 4) = 1*4^4 + 2*4^3 + 3*4^2 + 3*4^1 + 3*4^0 = 256 + 128 + 48 + 12 + 3 = 447

    Four number1_correct("0233");  // 0233 в 4-ой системе
    Four number2_correct("12333"); // 12333 в 4-ой системе

    EXPECT_THROW(number1_correct -= number2_correct, std::invalid_argument); // 47 - 447 невозможен
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
