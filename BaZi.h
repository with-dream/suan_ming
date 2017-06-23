//
//  BaZi.h
//  BaZi
//
//  Created by ms on 2017/6/9.
//  Copyright © 2017年 ms. All rights reserved.
//

#ifndef BaZi_h
#define BaZi_h

#include <time.h>

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

int getBaZiTm(struct tm *time, int *gzRt);
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
 @param dayunRt 返回的大运数组 16个int组成的数组 [天干，地支]
 */
void getDaYun(int *gz, int isShun, int *dayunRt);

/**
 是否是顺大运

 @param tg 年的天干
 @param sex 性别 1 男 0 女
 @return 1 顺大运  0 逆大运
 */
int isShun(int tg, sex);


/**
 计算交大运

 @param birthday 生日
 @param jieqi 生日下一个节气 分顺逆
 @param dayun 交大运[年, 月, 日]
 */
void jiaoDaYun(struct tm *birthday, struct tm *jieqi, int *dayunRt);

/**
 根据八字天干 大运地支计算生旺死绝
 
 @param dayun 排大运得到的数组
 @param tg 白字日天干
 @param shengWangRt 返回的生旺数组
 */
void getShengWang(int *dayun, int tg, int *shengWangRt);

/**
 二十八星宿

 @param year <#year description#>
 @param mon <#mon description#>
 @param day <#day description#>
 @return 返回星宿 从0计
 */
int getXingSu(int year, int mon, int day);

/**
 纳音

 @param tg <#tg description#>
 @param dz <#dz description#>
 @return <#return value description#>
 */
int getNaYin(int tg, int dz);


/**
 计算命卦

 @param year 出生年数
 @param isMan 男1 女0
 @return 命卦
 */
int getMingGua(int year, int isMan);

/**
 十种命格

 @param riTG 日天干
 @return 十种命格
 */
int getMingGe(int riTG);
#endif /* BaZi_h */
