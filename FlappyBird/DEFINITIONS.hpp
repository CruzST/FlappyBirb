#pragma once

// Window dims
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024


// How long to show logo in seconds
#define SPLASH_STATE_SHOW_TIME 3.0


// Loaction path of background logo
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

// main menu
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"

// game background
#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"

// game over background
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png"

// title
#define GAME_TITLE_FILEPATH "Resources/res/title.png"

// menu play button
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

// pipes
#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"

// move pipes
#define PIPE_MOVEMENT_SPEED 200.0f

// spawn rate of pipes
#define PIPE_SPAWN_FREQUENCY 1.5f

// ground file path
#define LAND_FILEPATH "Resources/res/Land.png"

// bird frames
#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"

// font for score
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

// bird animation rate in sec
#define BIRD_ANIMATION_DURATION 0.4f

// bird states
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

// rotation
#define ROTATION_SPEED 100.0f

// gravity
#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f

// collision with ground
enum GameStates
{
	eReady,		// spawn pipes, dont move player
	ePlaying,	// when they tap, start playing
	eGameOver	// when they lose
};

// game over flash
#define FLASH_SPEED 1500.0f


// game over title
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

// high score txt
#define HIGHSCORE_FILEPATH "Resources/Highscore.txt"

// medal
#define BRONZE_MEDAL_FILEPATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 50


