//
// Created by Pablo Moreno Um on 31.07.21.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Ball.hpp"

TEST_CASE("Ball") {
    Ball ball{200, 200};

    SUBCASE("Basic settings") {
        CHECK_EQ(ball.getPosition().left, 200.0f);
        CHECK_EQ(ball.getPosition().top, 200.0f);
        CHECK_EQ(ball.getPosition().height, 20.0f);
        CHECK_EQ(ball.getPosition().width, 20.0f);
        CHECK_EQ(ball.getShape().getFillColor(), sf::Color::Yellow);
    }

    SUBCASE("Update ball") {
        ball.update(.123f);
        CHECK_EQ(ball.getPosition().left, 201.0f);
        CHECK_EQ(ball.getPosition().top, 201.0f);
        CHECK_EQ(ball.getPosition().height, 20.0f);
        CHECK_EQ(ball.getPosition().width, 20.0f);
        CHECK_EQ(ball.getShape().getFillColor(), sf::Color::Yellow);
    }

}