//
//  LunarGre.h
//  BaZi
//
//  Created by ms on 2017/6/5.
//  Copyright © 2017年 ms. All rights reserved.
//

#ifndef LunarGre_h
#define LunarGre_h

#include "Config.h"

/**
 公历转农历

 @param calendar 需要填充公历日期solar 返回农历lun
 */
void solar2lunar(calendar *);

/**
 公历转农历 带节日

 @param calendar 需要填充公历日期solar 返回农历lun
 */
void solar2lunarInfo(calendar *);


/**
 24小时转为时辰

 @param hour 24小时
 @return 时辰 0-11
 */
int solar2shiChen(int hour);

#endif /* LunarGre_h */
