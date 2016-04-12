#pragma once
#include "cocos2d.h"

USING_NS_CC;

class ResultScene : public cocos2d::Layer
{


public:

	static Scene *CreateScene();
	virtual bool init();

	CREATE_FUNC(ResultScene);

	void MakeBackground();

	void SceneShift(Ref *sender);
};