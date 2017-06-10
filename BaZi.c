//
//  BaZi.c
//  BaZi
//
//  Created by ms on 2017/6/9.
//  Copyright © 2017年 ms. All rights reserved.
//

#include "BaZi.h"
#include "Config.h"
#include "SolarTermNew.h"
#include <stdarg.h>

/**
 * 六十甲子
 */
const char *jiazi[] = {
    "甲子", "乙丑", "丙寅", "丁卯", "戊辰", "己巳", "庚午", "辛未", "壬申", "癸酉",
    "甲戌", "乙亥", "丙子", "丁丑", "戊寅", "己卯", "庚辰", "辛巳", "壬午", "癸未",
    "甲申", "乙酉", "丙戌", "丁亥", "戊子", "己丑", "庚寅", "辛卯", "壬辰", "癸巳",
    "甲午", "乙未", "丙申", "丁酉", "戊戌", "己亥", "庚子", "辛丑", "壬寅", "癸卯",
    "甲辰", "乙巳", "丙午", "丁未", "戊申", "己酉", "庚戌", "辛亥", "壬子", "癸丑",
    "甲寅", "乙卯", "丙辰", "丁巳", "戊午", "己未", "庚申", "辛酉", "壬戌", "癸亥"
};

static char *shishen[] = {
    //    {"日/干", "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸",
    /*"甲", */"比肩", "劫财", "食神", "伤官", "偏财", "正财", "七杀", "正官", "偏印", "正印",
    /*"乙", */"劫财", "比肩", "伤官", "食神", "正财", "偏财", "正官", "七杀", "正印", "偏印",
    /*"丙", */"偏印", "正印", "比肩", "劫财", "食神", "伤官", "偏财", "正财", "七杀", "正官",
    /*"丁", */"正印", "偏印", "劫财", "比肩", "伤官", "食神", "正财", "偏财", "正官", "七杀",
    /*"戊", */"七杀", "正官", "偏印", "正印", "比肩", "劫财", "食神", "伤官", "偏财", "正财",
    /*"己", */"正官", "七杀", "正印", "偏印", "劫财", "比肩", "伤官", "食神", "正财", "偏财",
    /*"庚", */"偏财", "正财", "七杀", "正官", "偏印", "正印", "比肩", "劫财", "食神", "伤官",
    /*"辛", */"正财", "偏财", "正官", "七杀", "正印", "偏印", "劫财", "比肩", "伤官", "食神",
    /*"壬", */"食神", "伤官", "偏财", "正财", "七杀", "正官", "偏印", "正印", "比肩", "劫财",
    /*"癸", */"伤官", "食神", "正财", "偏财", "正官", "七杀", "正印", "偏印", "劫财", "比肩"};

static const char *gan[] = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};
static const char *zhi[] = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"};

//获取八字 所有月-1
int getBaZi(int year, int month, int day, int hour, int gz[]){
    //    char bazi[30];
    //    memset(bazi, 0, 30);
    jieqi_date *jieqi = NULL;
    jieqi_date *zhongqi = NULL;
    getCacheJieQi(year, &jieqi, &zhongqi);
    if(jieqi == NULL) {
        printf("getCacheJieQi == NULL\n");
        return -1;
    }
    //让指针直接指向缓冲区的立春日期
    struct tm *lichun = &((jieqi+2)->date);
    
    month -= 1;
    hour = (hour+1)/2;
    
    unsigned long lichunSec = date2sec(year, lichun->tm_mon, lichun->tm_mday, lichun->tm_hour, lichun->tm_min, lichun->tm_sec);
    unsigned long cur = date2sec(year, month, day, hour, 0, 0);
    unsigned long base = date2sec(1900, 0, 31, 0, 0, 0);
    
    int yearGZ = year;
    
    int off = lichunSec-cur;
    if(off > 0){
        yearGZ -= 1;
    }
    
    //1864年是甲子年，每隔六十年一个甲子
    int idx = (yearGZ - 1864) % 60;
    //    strcpy(bazi, jiazi[idx]);
    //没有过春节的话那么年还算上一年的，此处求的年份的干支
    gz[0] = idx%10;
    gz[1] = idx%12;
    
    idx = idx % 5;
    int idxm=0;
    /**
     * 年上起月
     * 甲己之年丙作首，乙庚之岁戊为头，
     * 丙辛必定寻庚起，丁壬壬位顺行流，
     * 更有戊癸何方觅，甲寅之上好追求。
     */
    idxm=(idx+1)*2;
    if(idxm==10) idxm=0;
    //求的月份的干支
    //    strcat(bazi, gan[(idxm+month-1)%10]);
    //    strcat(bazi, zhi[(month+2-1)%12]);
    gz[2] = (idxm+month-1)%10;
    gz[3] = (month+2-1)%12;
    
    /*求出和1900年1月31日甲辰日相差的天数
     * 甲辰日是第四十天
     */
    int offset = (int) ((cur - base) / 86400);
    
    offset=(offset+40)%60;
    int kong = offset;
    //求的日的干支
    //    strcat(bazi, jiazi[offset]);
    gz[4] = offset%10;
    gz[5] = offset%12;
    
    /**
     * 日上起时
     * 甲己还生甲，乙庚丙作初，
     * 丙辛从戊起，丁壬庚子居，
     * 戊癸何方发，壬子是真途。
     */
    
    offset=(offset % 5 )*2;
    //求得时辰的干支
    //    strcat(bazi, gan[(offset+hour)%10]);
    //    strcat(bazi, zhi[hour]);
    gz[6] = (offset+hour)%10;
    gz[7] = hour;
    
    //日空 算法https://wenku.baidu.com/view/1855670702768e9951e738c9.html
    int monDZK = (kong%12+(9-kong%10))%12;
    //    strcat(bazi, zhi[(monDZK+1)%12]);
    //    strcat(bazi, zhi[(monDZK+2)%12]);
    gz[8] = (monDZK+1)%12;
    gz[9] = (monDZK+2)%12;
    
    //    printf("八字==>%s\n", bazi);
    
    return 0;
}

//获取八字十神
void getShiShen(int *bazi, int *shishen){
    shishen[0] = bazi[4]*10 + bazi[0];  //年
    shishen[1] = bazi[4]*10 + bazi[2];  //月
    shishen[2] = bazi[4]*10 + bazi[6];  //时
}

static void groupDiZang(int cout, int tgZang, dizang *zang, ...){
    va_list args;
    va_start(args, zang);
    
    zang->len = cout;
    
    for(int i=0; i<cout; i++){
        int arg = va_arg(args,int);
        
        zang->dz[i][0] = arg;
        zang->dz[i][1] = tgZang + zang->dz[i][0];
    }
    
    va_end(args);
}

//地藏天干、十神
//@param dizhi 传入年月日时地支
//@param tg 传入日天干
//@return zang 地藏
void getDiZang(int dizhi, int tg, dizang *zang){
    
    int tgZang = tg * 10;
    
    switch (dizhi) {
        case 0:
            groupDiZang(1, tgZang, zang, 9);
            break;
        case 1:
            groupDiZang(3, tgZang, zang, 7, 9, 5);
            break;
        case 2:
            groupDiZang(3, tgZang, zang, 0, 2, 4);
            break;
        case 3:
            groupDiZang(1, tgZang, zang, 1);
            break;
        case 4:
            groupDiZang(3, tgZang, zang, 9, 5, 4);
            break;
        case 5:
            groupDiZang(3, tgZang, zang, 2, 6, 4);
            break;
        case 6:
            groupDiZang(2, tgZang, zang, 3, 5);
            break;
        case 7:
            groupDiZang(3, tgZang, zang, 1, 3, 5);
            break;
        case 8:
            groupDiZang(3, tgZang, zang, 6, 8, 4);
            break;
        case 9:
            groupDiZang(1, tgZang, zang, 7);
            break;
        case 10:
            groupDiZang(3, tgZang, zang, 3, 7, 4);
            break;
        case 11:
            groupDiZang(2, tgZang, zang, 0, 8);
            break;
    }
}

//排大运  http://www.360doc.com/content/14/0228/09/15225642_356355022.shtml
void getDaYun(int *gz, int isShun, int *dayunRt){
    int i = 0;
    if(isShun)
        for(; i<8; i++){
            dayunRt[i*2] = (gz[2]+i+1)%10;
            dayunRt[i*2+1] = (gz[3]+i+1)%12;
        }
    else {
        int tg = gz[2] - 1;
        int dz = gz[3] - 1;
        for(; i<8; i++){
            dayunRt[i*2] = (tg-i<0)?(tg-i+10):(tg-i);
            dayunRt[i*2+1] = (dz-i<0)?(dz-i+12):(dz-i);
        }
    }
}

int isShun(int tg, sex){
    return ((sex&&!(tg%2)) || (!sex&&(tg%2)));
}
