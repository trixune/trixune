#include <SFML/Graphics.hpp>
#include <optional>
#include <cmath>

namespace trixune_collision
{
	struct Result {
		enum class Side { None, Left, Right, Top, Bottom } side;
		sf::Vector2f correctedPosition;
	};

	// Simple AABB collision resolution
	std::optional<Result> CheckCollision(
		const sf::FloatRect& playerBounds,
		const sf::FloatRect& blockBounds,
		const sf::Vector2f& playerVelocity = {0.f, 0.f}) //Default value if unused
	{
		// Calculate player's next bounds after movement
		sf::FloatRect nextBounds = playerBounds;
		nextBounds.position += playerVelocity;

		// Check if next position intersects block
		auto intersection = nextBounds.findIntersection(blockBounds);
		if (!intersection)
			return std::nullopt; // no collision

		// Edges of next player bounds
		float playerLeft = nextBounds.position.x;
		float playerRight = nextBounds.position.x + nextBounds.size.x;
		float playerTop = nextBounds.position.y;
		float playerBottom = nextBounds.position.y + nextBounds.size.y;

		// Edges of block
		float blockLeft = blockBounds.position.x;
		float blockRight = blockBounds.position.x + blockBounds.size.x;
		float blockTop = blockBounds.position.y;
		float blockBottom = blockBounds.position.y + blockBounds.size.y;

		// Calculate overlaps
		float overlapLeft = playerRight - blockLeft;
		float overlapRight = blockRight - playerLeft;
		float overlapTop = playerBottom - blockTop;
		float overlapBottom = blockBottom - playerTop;

		// Find minimum overlap axis (smallest absolute overlap)
		float minOverlapX = (overlapLeft < overlapRight) ? overlapLeft : -overlapRight;
		float minOverlapY = (overlapTop < overlapBottom) ? overlapTop : -overlapBottom;

		sf::Vector2f correctedPosition = nextBounds.position;
		Result::Side collisionSide = Result::Side::None;

		// Resolve collision on the axis with smaller overlap
		if (std::abs(minOverlapX) < std::abs(minOverlapY)) {
			correctedPosition.x -= minOverlapX;
			collisionSide = (minOverlapX > 0) ? Result::Side::Left : Result::Side::Right;
		} else {
			correctedPosition.y -= minOverlapY;
			collisionSide = (minOverlapY > 0) ? Result::Side::Top : Result::Side::Bottom;
		}

		return Result{collisionSide, correctedPosition};
	}
}
