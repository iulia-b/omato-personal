/*
  Fade program

  This program sets a queue list with 10 queues. Each queue can be set to have a fade amount,
  a duration of the fading time, and a waiting time before the next queue starts.

  LED is defined on pin 12 (ESP8266 D6) using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  Coded by I.Lopez for Ivana Franke Studio
  © Ivana Franke Studio 2019

*/

#include <stdio.h>
#include <stdlib.h>


struct Item {
  int brig;
  int fade;
  int wait;
}

void interpolate(int start, int end, int intervalMS) {
  int sleepTime = intervalMS / abs(end-start); // this is the value you need to wait until you print next iteration

  int step = 1;
  int iterator = start;
  int finish = end;

  if (start > end) {
    step = -1;
    iterator = end;
    finish = start;
  }

  while(iterator != finish) {
    // Serial.print(iterator);   // analogWrite(led, LedState);
    printf("%d\n", iterator);
    iterator = iterator + step;
    delay(sleepTime);
  }
}


void loop() {

  int i = 1;
  struct Item current = (struct Item*)malloc(sizeof(struct Item));

  while (1 == 1) {
    current = entries[i];

    interpolate(current[i-1].brig, current[i].brig, current[i-1].fade);
    delay(current[i-1].wait);

    if(i == n) {
      i = 1;
    }
  }
}

int main() {

    // int led = 12;           // the PWM pin the LED is attached to
    // int fadeAmount = 1;    // how many points to fade the LED by
    // int LedState = 0;     //  variable to store the brigtness of the LED
    // int BrigSt = 0;
    // int FadeSt = 10;
    // rampInt myRamp;                              // new ramp object (ramp<unsigned char> by default)


    int n = 10;
    struct Item *entries = (struct Item*)malloc(sizeof(struct Item) * (n+1));


    entries = [ {10, 10000, 10000}, {0, 0, 0}, {255, 10000, 5000}];

    entries[n+1] = {10, 10000, 10000}];


	return 0;
}

