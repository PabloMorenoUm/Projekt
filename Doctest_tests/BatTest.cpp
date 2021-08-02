//
// Created by Pablo Moreno Um on 02.08.21.
//

#include "doctest.h"
#include "Bat.hpp"

TEST_CASE("Bat") {
    Bat bat{700, 500};
    float tolerance = .000001f;

    SUBCASE("Basic settings") {
        CHECK_EQ(bat.getPosition().left, doctest::Approx(700.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().top, doctest::Approx(500.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().width, doctest::Approx(250.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().height, doctest::Approx(10.0f).epsilon(tolerance));
        CHECK_EQ(bat.getShape().getFillColor(), sf::Color::Cyan);
    }

    SUBCASE("Method input") {
        bat.input();
        CHECK_EQ(bat.getPosition().left, doctest::Approx(700.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().top, doctest::Approx(500.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().width, doctest::Approx(250.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().height, doctest::Approx(10.0f).epsilon(tolerance));
        CHECK_EQ(bat.getShape().getFillColor(), sf::Color::Cyan);
    }

    SUBCASE("Method update") {
        bat.update(.1234f);
        CHECK_EQ(bat.getPosition().left, doctest::Approx(700.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().top, doctest::Approx(500.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().width, doctest::Approx(250.0f).epsilon(tolerance));
        CHECK_EQ(bat.getPosition().height, doctest::Approx(10.0f).epsilon(tolerance));
        CHECK_EQ(bat.getShape().getFillColor(), sf::Color::Cyan);
    }
}