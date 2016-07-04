//
//  SceneChanger.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/04.
//
//

#ifndef SceneChanger_hpp
#define SceneChanger_hpp

typedef enum
{
    SceneTitle,
    SceneMenu,
    SceneGame,
    SceneResult,
    
    SceneEmpty
}Scene;

class SceneChanger
{
public:
    
    virtual ~SceneChanger() = 0;
    virtual void ChangeScene(Scene nextScene) = 0;
};

#endif /* SceneChanger_hpp */
