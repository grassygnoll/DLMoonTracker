/* 
   dlMoonTrack.c
   DragonLance Moon Tracking Program

   This program will track the 3 moons of Krynn and
   will print the current effects based on the positions.

   BAW, 06/02/2016
*/

#include <stdlib.h>
#include <stdio.h>
#include "moon.h"

int main(void) {
        int Solinari[SOLDAYS] ; /* Solinari has a period of 36 days with 9 days per quarter */
        int Lunitari[LUNDAYS] ; /* Lunitari has a period of 28 days with 7 days per quarter */
        int Nuitari[NUIDAYS] ;  /* Nuitari has a period of 8 days with 2 days per quarter   */

        /* 
           Starting positions (1 based, count begins on the 1st cell of Low Sanction -
           i.e. "new moon" - and movement is counter-clockwise around) 
        int SolStart = 28 ;
        int LunStart = 7 ;
        int NuiStart = 4 ;
         */

        int i, SolStart, LunStart, NuiStart ;

        for( i = 1; i <= SOLDAYS; i++ ) {
                SolStart = i;
                LunStart = i;
                NuiStart = i;

                /* Bounds check the smaller cycled moon arrays */
                if( LunStart > LUNDAYS )
                        LunStart = i % LUNDAYS ;

                if( NuiStart > NUIDAYS )
                        NuiStart = i % NUIDAYS ;

                /* Initialize Moon Chart */
                setCurPos(SOLDAYS, SolStart, Solinari) ;
                setCurPos(LUNDAYS, LunStart, Lunitari) ;
                setCurPos(NUIDAYS, NuiStart, Nuitari) ;

                /* Debug Print */
                /* outputChart(Solinari, Lunitari, Nuitari) ; */

                int Nui = getCurPos(Nuitari, NUIDAYS) ;
                int Lun = getCurPos(Lunitari, LUNDAYS) ;
                int Sol = getCurPos(Solinari, SOLDAYS) ;
                printCurrentState(Sol, Lun, Nui) ;

                printf( "Solinari: " ) ;
                outputChart3(Solinari, SOLDAYS) ;
                printf( "Lunitari: " ) ;
                outputChart3(Lunitari, LUNDAYS) ;
                printf( "Nuitari:  " ) ;
                outputChart3(Nuitari, NUIDAYS) ;
        }

        return 0 ;
}

