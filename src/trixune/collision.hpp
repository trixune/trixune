#pragma once
#include <optional>

#include "SFML/Graphics/Rect.hpp"

namespace trixune_collision
{
    enum class Side {
        None,
        Left,
        Right,
        Top,
        Bottom
    };

    struct Result {
        Side side;
        sf::Vector2f correctedPosition;
    };

    // Simple AABB collision resolution
    std::optional<Result> CheckCollision(
        const sf::FloatRect& playerBounds,
        const sf::FloatRect& blockBounds,
        const sf::Vector2f& playerVelocity = {0.f, 0.f});
}
