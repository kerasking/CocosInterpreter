CocosInterpreter
================

read swfs in cocos2dx
this library can play swf using cocos2dx


usage
CCINode * node = CCINode::create("xxxx.swf");
node->setPosition(ccp(size.width / 2, size.height /2));
node->play();
this->addChild(node);

tips:
remember to clean when you don't want to use swf
CCIMovie::cleanup();
