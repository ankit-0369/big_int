#pragma once
#include <iostream>
#include<string>
#include<cstdint>
#include <vector>

/*
    the idea:-
    1. We will store the input as collection of limbs basically we will
    break down the input number as collection of chunks breaking from the right
    in the base 1e9 i.e. say the number is "123456789012345678901234567890" will be
    internally stored as {"098765432", "109876543", "210987654", "321"}.

    2. for negative numbers neg will be true, else false. "0" is considered as
    positive i.e neg= false for zero.

    3. Operations and algorithms will bw carried out in two layers.
         a. the magnitude layer -> handling core operations and hard logic assuming
            both input of the operation is positive
        b. the sign layer -> final decision of the output after calculation.

    4. Naming convention:- For functions and variables snake_case to be followed,
    constants kbase, class as BigInt

    5. Fixed width for types(uint32_t, uint64_t) and size_t for sizes and indexes

    Other conventions:-
        * pass anything bigger than a primitive by const&, return results by value
        * mark const on every method that doesn’t mutate, [[nodiscard]] on pure functions,
            noexcept only where truly guaranteed.
        * no using namespace std in headers, no raw new/delete, initialize every member at declaration.
        * header has declarations only, plus tiny trivial functions. all logic in the cpp.
        * one function does one thing, and any function that breaks the invariant temporarily
            must restore it before returning (call a trim() helper that pops zero limbs and fixes
            negative zero)

*/

class BigInt
{
    private:

    static constexpr std::uint32_t kBase= 1'000'000'000;
    static constexpr std::uint32_t kBaseDigits= 9;

    std::vector<std::uint32_t> limbs_; // storing input as collection of limbs
    bool neg_= false;                     // represent wheather input is negative or not

    static bool is_valid(const std::string& text);
    void trim();

public:
    BigInt()= default;
    explicit BigInt(const std::string& text);
    [[nodiscard]] std::string to_string() const;
};