//
//  BaZi.h
//  BaZi
//
//  Created by ms on 2017/6/9.
//  Copyright © 2017年 ms. All rights reserved.
//

#ifndef BaZi_h
#define BaZi_h

typedef  struct _dizang{
    int len;
    int dz[3][2]; //{天干，十神};
}dizang;


/**
 根据公历的年月日时获取天干地支数

 @param year
 @param month 1-12
 @param day
 @param hour 24小时
 @param gzRt 返回干支数组 int[10] 最后两个为日空
 @return
 */
int getBaZi(int year, int month, int day, int hour, int *gzRt);

/**
 获取十神

 @param bazi 八字数组
 @param shishenRt 返回十神数组 3个int数组
 */
void getShiShen(int *bazi, int *shishenRt);

/**
 获取藏干

 @param dizhi 年月日时地支
 @param tg 日天干
 @param zangRt 返回地藏 结构体dizang
 */
void getDiZang(int dizhi, int tg, dizang *zangRt);

/**
 排大运

 @param gz 干支数组
 @param isShun 是否是顺大运 1顺 0逆
 @param dayunRt 返回的大运数组 16个int组成的数组
 */
void getDaYun(int *gz, int isShun, int *dayunRt);

/**
 是否是顺大运

 @param tg 年的天干
 @param sex 性别 1 男 0 女
 @return 1 顺大运  0 逆大运
 */
int isShun(int tg, sex);

#endif /* BaZi_h */
