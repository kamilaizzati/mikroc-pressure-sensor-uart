#include "pressure_objects.h"
#include "pressure_resources.h"
#include "built_in.h"


// TFT module connections
sbit TFT_BLED at GPIOF_ODR.B10;
sbit TFT_CS at GPIOF_ODR.B13;
unsigned int TFT_DataPort at GPIOE_ODR;
sbit TFT_RD at GPIOF_ODR.B12;
sbit TFT_RS at GPIOF_ODR.B15;
sbit TFT_RST at GPIOF_ODR.B14;
sbit TFT_WR at GPIOF_ODR.B11;
// End TFT module connections

// Touch Panel module connections
// End Touch Panel module connections

// Global variables
unsigned int Xcoord, Ycoord;
char PenDown;
typedef unsigned long TPointer;
TPointer PressedObject;
int PressedObjectType;
unsigned int caption_length, caption_height;
unsigned int display_width, display_height;

int _object_count;
unsigned short object_pressed;


void Write_to_Data_Lines(unsigned char _hi, unsigned char _lo) {
  GPIOE_ODR = (unsigned int) (_lo | (_hi << 8));
}

void Set_Index(unsigned short index) {
  TFT_RS = 0;
  Write_to_Data_Lines(0, index);
  TFT_WR = 0;
  asm nop;
  TFT_WR = 1;
}

void Write_Command(unsigned short cmd) {
  TFT_RS = 1;
  Write_to_Data_Lines(0, cmd);
  TFT_WR = 0;
  asm nop;
  TFT_WR = 1;
}

void Write_Data(unsigned int _data) {
  TFT_RS = 1;
  Write_to_Data_Lines(Hi(_data), Lo(_data));
  TFT_WR = 0;
  asm nop;
  TFT_WR = 1;
}

static void InitializeTouchPanel() {
  TFT_Set_Active(Set_Index, Write_Command, Write_Data);
  TFT_Init_SSD1963_Board_50(800, 480);

  TFT_Set_DBC_SSD1963(255);

  PenDown = 0;
  PressedObject = 0;
  PressedObjectType = -1;
}


/////////////////////////
  TScreen*  CurrentScreen;

  TScreen                Screen1;



static void InitializeObjects() {
  Screen1.Color                     = 0x0000;
  Screen1.Width                     = 800;
  Screen1.Height                    = 480;
  Screen1.ObjectsCount              = 0;
  Screen1.OnSwipeUpPtr    = 0;
  Screen1.OnSwipeDownPtr  = 0;
  Screen1.OnSwipeLeftPtr  = 0;
  Screen1.OnSwipeRightPtr = 0;
  Screen1.OnZoomInPtr     = 0;
  Screen1.OnZoomOutPtr    = 0;

}

static char IsInsideObject (unsigned int X, unsigned int Y, unsigned int Left, unsigned int Top, unsigned int Width, unsigned int Height) { // static
  if ( (Left<= X) && (Left+ Width - 1 >= X) &&
       (Top <= Y)  && (Top + Height - 1 >= Y) )
    return 1;
  else
    return 0;
}




void DrawScreen(TScreen *aScreen) {
 unsigned int order;
  char save_bled;

  object_pressed = 0;
  order = 0;
  CurrentScreen = aScreen;

  if ((display_width != CurrentScreen->Width) || (display_height != CurrentScreen->Height)) {
    save_bled = TFT_BLED;
    TFT_BLED           = 0;
    TFT_Set_Active(Set_Index, Write_Command, Write_Data);
    TFT_Init_SSD1963_Board_50(CurrentScreen->Width, CurrentScreen->Height);
    FT5XX6_SetSize(CurrentScreen->Width, CurrentScreen->Height);
    TFT_Fill_Screen(CurrentScreen->Color);
    TFT_Set_DBC_SSD1963(255);
    display_width = CurrentScreen->Width;
    display_height = CurrentScreen->Height;
    TFT_BLED           = save_bled;
  }
  else
    TFT_Fill_Screen(CurrentScreen->Color);


  while (order < CurrentScreen->ObjectsCount) {
  }
}

void Get_Object(unsigned int X, unsigned int Y) {
  _object_count = -1;
}


void Process_TP_Press(unsigned int X, unsigned int Y) {

  Get_Object(X, Y);

  if (_object_count != -1) {
  }
}

void Process_TP_Up(unsigned int X, unsigned int Y) {


  Get_Object(X, Y);


  if (_object_count != -1) {
  }
  PressedObject = 0;
  PressedObjectType = -1;
}

void Process_TP_Down(unsigned int X, unsigned int Y) {

  object_pressed      = 0;

  Get_Object(X, Y);

  if (_object_count != -1) {
  }
}

void Check_TP() {
  if (FT5XX6_PressDetect()) {
    if (FT5XX6_GetCoordinates(&Xcoord, &Ycoord) == 0) {
    // After a PRESS is detected read X-Y and convert it to Display dimensions space
      Process_TP_Press(Xcoord, Ycoord);
      if (PenDown == 0) {
        PenDown = 1;
        Process_TP_Down(Xcoord, Ycoord);
      }
    }
  }
  else if (PenDown == 1) {
    PenDown = 0;
    Process_TP_Up(Xcoord, Ycoord);
  }
}

void Init_MCU()
{
  GPIO_Digital_Output(&GPIOB_BASE, _GPIO_PINMASK_6);
  GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_7);
  GPIOB_ODR.B6 = 1;
  while (GPIOB_IDR.B7 == 0) {
    GPIOB_ODR.B6 = 0;
    Delay_us(10);
    GPIOB_ODR.B6 = 1;
    Delay_us(10);
  }
   I2C1_Init_Advanced(400000, &_GPIO_MODULE_I2C1_PB67);
}

char FT5XX6_Config()  {
  FT5XX6_SetI2CAddress(0x38);
  if (FT5XX6_IsOperational() != FT5XX6_OK)
    return  FT5XX6_FAILURE;
  FT5XX6_SetDefaultMode();
  FT5XX6_SetController(_TC_FT5X06);
  FT5XX6_SetSizeAndRotation(800,480,0);
return FT5XX6_OK;
}

void Start_TP() {
  Init_MCU();

  InitializeTouchPanel();
  if (FT5XX6_Config() == FT5XX6_OK) {
  } else {
    while(1);
  }


  InitializeObjects();
  display_width = Screen1.Width;
  display_height = Screen1.Height;
  DrawScreen(&Screen1);
}