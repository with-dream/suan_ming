//
//  Config.c
//  BaZi
//
//  Created by ms on 2017/6/2.
//  Copyright © 2017年 ms. All rights reserved.
//

#include "Config.h"
#include <stdio.h>

static int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};

void printCalendar(calendar cal){
    printf("公历日期==>%d-%d-%d\n", cal.solar.tm_year, cal.solar.tm_mon, cal.solar.tm_mday);
    printf("农历日期==>%d-%d-%d\n", cal.lun.tm_year, cal.lun.tm_mon, cal.lun.tm_mday);
    printf("农历日期==>%s%s%s\n", cal.GanZhiYear, cal.lunarMonthName, cal.lunarDayName);
    printf("生肖==>%s\n", cal.zodiac);
    printf("公历节日==>%s\n", cal.solarFestival);
    printf("农历节日==>%s\n", cal.lunarFestival);
    printf("周节日==>%s\n", cal.weekFestival);
    printf("节气==>%s\n", cal.term);
}

int isLeap(int year){
    return ((year%4==0) && (year%100!=0)) || (year%400==0);
}

/**
 1900-1-1 0:0:0经过的时间
 */
unsigned long date2sec (unsigned int year, unsigned int mon, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec)
{
    int days = 0;
    int i =0;
    int leap = isLeap(year);
    for(i=0;i<year-1900;i++){
        days += isLeap(1900+i) ? 366 : 365;
    }
    
    for (i=0; i<mon; i++) {
        if(mon==1 && leap){
            days += 29;
            continue;
        }
        
        days += DAY[i];
    }
    
    days += day;
    
    return ((days*24+hour)*60+min)*60+sec;
}

unsigned long date2secLunar (lunar *lun){
    return date2sec(lun->tm_year, lun->tm_mon-1, lun->tm_mday, lun->tm_hour, lun->tm_min, 0);
}

unsigned long date2secTm (struct tm *time){
    return date2sec(time->tm_year, time->tm_mon, time->tm_mday, time->tm_hour, time->tm_min, time->tm_sec);
}

void formT(struct tm *time, char *date, int len){
    strftime(date, len, "%y-%m-%d %H:%M:%S\n", time);
}

