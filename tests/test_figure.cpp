#include "gtest/gtest.h"
#include "Trapezoid.hpp"
#include "Pentagon.hpp"
#include "Rhombus.hpp"

//////////////////////////////////////////
// Тесты для класса Trapezoid

TEST(TrapezoidTest, CreationTest) {
    Point points[4] = { Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2) };
    Trapezoid trapezoid(points);
    EXPECT_EQ(trapezoid.geometricCenter().x, 2.0);
    EXPECT_EQ(trapezoid.geometricCenter().y, 1.0);
}

TEST(TrapezoidTest, AreaTest) {
    Point points[4] = { Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2) };
    Trapezoid trapezoid(points);
    double area = static_cast<double>(trapezoid);
    EXPECT_NEAR(area, 8.0, 1e-6);
}

TEST(TrapezoidTest, GeometricCenterTest) {
    Point points[4] = { Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2) };
    Trapezoid trapezoid(points);
    Point center = trapezoid.geometricCenter();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 1.0, 1e-6);
}

TEST(TrapezoidTest, EqualityTest) {
    Point points1[4] = { Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2) };
    Point points2[4] = { Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2) };
    Trapezoid trapezoid1(points1);
    Trapezoid trapezoid2(points2);
    EXPECT_TRUE(trapezoid1 == trapezoid2);
}

//////////////////////////////////////////
// Тесты для класса Pentagon

TEST(PentagonTest, CreationTest) {
    Point points[5] = { Point(0, 0), Point(2, 0), Point(3, 1), Point(1.5, 3), Point(0, 1) };
    Pentagon pentagon(points);
    EXPECT_EQ(pentagon.geometricCenter().x, 1.3);
    EXPECT_EQ(pentagon.geometricCenter().y, 1.0);
}

TEST(PentagonTest, AreaTest) {
    Point points[5] = { Point(0, 0), Point(2, 0), Point(3, 1), Point(1.5, 3), Point(0, 1) };
    Pentagon pentagon(points);
    double area = static_cast<double>(pentagon);
    EXPECT_NEAR(area, 5.5, 1e-6);
}

TEST(PentagonTest, GeometricCenterTest) {
    Point points[5] = { Point(0, 0), Point(2, 0), Point(3, 1), Point(1.5, 3), Point(0, 1) };
    Pentagon pentagon(points);
    Point center = pentagon.geometricCenter();
    EXPECT_NEAR(center.x, 1.3, 1e-6);
    EXPECT_NEAR(center.y, 1.0, 1e-6);
}

TEST(PentagonTest, EqualityTest) {
    Point points1[5] = { Point(0, 0), Point(2, 0), Point(3, 1), Point(1.5, 3), Point(0, 1) };
    Point points2[5] = { Point(0, 0), Point(2, 0), Point(3, 1), Point(1.5, 3), Point(0, 1) };
    Pentagon pentagon1(points1);
    Pentagon pentagon2(points2);
    EXPECT_TRUE(pentagon1 == pentagon2);
}

//////////////////////////////////////////
// Тесты для класса Rhombus

TEST(RhombusTest, CreationTest) {
    Point points[4] = { Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1) };
    Rhombus rhombus(points);
    EXPECT_EQ(rhombus.geometricCenter().x, 0.0);
    EXPECT_EQ(rhombus.geometricCenter().y, 1.0);
}

TEST(RhombusTest, AreaTest) {
    Point points[4] = { Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1) };
    Rhombus rhombus(points);
    double area = static_cast<double>(rhombus);
    EXPECT_NEAR(area, 4.0, 1e-6);
}

TEST(RhombusTest, GeometricCenterTest) {
    Point points[4] = { Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1) };
    Rhombus rhombus(points);
    Point center = rhombus.geometricCenter();
    EXPECT_NEAR(center.x, 0.0, 1e-6);
    EXPECT_NEAR(center.y, 1.0, 1e-6);
}

TEST(RhombusTest, EqualityTest) {
    Point points1[4] = { Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1) };
    Point points2[4] = { Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1) };
    Rhombus rhombus1(points1);
    Rhombus rhombus2(points2);
    EXPECT_TRUE(rhombus1 == rhombus2);
}
