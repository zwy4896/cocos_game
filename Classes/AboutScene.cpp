#include "AboutScene.h"
#include "TextData.h"

USING_NS_CC;

Scene* AboutScene::createScene()
{
	Scene* scene = Scene::create();
	Layer* layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}

bool AboutScene::init()
{
	if (!LayerColor::initWithColor(Color4B(137, 201, 151, 255)))
	{
		return false;
	}
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getWinSize();
    
	auto bk = Sprite::create("UI/ABOUT/about.png");
	bk->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    //    背景平铺
    float winW = winSize.width;
    float winH = winSize.height;
    float spx = bk->getTextureRect().getMaxX();
    float spy = bk->getTextureRect().getMaxY();

    bk->setScaleX(winW / spx);
    bk->setScaleY(winH / spy);
	this->addChild(bk);

	auto event = EventListenerTouchOneByOne::create();
	event->onTouchBegan = [](Touch* t, Event* e){
		Director::getInstance()->popScene();
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event, this);

	return true;
}
