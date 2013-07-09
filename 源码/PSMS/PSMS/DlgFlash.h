#if !defined(AFX_DLGFLASH_H__FC9C5DF7_7144_4F99_9B5A_0C5451DEA813__INCLUDED_)

#define AFX_DLGFLASH_H__FC9C5DF7_7144_4F99_9B5A_0C5451DEA813__INCLUDED_


#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000


#include "stdafx.h"
class CDlgFlash 

{

public:

       CDlgFlash(CDialog* Dlg);                 //����Ϊ��Ҫʵ�ֶ���Ч���ĶԻ���

       CDlgFlash(CDialog* Dlg,int Timer1_ID,int Timer2_ID); //����1Ϊ��Ҫʵ�ֶ���Ч���ĶԻ��򣬲��������ֱ�Ϊ��ʱ��1�Ͷ�ʱ��2��ID

       virtual ~CDlgFlash();

       void StartFlashDestroyDlg();                  //��ʼ��������Ч��

       void OnTimer(UINT nIDEvent);                 //�����Ӧ��ʱ���������ں�������ʱ��ʱΪSetTimer(TimerID,10,NULL)

                                                                             //û������Ϊ�Զ���ִ�к�����ԭ����һ��Ҫ����Ҫ����Ч���Ĵ�������д��CDialog�м̳е�OnClose()��������ӳ�����ٴ���Ч����֮

                                                                             //

void SetFlashCreateSpeed(int x,int y);   //���ô������ڱ仯�ٶ�

                                                                             //����x��ʾ���ڿ�ȵı仯�ٶ�

                                                                             //����y��ʾ���ڸ߶ȵı仯�ٶ�

                                                                             

       void SetFlashDestroySpeed(int y);        //�������ٴ��ڱ仯�ٶ�

                                                                             //����y��ʾ���ڸ߶ȵı仯�ٶ�

protected:

       int xCreateSpeed;                                      //��������ʱ���ڿ�ȵı仯�ٶ�

       int yCreateSpeed;                                      //��������ʱ���ڸ߶ȵı仯�ٶ�

       int xDestorySpeed;                                    //���ٴ���ʱ���ڿ�ȵı仯�ٶ�                   

       int yDestorySpeed;                                    //��������ʱ���ڿ�ȵı仯�ٶ�

       int OriginalWidth,OriginalHeight;          //���ڵ�ԭʼ��С

       int DestoryPosX;                                       //���ٴ���ʱ���ڵ����Ͻ�x��λ��

       int DestoryPosY;                                       //���ٴ���ʱ���ڵ����Ͻ�y��λ��

       int Timer1_ID;                                                 //��ʱ��1ID����������ʱ��֮

       int Timer2_ID;                                                 //��ʱ��2ID�����ٴ���ʱ��֮  

       CDialog* flashDlg;                                    //ָ����Ҫ����Ч���Ĵ���ָ��

       void InitCDlg();                                         //��ʼ�����ڲ�ʹ��

};

#endif // !defined(AFX_DLGFLASH_H__FC9C5DF7_7144_4F99_9B5A_0C5451DEA813__INCLUDED_)

