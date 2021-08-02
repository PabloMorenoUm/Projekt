//
// Created by Pablo Moreno Um on 02.08.21.
//

#include "doctest.h"
#include "Direction.hpp"

TEST_CASE("Direction") {
    Direction direction{};

    SUBCASE("true") {
        direction.handleMoving(true);
        CHECK(direction.isPressed());
    }

    SUBCASE("false") {
        direction.handleMoving(false);
        CHECK_FALSE(direction.isPressed());
    }
}