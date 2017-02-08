#ifndef PlayerObject_H
#define PlayerObject_H
#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject(std::string Pname);
	~PlayerObject();

	void update(float elapsedTime);
	static void resetVelocity();

private:
	std::string playerName;

	bool RUN_YET;
	bool CHECK_SIGN = true; // Checks the sign of velocity when playerObject's position is outside of the defined bounds
	static bool ARROW_UP;
	static bool ROT_L; // ROT is short for rotation
	static bool ROT_R;

	float SpeedRate;
	static float velocityTracker;

	float velocity; // -- left ++ right
	float maxVelocity;
	float timeSinceStart;
	float rotRate;
	float rotAngle;
	sf::Clock clock;
};

#endif