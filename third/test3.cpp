#include<iostream.h>
class Worker
{ public:
	
	Worker(char wname[20],int wage,char wsex)
	{ name = wname;age = wage; sex = wsex; 
	}
	~Worker();
	virtual void display() =0;
	void Compute_pay(int hour);
	void getName(){
		cout<<name<<"的选择"<<endl;}
	//friend void ostream& operator<<(ostream&out,Worker&worker) = 0;
 protected:
	 char *name;int age;char sex;char sort;int rank;


};

class HourlyWorker:public Worker
{ public:
HourlyWorker(char wname[20],int wage,char wsex,char wsort,int wrank):Worker(wname,wage,wsex)
	{  sort =wsort;rank = wrank;
	}
	~HourlyWorker();
	void Compute_pay(int hour);
	void display()
	{ cout<<name<<age<<sex<<sort<<rank;
	}
	void getHour(int whour);
	void payperhour();
protected:
	int pay_per_hour;
	int hour;char sort;int rank;double pay;

};
void HourlyWorker::getHour (int whour)
{ hour = whour;
}

void HourlyWorker::payperhour(){
	if (rank ==1)
		pay_per_hour = 10;
	else if(rank ==2)
		pay_per_hour = 20;
		else if (rank ==3)
			pay_per_hour = 40;
	cout<<"小时工资额"<<pay_per_hour<<endl;
}

void HourlyWorker::Compute_pay(int hour)
{ if (hour<=40)
	{ if(rank == 1)
		pay = 10*hour;
	
	else if(rank ==2)
		pay = 20*hour;
		else if (rank ==3)
			pay = 40*hour;
	}
  else{ if (rank ==1)
		pay = 10 *40+1.5*10*(hour-40);
	else if(rank ==2)
		pay = 20*40+1.5*20*(hour-40);
       
		else if(rank == 3)
			pay =40*40+1.5*40*(hour-40);
       	}
   cout<<"工资是"<<pay<<endl;
}
class SalariedWorker:public Worker
{ public:
SalariedWorker(char wname[20],int wage,char wsex,char wsort,int wrank):Worker(wname,wage,wsex)
	{ sort =wsort;rank = wrank;
	}
	~SalariedWorker();
	void getHour(int whour);
	void Compute_pay(int hour);
	void display()
	{cout<<name<<age<<sex<<sort<<rank;}
	
	void payperhour();
 protected:
	int pay_per_hour,hour,rank;
	char sort ;
	double pay;

};

void SalariedWorker:: payperhour(){
	if (rank ==1)
		pay_per_hour = 30;
	else if(rank ==2)
		pay_per_hour = 50;
		
	cout<<"小时工资额"<<pay_per_hour<<endl;
}
void SalariedWorker::getHour (int whour)
{ hour = whour;
}
void SalariedWorker::Compute_pay(int hour)
{ if (hour<35)
	{ if(rank == 1)
		pay = 30*hour+0.5*30*(35-hour);
	
	else if(rank ==2)
		pay =50*hour+0.5*50*(35-hour);
		
	}
  else{ if (rank ==1)
		pay = 30*40;
	else if(rank ==2)
		pay = 50*40;
       
		else if(rank == 3)
			pay =40*40+1.5*40*(hour-40);
       	}
  cout<<"工资是"<<pay<<endl;
}
void main(){
	cout<<"请输入姓名，年龄，性别（w/m)，类别(h/s)，薪金等级,工作时间\n";
	char wname[20];
	int wage;
	char wsex;
	char wsort;
	int wrank;
	int whour;
	cin.get (wname,20);
		//cin>>wage>>
		cin>>wage>>wsex>>wsort>>wrank>>whour;
		//hour = whour;
	Worker *pWorkers[5];

	for(int i = 0 ;i<5;i++)
	{	if(i<3)
		{
		//pWorkers[i] = new HourlyWorker[i];
		pWorkers[i] =new HourlyWorker(wname,wage,wsex,wsort,wrank);

		}
		else 
		{	//pWorkers[i] = new SalariedWorker[i];
			pWorkers[i] = new SalariedWorker(wname,wage,wsex,wsort,wrank);
		}
		

	}
	cout<<"请输入您的编号\n";
	cout<<"1.显示基本信息  2.显示工人周薪  3.退出\n";
	//int i ,j;
	int j;
	cin>>i>>j;
	while(!(j==1||j==2||j==3))
	{ cout<<"请重新选择（1---3）\n";
	  cin>>j;
	}
	if(j == 1)
	
		pWorkers[i]->display();
	else if(j ==2)
		
		
		pWorkers[i]->Compute_pay(whour);
	
		else if(j==3)
			
				cout<<"谢谢使用本系统\n";
			
for(i= 0;i<5;i++)		
delete pWorkers[i];	
}