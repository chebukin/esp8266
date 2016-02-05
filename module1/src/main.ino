long buttonPressedAt=millis();
long timeout=300;
int currentScreen=0;
int screensCount=5;

if (buttonPressed && currentTime-buttonPressedAt>timeout){
buttonPressedAt = currentTime;
screen=screen+1;

}
