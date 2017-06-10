/**
 获取24节气
 */
#ifndef SolarTermNew_h
#define SolarTermNew_h

#include "Config.h"


/**
 初始化getCacheJieQi函数用到的变量
 */
void initJieQi();

/**
 销毁getCacheJieQi初始的变量
 */
void destoryJieQi();

/**
 每年的节气都是固定的 所以使用缓存提高效率

 @param y 要查询的年 公历
 @param jieqi_date 返回的节气 jieqi_date*类型 12个节气
 @param jieqi_date 返回的中气 jieqi_date*类型 12个中气
 @return 返回节气数 12或13
 */
int getCacheJieQi(int y, jieqi_date **, jieqi_date **);


/**
 获取一年中的所有节气、中气

 @param y 要查询的年 公历
 @param jieqi_date 返回的节气 jieqi_date*类型 12个节气 有时会有13个
 @param jieqi_date 返回的中气 jieqi_date*类型 12个中气
 @return 返回节气数 12或13
 */
int paiYue(int y, jieqi_date jieqiRt[], jieqi_date zhongqiRt[]);

/**
 返回输入年份立春具体时间

 @param y 要查询的年 公历
 @param lichun 立春的具体时间 公历
 */
void getLiChunString(int y, struct tm *lichunRt);


/**
 返回日期所在节气区间

 @param src 输入的日期 公历
 @param between 节气及日期 2个 公历
 */
void getBetween(struct tm *src, jieqi_date *between[]);

#endif /* SolarTermNew_h */
