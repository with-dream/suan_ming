//
//  ZiWei.c
//  BaZi
//
//  Created by ms on 2017/6/20.
//  Copyright © 2017年 ms. All rights reserved.
//

#include "ZiWei.h"
#include <string.h>

static const char *gan[] = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};
static const char *zhi[] = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"};

const char *cShui2[] = {"2-11","12-21","22-31","32-41","42-51","52-61","62-71","72-81","82-91","92-101","102-111","112-121"};
const char *cMu3[]   = {"3-12","13-22","23-32","33-42","43-52","53-62","63-72","73-82","83-92","93-102","103-112","113-122"};
const char *cJin4[]  = {"4-13","14-23","24-33","34-43","44-53","54-63","64-73","74-83","84-93","94-103","104-113","114-123"};
const char *cTu5[]   = {"5-14","15-24","25-34","35-44","45-54","55-64","65-74","75-84","85-94","95-104","105-114","115-124"};
const char *cHuo6[]  = {"6-15","16-25","26-35","36-45","46-55","56-65","66-75","76-85","86-95","96-105","106-115","116-125"};

static int year = 2004;
static int mon = 2;
static int day = 6;
static int hour = 4;//12个时辰
static int min = 0;
static int sec = 0;
static int nTianGan = 0;
static int nDiZhi = 8;
static int sex = 1;//1 男
static int shun;

char *szGongName[] = {
    "本命宫", "父母宫", "福德宫", "田宅宫", "官禄宫",
    "仆役宫", "迁移宫", "疾厄宫", "财帛宫", "子女宫", "夫妻宫", "兄弟宫"
};
//主星
const char *zhuXing[] = {"紫微","巨门","廉贞","武曲","破军","贪狼","天府","天同","天机","天梁","天相","七杀","太阴","太阳"};
//吉辅星
const char *jiFuXing[] = {"文曲","文昌","左辅","右弼","天魁","天钺","天马","禄存","天官","天福"};
//凶辅星
const char *xiongFuXing[] = {"擎羊","陀罗","火星","铃星","地劫","地空","天刑","天姚"};
//十二博士星
const char *cBoShi[] = {"博士","力士","青龙","小耗","将军","奏书","飞廉","喜神","病符","大耗","伏兵","官符"};
//十二太岁
const char *cTaiSui[] = {"丧门","贯索","五鬼","死符","岁破","龙德","白虎","天德","天狗","凶神","太岁","晦气"};
//十二将前
const char *cJiangQian[] = {"将星","攀鞍","驿马","息神","华盖","劫煞","灾煞","天煞","指背","咸池","月煞","亡神"};
//杂星
const char *ZaXing[] = {"台辅","封诰","解神","天巫","天月","阴煞","三台","八座","恩光","天贵",
                        "龙池","凤阁","天空","截空","孤辰","宿寡","天虚","天哭","红鸾","天喜",
                        "蜚廉","破碎","天才","天寿","天厨","天伤","天使"};
//长生
const char *cChangSheng[] = {"长生","沐浴","冠带","临官","帝旺","衰","病","死","墓","绝","胎","养"};
//庙旺
const char *miaoWangName[] = {"庙", "旺", "得", "平", "陷"};
const char *miaoWangStar[] = {"擎羊","天马","禄存","破军","七杀","天梁","天相","巨门","贪狼","太阴",
                        "天府","廉贞","天同","武曲","太阳","天机","紫微","文曲","文昌","右弼",
                        "左辅","天钺","天魁","地劫","地空","铃星","火星","陀罗"};
const int miaoWangStarInfo[12][28] = {
    //   羊   马   禄   破   杀   梁   相   巨   狼   阴   府   廉   同   武   阳   机   紫   曲   昌   右   左   钺   魁   劫   空   铃   火   陀
    {-1,1,0,4,0,0,0,0,3,2,0,0,2,2,1,1,0,3,4,1,0,1,-1,3,4,0,0,4},  //寅
    {4,-1,1,1,4,0,4,0,1,4,3,2,0,4,0,1,1,1,3,4,4,-1,0,3,3,0,3,-1},
    {0,-1,-1,1,1,1,1,3,0,2,0,1,3,0,0,0,4,0,1,0,0,-1,-1,4,4,1,2,0},
    {-1,3,0,2,3,4,3,3,4,4,3,4,0,3,3,3,1,0,4,3,3,1,-1,2,0,1,1,4},
    {3,-1,1,0,1,0,1,1,1,4,1,3,4,1,0,0,0,4,0,1,1,-1,0,0,0,0,0,-1},
    {0,-1,-1,0,1,1,2,4,0,3,0,0,4,0,3,4,0,1,3,0,0,1,-1,3,3,1,2,0},
    {-1,1,0,4,0,4,0,0,0,3,3,0,1,3,2,3,1,3,1,2,3,0,-1,0,0,1,4,4},
    {4,-1,1,4,2,4,4,0,3,1,1,3,3,1,2,1,3,0,0,4,4,0,-1,3,0,4,4,-1},
    {0,-1,-1,1,0,1,2,1,0,1,0,1,3,0,4,0,2,4,4,0,0,-1,-1,3,4,0,0,0},
    {-1,3,0,3,3,4,3,1,4,0,1,4,0,3,4,3,1,1,1,3,2,-1,1,1,4,0,3,4},
    {4,-1,1,0,1,0,0,1,1,0,0,3,1,1,4,0,3,0,1,0,1,-1,1,4,3,4,3,-1},   //子
    {0,-1,-1,1,0,1,0,1,0,0,0,1,4,0,4,4,0,0,0,0,0,-1,1,4,4,4,1,0}    //丑
};
const char *cMingzhu[] = {"贪狼","巨门","禄存","文曲","廉贞","武曲","破军","武曲","廉贞","文曲","禄存","巨门"};
const char *cShenzhu[] = {"铃星","天相","天梁","天同","文昌","天机","火星","天相","天梁","天同","文昌","天机"};
const char *huaJiName[] = {"[禄]","[权]","[科]","[忌]"};

int xingLevel[]={0/*主星*/, 1/*吉辅星*/, 2/*凶辅星*/, 1/*博士星*/, 1/*太岁*/, 1/*太岁*/};
enum xingLevel{
    ZXL = 0,//主星
    XFXL = 1,//凶辅星
    JFXL = 2,//吉辅星
    BSL = 3,//十二博士星
    TSL = 4,//十二太岁
    JQL = 5,//十二将前
    CSL = 6,//长生
    ZAXL = 7//杂星
};

char *getXingName(enum xingLevel xl, int index){
    switch (xl) {
        case ZXL:
            return *(zhuXing+index);
        case JFXL:
            return *(jiFuXing+index);
        case XFXL:
            return *(xiongFuXing+index);
        case BSL:
            return *(cBoShi+index);
        case TSL:
            return *(cTaiSui+index);
        case JQL:
            return *(cJiangQian+index);
        case CSL:
            return *(cChangSheng+index);
        case ZAXL:
            return *(ZaXing+index);
    }
    return NULL;
}

char *shenName[]={"命-身", "财-身", "迁-身", "官-身"};
int shenNameIndex[]={0, 4, 6, 8};
char *mingJuName[] = {"水二局", "木三局", "金四局", "土五局", "火六局"};
int mingJuNameIndex[] = {2, 3, 4, 5, 6};

void doError(char *err){
    printf("error==>%s\n", err);
}

typedef struct _xingYao{
    short index;
    enum xingLevel level; //enum xingLevel
    short wang;  //旺庙
    short huaJi;//化忌
}xingYao;

typedef struct _gong{
    xingYao xy[15];
    int xyCout; //xingYao结构体个数
    int tg;
    int dz;
    int nian;
    int gongIndex;  //十二宫
    char mingNian[10];
}gong;

gong mingGong[12];

typedef struct _ZiWei{
    int mingGongIndex;//命宫
    int shenGongIndex;//身宫
    int mingJuIndex;//命局
    int mingZhuIndex;//命主
    int shenZhuIndex;//身主
}ZiWei;
ZiWei ziWei;

//1 阳男阴女
int isShunYear(int year, int isMan){
    return (year+isMan)%2;
}

//安星
static void insert(int index, short xing, enum xingLevel xl){
    mingGong[index].xy[mingGong[index].xyCout].index = xing;
    mingGong[index].xy[mingGong[index].xyCout].level = xl;
    mingGong[index].xyCout++;
}
//设置旺庙 从1开始
static void insertWang(int index, short wang){
    mingGong[index].xy[mingGong[index].xyCout].wang = wang+1;
}

void getMingGong(){
    int i = 0;
    shun = isShunYear(year, sex);
    //命宫
    int ming = mon - hour;
//    printf("命宫==>\n");
    for(i=0; i<12; i++){
        mingGong[i].gongIndex = (12-ming+i+1)%12;
//        printf("%s  ", szGongName[mingGong[i].gongIndex]);
    }
    printf("\n");
    
    //身宫
    int shen = mon + hour;
    ziWei.shenGongIndex = (mingGong[0].gongIndex+(23+shen)%12)%12;
    printf("身宫==>%s\n", szGongName[ziWei.shenGongIndex]);
    
    //宫天干
    int tg_tmp= nTianGan>4?(nTianGan-5):nTianGan;
    for (i=0; i<12; i++) {
        int gongGanIndex = 10+((nTianGan+1)*2)%10+i;
        mingGong[i].tg = gongGanIndex%10;
        mingGong[i].dz = (i+2)%12;
//        printf("%s ", gan[mingGong[i].tg]);
    }

    //命局
    int mingGongIndex = -1;
    for(i=0;i<12;i++){
        if(mingGong[i].gongIndex == 0){
            mingGongIndex = i;
            break;
        }
    }
    
    ziWei.mingJuIndex = getMingJu(mingGongIndex, mingGong[mingGongIndex].tg);
    printf("命局==>%s\n", mingJuName[ziWei.mingJuIndex]);
    //命局年限
    getMingJuNian(shun, ziWei.mingJuIndex, mingGongIndex);
    
    //紫微星
    getZiWeiStar(mingJuNameIndex[ziWei.mingJuIndex]);
    
    //长生
    getChangSheng(isShunYear(year, sex), mingJuNameIndex[ziWei.mingJuIndex]);
}

//阳男阴女顺
void getMingJuNian(int shun, int mingJuIndex, int dz){
    int i = 0;
    char **nian = NULL;
    switch (mingJuIndex) {
        case 0:
            nian = cShui2;
            break;
        case 1:
            nian = cMu3;
            break;
        case 2:
            nian = cJin4;
            break;
        case 3:
            nian = cTu5;
            break;
        case 4:
            nian = cHuo6;
            break;
    }
    
    for (i=0; i<12; i++) {
        if(shun)
            strcpy(mingGong[i].mingNian, nian[(12+i-dz)%12]);
        else
            strcpy(mingGong[i].mingNian, nian[(12+dz-i)%12]);
    }
}

int getMingJu(int index, int tg){
    if(tg%2)
        tg -= tg;
    tg /= 2;
    
    switch (tg) {
        case 0://甲乙
            switch (index) {
                case 0:
                case 1:
                case 6:
                case 7:
                    return 0;
                case 2:
                case 3:
                case 8:
                case 9:
                    return 4;
                case 4:
                case 5:
                case 10:
                case 11:
                    return 2;
            }
            break;
        case 1://丙丁
            switch (index) {
                case 0:
                case 1:
                case 6:
                case 7:
                    return 0;
                case 2:
                case 3:
                case 8:
                case 9:
                    return 4;
                case 4:
                case 5:
                case 10:
                case 11:
                    return 3;
            }
            break;
        case 2://戊己
            switch (index) {
                case 0:
                case 1:
                case 6:
                case 7:
                    return 3;
                case 2:
                case 3:
                case 8:
                case 9:
                    return 1;
                case 4:
                case 5:
                case 10:
                case 11:
                    return 4;
            }
            break;
        case 3:
            switch (index) {
                case 0:
                case 1:
                case 6:
                case 7:
                    return 1;
                case 2:
                case 3:
                case 8:
                case 9:
                    return 2;
                case 4:
                case 5:
                case 10:
                case 11:
                    return 3;
            }
            break;
        case 4:
            switch (index) {
                case 0:
                case 1:
                case 6:
                case 7:
                    return 2;
                case 2:
                case 3:
                case 8:
                case 9:
                    return 0;
                case 4:
                case 5:
                case 10:
                case 11:
                    return 1;
            }
            break;
    }
    return -1;
}

//紫微星速求公式如下，设农历出生日数为A，五行局数为B。
//第一步：公式(A+X)÷B = C ，C为所得商数,刚好能除尽时,“最小的数”就是X
//第二步：当X为偶数时用公式D=C+X，求出紫微星所在宫位数D
//        当X为奇数时用公式D=C-X,出现负数时要加上12
//第三步：把D转换成紫微星所在宫位，D的宫位数与月支宫位数完全一样，
//        即寅1，卯2，辰3，巳4，午5，未6，申7，酉8，戌9，亥10，子11，丑12
void getZiWeiStar(int mingJuIndex)
{
    int i = 0;
    int a=day;
    int b=mingJuIndex;
    int x=0;
    for (i=0;i<10;i++)
    {
        if ((a+i)%b==0)
        {
            x=i;
            break;
        }
    }
    int c=(a+x)/b;
    int nZiWei=1;
    if (x==0 || x%2==0)
    {
        nZiWei=c+x;
        nZiWei=nZiWei%12;
    }
    else nZiWei=(12+c-x)%12;
    //紫微天机逆行旁，隔一阳武天同当，又隔二位廉贞地，空三复见紫微郞。
    int index = (11+nZiWei)%12;//紫薇
    insertWang(index, 16);
    insert(index, 0, ZXL);
    index = (11+nZiWei-1)%12;//天机
    insertWang(index, 15);
    insert(index, 8, ZXL);
    index = (11+nZiWei-3)%12;//太阳
    insertWang(index, 14);
    insert(index, 13, ZXL);
    index = (11+nZiWei-4)%12;//武曲
    insertWang(index, 13);
    insert(index, 3, ZXL);
    
    index = (11+nZiWei-5)%12;//天同
    insertWang(index, 12);
    insert(index, 7, ZXL);
    
    index = (11+nZiWei-8)%12;//廉贞
    insertWang(index, 11);
    insert(index, 2, ZXL);
    
    index = (13-nZiWei)%12;//天府
    insertWang(index, 10);
    insert(index, 6, ZXL);
    
    //nZiWei与寅1，卯2...对应
//    if (nZiWei ==1 || nZiWei==7) {
//        index = nZiWei-1;
//        insertWang(index, 16);
//        insert(index, 0, ZXL);
//        
//        index = nZiWei-1;
//        insertWang(index, 10);
//        insert(index, 6, ZXL);
//    }
    
    //天府太阴与贪狼，巨门天相及天梁，七杀空三破军位
//    int xingTmp[]={12,5,1,10,9,11};
//    for(i=0;i<6;i++){
//        index = (13-nZiWei+1+i)%12;
//        insert(index, xingTmp[i], ZXL);
//    }
    //太阴
    index = (13-nZiWei+1)%12;
    insertWang(index, 9);
    insert(index, 12, ZXL);
    
    //贪狼
    index = (13-nZiWei+2)%12;
    insertWang(index, 8);
    insert(index, 5, ZXL);
    
    //巨门
    index = (13-nZiWei+3)%12;
    insertWang(index, 7);
    insert(index, 1, ZXL);
    
    //天相
    index = (13-nZiWei+4)%12;
    insertWang(index, 6);
    insert(index, 10, ZXL);
    
    //天梁
    index = (13-nZiWei+5)%12;
    insertWang(index, 5);
    insert(index, 9, ZXL);
    
    //七杀
    index = (13-nZiWei+6)%12;
    insertWang(index, 4);
    insert(index, 11, ZXL);
    
    //破军
    index = (13-nZiWei+10)%12;
    insertWang(index, 3);
    insert(index, 4, ZXL);
    
//    printf("如果%d有值 放到2  %d--%s\n", (13-nZiWei+1)%12, (13-nZiWei+1)%12, "太阴");
//    printf("如果%d有值 放到2  %d--%s\n", (13-nZiWei+2)%12, (13-nZiWei+2)%12, "贪狼");
//    printf("如果%d有值 放到2  %d--%s\n", (13-nZiWei+3)%12, (13-nZiWei+3)%12, "巨门");
//    printf("如果%d有值 放到2  %d--%s\n", (13-nZiWei+4)%12, (13-nZiWei+4)%12, "天相");
//    printf("如果%d有值 放到2  %d--%s\n", (13-nZiWei+5)%12, (13-nZiWei+5)%12, "天梁");
//    printf("如果%d有值 放到2  %d--%s\n", (13-nZiWei+6)%12, (13-nZiWei+6)%12, "七杀");
//    printf("如果%d有值 放到2  %d--%s\n", (13-nZiWei+10)%12, (13-nZiWei+10)%12, "破军");
}

//金长生在巳，木长生在亥，火长生在寅，水土长生在申。由长生宫起头。
//阳男阴女顺行，阴男阳女逆行
void getChangSheng(int shun, int mingJuIndex){
    int i = 0;
    switch (mingJuIndex) {
        case 2:
        case 5:
            if(shun)
                for(i=0;i<12;i++){
                    insert(i, (12+i+6)%12, CSL);
                }
            else
                for(i=0;i<12;i++){
                    insert(i, (12-i+6)%12, CSL);
                }
            break;
        case 3:
            if(shun)
                for(i=0;i<12;i++){
                    insert(i, (12+i+3)%12, CSL);
                }
            else
                for(i=0;i<12;i++){
                    insert(i, (12-i+9)%12, CSL);
                }
//                for(i=0;i<12;i++)
//                    printf("%d==>%s\n", i, cChangSheng[(12-i+9)%12]);
            break;
        case 4:
            if(shun)
                for(i=0;i<12;i++){
                    insert(i, (12+i+9)%12, CSL);
                }
//                for(i=0;i<12;i++)
//                    printf("%d==>%s\n", i, cChangSheng[(12+i+9)%12]);
            else
//                for(i=0;i<12;i++)
//                    printf("%d==>%s\n", i, cChangSheng[(12-i+3)%12]);
                for(i=0;i<12;i++){
                    insert(i, (12-i+3)%12, CSL);
                }
            break;
        case 6:
            if(shun)
                for(i=0;i<12;i++){
                    insert(i, (12+i)%12, CSL);
                }
//                for(i=0;i<12;i++)
//                    printf("%d==>%s\n", i, cChangSheng[(12+i)%12]);
            else
                for(i=0;i<12;i++){
                    insert(i, (12-i)%12, CSL);
                }
//                for(i=0;i<12;i++)
//                    printf("%d==>%s\n", i, cChangSheng[(12-i)%12]);
            break;
    }
}

//辰上顺时文昌 戌上逆时文曲
void getChangQuStar() {
    int indexC = (12-hour+8)%12;//文昌
    insertWang(indexC, 18);
    insert(indexC, 1, JFXL);
    
    int indexQ = (hour+2)%12;//文曲
    insertWang(indexQ, 17);
    insert(indexQ, 0, JFXL);
    
    //恩光天贵 恩光顺文昌初一退一格 天贵顺文曲初一退一格
    int index = (indexC+day-1+11)%12;//恩光
    insert(index, 8, ZAXL);
    
    index = (indexQ+day-1+11)%12;//天贵
    insert(index, 9, ZAXL);
}

//甲禄在寅乙禄卯，丙戊在巳丁己午，庚禄居申辛禄酉，壬禄居亥癸禄子。
void getLuCunStar()
{
    int index = -1;
    switch (nTianGan) {
        case 0:
            index = 0;
            break;
        case 1:
            index = 1;
            break;
        case 2:
        case 4:
            index = 3;
            break;
        case 3:
        case 5:
            index = 4;
            break;
        case 6:
            index = 6;
            break;
        case 7:
            index = 7;
            break;
        case 8:
            index = 9;
            break;
        case 9:
            index = 10;
            break;
    }
    insertWang(index, 2);
    insert(index, 7, JFXL);
    
    //禄存前为羊 后为陀
    int indexY = (index+1)%12;
    insertWang(indexY, 0);
    insert(indexY, 0, XFXL);
    
    int indexT = (index-1)%12;
    insertWang(indexT, 27);
    insert(indexT, 1, XFXL);
    
    //生年博士十二神 禄存起
    //阳男阴女顺行，阴男阳女逆行
    for (int k=0;k<12;k++) {
        if (shun)
            insert((index+k)%12, k, BSL);
        else
            insert((12+index-k)%12, k, BSL);
    }
}

//辰上顺月左辅 戌上逆月右弼
void getZuoYouStar()
{
    int nMonth= mon-1;
    int indexF = (nMonth+2)%12;
    insertWang(indexF, 20);
    insert(indexF, 2, JFXL);
    

    int indexB = (12-nMonth+8)%12;
    insertWang(indexB, 19);
    insert(indexB, 3, JFXL);
    
    //三台八座  三台顺左辅初一 八座逆右弼初一
    insert((indexF+(day-1)%12)%12, 6, ZAXL);
    insert((indexB+(13-day)%12)%12, 7, ZAXL);
}

//甲戊兼牛羊,乙己鼠猴乡。 
//丙丁猪鸡位,壬癸兔蛇藏。 
//庚辛逢马虎,魁钺贵人方。
void getKuiYueStar()
{
    int indexK = -1;
    int indexY = -1;
    switch(nTianGan){
        case 0:
        case 4:
            indexK = 11;
            indexY = 5;
        break;
        case 1:
        case 5:
            indexK = 10;
            indexY = 6;
        break;
        case 2:
        case 3:
            indexK = 9;
            indexY = 7;
        break;
        case 10:
        case 11:
            indexK = 1;
            indexY = 3;
        break;
        case 6:
        case 7:
            indexK = 4;
            indexY = 0;
        break;
    }
    if(indexK!=-1){
        insertWang(indexK, 22);
        insert(indexK, 4, JFXL);    //天魁
    }
    if(indexY != -1){
        insertWang(indexY, 21);
        insert(indexY, 5, JFXL);    //天越
    }
}

//安火星：寅午戌年丑宫起，申子辰年寅宫始，巳酉丑年在卯宫，亥卯未年酉宫起，
//        从起始宫起子时，顺数至生时止，所在宫即是。
//安铃星：寅午戌年卯宫起子时，申子辰、巳酉丑、亥卯未年均从戌宫起子时，
//        顺数至生时止，所在宫即是。
void getHuoLingStar()
{
    int indexH = -1;
    int indexL = -1;
    switch(nDiZhi){
        case 2:
        case 6:
        case 10:
            indexH = (11+hour)%12;
            indexL = (1+hour)%12;
        break;
        case 8:
        case 0:
        case 4:
            indexH = hour;
        break;
        case 5:
        case 9:
        case 1:
            indexH = (1+hour)%12;
        break;
        case 11:
        case 3:
        case 7:
            indexH = (7+hour)%12;
        break;
    }

    //"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥"
    if (nDiZhi !=2 && nDiZhi != 6 && nDiZhi!=10){
        indexL = (8+hour)%12;
    }

    if(indexH != -1){
        insertWang(indexH, 26);
        insert(indexH, 2, XFXL);//火星
    }
    if(indexL != -1){
        insertWang(indexL, 25);
        insert(indexL, 3, XFXL);//铃星
    }
}

//地空地劫 亥宫起子时，逆地空，顺地劫
void getKongJieStar() {
    int indexK = (12-hour+9)%12;    //地空
    insertWang(indexK, 24);
    insert(indexK, 5, XFXL);
   
    int indexJ = (hour+9)%12;   //地劫
    insertWang(indexJ, 23);
    insert(indexJ, 4, XFXL);
}

//驿马 寅午戌马在申，申子辰马在寅，亥卯未马在巳，巳酉丑马在亥
//天马 排法尚未定论
//天马者,正月起午顺行六阳辰
void getTianMaStar() {
    int index = -1;
    switch(nDiZhi){
        case 2:
        case 6:
        case 10:
            index = 8;
            break;
        case 8:
        case 0:
        case 4:
            index = 2;
            break;
        case 11:
        case 3:
        case 7:
            index = 5;
            break;
        case 5:
        case 9:
        case 1:
            index = 11;
            break;
    }
    index -= 2;
    insertWang(index, 1);
    insert(index, 6, JFXL);
}

//天姚丑上顺正月 天刑酉上顺正月
void getXingYaoStar()
{
    int indexY = (11+mon-1)%12;
    int indexX = (7+mon-1)%12;

    insert(indexY, 7, XFXL);
    insert(indexX, 6, XFXL);
}

//甲起羊鸡乙龙猴 丙年鼠蛇一窝谋 丁虎擒猪戊玉兔
//己鸡居然与虎倚 庚豬馬辛雞蛇走 壬犬馬癸马蛇游
void getTianGuanTianFuStar()
{
    int indexG = -1;
    int indexF = -1;
    switch (nTianGan) {
        case 0:
            indexG = 5;
            indexF = 7;
            break;
        case 1:
            indexG = 2;
            indexF = 6;
            break;
        case 2:
            indexG = 3;
            indexF = 10;
            break;
        case 3:
            indexG = 0;
            indexF = 9;
            break;
        case 4:
            indexG = 1;
            indexF = 1;
            break;
        case 5:
            indexG = 7;
            indexF = 0;
            break;
        case 6:
            indexG = 9;
            indexF = 4;
            break;
        case 7:
            indexG = 7;
            indexF = 3;
            break;
        case 8:
            indexG = 8;
            indexF = 4;
            break;
        case 9:
            indexG = 4;
            indexF = 3;
            break;
    }
    
    insert(indexG, 8, JFXL);
    insert(indexF, 9, JFXL);
}

//台辅午上顺子时 封诰寅上顺子时
void getTaiFengStar()
{
    insert((hour+4)%12, 0, ZAXL);
    insert(hour, 1, ZAXL);
}

//申宫顺上正月 单月见神 双月返单
void getJieShenStar()
{
    int i = 0;
    int nMonth = mon;
    for (i=0;i<7;i++)
    {
        if (nMonth==2*i)
        {
            nMonth -= 1;
            break;
        }
    }
    
    insert((nMonth+5)%12, 2, ZAXL);//解神
}

//天巫 月系巳申寅亥
void getTianWuStar()
{
    int index = -1;
    switch (mon) {
        case 1:
        case 5:
        case 9:
            index = 3;
            break;
        case 2:
        case 6:
        case 10:
            index = 6;
            break;
        case 3:
        case 7:
        case 11:
            index = 0;
            break;
        case 4:
        case 8:
        case 12:
            index = 9;
            break;
    }
    
    insert(index, 3, ZAXL);
}

//正月起 戌巳辰寅未卯亥未寅午戌寅。（无规律）
void getTianYueStar()
{
    int index = -1;
    switch (mon) {
        case 1:
        case 11:
            index = 8;
            break;
        case 2:
            index = 3;
            break;
        case 3:
            index = 2;
            break;
        case 4:
        case 9:
        case 12:
            index = 0;
            break;
        case 5:
        case 8:
            index = 5;
            break;
        case 6:
            index = 1;
            break;
        case 7:
            index = 9;
            break;
    }
    
    insert(index, 4, ZAXL);
}

//阴煞 寅子戌申午辰 寅子戌申午辰
void getYinShaStar()
{
    insert((24-mon*2+2)%12, 5, ZAXL);
}

//辰上顺年支龙池 戌上逆年支凤阁
void getLongFengStar()
{
    insert((nDiZhi+2)%12, 10, ZAXL);
    insert((12-nDiZhi+8)%12, 11, ZAXL);
}

//天空 丑宫起子年地支
void getKongStar()
{
    insert((12+nDiZhi-1)%12, 12, ZAXL);//天空
    
    int nGong1 = -1, nGong2=-1;
    int tianGan = nTianGan+1;
    if (tianGan==1 || tianGan==6)
    {
        nGong1=6;
        nGong2=nGong1+1;
    }
    else if (tianGan==2 || tianGan==7)
    {
        nGong1=4;
        nGong2=nGong1+1;
    }
    else if (tianGan==3 || tianGan==8)
    {
        nGong1=2;
        nGong2=nGong1+1;
    }
    else if (tianGan==4 || tianGan==9)
    {
        nGong1=1;
        nGong2=nGong1-1;
    }
    else if (tianGan==5 || tianGan==10)
    {
        nGong1=10;
        nGong2=nGong1-1;
    }
    
    if (year%2==0){ //阳者用阳
        insert(nGong1, 13, ZAXL);   //截空
    } else
        insert(nGong2, 13, ZAXL);
}

//孤辰：寅卯辰年生人在巳，巳午未年在申，申酉戌年在亥，亥子丑年在寅。(四马宫)
//寡宿：寅卯辰年生人在丑，巳午未年在辰，申酉戌年在未，亥子丑年在戌。(四墓宫)
void getGuGuaStar()
{
    int nGong_Gu=-1;
    int nGong_Gua=-1;
    
    switch (nDiZhi) {
        case 2:
        case 3:
        case 4:
            nGong_Gu = 3;
            nGong_Gua = 11;
            break;
        case 5:
        case 6:
        case 7:
            nGong_Gu = 6;
            nGong_Gua = 2;
            break;

        case 8:
        case 9:
        case 10:
            nGong_Gu = 9;
            nGong_Gua = 5;
            break;

        case 11:
        case 0:
        case 1:
            nGong_Gu = 0;
            nGong_Gua = 8;
            break;
    }
    
    insert(nGong_Gu, 14, ZAXL);
    insert(nGong_Gua, 15, ZAXL);
}

//天哭午宫起子年顺 天虚午宫起子年逆
void getKuXuStar()
{
    insert((nDiZhi+4)%12, 16, ZAXL);
    insert((12-nDiZhi+4)%12, 17, ZAXL);
}

void getLuanXiStar()
{
    insert((12-nDiZhi+1)%12, 18, ZAXL);
    insert((12-nDiZhi+7)%12, 19, ZAXL);
}

//蜚廉 破碎
void getFeiLianStar()
{
    int nGong = -1;
    if (nDiZhi==0){
        nGong = 6;
    } else if (nDiZhi==1){nGong = 7;}
    else if (nDiZhi==2){nGong = 8;}
    else if (nDiZhi==3){nGong = 3;}
    else if (nDiZhi==4){nGong = 4;}
    else if (nDiZhi==5){nGong = 5;}
    else if (nDiZhi==6){nGong = 0;}
    else if (nDiZhi==7){nGong = 1;}
    else if (nDiZhi==8){nGong = 2;}
    else if (nDiZhi==9){nGong = 9;}
    else if (nDiZhi==10){nGong = 10;}
    else if (nDiZhi==11){nGong = 11;}
    
    insert(nGong, 20, ZAXL);
    
    if (nDiZhi==0 || nDiZhi==3 || nDiZhi==6 || nDiZhi==9)
    {nGong = 3;}
    else if (nDiZhi==1 || nDiZhi==4 || nDiZhi==7 || nDiZhi==10)
    {nGong = 11;}
    else if (nDiZhi==2 || nDiZhi==5 || nDiZhi==8 || nDiZhi==12)
    {nGong = 7;}
    
    insert(nGong, 21, ZAXL);
}

//.天才 命宫起子年 顺年支
//.天寿 身宫起子年 顺年支
void getTiancaiTianshouStar()
{
    int i = 0;
    for (i=0; i<12; i++) {
        if(!mingGong[i].gongIndex){
            insert((12+i+nDiZhi)%12, 22, ZAXL);
            break;
        }
    }
    
    //天寿
    for (i=0; i<12; i++) {
        if(mingGong[i].gongIndex == ziWei.shenGongIndex)
            if(ziWei.shenGongIndex==0 || ziWei.shenGongIndex==8 || ziWei.shenGongIndex==6 || ziWei.shenGongIndex==4 || ziWei.shenGongIndex==10 || ziWei.shenGongIndex==2){
                insert((12+i+nDiZhi)%12, 23, ZAXL);
                break;
            }
    }
}

//天厨
void getTianChuStar()
{
    int nGong = 0;
    if (nTianGan == 0 || nTianGan == 3)
    {nGong=3;}
    if (nTianGan == 1 || nTianGan == 4 || nTianGan == 7)
    {nGong=4;}
    if (nTianGan == 5)
    {nGong=6;}
    if (nTianGan == 8)
    {nGong=7;}
    if (nTianGan == 9)
    {nGong=9;}
    if (nTianGan == 2)
    {nGong=10;}
    if (nTianGan == 6)
    {nGong=0;}
    
    insert(nGong, 24, ZAXL);
}


//天伤在仆役宫 天使疾厄宫
void getTianshangTianshiStar()
{
    int i = 0;
    for(i=0; i<12; i++){
        if(mingGong[i].gongIndex == 5){
            insert(i, 25, ZAXL);
            break;
        }
    }
    
    for(i=0; i<12; i++){
        if(mingGong[i].gongIndex == 7){
            insert(i, 26, ZAXL);
        }
    }
}

//太岁十二神煞 丧门子年顺
void get12TaiSui() {
    for (int i=0;i<12;i++) {
        insert((nDiZhi+i)%12, i, TSL);
    }
}

//寅午戌年將星午，申子辰年子將星，
//巳酉丑將酉上駐，亥卯未將卯上停。
void get12Jiang()//将前
{
    int nGong=0;
    if (nDiZhi==0 || nDiZhi==4 || nDiZhi==8)
    {nGong=10;}
    else if (nDiZhi==1 || nDiZhi==5 || nDiZhi==9)
    {nGong=7;}
    else if (nDiZhi==2 || nDiZhi==6 || nDiZhi==10)
    {nGong=4;}
    else if (nDiZhi==3 || nDiZhi==7 || nDiZhi==11)
    {nGong=1;}
    
    for (int i=0;i<12;i++) {
        insert((nGong+i)%12, i, JQL);
    }
}

//庙旺平闲陷  从1开始
void getMiaoXian()
{
    int i = 0, j=0;
    for (i=0; i<12; i++) {
        int len = mingGong[i].xyCout;
        for (j=0; j<len; j++) {
            enum xingLevel level = mingGong[i].xy[j].level;
            if(level!=ZXL && level!=JFXL && level!=XFXL)
                continue;
            
            int w = mingGong[i].xy[j].wang-1;
            if(w >= 0) {
                int dizhi = mingGong[i].dz-2;
                if(dizhi<0)
                    dizhi += 12;
                mingGong[i].xy[j].wang = miaoWangStarInfo[dizhi][w]+1;
            }
        }
    }
}

//命主 命宫地支
//身主 生年地支
void getMingzhuShenzhu()
{
    int i = 0;
    for (i=0; i<12; i++) {
        if(mingGong[i].gongIndex == 0){
            ziWei.mingZhuIndex = (i+2)%12;
        }
    }
    
    ziWei.shenZhuIndex = nDiZhi;
}

//子年斗君 逆数生月 顺数生时
int getDouJun() {
    return (13+hour-mon)%12;
}

//八字
//void get8zi()
//{
//    //年干支
//    str_Year=m_TianGan+m_DiZhi;
//    
//    //月干支
//    const char *cListMonth[12][5] =
//    {
//        //甲己	 乙庚	丙辛   丁壬	  戊癸
//        {"丙寅","戊寅","庚寅","壬寅","甲寅"},
//        {"丁卯","己卯","辛卯","癸卯","乙卯"},
//        {"戊辰","庚辰","壬辰","甲辰","丙辰"},
//        {"己巳","辛巳","癸巳","乙巳","丁巳"},
//        {"庚午","壬午","甲午","丙午","戊午"},
//        {"辛未","癸未","乙未","丁未","己未"},
//        {"壬申","甲申","丙申","戊申","庚申"},
//        {"癸酉","乙酉","丁酉","己酉","辛酉"},
//        {"甲戌","丙戌","戊戌","庚戌","壬戌"},
//        {"乙亥","丁亥","己亥","辛亥","癸亥"},
//        {"丙子","戊子","庚子","壬子","甲子"},
//        {"丁丑","己丑","辛丑","癸丑","乙丑"}
//    };
//    
//    int nMonth = CGlobal::nFeastMonth;	//二十四节气定年月支
//    if (m_wMonth=="12")
//    {
//        if (CGlobal::nFeastMonth==13)//当日在立春后
//        {
//            nMonth=1;
//            for (int nTG=0;nTG<10;nTG++)
//            {
//                const char *cTianGan[] = {"甲","乙","丙","丁","戊","己","庚","辛","壬","癸"};
//                if (m_TianGan==cTianGan[nTG])
//                {m_TianGan=cTianGan[(nTG+1)%10];break;}
//            }
//            for (int nDZ=0;nDZ<12;nDZ++)
//            {
//                const char *cDiZhi[] = {"子","丑","寅","卯","辰","巳","午",	"未","申","酉","戌","亥"};
//                if (m_DiZhi==cDiZhi[nDZ])
//                {m_DiZhi=cDiZhi[(nDZ+1)%12];break;}
//            }
//            nTianGan=(nTianGan+1)%5;
//            str_Year=m_TianGan+m_DiZhi;
//        }
//        if (CGlobal::nFeastMonth==14) //当日在立春前
//        {
//            nMonth=12;
//        }
//    }
//    
//    if (m_wMonth=="1"|| m_wMonth=="2")
//    {
//        if (CGlobal::nFeastMonth==14 ) //当日在立春前
//        {
//            nMonth=12;
//            for (int nTG=0;nTG<10;nTG++)
//            {
//                const char *cTianGan[] = {"甲","乙","丙","丁","戊","己","庚","辛","壬","癸"};
//                if (m_TianGan==cTianGan[nTG])
//                {m_TianGan=cTianGan[(nTG-1)%10];break;}
//            }
//            for (int nDZ=0;nDZ<12;nDZ++)
//            {
//                const char *cDiZhi[] = {"子","丑","寅","卯","辰","巳","午",	"未","申","酉","戌","亥"};
//                if (m_DiZhi==cDiZhi[nDZ])
//                {m_DiZhi=cDiZhi[(nDZ-1)%12];break;}
//            }
//            nTianGan=(nTianGan-1)%5;
//            str_Year=m_TianGan+m_DiZhi;
//        }
//        if (CGlobal::nFeastMonth==13) //当日在立春后
//        {
//            nMonth=1;
//        }
//    }
//    
//    if (nTianGan>=5)
//    {
//        nTianGan = nTianGan-5;
//    }
//    
//    CString str_Month;
//    str_Month=cListMonth[nMonth-1][nTianGan];
//    
//    
//    //日干支
//    //1.求元旦干支 以阳历日期来求
//    CString str_GongYuanYear;
//    str_GongYuanYear=CGlobal::strYangLi_global.Left(4);
//    //公元纪年的最后两位
//    int nGongYuanYear=atoi(str_GongYuanYear.Right(2));
//    if (nGongYuanYear==0){nGongYuanYear=100;} //百年逢百
//    //求nA
//    int nA=(nGongYuanYear%12)*5;
//    //求nB
//    int nB=int(nGongYuanYear/4);
//    if (nGongYuanYear%4 != 0) //不能除尽 加1
//    {nB=nB+1;}
//    int nYuanDanGanZhi=nA+nB;
//    //2.查表 以cListMonth排列
//    //1901～2000年间以甲戌作1向后推某年C的值，既是该年元旦的干支﹙2001～2100年间以己未作1﹚
//    int nX=0;
//    int nY=0;
//    int nGongYuan=atoi(str_GongYuanYear);
//    //己未开始
//    nX=int(nYuanDanGanZhi/12)%5;
//    nY=nYuanDanGanZhi%12;
//    if (nGongYuan>2000)
//    {
//        //己未移位 x+5 y+5
//        nX=(nX+4)%5;
//        if (nY+5>12)
//        {
//            nX=(nX+1)%5;
//        }
//        nY=(nY+4)%12;
//        
//    }
//    if (nGongYuan<=2000)
//    {
//        if (nY+8>12)
//        {
//            nX=(nX+1)%5;
//        }
//        nY=(nY+7)%12;
//    }
//    CString str_YuanDanDay;
//    str_YuanDanDay=cListMonth[nY][nX];
//    //3.求当日干支
//    const char *cTianGan[] = {"甲","乙","丙","丁","戊","己","庚","辛","壬","癸"};
//    const char *cDiZhi[] = {"子","丑","寅","卯","辰","巳","午",	"未","申","酉","戌","亥"};
//    int nDayGan,nDayZhi;
//    for (int n=0;n<10;n++)
//    {
//        if (str_YuanDanDay.Left(2)==cTianGan[n])
//        {nDayGan=n;break;}
//    }
//    for (int k=0;k<12;k++)
//    {
//        if (str_YuanDanDay.Right(2)==cDiZhi[k])
//        {nDayZhi=k;break;}
//    }
//    //套公式
//    int nGongYuanDay=m_nYangLiDay;
//    int nGongYuanMonth=m_nYangLiMonth;
//    //诗诀
//    // 一月干支均减１    二月干加０支加６   三月干减二支加10
//    // 四月干减１支加５  五月干支均减１     六月干加０支加６
//    // 七月干支均加０    八月干加１支加７   九月干支均加２
//    // 十月干加２支加８  十一月干支均加３ 　十二月干加３支加９
//    int nGanRun=0;
//    int nZhiRun=0;
//    if (nGongYuanMonth==1)
//    {
//        nGanRun=nGanRun-1;
//        nZhiRun=nZhiRun-1;
//    }
//    if (nGongYuanMonth==2)
//    {
//        nZhiRun=nZhiRun+6;
//    }
//    if (nGongYuanMonth==3)
//    {
//        nGanRun=nGanRun-2;
//        nZhiRun=nZhiRun+10;
//    }
//    if (nGongYuanMonth==4)
//    {
//        nGanRun=nGanRun-1;
//        nZhiRun=nZhiRun+5;
//    }
//    if (nGongYuanMonth==5)
//    {
//        nGanRun=nGanRun-1;
//        nZhiRun=nZhiRun-1;
//    }
//    if (nGongYuanMonth==6)
//    {
//        nZhiRun=nZhiRun+6;
//    }
//    if (nGongYuanMonth==8)
//    {
//        nGanRun=nGanRun+1;
//        nZhiRun=nZhiRun+7;
//    }
//    if (nGongYuanMonth==9)
//    {
//        nGanRun=nGanRun+2;
//        nZhiRun=nZhiRun+2;
//    }
//    if (nGongYuanMonth==10)
//    {
//        nGanRun=nGanRun+2;
//        nZhiRun=nZhiRun+8;
//    }
//    if (nGongYuanMonth==11)
//    {
//        nGanRun=nGanRun+3;
//        nZhiRun=nZhiRun+3;
//    }
//    if (nGongYuanMonth==12)
//    {
//        nGanRun=nGanRun+3;
//        nZhiRun=nZhiRun+9;
//    }
//    int nRunYear=0; //四年一闰,百年不闰,四百年再闰
//    if ( (nGongYuan%400==0 || nGongYuan%100!=0) && (nGongYuan%4==0) )
//    {
//        if (nGongYuanMonth>2)
//        {nRunYear=nRunYear+1;}
//    }
//    //（nDayGan）+（nDay）+（所求月的天干加减数、闰年三月以后减1）÷10
//    int nTodayGan = (nDayGan + nGongYuanDay + nGanRun + nRunYear)%10;
//    // （所求年份的元旦地支）+（所求日期）+（所求月的地支加减数、闰年三月以后减1）÷12
//    int nTodayZhi = (nDayZhi + nGongYuanDay + nZhiRun + nRunYear)%12;
//    CString str_TodayGan = cTianGan[nTodayGan];
//    CString str_TodayZhi = cDiZhi[nTodayZhi];
//    CString str_Day = str_TodayGan + str_TodayZhi;
//    
//    //时干支
//    const char *cListTime[12][5] =
//    {
//        //甲己	 乙庚	丙辛   丁壬	  戊癸   日干
//        {"甲子","丙子","戊子","庚子","壬子"},
//        {"乙丑","丁丑","己丑","辛丑","癸丑"},
//        {"丙寅","戊寅","庚寅","壬寅","甲寅"},
//        {"丁卯","己卯","辛卯","癸卯","乙卯"},
//        {"戊辰","庚辰","壬辰","甲辰","丙辰"},
//        {"己巳","辛巳","癸巳","乙巳","丁巳"},
//        {"庚午","壬午","甲午","丙午","戊午"},
//        {"辛未","癸未","乙未","丁未","己未"},
//        {"壬申","甲申","丙申","戊申","庚申"},
//        {"癸酉","乙酉","丁酉","己酉","辛酉"},
//        {"甲戌","丙戌","戊戌","庚戌","壬戌"},
//        {"乙亥","丁亥","己亥","辛亥","癸亥"}
//    };
//    CString str_Time = cListTime[m_wHour][nTodayGan%5];
//    
//    //考刻分 时上起刻
//    m_wMinute = CGlobal::nFeng_global;
//    int nTimeGan;
//    for (int j=0;j<10;j++)
//    {
//        if (str_Time.Left(2)==cTianGan[j])
//        {nTimeGan=j;break;}
//    }
//    CString str_Minute = cListTime[m_wMinute][nTimeGan%5];
//    
//    //四柱 + 考时 十字
//    CString str_shizi;
//    str_shizi = str_Year + "  "+ str_Month + "  "+str_Day+"  "+str_Time+"  "+str_Minute;
//    SetDlgItemText(IDC_STATIC_SHIZI,str_shizi);
//}

//四化
void get4hua() {
    const char *cList4[] = {"[禄]","[权]","[科]","[忌]"};
    const char *cList4hua[12][4] = 
    {
        //禄     权      科     忌
        {"廉贞","破军","武曲","太阳"},   //甲
        {"天机","天梁","紫微","太阴"},   //乙
        {"天同","天机","文昌","廉贞"},   //丙
        {"太阴","天同","天机","巨门"},   //丁
        {"贪狼","太阴","右弼","天机"},   //戊
        {"武曲","贪狼","天梁","文曲"},   //己
        {"太阳","武曲","太阴","天同"},   //庚
        {"巨门","太阳","文曲","文昌"},   //辛
        {"天梁","紫微","左辅","武曲"},   //壬
        {"破军","巨门","太阴","贪狼"}    //癸  
    };
    
    int i = 0, j=0;
    for (i=0; i<12; i++) {
        int len = mingGong[i].xyCout;
        for (j=0; j<len; j++) {
            
            enum xingLevel level = mingGong[i].xy[j].level;
            
            if(level==ZXL || level==JFXL){
                int xingIndex = mingGong[i].xy[j].index;
                char *xingNameTmp = getXingName(level, xingIndex);
                for(int m=0;m<4;m++){
                    if(!strcmp(xingNameTmp, cList4hua[nTianGan][m])){
                        mingGong[i].xy[j].huaJi = m+1;
                    }
                }
            }
        }
    }
    
//    for (int n=0;n<4;n++)
//    {
//        str4hua += cList4hua[nTianGan][n];
//        str4hua += cList4[n];
//    }
//    SetDlgItemText(IDC_STATIC_4HUA,str4hua);
//    
//    const char *cList4s[] = {"禄","权","科","忌"};
//    CString str;
//    int nPos;
//    int nCir;
//    CString str_;
//    CString str4s="";
//    
//    for (int i=0;i<12*6;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            //i为圈 j为宫
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str);
//            for (int k=0;k<4;k++)
//            {
//                
//                if (str == cList4hua[nTianGan][k])
//                {
//                    nCir=i/12;
//                    nPos=j;
//                    
//                    //初始化挡号
//                    str_="";
//                    for (int m=0;m<nCir;m++)
//                    {
//                        CString str_IsFull;
//                        GetDlgItemText(IDC_STATIC_15ZW1+nPos,str_IsFull);
//                        if (str_IsFull=="")
//                        {
//                            str_ +="█";
//                        }
//                        else str_ = str_IsFull;
//                        
//                        if (nCir-str_IsFull.GetLength()/2==1)
//                        {							
//                            str_IsFull +="█";
//                            str_ = str_IsFull;
//                        }
//                        
//                        if (nCir-str_IsFull.GetLength()/2==2)
//                        {							
//                            str_IsFull +="██";
//                            str_ = str_IsFull;
//                        }
//                        
//                        if (nCir-str_IsFull.GetLength()/2==3)
//                        {							
//                            str_IsFull +="███";
//                            str_ = str_IsFull;
//                        }
//                    }
//                    
//                    str4s = str_ +cList4s[k];
//                    SetDlgItemText(IDC_STATIC_15ZW1+nPos,str4s);
//                    break;
//                }
//            }		
//        }
//        
//    }
    
}

void getZiWeiInfo(){
    getMingGong();
    getChangQuStar();
    getLuCunStar();
    getZuoYouStar();
    getKuiYueStar();
    getHuoLingStar();
    getKongJieStar();
    getTianMaStar();
    getXingYaoStar();
    getTianGuanTianFuStar();
    getTaiFengStar();
    getJieShenStar();
    getTianWuStar();
    getTianYueStar();
    getYinShaStar();
    getLongFengStar();
    getKongStar();
    getGuGuaStar();
    getKuXuStar();
    getLuanXiStar();
    getFeiLianStar();
    getTiancaiTianshouStar();
    getTianChuStar();
    getTianshangTianshiStar();
    get12TaiSui();
    get12Jiang();
    getMiaoXian();
    getMingzhuShenzhu();
    getDouJun();
    get4hua();
    
    printf("身主==>%s\n", cShenzhu[ziWei.shenZhuIndex]);
    printf("命主==>%s\n", cMingzhu[ziWei.mingZhuIndex]);
    printf("子年斗君==>%s\n", zhi[getDouJun()]);
    
    int i=0, j=0;
    for (i=0; i<12; i++) {
        printf("命宫==>%s\n", szGongName[mingGong[i].gongIndex]);
        printf("干支==>%s%s\n", gan[mingGong[i].tg], zhi[mingGong[i].dz]);
        printf("命年==>%s\n", mingGong[i].mingNian);
        
        for (j=0; j<mingGong[i].xyCout; j++) {
            printf("%s   ", getXingName(mingGong[i].xy[j].level, mingGong[i].xy[j].index));
            if(mingGong[i].xy[j].wang>0)
                printf("%s   ", miaoWangName[mingGong[i].xy[j].wang-1]);
            if(mingGong[i].xy[j].huaJi>0)
                printf("%s   ", huaJiName[mingGong[i].xy[j].huaJi-1]);
            printf("\n");
        }
        printf("cout==>%d\n", mingGong[i].xyCout);
        printf("\n-----------------------------------------------------\n");
    }
}
