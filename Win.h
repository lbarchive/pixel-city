//Versioning info
#define APP_TITLE           "PixelCity"
#define APP                 "pixelcity"
#define VERSION_MAJOR       1
#define VERSION_MINOR       0
#define VERSION_REVISION    10
//Best to disable screensaver mode when working on the program.
#define SCREENSAVER         0
//Do we hide scene building behing a loading screen or show it?
#define LOADING_SCREEN      1
//Controls the density of cars.
#define CARS                500
//The "dead zone" along the edge of the world, with super-low detail.
#define WORLD_EDGE          200
//How often to rebuild the city
#define RESET_INTERVAL      (SCREENSAVER ? 120000 : 999999)//milliseconds
//How long the screen fade takes when transitioning to a new city
#define FADE_TIME           (SCREENSAVER ? 1500 : 1) //milliseconds
//Debug ground texture that shows traffic lanes
#define SHOW_DEBUG_GROUND   0
//Controls the ammount of space available for buildings.  
//Other code is wrtten assuming this will be a power of two.
#define WORLD_SIZE          1024
#define WORLD_HALF          (WORLD_SIZE / 2)
//Bitflags used to track how world space is being used.
#define CLAIM_ROAD          1
#define CLAIM_WALK          2
#define CLAIM_BUILDING      4
#define MAP_ROAD_NORTH      8
#define MAP_ROAD_SOUTH      16
#define MAP_ROAD_EAST       32
#define MAP_ROAD_WEST       64
//Random SATURATED color
#define RANDOM_COLOR          (glRgbaFromHsl ((float)RandomVal (255)/255,1.0f, 0.75f))
//Used in orienting roads and cars
enum
{
  NORTH,
  EAST,
  SOUTH,
  WEST
};

#ifndef _WIN32

/* Win32 compatibility */
#include <sys/time.h>
/*
 * DWORD WINAPI GetTickCount(void);
 * DWORD A 32-bit unsigned integer. The range is 0 through 4294967295 decimal.
 * DWORD = unsigned long
 *
 * In the GNU C library, time_t is equivalent to long int.
 */
static inline time_t GetTickCount(void)
{
  struct timeval time;
  gettimeofday(&time, NULL);

  return time.tv_sec * 1000 + time.tv_usec / 1000;
}

#include <string.h>
static inline void ZeroMemory(void* dest, size_t length)
{
  memset(dest, 0, length);
}

#define GetRValue(rgb)   ((unsigned char)(rgb))
#define GetGValue(rgb)   ((unsigned char)((rgb) >> 8))
#define GetBValue(rgb)   ((unsigned char)((rgb) >> 16))
#endif

#ifdef _WIN32
HWND  WinHwnd (void);
#endif
void  WinPopup (char* message, ...);
void  WinTerm (void);
bool  WinInit (void);
int   WinWidth (void);
int   WinHeight (void);
void  WinMousePosition (int* x, int* y);
