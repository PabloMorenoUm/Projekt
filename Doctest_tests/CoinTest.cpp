//
// Created by Pablo Moreno Um on 18.08.21.
//

#include "doctest.h"
#include "Coin.hpp"

TEST_CASE("COIN") {
    Coin coin;
    const float tol = .0000001;

    SUBCASE("Neutral") {
        coin.makeNeutral();
        CHECK(coin.isNeutral());
        CHECK_FALSE(coin.isHidden());
        CHECK_FALSE(coin.isPlayer());
        CHECK_FALSE(coin.isOpponent());
    }

    SUBCASE("Hidden") {
        coin.makeHidden();
        CHECK(coin.isHidden());
        CHECK_FALSE(coin.isNeutral());
        CHECK_FALSE(coin.isPlayer());
        CHECK_FALSE(coin.isOpponent());
    }

    SUBCASE("Player") {
        coin.makePlayer();
        CHECK(coin.isPlayer());
        CHECK_FALSE(coin.isHidden());
        CHECK_FALSE(coin.isNeutral());
        CHECK_FALSE(coin.isOpponent());
    }

    SUBCASE("Opponent") {
        coin.makeOpponent();
        CHECK(coin.isOpponent());
        CHECK_FALSE(coin.isHidden());
        CHECK_FALSE(coin.isPlayer());
        CHECK_FALSE(coin.isNeutral());
    }

    SUBCASE("Position") {
        const float x = 600, y = 400;
        coin.setPosition(x, y);
        CHECK_EQ(coin.getShape().getPosition().x, doctest::Approx(x).epsilon(tol));
        CHECK_EQ(coin.getShape().getPosition().y, doctest::Approx(y).epsilon(tol));
    }

    SUBCASE("Radius") {
        const float rad = 50;
        coin.setRadius(rad);
        CHECK_EQ(coin.getShape().getRadius(), doctest::Approx(rad).epsilon(tol));
    }

    SUBCASE("Equality") {
        coin.makePlayer();
        Coin coin2;
        coin2.makePlayer();
        CHECK(coin == coin2);
        CHECK_FALSE(coin != coin2);
    }

    SUBCASE("Inequality") {
        coin.makePlayer();
        Coin coin2;
        coin2.makeOpponent();
        CHECK(coin != coin2);
        CHECK_FALSE(coin == coin2);
    }
}