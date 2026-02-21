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

TEST_CASE( "it returns 2 for start position 1" ) {
    REQUIRE( findIndex("The quick brown fox", 'e', true, 1) == 2 );
}

TEST_CASE( "it returns -1 for start position 3" ) {
    REQUIRE( findIndex("The quick brown fox", 'e', 3) == -1 );
}

TEST_CASE( "it returns 1 for a single wildcard character" ) {
    REQUIRE( findIndex("lamb", "a?b") == 1 );
}
