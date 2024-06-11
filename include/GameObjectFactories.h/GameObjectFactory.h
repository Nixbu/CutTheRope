#pragma once

class GameObjectFactory {
public:
	virtual std::unique_ptr<GameObject> createGameObject() const = 0;
	virtual ~GameObjectFactory() = default;
private:
};