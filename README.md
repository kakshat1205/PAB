# Precision Agriculture Bot

![1619868088454](https://user-images.githubusercontent.com/49076977/116781074-33782a80-aa9e-11eb-8d46-16b829ced1e3.jpg)

An agriculture bot we are developing which can help in controlling weed population in farm by identifying crops and weeds apart using our CNN model, then removing the weed or supplying crops with Growth enhancers.

Bots design was fabricated on SolidWorks CAD files are included.

Wiper motors are used which provides Bot sufficient torque to move in the Farm. High Amp motor driver(CYTRON DC MOTOR DRIVER 5V-30V 30AMP- MD30C) is being used for the purpose. Whole Bot is controlled by Arduino Mega. For now bot uses Joystick control to operate, in future proper navigation algorithm can be implemented for making it autonomous. 





https://user-images.githubusercontent.com/49076977/116781068-2d824980-aa9e-11eb-9c7e-228c5e702faa.mp4

https://user-images.githubusercontent.com/49076977/116781075-3a9f3880-aa9e-11eb-9679-f4356cdf47dd.mp4

<img src="bot.jpeg" width="550">


We built a four wheel drive robot with a camera places in the side to identify crops and weeds as it moves along the rows of crops.

Till now we have built our detection model and preliminary control for our robot, need to integrate both parts.

Link to all videos : https://drive.google.com/drive/folders/1dEyhc501Z7UikUqL99JR3ySwTcXkFh4d?usp=sharing

Faster RCNN model output:<br>
<img src="test.png">
