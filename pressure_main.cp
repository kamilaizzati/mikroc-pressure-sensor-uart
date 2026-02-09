#line 1 "C:/Users/Asus/Downloads/topik/pressure/pressure_main.c"
#line 1 "c:/users/asus/downloads/topik/pressure/pressure_objects.h"
typedef struct Screen TScreen;

typedef struct Label {
 TScreen* OwnerScreen;
 char Order;
 unsigned int Left;
 unsigned int Top;
 unsigned int Width;
 unsigned int Height;
 char *Caption;
 const char *FontName;
 unsigned int Font_Color;
 char VerticalText;
 char Visible;
 char Active;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TLabel;

struct Screen {
 unsigned int Color;
 unsigned int Width;
 unsigned int Height;
 unsigned int ObjectsCount;
 unsigned int LabelsCount;
 TLabel * const code *Labels;
 void (*OnSwipeLeftPtr)();
 void (*OnSwipeRightPtr)();
 void (*OnSwipeUpPtr)();
 void (*OnSwipeDownPtr)();
 void (*OnZoomInPtr)();
 void (*OnZoomOutPtr)();
};

extern TScreen Screen1;
extern TLabel Label1;
extern TLabel Label2;
extern TLabel * const code Screen1_Labels[2];








extern char Label1_Caption[];
extern char Label2_Caption[];


void DrawScreen(TScreen *aScreen);
void DrawLabel(TLabel *ALabel);
void Check_TP();
void Start_TP();
void Process_TP_Press(unsigned int X, unsigned int Y);
void Process_TP_Up(unsigned int X, unsigned int Y);
void Process_TP_Down(unsigned int X, unsigned int Y);
#line 1 "c:/users/asus/downloads/topik/pressure/pressure_resources.h"
const code char Tahoma26x33_Regular[];
#line 1 "c:/users/asus/downloads/topik/pressure/click_pressure8_types.h"
#line 1 "c:/users/asus/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/asus/downloads/topik/pressure/click_pressure8_config.h"
#line 1 "c:/users/asus/downloads/topik/pressure/click_pressure8_types.h"
#line 3 "c:/users/asus/downloads/topik/pressure/click_pressure8_config.h"
const uint32_t _PRESSURE8_I2C_CFG[ 1 ] =
{
 100000
};
#line 20 "C:/Users/Asus/Downloads/topik/pressure/pressure_main.c"
float PressureData, readADC, press;
char demoText[ 50 ], text[20];
int x,y;

void InitTimer2(){
 RCC_APB1ENR.TIM2EN = 1;
 TIM2_CR1.CEN = 0;
 TIM2_PSC = 279;
 TIM2_ARR = 59999;
 NVIC_IntEnable(IVT_INT_TIM2);
 TIM2_DIER.UIE = 1;
 TIM2_CR1.CEN = 1;
}


void systemInit()
{



 mikrobus_logInit( _MIKROBUS1, 9600 );
 mikrobus_logWrite("--- System Init ---", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{



 InitTimer2();
 ADC1_Init();
 ADC_Set_Input_Channel( _ADC_CHANNEL_4);
 Delay_ms(200);
}

 void bingkai(unsigned dat)
{
 x = 350;y = 110;
 TFT_Set_Pen(CL_BLACK, 1);
 TFT_Set_Brush(1, 0,0, LEFT_TO_RIGHT, CL_BLACK, CL_BLACK);
 TFT_Rectangle(x, y, x+110, y+100);
 TFT_Set_Pen(CL_WHITE, 5);
 TFT_Set_Font(Tahoma26x33_Regular, CL_WHITE, FO_HORIZONTAL);
 FloatToStr(dat, text );
 TFT_Write_Text(text, x, y);
 Delay_ms(10);
}

void applicationTask()
{
 readADC = ADC1_Get_Sample(4);
 press = (float)(readADC*(3.3/4095));

 PressureData = (press/3.3)*25.0;

 FloatToStr(PressureData, demoText);
 bingkai( PressureData );





 mikrobus_logWrite(" Pressure data : ", _LOG_TEXT);
 mikrobus_logWrite(demoText, _LOG_TEXT);
 mikrobus_logWrite(" mBar", _LOG_LINE);
 Delay_ms( 1000 );
}

void Timer2_interrupt() iv IVT_INT_TIM2 {
 TIM2_SR.UIF = 0;

}

void main() {
 Start_TP();
 systemInit();
 applicationInit();

 while (1) {

 applicationTask();
 }
}
