CocosInterpreter
================
<br>
Play swfs in cocos2dx<br>
This library can play swf using cocos2dx<br>
<br>
<br>
Usage:<br>
CCINode * node = CCINode::create("xxxx.swf");<br>
node->setPosition(ccp(size.width / 2, size.height /2));<br>
node->play();<br>
this->addChild(node);<br>
<br>
Tips:<br>
Remember to clean when you don't want to use swf<br>
CCIMovie::cleanup();<br>
