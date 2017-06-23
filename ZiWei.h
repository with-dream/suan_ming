//
//  ZiWei.h
//  BaZi
//
//  Created by ms on 2017/6/20.
//  Copyright © 2017年 ms. All rights reserved.
//

#ifndef ZiWei_h
#define ZiWei_h

#include <stdio.h>

void getMingGong();
int getMingJu(int index, int tg);
void getMingJuNian(int shun, int mingJuIndex, int dz);
void getZiWeiStar(int mingJuIndex);
void getChangSheng(int shun, int mingJuIndex);

void getZiWeiInfo();

#endif /* ZiWei_h */
