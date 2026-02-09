typedef struct Screen TScreen;

typedef struct  Label {
  TScreen*  OwnerScreen;
  char          Order;
  unsigned int  Left;
  unsigned int  Top;
  unsigned int  Width;
  unsigned int  Height;
  char          *Caption;
  const char    *FontName;
  unsigned int  Font_Color;
  char          VerticalText;
  char          Visible;
  char          Active;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TLabel;

struct Screen {
  unsigned int           Color;
  unsigned int           Width;
  unsigned int           Height;
  unsigned int           ObjectsCount;
  unsigned int           LabelsCount;
  TLabel                 * const code *Labels;
  void          (*OnSwipeLeftPtr)();
  void          (*OnSwipeRightPtr)();
  void          (*OnSwipeUpPtr)();
  void          (*OnSwipeDownPtr)();
  void          (*OnZoomInPtr)();
  void          (*OnZoomOutPtr)();
};

extern   TScreen                Screen1;
extern   TLabel                 Label1;
extern   TLabel                 Label2;
extern   TLabel                 * const code Screen1_Labels[2];


/////////////////////////
// Events Code Declarations
/////////////////////////

/////////////////////////////////
// Caption variables Declarations
extern char Label1_Caption[];
extern char Label2_Caption[];
/////////////////////////////////

void DrawScreen(TScreen *aScreen);
void DrawLabel(TLabel *ALabel);
void Check_TP();
void Start_TP();
void Process_TP_Press(unsigned int X, unsigned int Y);
void Process_TP_Up(unsigned int X, unsigned int Y);
void Process_TP_Down(unsigned int X, unsigned int Y);