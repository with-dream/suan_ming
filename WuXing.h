//
//  WuXing.h
//  BaZi
//
//  Created by ms on 2017/6/14.
//  Copyright © 2017年 ms. All rights reserved.
//

#ifndef WuXing_h
#define WuXing_h

#include <stdio.h>


/**
 根据干支获得五行
 
 @param gz <#gz description#>
 @param wx 金木水火土
 */
void getWuXing(int *gz, int *wx);


/**
 五行得分
 
 @param gz 八字
 @param wx 五行得分 [金,木,水,火,土,同类分,异类分,同异差,同类]
 */
void wuXingScore(int *gz, double *wx);

#endif /* WuXing_h */
