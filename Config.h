//
//  Config.h
//  BaZi
//
//  Created by ms on 2017/6/2.
//  Copyright © 2017年 ms. All rights reserved.
//

#ifndef Config_h
#define Config_h

#include <time.h>

#define true 1
#define false 0


#define LEN_D(__ARRAY__) sizeof(__ARRAY__)/sizeof(__ARRAY__[0])


/**
 农历结构体
 */
typedef struct _lunar{
    int tm_year;
    int tm_mon;
    int tm_mday;
    int tm_hour;
    int tm_min;
}lunar;


/**
 日历结构体
 */
typedef struct _calendar{
    char zodiac[3];         //生肖
    char weekFestival[30];  //周节日
    char solarFestival[30]; //公历节日
    char lunarFestival[20]; //农历节日
    char GanZhiYear[10];    //年干支
    char lunarMonthName[10];    //农历月
    char lunarDayName[10];  //农历日期
    char term[10];          //农历节气
    lunar lun;              //农历日期 数字
    struct tm solar;       //公历日期
}calendar;

typedef struct _jieqi_date{
    struct tm date;
    char name[10];
}jieqi_date;


/**
 打印calendar结构体

 @param calendar
 */
void printCalendar(calendar );


/**
 判断是否是闰年

 @param int 传入公历年
 @return  1 闰年  0 平年
 */
int isLeap(int );


/**
 1900-1-1 0:0:0经过的时间

 @param year
 @param mon
 @param day
 @param hour
 @param min
 @param sec
 @return 从1900-1-1 0:0:0经过的秒数
 */
unsigned long date2sec (unsigned int year, unsigned int mon, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec);

unsigned long date2secLunar (lunar *lun);
unsigned long date2secTm (struct tm *time);


/**
 格式化时间

 @param time <#time description#>
 @param date <#date description#>
 @param len <#len description#>
 */
void formT(struct tm *time, char *date, int len);

#endif /* Config_h */
