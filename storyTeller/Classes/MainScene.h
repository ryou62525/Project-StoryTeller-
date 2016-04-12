#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MainScene : public cocos2d::Layer
{

	void MakeBackground();

public:

	static Scene* CreateScene();
	virtual bool init();
	CREATE_FUNC(MainScene);

	void SceneShift(Ref*);
};

#endif	//__MAIN_SCENE_H__