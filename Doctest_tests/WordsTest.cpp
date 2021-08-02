//
// Created by Pablo Moreno Um on 02.08.21.
//

#include "doctest.h"
#include "Words.hpp"

TEST_CASE("Words") {
    Words words{"Hello World!", 50, 400, 300};
    float tolerance = .000001f;

    SUBCASE("Basic settings") {
        CHECK_EQ(words.getText().getString(), "Hello World!");
        CHECK_EQ(words.getText().getFillColor(), sf::Color::White);
        CHECK_EQ(words.getText().getCharacterSize(), 50);
        CHECK_EQ(words.getText().getPosition().x, doctest::Approx(400.0f).epsilon(tolerance));
        CHECK_EQ(words.getText().getPosition().y, doctest::Approx(300.0f).epsilon(tolerance));
    }
}