#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���崬��״̬
typedef struct{
	double roll; //��ҡ�Ƕ�
	double roll_rate; //��ҡ���ٶ�
}Shipstate;

//���������
typedef struct{
	double kp; //��������
	double kd; //΢������ 
}Controller;

//����������
double calculateControlOutput(Controller controller,ShipState state){
	//�������
	double error=0-state.roll; //Ŀ���ҡ�Ƕ�Ϊ��
	//����������
	double control_output=controller.kp*error-controller.kd*state.roll_rate;
	
	return control_output; 
} 

int main(int argc, char *argv[]) {
	//��ʼ������״̬�Ϳ�����
	ShipState state={0.0,0.0};
	Controller controller+{1.0,0.5};
	
	//ģ�⴬���˶�
	for(int i=0;i<10,i++){
		//���´���״̬
		state.roll_rate+=calculateContorlOutput(controller,state)*0.1; //���º�ҡ���ٶ�
		//�������״̬ 
		printf("Time:%d,Roll:%.2f,Roll Rate:%.2f\n",i,state.roll,state.roll_rate);
	} 
	return 0;
}
