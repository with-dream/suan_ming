//
//  Constellation.c
//  BaZi
//
//  Created by ms on 2017/6/8.
//  Copyright © 2017年 ms. All rights reserved.
//

#include "Constellation.h"

static int conDate[] = { 20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22 };
static char *con[] = { "摩羯座", "水瓶座", "双鱼座", "白羊座", "金牛座", "双子座", "巨蟹座", "狮子座", "处女座", "天秤座", "天蝎座", "射手座", "摩羯座" };

/**
 根据日期 获取星座
 */
void getConstellation(int month, int day, int *constell) {
    int offset = day < conDate[month - 1] ? -1 : 0;
    *constell = month+offset;
}

