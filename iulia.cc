#include <stdio.h>
#include <stdlib.h>


struct Item {
  int brig;
  int fade;
  int wait;
};

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
    //delay(sleepTime);
  }
}


void loop(Item *entries, int n) {

  int i = 1;
  Item *current = (Item*)malloc(sizeof(Item));

  while (1 == 1) {
    current = &entries[i];

    interpolate(current[i-1].brig, current[i].brig, current[i-1].fade);
    //delay(current[i-1].wait);

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
    //Item *entries = (Item*)malloc(sizeof(Item) * (n+1));
    Item entries[10] = {{10, 10000, 10000}, {0, 0, 0}, {255, 10000, 5000}};


    //entries[n+1] = {10, 10000, 10000}];


	return 0;
}
