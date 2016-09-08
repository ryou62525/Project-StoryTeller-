//
//  Header.h
//  storyTeller
//
//  Created by vantan on 2016/08/24.
//
//

#ifndef Header_h
#define Header_h

enum Tag
{
    t_Quest = 1,
    t_Option,
    t_HomeBg,
    t_Icon,
    t_Character,
};

enum
{
    BG_IMAGE_VALUE = 4,
    STAGE_UI_IMAGE_VALUE = 4,
    MENU_UI_VALUE = 9,
};

enum class UI_IMAGE
{
    HOME = 0,
    QUEST,
    DICTIONARY,
    OPTION,
    
    MAX
};

enum class OPTION_LABEL
{
    BGM = 0,
    SE,
    M_SPEED,
    
    MAX = 9
};

enum class STORY_SELECT
{
    ALICE = 0,
    
    MAX = 4
};

enum class OPTION_SLIDER
{
    BGM = 0,
    SE,
    SPEED
};

enum class PAGE
{
    STORY_SELECT = 0,
    STAGE_SELECT,
    
    MAX
};

#endif /* Header_h */
