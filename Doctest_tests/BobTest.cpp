//
// Created by Pablo Moreno Um on 02.08.21.
//

#include "doctest.h"
#include "Bob.hpp"

TEST_CASE("Bob") {
    Bob bob;
    float tolerance = .000001f;

    SUBCASE("Basic settings") {
        CHECK_EQ(bob.getSprite().getPosition().x, doctest::Approx(1440).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getPosition().y, doctest::Approx(900).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getTexture()->getSize().x, doctest::Approx(150).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getTexture()->getSize().y, doctest::Approx(192).epsilon(tolerance));
    }

    SUBCASE("Method input") {
        bob.input();
        CHECK_EQ(bob.getSprite().getPosition().x, doctest::Approx(1440).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getPosition().y, doctest::Approx(900).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getTexture()->getSize().x, doctest::Approx(150).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getTexture()->getSize().y, doctest::Approx(192).epsilon(tolerance));
    }

    SUBCASE("Method update") {
        bob.update(.1234f);
        CHECK_EQ(bob.getSprite().getPosition().x, doctest::Approx(1440).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getPosition().y, doctest::Approx(900).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getTexture()->getSize().x, doctest::Approx(150).epsilon(tolerance));
        CHECK_EQ(bob.getSprite().getTexture()->getSize().y, doctest::Approx(192).epsilon(tolerance));
    }
}