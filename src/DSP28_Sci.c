

#include "DSP28_Device.h"

void InitSci(void)
{
	ScibRegs.SCICCR.all = 0x07;	
	//8λ����λ��������ģʽ����ֹ���Ͳ���ģʽ������żУ�飬1λ����λ 
	
	ScibRegs.SCICTL1.all = 0x03; 
	//SCIA�������ͽ�����ʹ�� 
	
	ScibRegs.SCICTL2.all = 0x00; //��ʱ��ʹ��
	//����������/�ж�ʹ�ܣ�SCITXBUF�Ĵ����ж�ʹ��
	
	ScibRegs.SCIHBAUD = 0x01;
	ScibRegs.SCILBAUD = 0xe7;
	//������Ϊ9600
	
	ScibRegs.SCICTL1.all = 0x23;
	//����SCI

		SciaRegs.SCICCR.all = 0x07;	
	//8λ����λ��������ģʽ����ֹ���Ͳ���ģʽ������żУ�飬1λ����λ 
	
	SciaRegs.SCICTL1.all = 0x03; 
	//SCIA�������ͽ�����ʹ�� 
	
	SciaRegs.SCICTL2.all = 0x00; //��ʱ��ʹ��
	//����������/�ж�ʹ�ܣ�SCITXBUF�Ĵ����ж�ʹ��
	
	SciaRegs.SCIHBAUD = 0x01;
	SciaRegs.SCILBAUD = 0xe7;
	//������Ϊ9600
	
	SciaRegs.SCICTL1.all = 0x23;
//	PieCtrl.PIEIER9.bit.INTx3 = 1;
//	PieCtrl.PIEIER9.bit.INTx4 = 1;
	//SCIA�Ľ��պͷ����жϷֱ�λ��GPIO��9��ĵ�1�͵�2λ��ʹ��SCIA��PIE�ж�
 	

	// �����Ҫʹ��SCIB����������Ĵ��룬��SCIA��Ӧ�ĸĳ�SCIB�Ϳ���

	

	
}

/********************************************************************************
	name:	int SciaTx_Ready(void)
	input:	none
	output:	i	1:	ready
			0:	busy
*********************************************************************************/

int ScibTx_Ready(void)
{
	unsigned int i;
	if(ScibRegs.SCICTL2.bit.TXRDY == 1)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return(i);
}

/********************************************************************************
	name:	int SciaRx_Ready(void)
	input:	none
	output:	i	1:	new data
			0:	none
*********************************************************************************/

int ScibRx_Ready(void)
{
	unsigned int i;
	if(ScibRegs.SCIRXST.bit.RXRDY == 1)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return(i);
}

void sci_tx(int tx_data)
{
	if(ScibTx_Ready()==1)
	{
		ScibRegs.SCITXBUF=tx_data;	
	}
}
	
//===========================================================================
// No more.
//===========================================================================
