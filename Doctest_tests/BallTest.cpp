//
// Created by Pablo Moreno Um on 31.07.21.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Ball.hpp"

TEST_CASE("Ball") {
    Ball ball{200, 200};
    float tolerance = .000001f;

    SUBCASE("Basic settings") {
        CHECK_EQ(ball.getPosition().left, doctest::Approx(200.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().top, doctest::Approx(200.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().height, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().width, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getShape().getFillColor(), sf::Color::Yellow);
    }

    SUBCASE("Update ball") {
        ball.update(.123f);
        CHECK_EQ(ball.getPosition().left, doctest::Approx(201.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().top, doctest::Approx(201.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().height, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().width, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getShape().getFillColor(), sf::Color::Yellow);
    }

    SUBCASE("Rebound vertically") {
        ball.reboundBatOrTop();
        ball.update(.456f);
        CHECK_EQ(ball.getPosition().left, doctest::Approx(201.05f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().top, doctest::Approx(196.75f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().height, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().width, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getShape().getFillColor(), sf::Color::Yellow);
    }

    SUBCASE("Rebound horizontally") {
        ball.reboundSides();
        ball.update(.789);
        CHECK_EQ(ball.getPosition().left, doctest::Approx(196.8f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().top, doctest::Approx(201.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().height, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().width, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getShape().getFillColor(), sf::Color::Yellow);
    }

    SUBCASE("Bottom") {
        ball.hitBottom();
        ball.update(.13579f);
        CHECK_EQ(ball.getPosition().left, doctest::Approx(501.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().top, doctest::Approx(2.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().height, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getPosition().width, doctest::Approx(20.0f).epsilon(tolerance));
        CHECK_EQ(ball.getShape().getFillColor(), sf::Color::Yellow);
    }
}