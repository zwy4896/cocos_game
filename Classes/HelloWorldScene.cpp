#include "HelloWorldScene.h"
#include "GameScene.h"
#include "ConfigData.h"
#include "AboutScene.h"
#include "LevelScene.h"
//#include "JINTools.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);

	return scene;
}

bool HelloWorld::init()
{
    if ( !LayerColor::initWithColor(Color4B(0,255,255,255)) )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getWinSize();
    
    auto background = Sprite::create("UI/START/background.png");

    background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
//    背景平铺
    float winW = winSize.width;
    float winH = winSize.height;
    float spx = background->getTextureRect().getMaxX();
    float spy = background->getTextureRect().getMaxY();

    background->setScaleX(winW / spx);
    background->setScaleY(winH / spy);
	this->addChild(background);
	//左侧边栏
//	Sprite* left = Sprite::create("UI/START/START_UI_DOWN_0004_LeftFoot.png");
//	left->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
//	left->setPosition(0, 0);
//	this->addChild(left);

//	float leftFootWeight = left->getContentSize().width;
//	float leftFootHeight = left->getContentSize().height;
	//LOGO
	Sprite* logo = Sprite::create("UI/START/START_UI_UP_0005_BAD-GAME.png");
	logo->setPosition((winSize.width) / 2, CD_FLOAT("start_scene_logo_y"));
	this->addChild(logo);
	//版本号
	TTFConfig ttfConfig("fonts/font.ttf", 16);
	auto number = Label::createWithTTF(ttfConfig, CD_STRING("number"));
	number->setTextColor(Color4B(0, 0, 0, 150));
	number->setPosition(winSize.width - 460, 20);
	this->addChild(number);

	Menu* menu = Menu::create();
	menu->setPosition(0, 0);
	this->addChild(menu);
	//设置按钮
//	MenuItemImage* buttonSetting = MenuItemImage::create("UI/START/START_UI_UP_0000_setting.png", "UI/START/START_UI_DOWN_0000_setting.png", "UI/START_UI_DOWN_0000_setting.png", CC_CALLBACK_1(HelloWorld::settingCallBack, this));
//	buttonSetting->setPosition(leftFootWeight / 2, CD_FLOAT("start_scene_setting_button_y"));
//	menu->addChild(buttonSetting);
	//关于按钮
//	MenuItemImage* buttonAbout = MenuItemImage::create("UI/START/START_UI_UP_0003__.png", "UI/START/START_UI_DOWN_0003__.png", "UI/START_UI_UP_0003__.png", CC_CALLBACK_1(HelloWorld::aboutCallBack, this));
//	buttonAbout->setPosition(leftFootWeight / 2, CD_FLOAT("start_scene_about_button_y"));
//	menu->addChild(buttonAbout);
	//更多按钮
//	MenuItemImage* buttonMore = MenuItemImage::create("UI/START/START_UI_UP_0002_....png", "UI/START/START_UI_DOWN_0002_....png", "UI/START_UI_UP_0003__.png", CC_CALLBACK_1(HelloWorld::settingCallBack, this));
//	buttonMore->setPosition(leftFootWeight / 2, CD_FLOAT("start_scene_more_button_y"));
//	menu->addChild(buttonMore);
	//开始按钮
	MenuItemImage* buttonStart = MenuItemImage::create("UI/START/START_UI_UP_0006_StartButton.png", "UI/START/START_UI_DOWN_0006_StartButton.png", "UI/START_UI_UP_0003__.png", CC_CALLBACK_1(HelloWorld::startCallBack, this));
	buttonStart->setPosition((winSize.width) / 2, CD_FLOAT("start_scene_start_button_y"));
	menu->addChild(buttonStart);
	//退出按钮
	MenuItemImage* exitStart = MenuItemImage::create("UI/START/exit1.png", "UI/START/exit2.png", "UI/exit2.png", CC_CALLBACK_1(HelloWorld::exitCallBack, this));
	exitStart->setPosition(CD_FLOAT("start_scene_exit_button_x"), CD_FLOAT("start_scene_exit_button_y"));
	menu->addChild(exitStart);
	//反馈按钮
//	MenuItemImage* buttonMsg = MenuItemImage::create("UI/START/msg1.png", "UI/START/msg2.png", "UI/msg2.png", CC_CALLBACK_1(HelloWorld::msgCallBack, this));
//	buttonMsg->setPosition(CD_FLOAT("start_scene_msg_button_x"), CD_FLOAT("start_scene_msg_button_y"));
//	menu->addChild(buttonMsg);
	//todo logo动态动画
//	this->schedule(schedule_selector(HelloWorld::dyncLogo), 3.5f);
    
	//测试功能 显示FPS
	/*
	EventListenerTouchOneByOne* event = EventListenerTouchOneByOne::create();
	event->onTouchBegan = [=](Touch* touch, Event* event){
		if (logo->getBoundingBox().containsPoint(touch->getLocation()))
		{
			// 如果在LOGO处发生触摸时间，那么显示FPS
			Director::getInstance()->setDisplayStats(!Director::getInstance()->isDisplayStats());
		}
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event, this);
	*/

    return true;
}

void HelloWorld::aboutCallBack(cocos2d::Ref* ref)
{
	auto reScene = TransitionCrossFade::create(0.3f, AboutScene::createScene());
	Director::getInstance()->pushScene(reScene);
}

void HelloWorld::settingCallBack(cocos2d::Ref* ref)
{
	log("settingCallBack");
//	MessageBox("The function to be realized.\nWill be updated in the next version.", "Sorry");
}

void HelloWorld::startCallBack(cocos2d::Ref* ref)
{	
	auto reScene = TransitionCrossFade::create(0.3f, LevelScene::createScene());
	Director::getInstance()->replaceScene(reScene);
}

void HelloWorld::exitCallBack(cocos2d::Ref* ref)
{
	Director::getInstance()->end();
}

//void HelloWorld::msgCallBack(cocos2d::Ref* ref)
//{
//	JINTools::openFeedback();
//}

void HelloWorld::dyncLogo(float time)
{
	Size size(960, 640);
	float leftFootWeight = 194;
	Sprite* logo = Sprite::create("UI/START/START_UI_DOWN_0005_BAD-GAME.png");
	logo->setPosition((size.width - leftFootWeight) / 2 + leftFootWeight, CD_FLOAT("start_scene_logo_y"));
	this->addChild(logo);

	Sequence* action = Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.3), CallFuncN::create(CC_CALLBACK_1(HelloWorld::deleteNode, this)));
	logo->runAction(action);
}

void HelloWorld::deleteNode(cocos2d::Node* sender)
{
	sender->removeFromParent();
}



