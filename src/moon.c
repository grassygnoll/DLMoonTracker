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

        for( i = 0 ; i < total; i++ ) { 
                /* Using pos-1 b/c array is 0 based */
                if( i == (pos-1) )  
                        Moon[i] = 1 ;
                else
                        Moon[i] = 0 ;
        }
}

int getCurPos(int *Moon, int max) {
        int i ;
        int Pos = 0 ;

        for( i = 0; i < max; i++ )
                if( Moon[i] == 1 )
                        Pos = i + 1 ;

        return Pos ;
}

void printCurrentState(int Sol, int Lun, int Nui) {
        printf( "Current Moon Positions:\n" ) ;
        printf( "Solinari - %02i, which is in the %i quarter\n", Sol, (((Sol-1)/(SOLDAYS/4))+1) ) ;
        printf( "Lunitari - %02i, which is in the %i quarter\n", Lun, (((Lun-1)/(LUNDAYS/4))+1) ) ;
        printf( "Nuitari  - %02i, which is in the %i quarter\n", Nui, (((Nui-1)/(NUIDAYS/4))+1) ) ;
}

void outputChart2(int *Moon, int DaysInCycle) {
        int i, qtrMark ;
        char output ;

        qtrMark = DaysInCycle / 4 ;

        for( i = 0; i < DaysInCycle; i++ ) {
                if( (i % qtrMark) == 0 )
                        printf("|") ;

                if( Moon[i] == 1 && ((i / qtrMark) == 0))
                        output = 'O' ;
                else if( Moon[i] == 1 && ((i / qtrMark) == 1))
                        output = '(' ;
                else if( Moon[i] == 1 && ((i / qtrMark) == 2))
                        output = '@' ;
                else if( Moon[i] == 1 && ((i / qtrMark) == 3))
                        output = ')' ;
                else
                        output = ' ' ;

                printf("%c", output) ;
        }
        printf("|\n") ;
}
                        
void outputChart3(int *Moon, int DaysInCycle) {
        int i, j ;
        char output ;

        /* Create & Initialize output buffer */
        int OUTLEN = 36 ;
        int OUTQTR = OUTLEN / 4 ;
        char outBuffer[OUTLEN] ;

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
                        
void outputChart(int *Moon1, int *Moon2, int *Moon3 ) {
        int j ;

        for( j = 0; j < SOLDAYS; j++ ) {
                if( j == 0 ) {
                        printf( "Solinari\tLunitari\tNuitari\n" ) ;
                        printf( "========\t========\t=======\n" ) ;
                        printf( "    %i   \t    %i   \t   %i   \n", 
                                        Moon1[j], Moon2[j], Moon3[j] ) ;
                } else if( j < NUIDAYS ) {
                        printf( "    %i   \t    %i   \t   %i   \n", 
                                        Moon1[j], Moon2[j], Moon3[j] ) ;
                } else if( j < LUNDAYS ) {
                        printf( "    %i   \t    %i   \t   -    \n", 
                                        Moon1[j], Moon2[j] ) ;
                } else
                        printf( "    %i   \t    -    \t   -    \n", 
                                        Moon1[j] ) ;
        }
}

