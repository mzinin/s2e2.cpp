#pragma once

#include <operator.hpp>

#include <any>


namespace s2e2
{
    /**
     * @class OperatorGreater
     * @brief Operator >
     * @details Lexicographically compares two strings.
     */
    class OperatorGreater final : public Operator
    {
    public:
        /**
         * Default constructor.
         */
        OperatorGreater();

    private:
        /**
         * @brief Check if arguments are correct.
         * @returns true is arguments are correct, false otherwise.
         */
        bool checkArguments() const override;

        /**
         * @brief Calculate result of the operator.
         * @return Result.
         */
        std::any result() const override;
    };

} // namespace s2e2