#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/where.hpp"

TEST_CASE( "it returns 2 for a char" ) {
    REQUIRE( findIndex("The quick brown fox", 'e') == 2 );
}

TEST_CASE( "it returns 2 for a single character string" ) {
    REQUIRE( findIndex("The quick brown fox", "e") == 2 );
}

TEST_CASE( "it returns 3 for a space char" ) {
    REQUIRE( findIndex("The quick brown fox", ' ') == 3 );
}

TEST_CASE( "it returns 4 for 'quick'" ) {
    REQUIRE( findIndex("The quick brown fox", "quick") == 4 );
}

TEST_CASE( "it returns -1 for a non-findable string" ) {
    REQUIRE( findIndex("The quick brown fox", "quiet") == -1 );
}

TEST_CASE( "it returns 0 for a case-insensitive string" ) {
    REQUIRE( findIndex("The quick brown fox", "the", false) == 0 );
}

TEST_CASE( "it returns -1 for a case-sensitive string" ) {
    REQUIRE( findIndex("The quick brown fox", "the", true) == -1 );
}

TEST_CASE( "it returns 2 for start position 1" ) {
    REQUIRE( findIndex("The quick brown fox", 'e', true, 1) == 2 );
}

TEST_CASE( "it returns -1 for start position 3" ) {
    REQUIRE( findIndex("The quick brown fox", 'e', 3) == -1 );
}

TEST_CASE( "it returns last index" ) {
    REQUIRE( findIndex("qwertyuiop", "p") == 9 );
}

TEST_CASE( "it returns last index starting at the end" ) {
    REQUIRE( findIndex("qwertyuiop", "p", 9) == 9 );
}

TEST_CASE( "it returns 0 for 'p' at the beginning" ) {
    REQUIRE( findIndex("pqwertyuiop", "p") == 0 );
}

TEST_CASE( "it returns 10 for 'p' at the end" ) {
    REQUIRE( findIndex("pqwertyuiop", "p", 1) == 10 );
}

TEST_CASE( "it returns -1 for 'p' when start is out of bounds" ) {
    REQUIRE( findIndex("qwertyuiop", "p", 10) == -1 );
}

TEST_CASE( "it returns -1 for 'p' when start is out negative" ) {
    REQUIRE( findIndex("qwertyuiop", "p", -1) == -1 );
}

TEST_CASE( "it returns 3 for 'cats' in 'catcats'" ) {
    REQUIRE( findIndex("catcats", "cats") == 3 );
}

TEST_CASE( "it returns 0 when input and find are the same" ) {
    REQUIRE( findIndex("qwertyuiop", "qwertyuiop") == 0 );
}