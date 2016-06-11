/* 
   moon.h
   DragonLance Moon Tracking Program

   Header file defining all moon related objects and 
   procedures

   BAW, 06/10/2016
*/

#define SOLDAYS 36
#define LUNDAYS 28
#define NUIDAYS  8

void outputChart(int *Moon1, int *Moon2, int *Moon3) ;
void outputChart2(int *Moon, int DaysInCycle) ;
void outputChart3(int *Moon, int DaysInCycle) ;
void printCurrentState(int Sol, int Lun, int Nui) ;
int getCurPos(int *Moon, int max) ;
void setCurPos(int max, int pos, int *Moon) ;
