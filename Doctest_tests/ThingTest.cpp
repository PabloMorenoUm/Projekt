//
// Created by Pablo Moreno Um on 02.08.21.
//

#include "doctest.h"
#include "Thing.hpp"

TEST_CASE("Thing") {
    Thing thing{100, 200, "P2_upper_0_1.png"};
    float tolerance = .000001f;

    SUBCASE("Basic settings") {
        CHECK_EQ(thing.getSprite().getPosition().x, doctest::Approx(100).epsilon(tolerance));
        CHECK_EQ(thing.getSprite().getPosition().y, doctest::Approx(200).epsilon(tolerance));
        CHECK_EQ(thing.getSprite().getTexture()->getSize().x, doctest::Approx(32).epsilon(tolerance));
        CHECK_EQ(thing.getSprite().getTexture()->getSize().y, doctest::Approx(45).epsilon(tolerance));
    }

    SUBCASE("Change photo") {
        thing.setSprite("P2_upper_0_2.png");
        CHECK_EQ(thing.getSprite().getPosition().x, doctest::Approx(100).epsilon(tolerance));
        CHECK_EQ(thing.getSprite().getPosition().y, doctest::Approx(200).epsilon(tolerance));
        CHECK_EQ(thing.getSprite().getTexture()->getSize().x, doctest::Approx(32).epsilon(tolerance));
        CHECK_EQ(thing.getSprite().getTexture()->getSize().y, doctest::Approx(45).epsilon(tolerance));
    }
}