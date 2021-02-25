#include "buttons.h"
#include "common.h"
#include "oled.h"
#include "setup.h"
#include "storage.h"
#include <SDL.h>
#include <unistd.h>

const uint8_t sleeping_data[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x38, 0x00, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x00, 0xfc, 0x3c, 
	0xfc, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xfe, 
	0x00, 0x00, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0xc0, 0x03, 
	0xff, 0xff, 0xff, 0xc0, 0x03, 0xf0, 0xfe, 0x1f, 0xc0, 0x07, 0xe0, 0xfc, 0x1f, 0xe0, 0x07, 0xff, 
	0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 
	0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xe7, 0xff, 
	0xe0, 0x07, 0xff, 0xe7, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xf0, 
	0x07, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x03, 
	0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 
	0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static const BITMAP sleeping_bmp = {40, 40, sleeping_data};

const uint8_t number_one_data[] = {
    0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xf6, 0x3f,
    0xef, 0x7f, 0xdf, 0x7f, 0x9f, 0x7f, 0x3f, 0x7f, 0xff, 0x7f, 0xff,
    0x3f, 0xff, 0x3f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf0,
};
const uint8_t number_two_data[] = {
  0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xff, 0x7f, 0xff, 0x7f, 0xf9, 
	0x7f, 0x83, 0x7f, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x3f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf0,
};
const uint8_t number_three_data[] = {
  0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 
	0x7f, 0xbf, 0x7f, 0x9f, 0x7f, 0xe7, 0x3f, 0xf3, 0x3f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf0,
};
const uint8_t number_four_data[] = {
  0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 
	0x7f, 0xff, 0x7f, 0x3f, 0x7f, 0xbf, 0x3f, 0xbf, 0x3f, 0xde, 0x1f, 0xde, 0x0f, 0xdc, 0x07, 0xf0,
};
const uint8_t number_five_data[] = {
  0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 
	0x7f, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x3e, 0xff, 0x3e, 0xfe, 0x1c, 0xfe, 0x0d, 0xfc, 0x07, 0xf0,
};
const uint8_t number_six_data[] = {
  0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 
	0x7f, 0x7f, 0x7c, 0x7f, 0x79, 0xff, 0x27, 0xff, 0x3f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf0,
};
const uint8_t number_seven_data[] = {
    0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f,
    0xff, 0x7f, 0xff, 0x67, 0xff, 0x70, 0x7f, 0x7f, 0xff, 0x7f, 0xff,
    0x3f, 0xff, 0x3f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf0,
};
const uint8_t number_eight_data[] = {
0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0xfc, 0x33, 0xfe, 0x39, 0xff, 0x7c, 0xff, 0x7e, 0xff, 
	0x7f, 0x7f, 0x7f, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x3f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf0,
};
const uint8_t number_nine_data[] = {
0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf8, 0x1f, 0x7c, 0x3f, 0x7e, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
	0x7f, 0x7f, 0x7f, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x3f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf0,
};

const BITMAP knob[] = {{16, 16, number_one_data}, {16, 16, number_two_data}, {16, 16, number_three_data}, {16, 16, number_four_data}, {16, 16, number_five_data}, {16, 16, number_six_data}, {16, 16, number_seven_data}, {16, 16, number_eight_data}, {16, 16, number_nine_data}};

// Math
#define CUSTOM_PI 3.141592654

// Storage
#define APP (0x01 << 8)
#define PIN (18 | APP)

// Coordinates and sizes
static const int centerX = OLED_WIDTH / 2;
static const int centerY = OLED_HEIGHT / 2;
static const int biggerCircleRadius = 30;
static const int digitcircleRadius = 23;
static const int digitOffsetX = 2;
static const int digitOffsetY = 3;

// State variables
static bool unlocked = false;
static bool pinInserted = false;
static int actual_digit = 9;
static int direction = 2;
static int position = 0;
static int pin[4];
static int pinSetupStage = 1;
static int pinToCompare = 0;
static bool pinInitialized = false;
static bool doubleClick = false;
static bool leftDown = false;
static bool rightDown = false;
static bool sleeping = true;

static int timeElapsed = 0;

// Math
float sine(double x) {
  double sign = 1;
  if (x<0){
    sign = -1.0;
    x = -x;
  }
  if (x>360) x -= x / 360 * 360;
  x *= CUSTOM_PI / 180.0;
  double res = 0;
  double term = x;
  int k = 1;
  while (res + term != res){
    res += term;
    k += 2;
    term *= -x * x / k / (k - 1);
  }

  return sign * res;
}

float cosine(double x) {
  if (x<0) x = -x;
  if (x>360) x -= x / 360 * 360;
  x *= CUSTOM_PI / 180.0;
  double res = 0;
  double term = 1;
  int k = 0;
  while (res + term != res){
    res += term;
    k += 2;
    term *= -x * x / k / (k - 1);
  }  
  return res;
}

// Drawing functions
void drawOuterCircle(int x, int y, int r)
{
      double i, angle, x1, y1;

      for(i = 0; i < 360; i += 1)
      {
            angle = i;
            x1 = r * cosine(angle);
            y1 = r * sine(angle);
            oledDrawPixel(x + x1, y + y1);
      }
}

void drawDigits(int cx, int cy, int radius) {
  for(int i = 1; i <= 9; i++) {
    double x = radius * cosine(360 / 9 * i - 90) + cx; // CUSTOM_PI / -2 + (2 * i * CUSTOM_PI) / 9
    double y = radius * sine(360 / 9 * i - 90) + cy; // CUSTOM_PI / -2 + (2 * i * CUSTOM_PI) / 9

    char c = '0' + i;
    oledDrawChar(x, y, c, FONT_STANDARD);
  }
}

void invertDigit(int digit)
{
  int radius, cx, cy;
  radius = digitcircleRadius;
  cx = centerX - digitOffsetX;
  cy = centerY - digitOffsetY;
  double x = radius * cosine(360 / 9 * digit - 90) + cx; // CUSTOM_PI / -2 + (2 * digit * CUSTOM_PI) / 9
  double y = radius * sine(360 / 9 * digit - 90) + cy; // CUSTOM_PI / -2 + (2 * digit * CUSTOM_PI) / 9
  oledInvert(x - 3, y - 1, x + 6, y + 7);
}

static int getPin(void) 
{ 
    uint16_t val = 0;
    uint16_t len = 0;
    storage_get(PIN, &val, sizeof(val), &len);
    return val;
}

void initLock(void)
{
  drawOuterCircle(centerX, centerY, biggerCircleRadius);
  drawDigits(centerX - digitOffsetX, centerY - digitOffsetY, digitcircleRadius);
  oledDrawBitmap(centerX - 8, centerY - 8, &knob[8]);
  invertDigit(actual_digit);
  int stored_pin;
  stored_pin = getPin();
  if (stored_pin == 0) {
    if (pinSetupStage == 1) {
      oledDrawStringRight(OLED_WIDTH, OLED_HEIGHT - 10, "Set pin", FONT_STANDARD);
    } else if (pinSetupStage == 2) {
      oledDrawStringRight(OLED_WIDTH, OLED_HEIGHT - 10, "Repeat", FONT_STANDARD);
    }
  } else {
    pinInitialized = true;
  }
}

// Pin functions
static void validatePin(void)
{
    if (!pinInserted) {
      pin[position] = actual_digit;
      uint16_t pin_to_store = 0;
      int i;
      for (i = 0; i < 4; i += 1) {
        pin_to_store = 10 * pin_to_store + pin[i];
      }
      if (pinInitialized) {
          int stored_pin = getPin();
          if (stored_pin == pin_to_store) {
              unlocked = true;
          } else {
              oledSwipeLeft();
              oledDrawStringCenter(centerX, centerY, "Bad pin", FONT_STANDARD);
              oledRefresh();
              sleep(3);
              oledSwipeRight();
              actual_digit = 9;
              position = 0;
              direction = 2;
              initLock();
          }
      } else {
          if (pinSetupStage == 1) {
              printf("PRVNI\n");
              printf("%d\n", pin_to_store);
              pinToCompare = pin_to_store;
              pinSetupStage = 2;
              actual_digit = 9;
              position = 0;
              direction = 2;
              oledSwipeLeft();
              initLock();
          } else if (pinSetupStage == 2) {
              printf("DRUHY\n");
              printf("%d\n", pin_to_store);
              if (pinToCompare == pin_to_store) {
                  storage_set(PIN, &pin_to_store, sizeof(pin_to_store));
                  oledSwipeRight();
                  oledDrawStringCenter(centerX, centerY, "Pin created!", FONT_STANDARD);
                  oledRefresh();
                  sleep(3);
                  oledSwipeLeft();
                  pinToCompare = 0;
                  pinSetupStage = 1;
                  actual_digit = 9;
                  position = 0;
                  direction = 2;
                  pinInitialized = true;
                  initLock();
              } else {
                oledSwipeLeft();
                oledDrawStringCenter(centerX, centerY - 10, "Not same!",
                                     FONT_STANDARD);
                oledDrawStringCenter(centerX, centerY + 10, "please start over",
                                     FONT_STANDARD);
                oledRefresh();
                sleep(3);
                oledSwipeRight();
                pinToCompare = 0;
                pinSetupStage = 1;
                actual_digit = 9;
                position = 0;
                direction = 2;
                initLock();
                printf("ERROR\n");
              }
          }
      }
    }
}

// Buttons functions
static void leftButton(void)
{
    if (direction != 2 && direction != 0) {
      pin[position] = actual_digit;
      position += 1;
    }
    direction = 0;
    invertDigit(actual_digit);
    if (actual_digit - 1 < 1) {
      actual_digit = 9;
    } else {
      actual_digit = actual_digit - 1;
    }
    oledDrawBitmap(centerX - 8, centerY - 8, &knob[actual_digit - 1]);
    invertDigit(actual_digit);
}

static void rightButton(void)
{
    if (direction != 2 && direction != 1) {
      pin[position] = actual_digit;
      position += 1;
    }
    direction = 1;
    invertDigit(actual_digit);
    if (actual_digit + 1 > 9) {
      actual_digit = 1;
    } else {
      actual_digit = actual_digit + 1;
    }
    oledDrawBitmap(centerX - 8, centerY - 8, &knob[actual_digit - 1]);
    invertDigit(actual_digit);
}

static void checkPiTrezorButtons(void) 
{ 
    buttonUpdate(); 
    if (!sleeping) {
        if (button.YesDown && button.NoDown) {
        if (!doubleClick) {
            doubleClick = true;
            leftDown = true;
            rightDown = true;
            validatePin();
        }
        }
        if (button.YesUp) {
            // Right button
            if (!doubleClick) {
            rightButton();
            }
            rightDown = false;
        }
        if (button.NoUp) {
            // Left button
            if (!doubleClick) {
                leftButton();
            }
            leftDown = false;
        }

        if (!leftDown && !rightDown) {
            doubleClick = false;
        }
    } else {
        if (button.YesDown >= 200 && button.NoDown >= 200) {
            doubleClick = true;
            leftDown = true;
            rightDown = true;
            oledSwipeRight();
            initLock();
            sleeping = false;
        }
    }
    oledRefresh();
}

static void drawFace() { 
  oledDrawBitmap(centerX - 20, centerY - 20, &sleeping_bmp);
  oledDrawString(centerX + 15, centerY - 15, "Z", FONT_STANDARD);
}

static void animateFace()
{
  if (timeElapsed == 100) {
    oledClear();
    oledDrawBitmap(centerX - 20, centerY - 20, &sleeping_bmp);
    oledDrawString(centerX + 20, centerY - 20, "Z", FONT_STANDARD);
    oledRefresh();
  }
  if (timeElapsed == 200) {
    oledClear();
    oledDrawBitmap(centerX - 20, centerY - 20, &sleeping_bmp);
    oledDrawString(centerX + 25, centerY - 25, "Z", FONT_STANDARD);
    oledRefresh();
  }
  if (timeElapsed == 300) {
    oledClear();
    oledDrawBitmap(centerX - 20, centerY - 20, &sleeping_bmp);
    oledDrawString(centerX + 15, centerY - 15, "Z", FONT_STANDARD);
    oledRefresh();
    timeElapsed = 0;
  }
  timeElapsed += 1;
}

int pretrezor (void) __attribute__ ((constructor));

int pretrezor(void)
{
  setup();
  storage_init(NULL, HW_ENTROPY_DATA, HW_ENTROPY_LEN);
  storage_unlock(1, NULL);
  oledInit();
  drawFace();
  oledRefresh();

  for (;;) {
    if (!unlocked) {
      emulatorPoll();
      checkPiTrezorButtons();
      if (sleeping) {
        animateFace();
      }
    } else {
      SDL_Quit();
      return 0;
    }
  }
}
