#include <stdio.h>
#include "../SolarTermNew.h"
#include "../LunarGre.h"
#include "../Constellation.h"
#include "../BaZi.h"
#include <sys/timeb.h>
#include <time.h>

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

long long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
    //    return 0;
}

int main(int argc, const char * argv[]) {
    long test = getSystemTime();
    initJieQi();
    
    calendar cal;
    memset(&cal, 0, sizeof(calendar));
    cal.solar.tm_year = 1990;
    cal.solar.tm_mon = 5-1;
    cal.solar.tm_mday = 28;
    cal.solar.tm_hour = 4;
    cal.solar.tm_min = 0;
    
    int i;
    int sex = 1;
    //八字
    int gz[10];
    getBaZi(cal.solar.tm_year, cal.solar.tm_mon, cal.solar.tm_mday, cal.solar.tm_hour,  gz);
    for(i=0;i<8;i+=2){
        printf("%s", gan[gz[i]]);
        printf("%s ", zhi[gz[i+1]]);
    }
    printf("日空==>%s%s\n", zhi[gz[8]], zhi[gz[9]]);
    printf("\n");
    
    //四柱十神
    printf("四柱干支十神==>\n");
    int shishenData[3];
    getShiShen(gz, shishenData);
    for (i=0; i<3; i++) {
        printf("%s ", shishen[shishenData[i]]);
        if(i==1){
            printf("日元 ");
        }
    }
    printf("\n\n");
    
    //臧干
    dizang dizangs[4];
    memset(dizangs, 0, sizeof(dizang)*3);
    
    printf("臧干==>\n");
    for (int j=0; j<4; j++) {
        dizang *dizang = dizangs+i;
        getDiZang(gz[j*2+1], gz[4], dizang);
        for(i=0;i<dizang->len;i++){
            printf("%s %s ", gan[dizang->dz[i][0]], shishen[dizang->dz[i][1]]);
        }
        printf("\n");
    }
    printf("\n");
    
    //大运
    printf("大运==>\n");
    int dayun[16];
    getDaYun(gz, isShun(gz[0], sex), dayun);
    for (i=0; i<16; i+=2) {
        printf("%s%s ", gan[dayun[i]], zhi[dayun[i+1]]);
    }
    printf("\n\n");
    
    //节气
    jieqi_date *between[2];
    getBetween(&cal.solar, between);
    for (i=0; i<2; i++) {
        char date[50];
        formT(&between[i]->date, date, 50);
        printf("%s:%s", between[i]->name, date);
    }
    printf("\n");
    
    //TODO  起大运周岁
    
    //日历
    printf("节气==>\n");
    jieqi_date *jieqi;
    jieqi_date *zhongqi;
    
    int cout = getCacheJieQi(cal.solar.tm_year, &jieqi, &zhongqi);
    
    for(i=0; i<cout; i++){
        char *name = jieqi[i].name;
        struct tm *time = &jieqi[i].date;
        
        char datetime[200];
        strftime(datetime, 200, "%y-%m-%d %H:%M:%S\n", time);
        printf("%s ==> %s", name, datetime);
    }
    printf("\n");
    
    printf("日历==>\n");
    solar2lunar(&cal);
    printCalendar(cal);
    printf("\n\n");
    
    printf("diff==>%ld\n", getSystemTime() - test);
    return 0;
}
