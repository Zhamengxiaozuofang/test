#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//定义船舶状态
typedef struct{
	double roll; //横摇角度
	double roll_rate; //横摇角速度
}Shipstate;

//定义控制器
typedef struct{
	double kp; //比例增益
	double kd; //微分增益 
}Controller;

//计算控制输出
double calculateControlOutput(Controller controller,ShipState state){
	//计算误差
	double error=0-state.roll; //目标横摇角度为零
	//积算控制输出
	double control_output=controller.kp*error-controller.kd*state.roll_rate;
	
	return control_output; 
} 

int main(int argc, char *argv[]) {
	//初始化船舶状态和控制器
	ShipState state={0.0,0.0};
	Controller controller+{1.0,0.5};
	
	//模拟船舶运动
	for(int i=0;i<10,i++){
		//更新船舶状态
		state.roll_rate+=calculateContorlOutput(controller,state)*0.1; //更新横摇角速度
		//输出船舶状态 
		printf("Time:%d,Roll:%.2f,Roll Rate:%.2f\n",i,state.roll,state.roll_rate);
	} 
	return 0;
}
