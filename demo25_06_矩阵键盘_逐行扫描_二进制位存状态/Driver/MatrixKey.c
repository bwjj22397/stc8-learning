#include "MatrixKey.h"

#define KCOL1   P03
#define KCOL2   P06
#define KCOL3   P07
#define KCOL4   P17

#define KROW1   P34
#define KROW2   P35
#define KROW3   P40
#define KROW4   P41

#define ROW_NUM 4
#define COL_NUM 4

u16 key_state = 0xFFFF;

//获取某一按键的状态
#define KEY_STATE_POSITION(pos)    ((key_state >> pos) & 1)

//设置某一按键的状态
#define KEY_SET_STATE(state, pos)  (key_state = key_state & ~(1L << pos) | (state << pos))

static void GPIO_config(void) {
    P0_MODE_IO_PU(GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7);
    P1_MODE_IO_PU(GPIO_Pin_7);
    P3_MODE_IO_PU(GPIO_Pin_4 | GPIO_Pin_5);
    P4_MODE_IO_PU(GPIO_Pin_0 | GPIO_Pin_1);
}

void MatrixKey_init(void) {
    EAXSFR();
    GPIO_config();
}

void KROW_OUT(u8 row) {
    KROW1 = ((row == 0) ? 0 : 1);
    KROW2 = ((row == 1) ? 0 : 1);
    KROW3 = ((row == 2) ? 0 : 1);
    KROW4 = ((row == 3) ? 0 : 1);
}

u8 KCOL_IN(u8 col) {
    switch (col) {
        case 0: return KCOL1;
        case 1: return KCOL2;
        case 2: return KCOL3;
        case 3: return KCOL4;
        default: return 0;
    }
}

void MatrixKey_scan(void) {
    u8 row;
    u8 col;
    u8 pos = 0;

    for (row = 0; row < 4; row++) {
        KROW_OUT(row);
        
        NOP2();

        for (col = 0; col < 4; col++) {
            
            if (KEY_STATE_POSITION(pos) != KCOL_IN(col)) {
                KEY_SET_STATE(KCOL_IN(col), pos);

                if (!KCOL_IN(col)) {
                    printf("key%d (%d行%d列) DOWN\n", (int)(pos + 1), (int)(row + 1), (int)(col + 1));
                } else {
                    printf("key%d (%d行%d列) UP\n", (int)(pos + 1), (int)(row + 1), (int)(col + 1));
                }
            }

            pos++;
        }
        
    }
    

}
