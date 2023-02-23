//
// Created by Зухраб Асаханов on 18.11.2022.
//

#include <gtest/gtest.h>
#include "../src/lotto.hpp"

using namespace lab32;

TEST(ConstructorType, DefaultConstructor)
{
    Card Crd;
    EXPECT_EQ(Crd.getLineNumber(), 3);
    EXPECT_EQ(Crd.getCageNumber(), 9);
}

TEST(ConstructorType, GetConstructor)
{
    Card Crd(9);
    EXPECT_EQ(Crd.getLineNumber(), 9);
    EXPECT_EQ(Crd.getCageNumber(), 9);
}

TEST(ConstructorType, CopyConstructor)
{
    Card Crd;
    Card Crd2(Crd);
    EXPECT_EQ(Crd2.getLineNumber(), 3);
    EXPECT_EQ(Crd2.getCageNumber(), 9);
}

TEST(ConstructorType, MoveConstructor)
{
    Card Crd;
    Card Crd2(Crd);
    EXPECT_EQ(Crd.getLineNumber(), 3);
    EXPECT_EQ(Crd.getCageNumber(), 9);
}

TEST(SetterType, Setters)
{
    Card Crd;
    EXPECT_ANY_THROW(Crd.setStatus(EMPTY, 8, 0));
    EXPECT_ANY_THROW(Crd.setNumber(100, 1, 1));
}

TEST(GetterType, Getters)
{
    Card Crd;
    EXPECT_EQ(Crd.getStatus(9, 0), FREE);
    EXPECT_EQ(Crd.getNumber(8, 0), 0);
    EXPECT_EQ(Crd.getLineNumber(), 3);
    EXPECT_EQ(Crd.getCageNumber(), 9);
}

TEST(MethodsType, KegSelection)
{
    Card Crd;
    EXPECT_EQ(Crd.kegSelection(), 84);
}

TEST(MethodsType, CheckMatch)
{
    Card Crd;
    EXPECT_EQ(Crd.checkMatch(5), 0);
}

TEST(MethodsType, StatusOfCard)
{
    Card Crd;
    EXPECT_EQ(Crd.statusOfCard(), FREE);
}

TEST(OperatorType, CopyOperator)
{
    Card Crd;
    Card Crd2(5);
    Crd2 = Crd;
    EXPECT_EQ(Crd2.getLineNumber(), 3);
    EXPECT_EQ(Crd2.getCageNumber(), 9);
}

TEST(OperatorType, MoveOperator)
{
    Card Crd;
    Card Crd2;
    Crd2.operator=(Crd);
    EXPECT_EQ(Crd2.getLineNumber(), 3);
    EXPECT_EQ(Crd2.getCageNumber(), 9);
}

