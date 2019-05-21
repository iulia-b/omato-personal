#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

    // i used prin here so i can write the values in the console. you should use the line above to write them in the controller
    printf("%d\n", iterator);
    
    iterator = iterator + step;
    delay(sleepTime); // for me delay does not work, i used sleep. delay should work for you
  }
}


void loop(struct Item *entries, int n) {

  int i = 1;

  while (1 == 1) {
    interpolate(entries[i-1].brig, entries[i].brig, entries[i-1].fade);
    delay(entries[i-1].wait); // again here i used sleep cause delay does not work

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


    int n = 10; //declare how many items you have
    
    // make sure andries will be declared like entries[11] if n=10 or entries n+1 in general.
    // Eg: for n = 10, put all your 10 values in entries and in the last position put again the first value. so entries will begin and start with the same value
    struct Item entries[10] = {{10, 10000, 10000}, {0, 0, 0}, {255, 10000, 5000}};

    loop(entries, 3);

	return 0;
}
