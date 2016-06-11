/* 
   moon.c
   DragonLance Moon Tracking Program

   Implementation source for moon related objects and 
   procedures

   BAW, 06/10/2016
*/

#include <stdlib.h>
#include <stdio.h>
#include "moon.h"

void setCurPos(int total, int pos, int *Moon) {
        int i ;

        for( i = 0 ; i < total; i++ )
                Moon[i] = 0 ;

        Moon[pos] = 1 ;
}

int getCurPos(int *Moon, int max) {
        int i ;

        for( i = 0; i < max; i++ ) {
                if( Moon[i] == 1 )
                        break ;
        }

        return i ;
}

void printCurrentState(int Sol, int Lun, int Nui) {
        printf( "Current Moon Positions:\n" ) ;

        /*
           Arrays are 0 based, ints passed in reflect that; Since this is
           for display purposes only, increment ints by 1 so display reflects
           normal counting (1 based) from the user perspective
        */
        printf( "Solinari - %02i, which is in the %i quarter\n", (Sol+1), ((Sol/(SOLDAYS/4))+1) ) ;
        printf( "Lunitari - %02i, which is in the %i quarter\n", (Lun+1), ((Lun/(LUNDAYS/4))+1) ) ;
        printf( "Nuitari  - %02i, which is in the %i quarter\n", (Nui+1), ((Nui/(NUIDAYS/4))+1) ) ;
}

void outputChart3(int *Moon, int DaysInCycle) {
        int i, j ;
        char output ;

        /* Create & Initialize output buffer */
        int OUTLEN = 36 ;
        int OUTQTR = OUTLEN / 4 ;
        char outBuffer[OUTLEN] ;

        /* Initializes buffer to empty */
        for( j = 0; j < OUTLEN; j++ ) {
                outBuffer[j] = ' ' ;
        }

        /* 
           Normalize current moon to 36 day max cycle and 
           Update output buffer with proper moon position 
           based on corresponding ratio
         */
        for( i = 0; i < DaysInCycle; i++ ) {
                if( Moon[i] == 1 ) {
                        outBuffer[((i * OUTLEN)/DaysInCycle)] = 1 ;
                        break ;
                }
        }

        /* Output the output buffer */
        for( i = 0; i < OUTLEN ; i++ ) {
                if( (i % OUTQTR) == 0 )
                        printf("|") ;

                if( outBuffer[i] == 1 && ((i / OUTQTR) == 0))
                        output = 'O' ;
                else if( outBuffer[i] == 1 && ((i / OUTQTR) == 1))
                        output = '(' ;
                else if( outBuffer[i] == 1 && ((i / OUTQTR) == 2))
                        output = '@' ;
                else if( outBuffer[i] == 1 && ((i / OUTQTR) == 3))
                        output = ')' ;
                else
                        output = ' ' ;

                printf("%c", output) ;
        }
        printf("|\n") ;
}
                        
