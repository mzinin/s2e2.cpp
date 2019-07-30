#include "../test_utils.hpp"

#include <error.hpp>
#include <functions/function_if.hpp>

#include <gtest/gtest.h>

#include <typeinfo>


TEST(FunctionIfTests, positiveTest_FirstArgumentTrue_StackSize)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(true, std::string{"A"}, std::string{"B"});

    function.invoke(stack);

    ASSERT_EQ(stack.size(), 1);
}

TEST(FunctionIfTests, positiveTest_FirstArgumentTrue_ResultType)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(true, std::string{"A"}, std::string{"B"});

    function.invoke(stack);

    ASSERT_TRUE(stack.top().has_value());
    ASSERT_EQ(stack.top().type(), typeid(std::string));
}

TEST(FunctionIfTests, positiveTest_FirstArgumentTrue_ResultValue)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(true, std::string{"A"}, std::string{"B"});

    function.invoke(stack);

    ASSERT_TRUE(stack.top().has_value());
    ASSERT_EQ(std::any_cast<std::string>(stack.top()), std::string{"A"});
}

TEST(FunctionIfTests, positiveTest_FirstArgumentFalse_ResultValue)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(false, std::string{"A"}, std::string{"B"});

    function.invoke(stack);

    ASSERT_TRUE(stack.top().has_value());
    ASSERT_EQ(std::any_cast<std::string>(stack.top()), std::string{"B"});
}

TEST(FunctionIfTests, positiveTest_MoreArguments_StackSize)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(std::string{"ARG"}, false, std::string{"A"}, std::string{"B"});

    function.invoke(stack);

    ASSERT_EQ(stack.size(), 2);
}

TEST(FunctionIfTests, positiveTest_SecondArgumentNull_ResultValue)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(true, std::any{}, std::string{"B"});

    function.invoke(stack);

    ASSERT_FALSE(stack.top().has_value());
}

TEST(FunctionIfTests, positiveTest_ThirdArgumentNull_ResultValue)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(false, std::string{"A"}, std::any{});

    function.invoke(stack);

    ASSERT_FALSE(stack.top().has_value());
}

TEST(FunctionIfTests, negativeTest_FewerArguments)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(false);

    ASSERT_THROW({
        try
        {
            function.invoke(stack);
        }
        catch (const s2e2::Error& e)
        {
            EXPECT_EQ(e.what(), "Not enough arguments for function " + function.name);
            throw;
        }
    }, s2e2::Error);
}

TEST(FunctionIfTests, negativeTest_FirstArgumentWrongType)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(std::string{"false"}, std::string{"A"}, std::string{"B"});

    ASSERT_THROW({
        try
        {
            function.invoke(stack);
        }
        catch (const s2e2::Error& e)
        {
            EXPECT_EQ(e.what(), "Invalid arguments for function " + function.name);
            throw;
        }
    }, s2e2::Error);
}

TEST(FunctionIfTests, negativeTest_FirstArgumentNull)
{
	s2e2::FunctionIf function;
    auto stack = TestUtils::createStack(std::any{}, std::string{"A"}, std::string{"B"});

    ASSERT_THROW({
        try
        {
            function.invoke(stack);
        }
        catch (const s2e2::Error& e)
        {
            EXPECT_EQ(e.what(), "Invalid arguments for function " + function.name);
            throw;
        }
    }, s2e2::Error);
}
