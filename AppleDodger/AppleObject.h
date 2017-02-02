#ifndef AppleObject_H
#define AppleObject_H
#include "GameObject.h"

class AppleObject : public GameObject
{
public:
	AppleObject(int apples);
	~AppleObject();

	void update(float elapsedTime);
	void setStartingPosition();
	static std::string getIndexChar(int i);

	static int scoreTracker;

private:
	bool RUN_YET;
	const float SpeedRate;

	int appleCount;
	static int countingAppleCount;

	float velocity;
	float randXpos;
	static float startYpos;
	static float timeSinceStart;
	static float velocityTracker;

	static std::string tempChar;
	static std::string _A_char;
};

#endif