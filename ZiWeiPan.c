////
////  ZiWeiPan.c
////  BaZi
////
////  Created by ms on 2017/6/21.
////  Copyright © 2017年 ms. All rights reserved.
////
//
//#include "ZiWeiPan.h"
//
//static int year = 2017;
//static int mon = 5;
//static int day = 26;
//static int hour = 6;
//static int min = 0;
//static int sec = 0;
//static int tg = 3;
//static int sex = 1;//1 男
//static int i=0;
//
//typedef struct _xingYao{
//    int index;
//    int level;
//    int wang;
//}xingYao;
//
//typedef struct _gong{
//    xingYao xy[15];
//    int xyCout;
//    int tg;
//    int dz;
//    int nian;
//    int gongIndex;
//}gong;
//
//gong mingGong[12];
//int shenGong;
//
//void SetMingGong()
//{
//    //命宫位置 寅宫开始 顺数月 逆数时
//    int nMing;
//    nMing=mon-hour;
//    
//    //十二宫名称数组
//    char szGongName[][7] =
//    {
//        "本命宫", "父母宫", "福德宫", "田宅宫", "官禄宫", "仆役宫",
//        "迁移宫", "疾厄宫", "财帛宫", "子女宫", "夫妻宫", "兄弟宫"
//    };
//    
//    //命宫的位置 12宫定位
////    m_gong1.SetWindowText(szGongName[(12-nMing+1)%12]);
////    m_gong2.SetWindowText(szGongName[(12-nMing+2)%12]);
////    m_gong3.SetWindowText(szGongName[(12-nMing+3)%12]);
////    m_gong4.SetWindowText(szGongName[(12-nMing+4)%12]);
////    m_gong5.SetWindowText(szGongName[(12-nMing+5)%12]);
////    m_gong6.SetWindowText(szGongName[(12-nMing+6)%12]);
////    m_gong7.SetWindowText(szGongName[(12-nMing+7)%12]);
////    m_gong8.SetWindowText(szGongName[(12-nMing+8)%12]);
////    m_gong9.SetWindowText(szGongName[(12-nMing+9)%12]);
////    m_gong10.SetWindowText(szGongName[(12-nMing+10)%12]);
////    m_gong11.SetWindowText(szGongName[(12-nMing+11)%12]);
////    m_gong12.SetWindowText(szGongName[(12-nMing+12)%12]);
//    for(i=0;i<12;i++){
//        mingGong[i].gongIndex = (12-nMing+i+1)%12;
//    }
//    
//    //身宫 寅宫开始 顺数月 顺数时
//    int nShen;
//    nShen = mon+hour;
//    shenGong = (23+nShen)%12;
//    
////    GetDlgItemText(IDC_STATIC_GONG1+(23+nShen)%12,sBuf,3);
////    CString str;
////    str.Format(_T("%s"),sBuf);
////    if (str == "本")
////    {
////        SetDlgItemText(IDC_STATIC_GONG1+,"命★身");
////    }
////    else SetDlgItemText(IDC_STATIC_GONG1+(23+nShen)%12,str+"★身");
//    
//}
//
////BOOL CZiWei::OnInitDialog()
////{
////    CDialog::OnInitDialog();
////    // TODO: Add extra initialization here
////    
////    
////    //初始化
////    for (int ni=0;ni<12;ni++)
////    {
////        SetDlgItemText(IDC_STATIC_15ZW1+ni,"");
////        SetDlgItemText(IDC_STATIC_MX1+ni,"");
////    }
////    
////    SetMingGong();
////    SetGongTianGan();
////    SetMingJu();
////    SetZiWeiStar();
////    Set12ChangSheng();
////    SetChangQuStar();
////    SetZuoYouStar();
////    SetLuCunStar();
////    SetKuiYueStar();
////    SetHuoLingStar();
////    SetYangTuoStar();
////    SetKongJieStar();
////    SetTianMaStar();
////    SetXingYaoStar();
////    SetTianGuanTianFuStar();
////    SetTaiFengStar();
////    SetJieShenStar();
////    SetTianWuStar();
////    SetTianYueStar();
////    SetYinShaStar();
////    SetTaiZuoStar();
////    SetEnGuiStar();
////    SetLongFengStar();
////    SetKongStar();
////    SetLuanXiStar();
////    SetKuXuStar();
////    SetGuGuaStar();
////    SetFeiLianStar();
////    SetTiancaiTianshouStar();
////    SetTianChuStar();
////    SetTianshangTianshiStar();
////    Set12BoShi();
////    Set12TaiSui();
////    Set12Jiang();
////    SetMiaoXian();
////    SetMingzhuShenzhu();
////    SetDouJun();
////    Set8zi();
////    Set4hua();
////    return TRUE;  // return TRUE unless you set the focus to a control
////    // EXCEPTION: OCX Property Pages should return FALSE
////}
//
////void CZiWei::SetMingGongColor(CDC* pDC, CWnd* pWnd)
////{
////    CString str;
////    pWnd->GetWindowText(str);
////    if (str=="本命宫" || str=="财帛宫" || str=="迁移宫" || str=="官禄宫"
////        || str=="命★身" || str=="财★身" || str=="迁★身" || str=="官★身")
////    {
////        pDC->SetBkMode(BKMODE_LAST);
////        pDC->SetBkColor(RGB(255,255,0));
////    }
////}
//
//void setGongTianGan()
//{
//    const char *cTianGan[] = {"甲","乙","丙","丁","戊","己","庚","辛","壬","癸"};
//    int nTianGan = ((year - 4) % 60) % 10;
//    if ( nTianGan < 0 || nTianGan >= 10 )
//        return ;
//    CString str_TianGan;
//    str_TianGan.Format(_T("%s"),cTianGan[nTianGan]);
//    
//    //甲己之岁起丙寅
//    if (str_TianGan == "甲" || str_TianGan == "己")
//    {
//        //	SetDlgItemText(IDC_STATIC_TG1,"丙");
//        for (int i=0;i<12;i++)
//        {
//            SetDlgItemText(IDC_STATIC_TG1+i,cTianGan[(10+2+i)%10]);
//        }
//    }
//    
//    //乙庚之岁起戊寅
//    if (str_TianGan == "乙" || str_TianGan == "庚")
//    {
//        for (int i=0;i<12;i++)
//        {
//            SetDlgItemText(IDC_STATIC_TG1+i,cTianGan[(10+4+i)%10]);
//        }
//    }
//    
//    //丙辛之岁起庚寅
//    if (str_TianGan == "丙" || str_TianGan == "辛")
//    {
//        for (int i=0;i<12;i++)
//        {
//            SetDlgItemText(IDC_STATIC_TG1+i,cTianGan[(10+6+i)%10]);
//        }
//    }
//    
//    //丁壬之岁起壬寅
//    if (str_TianGan == "丁" || str_TianGan == "壬")
//    {
//        for (int i=0;i<12;i++)
//        {
//            SetDlgItemText(IDC_STATIC_TG1+i,cTianGan[(10+8+i)%10]);
//        }
//    }
//    
//    //戊癸之岁起甲寅
//    if (str_TianGan == "戊" || str_TianGan == "癸")
//    {
//        for (int i=0;i<12;i++)
//        {
//            SetDlgItemText(IDC_STATIC_TG1+i,cTianGan[(10+i)%10]);
//        }
//    }
//    
//    //获得生年干
//    m_TianGan = str_TianGan;
//}
//
//void CZiWei::SetMingJu()
//{
//    CString str_TG;
//    for (int i=0;i<12;i++)
//    {
//        CString str_Gong;
//        GetDlgItemText(IDC_STATIC_GONG1+i,str_Gong);
//        if (str_Gong == "命★身" || str_Gong == "本命宫")
//        {
//            GetDlgItemText(IDC_STATIC_TG1+i,str_TG);
//            break;
//        }
//    }
//    
//    //甲乙1，丙丁2，戊己3，庚辛4，壬癸5
//    //子丑午未1，寅卯申酉2，辰巳戌亥3
//    //1木三局，2金四局，3水二局，4火六局，5土五局。
//    if (str_TG == "甲" || str_TG == "乙")
//    {
//        if (i==4 || i ==5 || i==10 ||i==11) //子丑午未
//        {
//            m_mingju.SetWindowText("金四局");
//            //金四局
//        }
//        if (i==0 || i ==1 || i==6 ||i==7) //寅卯申酉
//        {
//            m_mingju.SetWindowText("水二局");
//            //水二局
//        }
//        if (i==2 || i ==3 || i==8 ||i==9) //辰巳戌亥
//        {
//            m_mingju.SetWindowText("火六局");
//            //火六局
//        }
//    }
//    
//    if (str_TG == "丙" || str_TG == "丁")
//    {
//        if (i==4 || i ==5 || i==10 ||i==11) //子丑午未
//        {
//            m_mingju.SetWindowText("水二局");
//            //水二局
//        }
//        if (i==0 || i ==1 || i==6 ||i==7) //寅卯申酉
//        {
//            m_mingju.SetWindowText("火六局");
//            //火六局
//        }
//        if (i==2 || i ==3 || i==8 ||i==9) //辰巳戌亥
//        {
//            m_mingju.SetWindowText("土五局");
//            //土五局
//        }
//    }
//    
//    if (str_TG == "戊" || str_TG == "己")
//    {
//        if (i==4 || i ==5 || i==10 ||i==11) //子丑午未
//        {
//            m_mingju.SetWindowText("火六局");
//            //火六局
//        }
//        if (i==0 || i ==1 || i==6 ||i==7) //寅卯申酉
//        {
//            m_mingju.SetWindowText("土五局");
//            //土五局
//        }
//        if (i==2 || i ==3 || i==8 ||i==9) //辰巳戌亥
//        {
//            m_mingju.SetWindowText("木三局");
//            //木三局
//        }
//    }
//    
//    if (str_TG == "庚" || str_TG == "辛")
//    {
//        if (i==4 || i ==5 || i==10 ||i==11) //子丑午未
//        {
//            m_mingju.SetWindowText("土五局");
//            //土五局
//        }
//        if (i==0 || i ==1 || i==6 ||i==7) //寅卯申酉
//        {
//            m_mingju.SetWindowText("木三局");
//            //木三局
//        }
//        if (i==2 || i ==3 || i==8 ||i==9) //辰巳戌亥
//        {
//            m_mingju.SetWindowText("金四局");
//            //金四局
//        }
//    }
//    
//    if (str_TG == "壬" || str_TG == "癸")
//    {
//        if (i==4 || i ==5 || i==10 ||i==11) //子丑午未
//        {
//            m_mingju.SetWindowText("木三局");
//            //木三局
//        }
//        if (i==0 || i ==1 || i==6 ||i==7) //寅卯申酉
//        {
//            m_mingju.SetWindowText("金四局");
//            //金四局
//        }
//        if (i==2 || i ==3 || i==8 ||i==9) //辰巳戌亥
//        {
//            m_mingju.SetWindowText("水二局");
//            //水二局
//        }
//    }
//    
//    const char *cShui2[] = {"2-11","12-21","22-31","32-41","42-51","52-61","62-71","72-81","82-91","92-101","102-111","112-121"};
//    const char *cMu3[]   = {"3-12","13-22","23-32","33-42","43-52","53-62","63-72","73-82","83-92","93-102","103-112","113-122"};
//    const char *cJin4[]  = {"4-13","14-23","24-33","34-43","44-53","54-63","64-73","74-83","84-93","94-103","104-113","114-123"};
//    const char *cTu5[]   = {"5-14","15-24","25-34","35-44","45-54","55-64","65-74","75-84","85-94","95-104","105-114","115-124"};
//    const char *cHuo6[]  = {"6-15","16-25","26-35","36-45","46-55","56-65","66-75","76-85","86-95","96-105","106-115","116-125"};
//    
//    CString str_mingju;
//    m_mingju.GetWindowText(str_mingju);
//    if (str_mingju == "水二局")
//    {
//        for (int j=0;j<12;j++)
//        {
//            //阳男阴女的大限是顺时而转
//            //阴男阳女的大限 逆
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_MINGJU1+j,cShui2[(12+j-i)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_MINGJU1+j,cShui2[(12+i-j)%12]);
//        }
//    }
//    
//    if (str_mingju == "木三局")
//    {
//        for (int j=0;j<12;j++)
//        {
//            //阳男阴女的大限是顺时而转
//            //阴男阳女的大限 逆
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_MINGJU1+j,cMu3[(12+j-i)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_MINGJU1+j,cMu3[(12+i-j)%12]);
//        }
//    }
//    
//    if (str_mingju == "金四局")
//    {
//        for (int j=0;j<12;j++)
//        {
//            //阳男阴女的大限是顺时而转
//            //阴男阳女的大限 逆
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_MINGJU1+j,cJin4[(12+j-i)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_MINGJU1+j,cJin4[(12+i-j)%12]);
//        }
//    }
//    
//    if (str_mingju == "土五局")
//    {
//        for (int j=0;j<12;j++)
//        {
//            //阳男阴女的大限是顺时而转
//            //阴男阳女的大限 逆
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_MINGJU1+j,cTu5[(12+j-i)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_MINGJU1+j,cTu5[(12+i-j)%12]);
//        }
//    }
//    
//    if (str_mingju == "火六局")
//    {
//        for (int j=0;j<12;j++)
//        {
//            //阳男阴女的大限是顺时而转
//            //阴男阳女的大限 逆
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_MINGJU1+j,cHuo6[(12+j-i)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_MINGJU1+j,cHuo6[(12+i-j)%12]);
//        }
//    }
//}
//
////紫微星速求公式如下，设农历出生日数为A，五行局数为B。
////第一步：公式(A+X)÷B = C ，C为所得商数,刚好能除尽时,“最小的数”就是X
////第二步：当X为偶数时用公式D=C+X，求出紫微星所在宫位数D
////        当X为奇数时用公式D=C-X,出现负数时要加上12
////第三步：把D转换成紫微星所在宫位，D的宫位数与月支宫位数完全一样，
////        即寅1，卯2，辰3，巳4，午5，未6，申7，酉8，戌9，亥10，子11，丑12
//void CZiWei::SetZiWeiStar()
//{
//    int a=atoi(m_wDay);
//    int b=GetMingJu();
//    
//    char m[30];
//    sprintf(m, "%d  %d", b, a);
//    MessageBox(m);
//    
//    int x=0;
//    for (int i=0;i<10;i++)
//    {
//        if ((a+i)%b==0)
//        {
//            x=i;
//            break;
//        }
//    }
//    int c=(a+x)/b;
//    int nZiWei=1;
//    if (x==0 || x%2==0)
//    {
//        nZiWei=c+x;
//        nZiWei=nZiWei%12;
//    }
//    else nZiWei=(12+c-x)%12;
//    
//    memset(m, '\0', 30);
//    sprintf(m, "%d", nZiWei);
//    MessageBox(m);
//    
//    //紫微天机逆行旁，隔一阳武天同当，又隔二位廉贞地，空三复见紫微郞。
//    SetDlgItemText((11+nZiWei)%12+IDC_STATIC_ZW1,"紫微");
//    SetDlgItemText((11+nZiWei-1)%12+IDC_STATIC_ZW1,"天机");
//    SetDlgItemText((11+nZiWei-3)%12+IDC_STATIC_ZW1,"太阳");
//    SetDlgItemText((11+nZiWei-4)%12+IDC_STATIC_ZW1,"武曲");
//    SetDlgItemText((11+nZiWei-5)%12+IDC_STATIC_ZW1,"天同");
//    SetDlgItemText((11+nZiWei-8)%12+IDC_STATIC_ZW1,"廉贞");
//    //天府宫位
//    CString str;
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei)%12,"天府");
//    }
//    else  SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei)%12,"天府");
//    
//    //nZiWei与寅1，卯2...对应
//    if (nZiWei ==1 || nZiWei==7)
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+nZiWei-1,"紫微");
//        SetDlgItemText(IDC_STATIC_2ZIWEI1+nZiWei-1,"天府");
//    }
//    //天府太阴与贪狼，巨门天相及天梁，七杀空三破军位
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+1)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+1)%12,"太阴");
//    }
//    else SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei+1)%12,"太阴");
//    
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+2)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+2)%12,"贪狼");
//    }
//    else SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei+2)%12,"贪狼");
//    
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+3)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+3)%12,"巨门");
//    }
//    else SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei+3)%12,"巨门");
//    
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+4)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+4)%12,"天相");
//    }
//    else SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei+4)%12,"天相");
//    
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+5)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+5)%12,"天梁");
//    }
//    else SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei+5)%12,"天梁");
//    
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+6)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+6)%12,"七杀");
//    }
//    else SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei+6)%12,"七杀");
//    
//    GetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+10)%12,str);
//    if (str == "")
//    {
//        SetDlgItemText(IDC_STATIC_ZW1+(13-nZiWei+10)%12,"破军");
//    }
//    else SetDlgItemText(IDC_STATIC_2ZIWEI1+(13-nZiWei+10)%12,"破军");
//    
//}
//
//int CZiWei::GetMingJu()
//{
//    CString str;
//    m_mingju.GetWindowText(str);
//    if (str == "水二局")
//    {
//        return 2;
//    }
//    if (str == "木三局")
//    {
//        return 3;
//    }
//    if (str == "金四局")
//    {
//        return 4;
//    }
//    if (str == "土五局")
//    {
//        return 5;
//    }
//    else
//        return 6;
//}
//
////金长生在巳，木长生在亥，火长生在寅，水土长生在申。由长生宫起头。
////阳男阴女顺行，阴男阳女逆行
//void CZiWei::Set12ChangSheng()
//{
//    const char *cChangSheng[] = {"长生","沐浴","冠带","临官","帝旺","衰","病","死","墓","绝","胎","养"};
//    int nChangSheng=GetMingJu();
//    if (nChangSheng == 4) //金四局
//    {
//        for (int j=0;j<12;j++)
//        {
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12+j+9)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12-j+3)%12]);
//        }
//    }
//    if (nChangSheng == 3) //木三局
//    {
//        for (int j=0;j<12;j++)
//        {
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12+j+3)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12-j+9)%12]);
//        }
//    }
//    if (nChangSheng == 6) //火六局
//    {
//        for (int j=0;j<12;j++)
//        {
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12+j)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12-j)%12]);
//        }
//    }
//    if(nChangSheng == 2 || nChangSheng == 5) //水二 土五
//    {
//        for (int j=0;j<12;j++)
//        {
//            if ((m_nSex+atoi(m_wYear))%2 == 0)
//            {
//                SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12+j+6)%12]);
//            }
//            else SetDlgItemText(IDC_STATIC_CS1+j,cChangSheng[(12-j+6)%12]);
//        }
//    }
//}
//
////辰上顺时文昌 戌上逆时文曲
//void CZiWei::SetChangQuStar()
//{
//    int nHour= m_wHour;
//    CString str;
//    //ID号 每隔12一轮回 遍历同group里的星座位 昌曲必定在前四位
//    for (int j=0;j<12*10;j=j+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(12-nHour+8)%12+j,str);
//        if (str == "")
//        {
//            SetDlgItemText(IDC_STATIC_ZW1+(12-nHour+8)%12+j,"文昌");
//            break;
//        }
//    }
//    
//    for (int i=0;i<12*10;i=i+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nHour+2)%12+i,str);
//        if (str == "")
//        {
//            SetDlgItemText(IDC_STATIC_ZW1+(nHour+2)%12+i,"文曲");
//            break;
//        }
//    }
//}
//
////甲禄在寅乙禄卯，丙戊在巳丁己午，庚禄居申辛禄酉，壬禄居亥癸禄子。
//void CZiWei::SetLuCunStar()
//{
//    CString str;
//    if (m_TianGan == "甲")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW1+i,"禄存");
//                break;
//            }
//        }
//    }
//    
//    if (m_TianGan == "乙")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW2+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW2+i,"禄存");
//                break;
//            }
//        }
//    }
//    
//    if (m_TianGan == "丙" || m_TianGan == "戊")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW4+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW4+i,"禄存");
//                break;
//            }
//        }
//    }
//    
//    if (m_TianGan == "丁" || m_TianGan == "己")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW5+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW5+i,"禄存");
//                break;
//            }
//        }
//    }
//    
//    if (m_TianGan == "庚")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW7+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW7+i,"禄存");
//                break;
//            }
//        }
//    }
//    
//    if (m_TianGan == "辛")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW8+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW8+i,"禄存");
//                break;
//            }
//        }
//    }
//    
//    if (m_TianGan == "壬")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW10+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW10+i,"禄存");
//                break;
//            }
//        }
//    }
//    
//    if (m_TianGan == "癸")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW11+i,str);
//            if (str == "")
//            {
//                SetDlgItemText(IDC_STATIC_ZW11+i,"禄存");
//                break;
//            }
//        }
//    }
//}
//
////辰上顺月左辅 戌上逆月右弼
//void CZiWei::SetZuoYouStar()
//{
//    int nMonth= atoi(m_wMonth)-1;
//    CString str;
//    //ID号 每隔12一轮回 遍历同group里的星座位 左辅右弼必定在前6位
//    for (int i=0;i<12*10;i=i+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nMonth+2)%12+i,str);
//        if (str == "")
//        {
//            SetDlgItemText(IDC_STATIC_ZW1+(nMonth+2)%12+i,"左辅");
//            break;
//        }
//    }
//    
//    for (int j=0;j<12*10;j=j+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(12-nMonth+8)%12+j,str);
//        if (str == "")
//        {
//            SetDlgItemText(IDC_STATIC_ZW1+(12-nMonth+8)%12+j,"右弼");
//            break;
//        }
//    }
//}
//
////甲戊兼牛羊,乙己鼠猴乡。
////丙丁猪鸡位,壬癸兔蛇藏。
////庚辛逢马虎,魁钺贵人方。
//void CZiWei::SetKuiYueStar()
//{
//    CString str_TianKui;
//    CString str_TianYue;
//    if (m_TianGan == "甲" || m_TianGan == "戊")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW12+i,str_TianKui);
//            if (str_TianKui == "")
//            {SetDlgItemText(IDC_STATIC_ZW12+i,"天魁");break;}
//        }
//        for (int j=0;j<12*10;j=j+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW6+j,str_TianYue);
//            if (str_TianYue == "")
//            {SetDlgItemText(IDC_STATIC_ZW6+j,"天钺");break;}
//        }
//    }
//    
//    if (m_TianGan == "乙" || m_TianGan == "己")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW11+i,str_TianKui);
//            if (str_TianKui == "")
//            {SetDlgItemText(IDC_STATIC_ZW11+i,"天魁");break;}
//        }
//        for (int j=0;j<12*10;j=j+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW7+j,str_TianYue);
//            if (str_TianYue == "")
//            {SetDlgItemText(IDC_STATIC_ZW7+j,"天钺");break;}
//        }
//    }
//    
//    if (m_TianGan == "丙" || m_TianGan == "丁")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW10+i,str_TianKui);
//            if (str_TianKui == "")
//            {SetDlgItemText(IDC_STATIC_ZW10+i,"天魁");break;}
//        }
//        for (int j=0;j<12*10;j=j+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW8+j,str_TianYue);
//            if (str_TianYue == "")
//            {SetDlgItemText(IDC_STATIC_ZW8+j,"天钺");break;}
//        }
//    }
//    
//    if (m_TianGan == "壬" || m_TianGan == "癸")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW2+i,str_TianKui);
//            if (str_TianKui == "")
//            {SetDlgItemText(IDC_STATIC_ZW2+i,"天魁");break;}
//        }
//        for (int j=0;j<12*10;j=j+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW4+j,str_TianYue);
//            if (str_TianYue == "")
//            {SetDlgItemText(IDC_STATIC_ZW4+j,"天钺");break;}
//        }
//    }
//    
//    if (m_TianGan == "庚" || m_TianGan == "辛")
//    {
//        for (int i=0;i<12*10;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW5+i,str_TianKui);
//            if (str_TianKui == "")
//            {SetDlgItemText(IDC_STATIC_ZW5+i,"天魁");break;}
//        }
//        for (int j=0;j<12*10;j=j+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+j,str_TianYue);
//            if (str_TianYue == "")
//            {SetDlgItemText(IDC_STATIC_ZW1+j,"天钺");break;}
//        }
//    }
//}
//
////安火星：寅午戌年丑宫起，申子辰年寅宫始，巳酉丑年在卯宫，亥卯未年酉宫起，
////        从起始宫起子时，顺数至生时止，所在宫即是。
////安铃星：寅午戌年卯宫起子时，申子辰、巳酉丑、亥卯未年均从戌宫起子时，
////        顺数至生时止，所在宫即是。
//void CZiWei::SetHuoLingStar()
//{
//    const char *cDiZhi[] = {"子","丑","寅","卯","辰","巳","午",	"未","申","酉","戌","亥"};
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    m_DiZhi.Format(_T("%s"),cDiZhi[nDiZhi]);
//    
//    CString str_HuoStar;
//    CString str_LingStar;
//    int nShiChen = m_wHour;
//    if (m_DiZhi=="寅" || m_DiZhi=="午" || m_DiZhi=="戌")
//    {
//        for (int i=0;i<12*15;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+(11+nShiChen)%12+i,str_HuoStar);
//            if (str_HuoStar == "")
//            {SetDlgItemText(IDC_STATIC_ZW1+(11+nShiChen)%12+i,"火星");break;}
//        }
//        for (int j=0;j<12*15;j=j+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+(1+nShiChen)%12+j,str_LingStar);
//            if (str_LingStar == "")
//            {SetDlgItemText(IDC_STATIC_ZW1+(1+nShiChen)%12+j,"铃星");break;}
//        }
//    }
//    if (m_DiZhi=="申" || m_DiZhi=="子" || m_DiZhi=="辰")
//    {
//        for (int i=0;i<12*15;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+nShiChen+i,str_HuoStar);
//            if (str_HuoStar == "")
//            {SetDlgItemText(IDC_STATIC_ZW1+nShiChen+i,"火星");break;}
//        }
//    }
//    if (m_DiZhi=="巳" || m_DiZhi=="酉" || m_DiZhi=="丑")
//    {
//        for (int i=0;i<12*15;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+(1+nShiChen)%12+i,str_HuoStar);
//            if (str_HuoStar == "")
//            {SetDlgItemText(IDC_STATIC_ZW1+(1+nShiChen)%12+i,"火星");break;}
//        }
//    }
//    if (m_DiZhi=="亥" || m_DiZhi=="卯" || m_DiZhi=="未")
//    {
//        for (int i=0;i<12*15;i=i+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+(7+nShiChen)%12+i,str_HuoStar);
//            if (str_HuoStar == "")
//            {SetDlgItemText(IDC_STATIC_ZW1+(7+nShiChen)%12+i,"火星");break;}
//        }
//    }
//    //"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥"
//    if (nDiZhi !=2 && nDiZhi != 6 && nDiZhi!=10)
//    {
//        for (int j=0;j<12*15;j=j+12)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+(8+nShiChen)%12+j,str_LingStar);
//            if (str_LingStar == "")
//            {SetDlgItemText(IDC_STATIC_ZW1+(8+nShiChen)%12+j,"铃星");break;}
//        }
//    }
//}
//
////禄存前为羊 后为陀
//void CZiWei::SetYangTuoStar()
//{
//    int nLuCunPos;
//    CString str_FindLuCun;
//    for (int i=0;i<12*10;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str_FindLuCun);
//            if (str_FindLuCun == "禄存")
//            {
//                nLuCunPos = j;
//                i=120; //跳出循环
//                break;
//            }
//        }
//    }
//    
//    CString str_QingYang; //擎羊
//    CString str_TuoLuo;   //陀罗
//    for (int k=0;k<12*15;k=k+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nLuCunPos+1)%12+k,str_QingYang);
//        if (str_QingYang == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(nLuCunPos+1)%12+k,"擎羊");break;}
//    }
//    for (k=0;k<12*15;k=k+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(12+nLuCunPos-1)%12+k,str_TuoLuo);
//        if (str_TuoLuo == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(12+nLuCunPos-1)%12+k,"陀罗");break;}
//    }
//}
//
////地空地劫 亥宫起子时，逆地空，顺地劫
//void CZiWei::SetKongJieStar()
//{
//    int nHour= m_wHour;
//    CString str;
//    for (int j=0;j<12*15;j=j+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(12-nHour+9)%12+j,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(12-nHour+9)%12+j,"地空");break;}
//    }
//    
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nHour+9)%12+i,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(nHour+9)%12+i,"地劫");break;}
//    }
//}
//
////驿马 寅午戌马在申，申子辰马在寅，亥卯未马在巳，巳酉丑马在亥
////天马 排法尚未定论
////天马者,正月起午顺行六阳辰
//void CZiWei::SetTianMaStar()
//{
//    int nMonth = atoi(m_wMonth);
//    int nGong;
//    if (nMonth==1 || nMonth==5 || nMonth==9)
//    {nGong=IDC_STATIC_ZW7;}
//    if (nMonth==3 || nMonth==7 || nMonth==11)
//    {nGong=IDC_STATIC_ZW1;}
//    if (nMonth==2 || nMonth==6 || nMonth==10)
//    {nGong=IDC_STATIC_ZW4;}
//    if (nMonth==4 || nMonth==8 || nMonth==12)
//    {nGong=IDC_STATIC_ZW10;}
//    
//    CString str;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(nGong+i,str);
//        if (str == "")
//        {SetDlgItemText(nGong+i,"天马");break;}
//    }
//}
//
////天姚丑上顺正月 天刑酉上顺正月
//void CZiWei::SetXingYaoStar()
//{
//    int nMonth = atoi(m_wMonth);
//    CString str;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(11+nMonth-1)%12+i,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(11+nMonth-1)%12+i,"天姚");break;}
//    }
//    for (i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(7+nMonth-1)%12+i,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(7+nMonth-1)%12+i,"天刑");break;}
//    }
//}
//
////甲起羊鸡乙龙猴 丙年鼠蛇一窝谋 丁虎擒猪戊玉兔
////己鸡居然与虎倚 庚豬馬辛雞蛇走 壬犬馬癸马蛇游
//void CZiWei::SetTianGuanTianFuStar()
//{
//    int nGongTG=0;
//    int nGongTF=0;
//    if (m_TianGan=="甲")
//    {
//        nGongTG=IDC_STATIC_ZW6;
//        nGongTF=IDC_STATIC_ZW8;
//    }
//    if (m_TianGan=="乙")
//    {
//        nGongTG=IDC_STATIC_ZW3;
//        nGongTF=IDC_STATIC_ZW7;
//    }
//    if (m_TianGan=="丙")
//    {
//        nGongTG=IDC_STATIC_ZW4;
//        nGongTF=IDC_STATIC_ZW11;
//    }
//    if (m_TianGan=="丁")
//    {
//        nGongTG=IDC_STATIC_ZW1;
//        nGongTF=IDC_STATIC_ZW10;
//    }
//    if (m_TianGan=="戊")
//    {
//        nGongTG=IDC_STATIC_ZW2;
//        nGongTF=IDC_STATIC_ZW2;
//    }
//    if (m_TianGan=="己")
//    {
//        nGongTG=IDC_STATIC_ZW8;
//        nGongTF=IDC_STATIC_ZW1;
//    }
//    if (m_TianGan=="庚")
//    {
//        nGongTG=IDC_STATIC_ZW10;
//        nGongTF=IDC_STATIC_ZW5;
//    }
//    if (m_TianGan=="辛")
//    {
//        nGongTG=IDC_STATIC_ZW8;
//        nGongTF=IDC_STATIC_ZW4;
//    }
//    if (m_TianGan=="壬")
//    {
//        nGongTG=IDC_STATIC_ZW9;
//        nGongTF=IDC_STATIC_ZW5;
//    }
//    if (m_TianGan=="癸")
//    {
//        nGongTG=IDC_STATIC_ZW5;
//        nGongTF=IDC_STATIC_ZW4;
//    }
//    CString str;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(nGongTG+i,str);
//        if (str == "")
//        {SetDlgItemText(nGongTG+i,"天官");break;}
//    }
//    for (i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(nGongTF+i,str);
//        if (str == "")
//        {SetDlgItemText(nGongTF+i,"天福");break;}
//    }
//}
//
////台辅午上顺子时 封诰寅上顺子时
//void CZiWei::SetTaiFengStar()
//{
//    int nHour= m_wHour;
//    CString str;
//    for (int j=0;j<12*15;j=j+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nHour+4)%12+j,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(nHour+4)%12+j,"台辅");break;}
//    }
//    
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+nHour+i,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+nHour+i,"封诰");break;}
//    }
//}
//
////申宫顺上正月 单月见神 双月返单
//void CZiWei::SetJieShenStar()
//{
//    int nMonth=atoi(m_wMonth);
//    for (int i=0;i<7;i++)
//    {
//        if (nMonth==2*i)
//        {
//            nMonth=nMonth-1;
//            break;
//        }
//    }
//    int nGong=IDC_STATIC_ZW1+(nMonth+5)%12;
//    
//    CString str;
//    for (i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(nGong+i,str);
//        if (str == "")
//        {SetDlgItemText(nGong+i,"解神");break;}
//    }
//}
//
////天巫 月系巳申寅亥
//void CZiWei::SetTianWuStar()
//{
//    int nMonth=atoi(m_wMonth);
//    int nGong;
//    if (nMonth==1 || nMonth==5 || nMonth==9)
//    {nGong=IDC_STATIC_ZW4;}
//    if (nMonth==2 || nMonth==6 || nMonth==10)
//    {nGong=IDC_STATIC_ZW7;}
//    if (nMonth==3 || nMonth==7 || nMonth==11)
//    {nGong=IDC_STATIC_ZW1;}
//    if (nMonth==4 || nMonth==8 || nMonth==12)
//    {nGong=IDC_STATIC_ZW10;}
//    CString str;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(nGong+i,str);
//        if (str == "")
//        {SetDlgItemText(nGong+i,"天巫");break;}
//    }
//}
//
////正月起 戌巳辰寅未卯亥未寅午戌寅。（无规律）
//void CZiWei::SetTianYueStar()
//{
//    int nMonth=atoi(m_wMonth);
//    int nGong;
//    if (nMonth==1 || nMonth==11)
//    {nGong=IDC_STATIC_ZW9;}
//    if (nMonth==2)
//    {nGong=IDC_STATIC_ZW4;}
//    if (nMonth==3)
//    {nGong=IDC_STATIC_ZW3;}
//    if (nMonth==4 || nMonth==9 || nMonth==12)
//    {nGong=IDC_STATIC_ZW1;}
//    if (nMonth==5 || nMonth==8)
//    {nGong=IDC_STATIC_ZW6;}
//    if (nMonth==6)
//    {nGong=IDC_STATIC_ZW2;}
//    if (nMonth==7)
//    {nGong=IDC_STATIC_ZW10;}
//    CString str;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(nGong+i,str);
//        if (str == "")
//        {SetDlgItemText(nGong+i,"天月");break;}
//    }
//}
//
////阴煞 寅子戌申午辰 寅子戌申午辰
//void CZiWei::SetYinShaStar()
//{
//    int nMonth=atoi(m_wMonth);
//    nMonth = 2*nMonth;
//    int nGong=IDC_STATIC_ZW1+(24-nMonth+2)%12;
//    CString str;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(nGong+i,str);
//        if (str == "")
//        {SetDlgItemText(nGong+i,"阴煞");break;}
//    }
//}
//
////三台八座  三台顺左辅初一 八座逆右弼初一
//void CZiWei::SetTaiZuoStar()
//{
//    int nZuoPos;
//    CString str_FindZuo;
//    for (int i=0;i<12*10;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str_FindZuo);
//            if (str_FindZuo == "左辅")
//            {
//                nZuoPos = j;
//                i=120; //跳出循环
//                break;
//            }
//        }
//    }
//    CString str;
//    int nDay=atoi(m_wDay);
//    for (int k=0;k<12*15;k=k+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+nZuoPos+(nDay-1)%12+k,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+nZuoPos+(nDay-1)%12+k,"三台");break;}
//    }
//    
//    int nYouPos;
//    CString str_FindYou;
//    for (i=0;i<12*10;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str_FindYou);
//            if (str_FindYou == "右弼")
//            {
//                nYouPos = j;
//                i=120; //跳出循环
//                break;
//            }
//        }
//    }
//    for (k=0;k<12*15;k=k+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+nYouPos+(13-nDay)%12+k,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+nYouPos+(13-nDay)%12+k,"八座");break;}
//    }
//}
//
////恩光天贵 恩光顺文昌初一退一格 天贵顺文曲初一退一格
//void CZiWei::SetEnGuiStar()
//{
//    int nPos;
//    CString str;
//    for (int i=0;i<12*10;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str);
//            if (str == "文昌")
//            {
//                nPos = j;
//                i=120; //跳出循环
//                break;
//            }
//        }
//    }
//    int nDay=atoi(m_wDay);
//    for (int k=0;k<12*15;k=k+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nPos+nDay-1+11)%12+k,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(nPos+nDay-1+11)%12+k,"恩光");break;}
//    }
//    
//    for (i=0;i<12*10;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str);
//            if (str == "文曲")
//            {
//                nPos = j;
//                i=120; //跳出循环
//                break;
//            }
//        }
//    }
//    for (k=0;k<12*15;k=k+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nPos+nDay-1+11)%12+k,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(nPos+nDay-1+11)%12+k,"天贵");break;}
//    }
//}
//
////辰上顺年支龙池 戌上逆年支凤阁
//void CZiWei::SetLongFengStar()
//{
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    CString str;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(nDiZhi+2)%12+i,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(nDiZhi+2)%12+i,"龙池");break;}
//    }
//    
//    for (int j=0;j<12*15;j=j+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(12-nDiZhi+8)%12+j,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(12-nDiZhi+8)%12+j,"凤阁");break;}
//    }
//}
//
////天空 丑宫起子年地支
//void CZiWei::SetKongStar()
//{
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    CString str;
//    for (int j=0;j<12*15;j=j+12)
//    {
//        GetDlgItemText(IDC_STATIC_ZW1+(12+nDiZhi-1)%12+j,str);
//        if (str == "")
//        {SetDlgItemText(IDC_STATIC_ZW1+(12+nDiZhi-1)%12+j,"天空");break;}
//    }
//    
//    int nTianGan = ((atoi(m_wYear) - 4) % 60) % 10 + 1;
//    int nGong1,nGong2;
//    if (nTianGan==1 || nTianGan==6)
//    {
//        nGong1=IDC_STATIC_ZW7;
//        nGong2=nGong1+1;
//    }
//    if (nTianGan==2 || nTianGan==7)
//    {
//        nGong1=IDC_STATIC_ZW5;
//        nGong2=nGong1+1;
//    }
//    if (nTianGan==3 || nTianGan==8)
//    {
//        nGong1=IDC_STATIC_ZW3;
//        nGong2=nGong1+1;
//    }
//    if (nTianGan==4 || nTianGan==9)
//    {
//        nGong1=IDC_STATIC_ZW2;
//        nGong2=nGong1-1;
//    }
//    if (nTianGan==5 || nTianGan==10)
//    {
//        nGong1=IDC_STATIC_ZW11;
//        nGong2=nGong1-1;
//    }
//    for (j=0;j<12*15;j=j+12)
//    {
//        if (atoi(m_wYear)%2==0) //阳者用阳
//        {
//            GetDlgItemText(nGong1+j,str);
//            if (str == "")
//            {SetDlgItemText(nGong1+j,"截空");break;}
//        }
//        else
//            GetDlgItemText(nGong2+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong2+j,"截空");break;}
//    }
//}
//
////孤辰：寅卯辰年生人在巳，巳午未年在申，申酉戌年在亥，亥子丑年在寅。(四马宫)
////寡宿：寅卯辰年生人在丑，巳午未年在辰，申酉戌年在未，亥子丑年在戌。(四墓宫)
//void CZiWei::SetGuGuaStar()
//{
//    int nGong_Gu;
//    int nGong_Gua;
//    if (m_DiZhi=="寅" || m_DiZhi=="卯" || m_DiZhi=="辰")
//    {nGong_Gu=IDC_STATIC_ZW4;nGong_Gua=IDC_STATIC_ZW12;}
//    if (m_DiZhi=="巳" || m_DiZhi=="午" || m_DiZhi=="未")
//    {nGong_Gu=IDC_STATIC_ZW7;nGong_Gua=IDC_STATIC_ZW3;}
//    if (m_DiZhi=="申" || m_DiZhi=="酉" || m_DiZhi=="戌")
//    {nGong_Gu=IDC_STATIC_ZW10;nGong_Gua=IDC_STATIC_ZW6;}
//    if (m_DiZhi=="亥" || m_DiZhi=="子" || m_DiZhi=="丑")
//    {nGong_Gu=IDC_STATIC_ZW1;nGong_Gua=IDC_STATIC_ZW9;}
//    CString str;
//    for (int j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong_Gu+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong_Gu+j,"孤辰");break;}
//    }
//    for (j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong_Gua+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong_Gua+j,"宿寡");break;}
//    }
//}
//
////天哭午宫起子年顺 天虚午宫起子年逆
//void CZiWei::SetKuXuStar()
//{
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    int nGong = IDC_STATIC_ZW1 + (nDiZhi+4)%12;
//    CString str;
//    for (int j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天虚");break;}
//    }
//    nGong = IDC_STATIC_ZW1 + (12-nDiZhi+4)%12;
//    for (j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天哭");break;}
//    }
//}
//
//void CZiWei::SetLuanXiStar()
//{
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    int nGong = IDC_STATIC_ZW1 + (12-nDiZhi+1)%12;
//    CString str;
//    for (int j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"红鸾");break;}
//    }
//    nGong = IDC_STATIC_ZW1 + (12-nDiZhi+7)%12;
//    for (j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天喜");break;}
//    }
//}
//
////蜚廉 破碎
//void CZiWei::SetFeiLianStar()
//{
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    int nGong;
//    if (nDiZhi==0){nGong = IDC_STATIC_ZW7;}
//    if (nDiZhi==1){nGong = IDC_STATIC_ZW8;}
//    if (nDiZhi==2){nGong = IDC_STATIC_ZW9;}
//    if (nDiZhi==3){nGong = IDC_STATIC_ZW4;}
//    if (nDiZhi==4){nGong = IDC_STATIC_ZW5;}
//    if (nDiZhi==5){nGong = IDC_STATIC_ZW6;}
//    if (nDiZhi==6){nGong = IDC_STATIC_ZW1;}
//    if (nDiZhi==7){nGong = IDC_STATIC_ZW2;}
//    if (nDiZhi==8){nGong = IDC_STATIC_ZW3;}
//    if (nDiZhi==9){nGong = IDC_STATIC_ZW10;}
//    if (nDiZhi==10){nGong = IDC_STATIC_ZW11;}
//    if (nDiZhi==11){nGong = IDC_STATIC_ZW12;}
//    CString str;
//    for (int j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"蜚廉");break;}
//    }
//    
//    if (nDiZhi==0 || nDiZhi==3 || nDiZhi==6 || nDiZhi==9)
//    {nGong = IDC_STATIC_ZW4;}
//    if (nDiZhi==1 || nDiZhi==4 || nDiZhi==7 || nDiZhi==10)
//    {nGong = IDC_STATIC_ZW12;}
//    if (nDiZhi==2 || nDiZhi==5 || nDiZhi==8 || nDiZhi==12)
//    {nGong = IDC_STATIC_ZW8;}
//    for (j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"破碎");break;}
//    }
//}
//
////.天才 命宫起子年 顺年支
////.天寿 身宫起子年 顺年支
//void CZiWei::SetTiancaiTianshouStar()
//{
//    CString str;
//    int nPos;
//    for (int i=0;i<12;i++)
//    {
//        GetDlgItemText(IDC_STATIC_GONG1+i,str);
//        if (str == "本命宫" || str == "命★身")
//        {nPos=i;break;}
//    }
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    int nGong = IDC_STATIC_ZW1 + (12+nPos+nDiZhi)%12;
//    for (int j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天才");break;}
//    }
//    
//    for (i=0;i<12;i++)
//    {
//        GetDlgItemText(IDC_STATIC_GONG1+i,str);
//        if (str=="命★身" || str=="财★身" || str=="迁★身" || str=="官★身"
//            || str=="夫★身" || str=="福★身")
//        {nPos=i;break;}
//    }
//    nGong = IDC_STATIC_ZW1 + (12+nPos+nDiZhi)%12;
//    for (j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天寿");break;}
//    }
//}
//
////天厨
//void CZiWei::SetTianChuStar()
//{
//    int nGong;
//    if (m_TianGan == "甲" || m_TianGan == "丁")
//    {nGong=IDC_STATIC_ZW4;}
//    if (m_TianGan == "乙" || m_TianGan == "戊" || m_TianGan == "辛")
//    {nGong=IDC_STATIC_ZW5;}
//    if (m_TianGan == "己")
//    {nGong=IDC_STATIC_ZW7;}
//    if (m_TianGan == "壬")
//    {nGong=IDC_STATIC_ZW8;}
//    if (m_TianGan == "癸")
//    {nGong=IDC_STATIC_ZW10;}
//    if (m_TianGan == "丙")
//    {nGong=IDC_STATIC_ZW11;}
//    if (m_TianGan == "庚")
//    {nGong=IDC_STATIC_ZW1;}
//    CString str;
//    for (int j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天厨");break;}
//    }
//}
//
//void CZiWei::Set14StarColor(CDC *pDC, CWnd *pWnd)
//{
//    CString str;
//    pWnd->GetWindowText(str);
//    if (str=="紫微" || str=="巨门" || str=="廉贞" || str=="武曲" || str=="破军" || str=="贪狼"
//        || str=="天府" || str=="天同" || str=="天机" || str=="天机" || str=="天梁"|| str=="天相"|| str=="七杀"
//        || str=="太阴" || str=="太阳")
//        pDC->SetTextColor(RGB(255,0,0));
//    
//    if (str=="文曲" || str=="文昌" || str=="左辅" || str=="右弼" || str=="天魁" || str=="天钺"||
//        str=="天马"|| str=="禄存" || str=="天官"|| str=="天福")
//        pDC->SetTextColor(RGB(255,0,255));
//    
//    if (str=="擎羊" || str=="陀罗" || str=="火星" || str=="铃星" || str=="地劫"|| str=="地空" ||
//        str=="天刑"|| str=="天姚")
//        pDC->SetTextColor(RGB(200,0,200));
//    
//    //十二长生颜色
//    if (pWnd->GetDlgCtrlID() >= IDC_STATIC_CS1 && pWnd->GetDlgCtrlID() <= IDC_STATIC_CS12)
//    {pDC->SetTextColor(RGB(0,180,50));}
//    
//    //十二博士颜色
//    if (pWnd->GetDlgCtrlID() >= IDC_STATIC_BS1 && pWnd->GetDlgCtrlID() <= IDC_STATIC_BS12)
//    {pDC->SetTextColor(RGB(0,0,250));}
//    
//    //十二太岁颜色
//    if (pWnd->GetDlgCtrlID() >= IDC_STATIC_TS1 && pWnd->GetDlgCtrlID() <= IDC_STATIC_TS12)
//    {pDC->SetTextColor(RGB(0,100,200));}
//    
//    //十二将前颜色
//    if (pWnd->GetDlgCtrlID() >= IDC_STATIC_JQ1 && pWnd->GetDlgCtrlID() <= IDC_STATIC_JQ12)
//    {pDC->SetTextColor(RGB(100,0,255));}
//    
//    //命主 身主颜色
//    if (pWnd->GetDlgCtrlID() == IDC_STATIC_MINGZHU || pWnd->GetDlgCtrlID() == IDC_STATIC_SHENZHU)
//    {pDC->SetTextColor(RGB(0,200,100));}
//    
//    //阳历 阴历
//    if (pWnd->GetDlgCtrlID() == IDC_STATIC_YANGLI || pWnd->GetDlgCtrlID() == IDC_STATIC_NONGLI)
//    {pDC->SetTextColor(RGB(200,0,100));}
//    
//    //十字
//    if (pWnd->GetDlgCtrlID() == IDC_STATIC_SHIZI)
//    {pDC->SetTextColor(RGB(250,0,11));}
//    
//    //四化
//    if (pWnd->GetDlgCtrlID() == IDC_STATIC_4HUA)
//    {
//        pDC->SetBkMode(BKMODE_LAST);
//        pDC->SetTextColor(RGB(255,255,255));
//        pDC->SetBkColor(RGB(0,100,0));
//    }
//    if (pWnd->GetDlgCtrlID() >= IDC_STATIC_15ZW1 && pWnd->GetDlgCtrlID() <= IDC_STATIC_15ZW12)
//    {
//        pDC->SetBkMode(BKMODE_LAST);
//        pDC->SetTextColor(RGB(255,255,255));
//        pDC->SetBkColor(RGB(0,100,0));
//    }
//    
//}
//
////天伤在仆役宫 天使疾厄宫
//void CZiWei::SetTianshangTianshiStar()
//{
//    int nPos;
//    CString str;
//    for (int i=0;i<12;i++)
//    {
//        GetDlgItemText(IDC_STATIC_GONG1+i,str);
//        if (str == "仆役宫")
//        {nPos=i;break;}
//    }
//    int nGong = IDC_STATIC_ZW1 + nPos;
//    for (int j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天伤");break;}
//    }
//    
//    for (i=0;i<12;i++)
//    {
//        GetDlgItemText(IDC_STATIC_GONG1+i,str);
//        if (str == "疾厄宫")
//        {nPos=i;break;}
//    }
//    nGong = IDC_STATIC_ZW1 + nPos;
//    for (j=0;j<12*20;j=j+12)
//    {
//        GetDlgItemText(nGong+j,str);
//        if (str == "")
//        {SetDlgItemText(nGong+j,"天使");break;}
//    }
//}
//
////生年博士十二神 禄存起
////阳男阴女顺行，阴男阳女逆行
//void CZiWei::Set12BoShi()
//{
//    const char *cBoShi[] = {"博士","力士","青龙","小耗","将军","奏书","飞廉","喜神","病符","大耗","伏兵","官符"};
//    int nPos;
//    CString str;
//    for (int i=0;i<12*10;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str);
//            if (str == "禄存")
//            {
//                nPos = j;
//                i=120; //跳出循环
//                break;}
//        }
//    }
//    for (int k=0;k<12;k++)
//    {
//        if ((m_nSex+atoi(m_wYear))%2 == 0)
//        {SetDlgItemText(IDC_STATIC_BS1+(nPos+k)%12,cBoShi[k]);}
//        else SetDlgItemText(IDC_STATIC_BS1+(12+nPos-k)%12,cBoShi[k]);
//    }
//}
//
////太岁十二神煞 丧门子年顺
//void CZiWei::Set12TaiSui()
//{
//    const char *cTaiSui[] = {"丧门","贯索","五鬼","死符","岁破","龙德","白虎","天德","天狗","凶神","太岁","晦气"};
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    for (int i=0;i<12;i++)
//    {
//        SetDlgItemText(IDC_STATIC_TS1+(nDiZhi+i)%12,cTaiSui[i]);
//    }
//}
//
////寅午戌年將星午，申子辰年子將星，
////巳酉丑將酉上駐，亥卯未將卯上停。
//void CZiWei::Set12Jiang()
//{
//    const char *cJiangQian[] = {"将星","攀鞍","驿马","息神","华盖","劫煞","灾煞","天煞","指背","咸池","月煞","亡神"};
//    
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    int nGong;
//    if (nDiZhi==0 || nDiZhi==4 || nDiZhi==8)
//    {nGong=10;}
//    if (nDiZhi==1 || nDiZhi==5 || nDiZhi==9)
//    {nGong=7;}
//    if (nDiZhi==2 || nDiZhi==6 || nDiZhi==10)
//    {nGong=4;}
//    if (nDiZhi==3 || nDiZhi==7 || nDiZhi==11)
//    {nGong=1;}
//    
//    for (int i=0;i<12;i++)
//    {
//        SetDlgItemText(IDC_STATIC_JQ1+(nGong+i)%12,cJiangQian[i]);
//    }
//}
//
////庙旺平闲陷
//void CZiWei::SetMiaoXian()
//{
//    const char *cStar[] =
//    {
//        "擎羊","天马","禄存","破军","七杀","天梁","天相","巨门","贪狼","太阴","天府","廉贞","天同","武曲","太阳","天机","紫微",
//        "文曲","文昌","右弼","左辅","天钺","天魁","地劫","地空","铃星","火星","陀罗"
//    };
//    
//    const char *cList[12][28] =
//    {
//        //   羊   马   禄   破   杀   梁   相   巨   狼   阴   府   廉   同   武   阳   机   紫   曲   昌   右   左   钺   魁   劫   空   铃   火   陀
//        {"  ","旺","庙","陷","庙","庙","庙","庙","平","闲","庙","庙","闲","闲","旺","旺","庙","平","陷","旺","庙","旺","  ","平","陷","庙","庙","陷"},  //寅
//        {"陷","  ","旺","旺","陷","庙","陷","庙","旺","陷","平","闲","庙","陷","庙","旺","旺","旺","平","陷","陷","  ","庙","平","平","庙","平","  "},
//        {"庙","  ","  ","旺","旺","旺","旺","平","庙","闲","庙","旺","平","庙","庙","庙","陷","庙","旺","庙","庙","  ","  ","陷","陷","旺","闲","庙"},
//        {"  ","平","庙","闲","平","陷","平","平","陷","陷","平","陷","庙","平","平","平","旺","庙","陷","平","平","旺","  ","闲","庙","旺","旺","陷"},
//        {"平","  ","旺","庙","旺","庙","旺","旺","旺","陷","旺","平","陷","旺","庙","庙","庙","陷","庙","旺","旺","  ","庙","庙","庙","庙","庙","  "},
//        {"庙","  ","  ","庙","旺","旺","闲","陷","庙","平","庙","庙","陷","庙","平","陷","庙","旺","平","庙","庙","旺","  ","平","平","旺","闲","庙"},
//        {"  ","旺","庙","陷","庙","陷","庙","庙","庙","平","平","庙","旺","平","闲","平","旺","平","旺","闲","平","庙","  ","庙","庙","旺","陷","陷"},
//        {"陷","  ","旺","陷","闲","地","陷","庙","平","旺","旺","平","平","旺","闲","旺","平","庙","庙","陷","陷","庙","  ","平","庙","陷","陷","  "},
//        {"庙","  ","  ","旺","庙","旺","闲","旺","庙","旺","庙","旺","平","庙","陷","庙","闲","陷","陷","庙","庙","  ","  ","平","陷","庙","庙","庙"},
//        {"  ","平","庙","平","平","陷","平","旺","陷","庙","旺","陷","庙","平","陷","平","旺","旺","旺","平","闲","  ","旺","旺","陷","庙","平","陷"},
//        {"陷","  ","旺","庙","旺","庙","庙","旺","旺","庙","庙","平","旺","旺","陷","庙","平","庙","旺","庙","旺","  ","旺","陷","平","陷","平","  "},   //子
//        {"庙","  ","  ","旺","庙","旺","庙","旺","庙","庙","庙","旺","陷","庙","陷","陷","庙","庙","庙","庙","庙","  ","旺","陷","陷","陷","旺","庙"}    //丑
//    };
//    
//    CString str;
//    int nPos;
//    int nCir;
//    for (int i=0;i<12*15;i=i+12)
//    {
//        for (int j=0;j<12;j++)
//        {
//            //i为圈 j为宫
//            GetDlgItemText(IDC_STATIC_ZW1+i+j,str);
//            for (int k=0;k<28;k++)
//            {
//                if (str == cStar[k])
//                {
//                    nCir=i;
//                    nPos=j;
//                    SetDlgItemText(IDC_STATIC_MX1+nCir+nPos,cList[nPos][k]);
//                    break;
//                }
//            }
//        }
//    }
//    
//}
//
////命主 命宫地支
////身主 生年地支
//void CZiWei::SetMingzhuShenzhu()
//{
//    const char *cMingzhu[] = {"贪狼","巨门","禄存","文曲","廉贞","武曲","破军","武曲","廉贞","文曲","禄存","巨门"};
//    CString str;
//    int nPos;
//    for (int i=0;i<12;i++)
//    {
//        GetDlgItemText(IDC_STATIC_GONG1+i,str);
//        if (str == "本命宫" || str == "命★身")
//        {nPos=i;break;}
//    }
//    SetDlgItemText(IDC_STATIC_MINGZHU,CString("命主")+cMingzhu[(nPos+2)%12]);
//    
//    int nDiZhi = ((atoi(m_wYear) - 4) % 60) % 12;
//    const char *cShenzhu[] = {"铃星","天相","天梁","天同","文昌","天机","火星","天相","天梁","天同","文昌","天机"};
//    SetDlgItemText(IDC_STATIC_SHENZHU,CString("身主")+cShenzhu[nDiZhi]);
//}
//
////子年斗君 逆数生月 顺数生时
//void CZiWei::SetDouJun()
//{
//    const char *cDiZhi[] = {"子","丑","寅","卯","辰","巳","午",	"未","申","酉","戌","亥"};
//    int nPos = (13+m_wHour-atoi(m_wMonth))%12;
//    SetDlgItemText(IDC_STATIC_ZIDOU,CString("子年斗君：")+cDiZhi[nPos]);
//    
//    SetDlgItemText(IDC_STATIC_YANGLI,CString("阳历：")+CGlobal::strYangLi_global);
//    SetDlgItemText(IDC_STATIC_NONGLI,CString("农历：")+CGlobal::strNongLi_global);
//    
//}
//
////八字
//void CZiWei::Set8zi()
//{
//    int nTianGan = ((atoi(m_wYear) - 4) % 60) % 10;
//    //年干支
//    CString str_Year;
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
//
//void CZiWei::OnRButtonDown(UINT nFlags, CPoint point) 
//{
//    // TODO: Add your message handler code here and/or call default
//    CCatchScreenDlg dlg;
//    dlg.DoModal();
//    //	CDialog::OnRButtonDown(nFlags, point);
//}
//
//void CZiWei::Set4hua()
//{
//    const char *cList4[] = {"[禄]","[权]","[科]","[忌]"};
//    const char *cList4hua[12][4] = 
//    {
//        //禄     权      科     忌
//        {"廉贞","破军","武曲","太阳"},   //甲
//        {"天机","天梁","紫微","太阴"},   //乙
//        {"天同","天机","文昌","廉贞"},   //丙
//        {"太阴","天同","天机","巨门"},   //丁
//        {"贪狼","太阴","右弼","天机"},   //戊
//        {"武曲","贪狼","天梁","文曲"},   //己
//        {"太阳","武曲","太阴","天同"},   //庚
//        {"巨门","太阳","文曲","文昌"},   //辛
//        {"天梁","紫微","左辅","武曲"},   //壬
//        {"破军","巨门","太阴","贪狼"}    //癸  
//    };
//    int nTianGan = ((atoi(m_wYear) - 4) % 60) % 10;
//    CString str4hua; 
//    //	cList4hua[][nTianGan];
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
//    
//}
//
//int CZiWei::OnCreate(LPCREATESTRUCT lpCreateStruct) 
//{
//    if (CDialog::OnCreate(lpCreateStruct) == -1)
//        return -1;
//    
//    // TODO: Add your specialized creation code here
//    
//    return 0;
//}
