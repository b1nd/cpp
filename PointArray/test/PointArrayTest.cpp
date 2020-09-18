#include <gtest/gtest.h>

#include "PointArray.h"

using namespace task2;

TEST(PointArray, defaultConstructor) {
    PointArray arr;
    EXPECT_EQ(nullptr, arr.getRawPtr());
    EXPECT_EQ(0, arr.getSize());
}

TEST(PointArray, initByArray) {
    Point testArr[] = {Point(1, 1), Point(2, 2), Point(3, 3)};
    PointArray::Uint testArrSize = sizeof(testArr) / sizeof(testArr[0]);

    PointArray arr(testArr, testArrSize);
    EXPECT_NE(nullptr, arr.getRawPtr());
    EXPECT_EQ(testArrSize, arr.getSize());
}

TEST(PointArray, indexer) {
    Point testArr[] = {Point(1, 1), Point(2, 2), Point(3, 3)};
    PointArray::Uint testArrSize = sizeof(testArr) / sizeof(testArr[0]);

    PointArray arr(testArr, testArrSize);

    EXPECT_EQ(1, arr[0].getX());
    EXPECT_EQ(3, arr[2].getX());

    arr[1].setX(999);
    EXPECT_EQ(999, arr[1].getX());

    EXPECT_THROW(arr[3], std::out_of_range);
}

TEST(PointArray, append) {
    PointArray arr;
    arr.append(Point(0, 0));
    EXPECT_NE(nullptr, arr.getRawPtr());
    EXPECT_EQ(1, arr.getSize());

    arr.append(Point(1, 1));
    EXPECT_EQ(2, arr.getSize());

    EXPECT_EQ(1, arr[1].getX());
}

TEST(PointArray, initByPointArray) {
    Point testArr[] = {Point(1, 1), Point(2, 2), Point(3, 3)};
    PointArray::Uint testArrSize = sizeof(testArr) / sizeof(testArr[0]);

    PointArray firstArr(testArr, testArrSize);
    PointArray arr(firstArr);
    EXPECT_EQ(testArrSize, arr.getSize());
    EXPECT_EQ(1, arr[0].getX());
    EXPECT_EQ(2, arr[1].getX());
    EXPECT_EQ(3, arr[2].getX());
}

TEST(PointArray, initByRvaluePointArray) {
    Point testArr[] = {Point(1, 1), Point(2, 2), Point(3, 3)};
    PointArray::Uint testArrSize = sizeof(testArr) / sizeof(testArr[0]);

    PointArray arr(std::move(PointArray(testArr, testArrSize)));
    EXPECT_EQ(testArrSize, arr.getSize());
    EXPECT_EQ(1, arr[0].getX());
    EXPECT_EQ(2, arr[1].getX());
    EXPECT_EQ(3, arr[2].getX());
}

TEST(PointArray, assignmentByPointArray) {
    Point testArr[] = {Point(1, 1), Point(2, 2), Point(3, 3)};
    PointArray::Uint testArrSize = sizeof(testArr) / sizeof(testArr[0]);

    PointArray firstArr(testArr, testArrSize);
    PointArray arr;
    arr = firstArr;
    EXPECT_EQ(testArrSize, arr.getSize());
    EXPECT_EQ(1, arr[0].getX());
    EXPECT_EQ(2, arr[1].getX());
    EXPECT_EQ(3, arr[2].getX());
}

TEST(PointArray, assignmentByRvaluePointArray) {
    Point testArr[] = {Point(1, 1), Point(2, 2), Point(3, 3)};
    PointArray::Uint testArrSize = sizeof(testArr) / sizeof(testArr[0]);

    PointArray arr;
    arr = PointArray(testArr, testArrSize);
    EXPECT_EQ(testArrSize, arr.getSize());
    EXPECT_EQ(1, arr[0].getX());
    EXPECT_EQ(2, arr[1].getX());
    EXPECT_EQ(3, arr[2].getX());
}

TEST(PointArray, insert) {
    PointArray arr;
    arr.insert(Point(0, 0), 0);
    EXPECT_EQ(1, arr.getSize());
    EXPECT_EQ(0, arr[0].getX());

    arr.insert(Point(1, 1), 0);
    EXPECT_EQ(2, arr.getSize());
    EXPECT_EQ(1, arr[0].getX());

    arr.insert(Point(2, 2), 1);
    EXPECT_EQ(3, arr.getSize());
    EXPECT_EQ(1, arr[0].getX());
    EXPECT_EQ(2, arr[1].getX());
    EXPECT_EQ(0, arr[2].getX());
}

TEST(PointArray, remove) {
    PointArray arr;
    arr.append(Point(0, 0));
    arr.append(Point(1, 1));
    arr.append(Point(2, 2));

    arr.remove(3);
    EXPECT_EQ(3, arr.getSize());

    arr.remove(1);
    EXPECT_EQ(2, arr.getSize());
    EXPECT_EQ(0, arr[0].getX());
    EXPECT_EQ(2, arr[1].getX());

    arr.remove(0);
    EXPECT_EQ(1, arr.getSize());
    EXPECT_EQ(2, arr[0].getX());

    arr.remove(0);
    EXPECT_EQ(0, arr.getSize());
    EXPECT_EQ(nullptr, arr.getRawPtr());
}

TEST(PointArray, clear) {
    PointArray arr;
    arr.append(Point(0, 0));
    arr.append(Point(1, 1));

    arr.clear();
    EXPECT_EQ(0, arr.getSize());
    EXPECT_EQ(nullptr, arr.getRawPtr());
}

TEST(PointArray, resize) {
    PointArray arr;
    arr.append(Point(0, 0));
    arr.append(Point(1, 1));
    arr.append(Point(2, 2));

    arr.resize(2);
    EXPECT_EQ(2, arr.getSize());
    EXPECT_EQ(0, arr[0].getX());
    EXPECT_EQ(1, arr[1].getX());
}